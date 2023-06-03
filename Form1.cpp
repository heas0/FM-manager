#include "pch.h"
#include "Form1.h"
#include "ProblemForm.h"
#include <string>
#include <filesystem>
#include <cliext/vector>
#include "algorithms.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

System::Void CppCLRWinFormsProject::Form1::TextBox1_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter){
        if (Path::IsPathRooted(this->textBox1->Text) && Directory::Exists(this->textBox1->Text))
        {
            try {
                List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->textBox1->Text);
                this->label3->Text = this->textBox1->Text;
                this->dataGridView1->Rows->Clear();
                for each (array<String^> ^ rows in Range) {
                    this->dataGridView1->Rows->Add(rows);
                }
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, �������� ����");
            }
        }
        else {
            try {
                List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->label1->Text + this->textBox1->Text);
                this->label3->Text = this->label1->Text + this->textBox1->Text;
                this->dataGridView1->Rows->Clear();
                for each (array<String^> ^ rows in Range) {
                    this->dataGridView1->Rows->Add(rows);
                }
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, �������� ����");
            }
        }
            this->textBox1->Text = "";
            // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
            e->Handled = true;
            e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::TextBox2_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter) {
        if (Path::IsPathRooted(this->textBox2->Text) && Directory::Exists(this->textBox2->Text))
        {
            try {
                List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->textBox2->Text);
                this->label4->Text = this->textBox2->Text;
                this->dataGridView2->Rows->Clear();
                for each (array<String^> ^ rows in Range) {
                    this->dataGridView2->Rows->Add(rows);
                }
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, �������� ����");
            }
        }
        else {
            try {
                List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->label2->Text + this->textBox2->Text);
                this->label4->Text = this->label2->Text + this->textBox2->Text;
                this->dataGridView2->Rows->Clear();
                for each (array<String^> ^ rows in Range) {
                    this->dataGridView2->Rows->Add(rows);
                }
            }
            catch (String^ e) {
                CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(e);

                callProblemForm(e + "\n��������, �������� ����");
            }
        }
        this->textBox2->Text = "";
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView_AfterExpand(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // �������������� ��������� �������� �������� !!!!!!!!!!!!!!!!!!!!!!!!
    // �������� �������� ����
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // �������� �������� �������� Tag �� ����
    String^ path = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(path, rootNode, 2);
}

System::Void CppCLRWinFormsProject::Form1::treeView_AfterCollapse(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // �������������� ��������� �������� �������� !!!!!!!!!!!!!!!!!!!!!!!!
    // �������� �������� ����
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // �������� �������� �������� Tag �� ����
    String^ path = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(path, rootNode, 2);
    // ��������� ���� ����� ����� � TreeView
    TreeNodeCollection^ rootNodes = e->Node->Nodes;

    // ����� � ��������� ������� ���� �����
    for each (TreeNode ^ node in rootNodes)
    {
        node->Nodes->Clear();
    }
}

System::Void CppCLRWinFormsProject::Form1::UpdateLeftTreeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->treeView1->Nodes->Clear();
    List<String^>^ Range = PopulateDrives();
    for each (String ^ pathDrive in Range) {
        // ������� ������ DriveInfo � ��������� ������ �����
        DriveInfo^ driveInfo = gcnew DriveInfo(pathDrive);
        // �������� ���������� � �����
        String^ driveName = driveInfo->Name;
        TreeNode^ rootNode = gcnew TreeNode(driveName);
        rootNode->Tag = pathDrive;
        this->treeView1->Nodes->Add(rootNode);
        AddDirectoriesAndFilesToTreeView(pathDrive, rootNode, 2);
    }
}

