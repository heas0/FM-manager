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
                callProblemForm(e + "\nВозможно, неверный путь");
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
                callProblemForm(e + "\nВозможно, неверный путь");
            }
        }
            this->textBox1->Text = "";
            // Помечаем событие как обработанное, чтобы избежать дополнительной обработки клавиши Enter
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
                callProblemForm(e + "\nВозможно, неверный путь");
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

                callProblemForm(e + "\nВозможно, неверный путь");
            }
        }
        this->textBox2->Text = "";
        // Помечаем событие как обработанное, чтобы избежать дополнительной обработки клавиши Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView_AfterExpand(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // ПРЕДВАРИТЕЛЬНО ОБНОВЛЯЕМ ЭЛЕМЕНТЫ КАТАЛОГА !!!!!!!!!!!!!!!!!!!!!!!!
    // Получаем корневой узел
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // Получаем значение свойства Tag из узла
    String^ path = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(path, rootNode, 2);
}

System::Void CppCLRWinFormsProject::Form1::treeView_AfterCollapse(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // ПРЕДВАРИТЕЛЬНО ОБНОВЛЯЕМ ЭЛЕМЕНТЫ КАТАЛОГА !!!!!!!!!!!!!!!!!!!!!!!!
    // Получаем корневой узел
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // Получаем значение свойства Tag из узла
    String^ path = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(path, rootNode, 2);
    // Получение всех узлов корня в TreeView
    TreeNodeCollection^ rootNodes = e->Node->Nodes;

    // Обход и обработка каждого узла корня
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
        // Создаем объект DriveInfo с указанным именем диска
        DriveInfo^ driveInfo = gcnew DriveInfo(pathDrive);
        // Получаем информацию о диске
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
        // Создаем объект DriveInfo с указанным именем диска
        DriveInfo^ driveInfo = gcnew DriveInfo(pathDrive);
        // Получаем информацию о диске
        String^ driveName = driveInfo->Name;
        TreeNode^ rootNode = gcnew TreeNode(driveName);
        rootNode->Tag = pathDrive;
        this->treeView2->Nodes->Add(rootNode);
        AddDirectoriesAndFilesToTreeView(pathDrive, rootNode, 2);
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView1_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
{
    // Проверяем, что двойной щелчок произошел на узле с путем к папке
    if (e->Node->Tag != nullptr) {
        String^ path = e->Node->Tag->ToString();
        try {
            UpdateDataGridView1(path);
        }
        catch(String^ e) {
            callProblemForm(e + "\nВозможно, ошибка доступа");
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::treeView2_NodeMouseDoubleClick(System::Object^ sender, System::Windows::Forms::TreeNodeMouseClickEventArgs^ e)
{
    // Проверяем, что двойной щелчок произошел на узле с путем к папке
    if (e->Node->Tag != nullptr) {
        String^ path = e->Node->Tag->ToString();
        try {
            UpdateDataGridView2(path);
        }
        catch (String^ e) {
            callProblemForm(e + "\nВозможно, ошибка доступа");
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
        // Вызываем вашу функцию для обработки двойного щелчка на папке
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
        // Вызываем вашу функцию для обработки двойного щелчка на папке
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
        // Получаем значение ячейки третьего столбца выбранной строки
        String^ value = dataGridView1->Rows[e->RowIndex]->Cells[2]->Value->ToString();
        // Проверяем условие (значение содержит "<Папка>")
        if (value == "<Папка>")
        {
            String^ cellText = dataGridView1->Rows[e->RowIndex]->Cells[0]->Value->ToString();
            // Вызываем функцию UpdateDataGridView1 или выполняем необходимые действия
            try {
                UpdateDataGridView1(label3->Text + "\\" + cellText);
            }
            catch (String^ e) {
                callProblemForm(e + "\nВозможно, ошибка доступа");
            }
        }
        else if (value == "<Папка> ")
        {
            String^ parentDirectory = Path::GetDirectoryName(label3->Text);
            // Вызываем функцию UpdateDataGridView1 или выполняем необходимые действия
            try {
                UpdateDataGridView1(parentDirectory);
            }
            catch (String^ e) {
                callProblemForm(e + "\nВозможно, файл удалён");
            }
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::dataGridView2_CellDoubleClick(System::Object^ sender, System::Windows::Forms::DataGridViewCellEventArgs^ e)
{
    if (e->RowIndex >= 0) {
        // Получаем значение ячейки третьего столбца выбранной строки
        String^ value = dataGridView2->Rows[e->RowIndex]->Cells[2]->Value->ToString();
        // Проверяем условие (значение содержит "<Папка>")
        if (value == "<Папка>")
        {
            String^ cellText = dataGridView2->Rows[e->RowIndex]->Cells[0]->Value->ToString();
            // Вызываем функцию UpdateDataGridView1 или выполняем необходимые действия
            try {
                UpdateDataGridView2(label4->Text + "\\" + cellText);
            }
            catch (String^ e) {
                callProblemForm(e + "\nВозможно, ошибка доступа");
            }
        }
        else if (value == "<Папка> ")
        {
            String^ parentDirectory = Path::GetDirectoryName(label4->Text);
            // Вызываем функцию UpdateDataGridView1 или выполняем необходимые действия
            try {
                UpdateDataGridView2(parentDirectory);
            }
            catch (String^ e) {
                callProblemForm(e + "\nВозможно, файл удалён");
            }
        }
    }
}

System::Void CppCLRWinFormsProject::Form1::callProblemForm(String^ problem)
{
    if (ProblemForm != nullptr)
    {
        ProblemForm->Close();
        ProblemForm = nullptr; // Обнуляем ссылку на экземпляр Form2
    }
    ProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(problem);
    ProblemForm->Show();
}

System::Void CppCLRWinFormsProject::Form1::toolStripButton2_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (CopyForm != nullptr)
    {
        CopyForm->Close();
        CopyForm = nullptr; // Обнуляем ссылку на экземпляр Form2
    }
    // Получение выделенных строк и добавление текста из первой ячейки в список
    List<String^>^ selectedTextList = gcnew List<String^>();
    for each (DataGridViewRow ^ row in dataGridView1->SelectedRows)
    {
        String^ cellText = row->Cells[0]->Value->ToString(); // Получение текста из первой ячейки
        selectedTextList->Add(label3->Text + "\\" + cellText); // Добавление пути родительского каталога + имя файла в список
    }
    // Проверка условия
    if (dataGridView1->SelectedRows->Count > 0 &&
        dataGridView1->Rows[0]->Selected &&
        dataGridView1->Rows[0]->Cells[2]->Value->ToString() == "<Папка> ")
    {
        selectedTextList->RemoveAt(0);
    }
    if (selectedTextList->Count > 0) {
        // Создаем экземпляр формы CopyForm и передаем ей список с текстами ячеек и путь копирования
        CopyForm = gcnew CppCLR_WinFormsProject1::CopyForm(selectedTextList, this->label4->Text);
        CopyForm->CopyFormClosed += gcnew System::EventHandler(this, &Form1::СopyForm_CopyFormClosed);
        CopyForm->Show();
    }
    else {
        callProblemForm("Не выделен ни один объект,\nРодительский каталог не копируется!");
    }
}

System::Void CppCLRWinFormsProject::Form1::СopyForm_CopyFormClosed(System::Object^ sender, System::EventArgs^ e)
{
    if (CopyForm->status != "Ok") {
        callProblemForm(CopyForm->status);
    }
    UpdateDataGridView1(label3->Text);
    UpdateDataGridView2(label4->Text);
}

System::Void CppCLRWinFormsProject::Form1::toolStripButton3_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (MoveForm != nullptr)
    {
        MoveForm->Close();
        MoveForm = nullptr; // Обнуляем ссылку на экземпляр Form2
    }
    // Получение выделенных строк и добавление текста из первой ячейки в список
    List<String^>^ selectedTextList = gcnew List<String^>();
    for each (DataGridViewRow ^ row in dataGridView1->SelectedRows)
    {
        String^ cellText = row->Cells[0]->Value->ToString(); // Получение текста из первой ячейки
        selectedTextList->Add(label3->Text + "\\" + cellText); // Добавление пути родительского каталога + имя файла в список
    }
    // Проверка условия
    if (dataGridView1->SelectedRows->Count > 0 &&
        dataGridView1->Rows[0]->Selected &&
        dataGridView1->Rows[0]->Cells[2]->Value->ToString() == "<Папка> ")
    {
        selectedTextList->RemoveAt(0);
    }
    if (selectedTextList->Count > 0) {
        // Создаем экземпляр формы CopyForm и передаем ей список с текстами ячеек и путь копирования
        MoveForm = gcnew CppCLR_WinFormsProject1::MoveForm(selectedTextList, this->label4->Text);
        MoveForm->MoveFormClosed += gcnew System::EventHandler(this, &Form1::MoveForm_MoveFormClosed);
        MoveForm->Show();
    }
    else {
        callProblemForm("Не выделен ни один объект,\nРодительский каталог не перемещается!");
    }
}

System::Void CppCLRWinFormsProject::Form1::MoveForm_MoveFormClosed(System::Object^ sender, System::EventArgs^ e)
{
    if (MoveForm->status != "Ok") {
        callProblemForm(MoveForm->status);
    }
    UpdateDataGridView1(label3->Text);
    UpdateDataGridView2(label4->Text);
}


System::Void CppCLRWinFormsProject::Form1::toolStripButton4_Click(System::Object^ sender, System::EventArgs^ e)
{
    if (DeleteForm != nullptr)
    {
        DeleteForm->Close();
        DeleteForm = nullptr; // Обнуляем ссылку на экземпляр Form2
    }
    // Получение выделенных строк и добавление текста из первой ячейки в список
    List<String^>^ selectedTextList = gcnew List<String^>();
    for each (DataGridViewRow ^ row in dataGridView1->SelectedRows)
    {
        String^ cellText = row->Cells[0]->Value->ToString(); // Получение текста из первой ячейки
        selectedTextList->Add(label3->Text + "\\" + cellText); // Добавление пути родительского каталога + имя файла в список
    }
    // Проверка условия
    if (dataGridView1->SelectedRows->Count > 0 &&
        dataGridView1->Rows[0]->Selected &&
        dataGridView1->Rows[0]->Cells[2]->Value->ToString() == "<Папка> ")
    {
        selectedTextList->RemoveAt(0);
    }
    if (selectedTextList->Count > 0) {
        // Создаем экземпляр формы CopyForm и передаем ей список с текстами ячеек и путь копирования
        DeleteForm = gcnew CppCLR_WinFormsProject1::DeleteForm(selectedTextList);
        DeleteForm->DeleteFormClosed += gcnew System::EventHandler(this, &Form1::DeleteForm_DeleteFormClosed);
        DeleteForm->Show();
    }
    else {
        callProblemForm("Не выделен ни один объект,\nРодительский каталог не удаляется!");
    }
}
System::Void CppCLRWinFormsProject::Form1::DeleteForm_DeleteFormClosed(System::Object^ sender, System::EventArgs^ e)
{
    if (DeleteForm->status != "Ok") {
        callProblemForm(MoveForm->status);
    }
    UpdateDataGridView1(label3->Text);
    UpdateDataGridView2(label4->Text);
}
System::Void CppCLRWinFormsProject::Form1::ClosingTheProgramToolStripMenuItem_Click(System::Object^ sender, System::EventArgs^ e) {
    this->Close();
}