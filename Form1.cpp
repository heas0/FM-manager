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
        try {
            List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->label1->Text + this->textBox1->Text);
            this->label3->Text = this->label1->Text + this->textBox1->Text;
            this->dataGridView1->Rows->Clear();
            for each (array<String^> ^ rows in Range) {
                this->dataGridView1->Rows->Add(rows);
            }
        }
        catch(String^ e){
            this->textBox1->Text = "";
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(e);
            // ���������� ����� ������������ ����
            newProblemForm->StartPosition = FormStartPosition::Manual;
            newProblemForm->Left = (Screen::PrimaryScreen->Bounds.Width - newProblemForm->Width) / 2;
            newProblemForm->Top = (Screen::PrimaryScreen->Bounds.Height - newProblemForm ->Height) / 2;
            newProblemForm->Show();
        }
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::TextBox2_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter) {
        try {
            List<array<String^>^>^ Range = getFileDirectoryForDataGridView(this->label2->Text + this->textBox2->Text);
            this->label4->Text = this->label2->Text + this->textBox2->Text;
            this->dataGridView2->Rows->Clear();
            for each (array<String^> ^ rows in Range) {
                this->dataGridView2->Rows->Add(rows);
            }
        }
        catch (String^ e) {
            this->textBox2->Text = "";
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(e);
            // ���������� ����� ������������ ����
            newProblemForm->StartPosition = FormStartPosition::Manual;
            newProblemForm->Left = (Screen::PrimaryScreen->Bounds.Width - newProblemForm->Width) / 2;
            newProblemForm->Top = (Screen::PrimaryScreen->Bounds.Height - newProblemForm->Height) / 2;
            newProblemForm->Show();
        }
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
        if (Directory::Exists(path))
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
                return;
            }
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView2_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
{
    // ���������, ��� ������� ������ ��������� �� ���� � ����� � �����
    if (e->Node->Tag != nullptr) {
        String^ path = e->Node->Tag->ToString();
        if (Directory::Exists(path))
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
                return;
            }
        }
    }
}