System::Void CppCLRWinFormsProject::Form1::UpdateRightTreeToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->treeView2->Nodes->Clear();
    List<String^>^ Range = PopulateDrives();
    for each (String ^ pathDrive in Range) {
        // ������� ������ DriveInfo � ��������� ������ �����
        DriveInfo^ driveInfo = gcnew DriveInfo(pathDrive);
        // �������� ���������� � �����
        String^ driveName = driveInfo->Name;
        TreeNode^ rootNode = gcnew TreeNode(driveName);
        rootNode->Tag = pathDrive;
        this->treeView2->Nodes->Add(rootNode);
        AddDirectoriesAndFilesToTreeView(pathDrive, rootNode, 2);
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView1_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
{
    // ���������, ��� ������� ������ ��������� �� ���� � ����� � �����
    if (e->Node->Tag != nullptr) {
        String^ path = e->Node->Tag->ToString();
        try {
            UpdateDataGridView1(path);
        }
        catch(String^ e) {
            callProblemForm(e + "\n��������, ������ �������");
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView2_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
{
    // ���������, ��� ������� ������ ��������� �� ���� � ����� � �����
    if (e->Node->Tag != nullptr) {
        String^ path = e->Node->Tag->ToString();
        try {
            UpdateDataGridView2(path);
        }
        catch (String^ e) {
            callProblemForm(e + "\n��������, ������ �������");
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::Form1_Load(System::Object^ sender, System::EventArgs^ e)
{
    UpdateLeftTreeToolStripMenuItem_Click(sender, e);
    UpdateRightTreeToolStripMenuItem_Click(sender, e);
    String^ driveForLabel = PopulateDrives()[0];
    this->label1->Text = driveForLabel;
    this->label2->Text = driveForLabel;
    this->label3->Text = driveForLabel;
    this->label4->Text = driveForLabel;
    List<array<String^>^>^ Range = getFileDirectoryForDataGridView(driveForLabel);
    for each (array<String^> ^ rows in Range) {
        this->dataGridView1->Rows->Add(rows);
        this->dataGridView2->Rows->Add(rows);
    }
}

System::Void CppCLRWinFormsProject::Form1::UpdateDataGridView1(String^ path)
{
        // �������� ���� ������� ��� ��������� �������� ������ �� �����
        // ...
    try {
        List<array<String^>^>^ Range = getFileDirectoryForDataGridView(path);
        this->label3->Text = path;
        this->dataGridView1->Rows->Clear();
        for each (array<String^> ^ rows in Range) {
            this->dataGridView1->Rows->Add(rows);
        }
    }
    catch (String^ e) {
    throw e;
    }
}   

    System::Void CppCLRWinFormsProject::Form1::UpdateDataGridView2(String^ path)
    {
        // �������� ���� ������� ��� ��������� �������� ������ �� �����
    // ...
    try {
        List<array<String^>^>^ Range = getFileDirectoryForDataGridView(path);
        this->label4->Text = path;
        this->dataGridView2->Rows->Clear();
        for each (array<String^> ^ rows in Range) {
        this->dataGridView2->Rows->Add(rows);
        }
    }
    catch (String^ e) {
        throw e;
    }
}

System::Void CppCLRWinFormsProject::Form1::dataGridView1_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0) {
        // �������� �������� ������ �������� ������� ��������� ������
        String^ value = dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString();
        // ��������� ������� (�������� �������� "<�����>")
        if (value == "<�����>")
        {
            String^ cellText = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
            // �������� ������� UpdateDataGridView1 ��� ��������� ����������� ��������
            try {
                UpdateDataGridView1(label3->Text + "\\" + cellText);
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, ������ �������");
            }
        }
        else if (value == "<�����> ")
        {
            String^ parentDirectory = Path::GetDirectoryName(label3->Text);
            // �������� ������� UpdateDataGridView1 ��� ��������� ����������� ��������
            try {
                UpdateDataGridView1(parentDirectory);
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, ���� �����");
            }
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::dataGridView2_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0) {
        // �������� �������� ������ �������� ������� ��������� ������
        String^ value = dataGridView2->Rows[e->RowIndex]->Cells[2]->Value->ToString();
        // ��������� ������� (�������� �������� "<�����>")
        if (value == "<�����>")
        {
            String^ cellText = dataGridView2->Rows[e->RowIndex]->Cells[0]->Value->ToString();
            // �������� ������� UpdateDataGridView1 ��� ��������� ����������� ��������
            try {
                UpdateDataGridView2(label4->Text + "\\" + cellText);
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, ������ �������");
            }
        }
        else if (value == "<�����> ")
        {
            String^ parentDirectory = Path::GetDirectoryName(label4->Text);
            // �������� ������� UpdateDataGridView1 ��� ��������� ����������� ��������
            try {
                UpdateDataGridView2(parentDirectory);
            }
            catch (String^ e) {
                callProblemForm(e + "\n��������, ���� �����");
            }
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::callProblemForm(String^ problem)
{
    if (ProblemForm != nullptr)
    {
        ProblemForm->Close();
        ProblemForm = nullptr; // �������� ������ �� ��������� Form2
    }
    ProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(problem);
    ProblemForm->Show();
}

System::Void CppCLRWinFormsProject::Form1::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (CopyForm != nullptr)
    {
        CopyForm->Close();
        CopyForm = nullptr; // �������� ������ �� ��������� Form2
    }
    // ��������� ���������� ����� � ���������� ������ �� ������ ������ � ������
    List<String^>^ selectedTextList = gcnew List<String^>();
    for each (DataGridViewRow ^ row in dataGridView1->SelectedRows)
    {
        String^ cellText = row->Cells[0]->Value->ToString(); // ��������� ������ �� ������ ������
        selectedTextList->Add(label3->Text + "\\" + cellText); // ���������� ���� ������������� �������� + ��� ����� � ������
    }
    // �������� �������
    if (dataGridView1->SelectedRows->Count > 0 &&
        dataGridView1->Rows[0]->Selected &&
        dataGridView1->Rows[0]->Cells[2]->Value->ToString() == "<�����> ")
    {
        selectedTextList->RemoveAt(0);
    }
    if (selectedTextList->Count > 0) {
        // ������� ��������� ����� CopyForm � �������� �� ������ � �������� ����� � ���� �����������
        CopyForm = gcnew CppCLR_WinFormsProject1::CopyForm(selectedTextList, this->label4->Text);
        CopyForm->Show();
    }
    else {
        callProblemForm("�� ������� �� ���� ������,\n������������ ������� �� ����������!");
    }
}

