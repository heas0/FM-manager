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
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm("Файл не найден");
            // Центрируем форму относительно окна
            newProblemForm->StartPosition = FormStartPosition::Manual;
            newProblemForm->Left = (Screen::PrimaryScreen->Bounds.Width - newProblemForm->Width) / 2;
            newProblemForm->Top = (Screen::PrimaryScreen->Bounds.Height - newProblemForm ->Height) / 2;
            newProblemForm->Show();
        }
        // Помечаем событие как обработанное, чтобы избежать дополнительной обработки клавиши Enter
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
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm("Файл не найден");
            // Центрируем форму относительно окна
            newProblemForm->StartPosition = FormStartPosition::Manual;
            newProblemForm->Left = (Screen::PrimaryScreen->Bounds.Width - newProblemForm->Width) / 2;
            newProblemForm->Top = (Screen::PrimaryScreen->Bounds.Height - newProblemForm->Height) / 2;
            newProblemForm->Show();
        }
        // Помечаем событие как обработанное, чтобы избежать дополнительной обработки клавиши Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

// Обработчик события Load формы
System::Void CppCLRWinFormsProject::Form1::toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e)
{
    // Ваш код...
    if (this->treeView1->Nodes->Count > 0) {
        return;
    }
    String^ rootDirectory = "C:\\";

    // Создаем корневой узел TreeView
    TreeNode^ rootNode = gcnew TreeNode(rootDirectory);
    rootNode->Tag = "C:\\";
    this->treeView1->Nodes->Add(rootNode);

    // Добавляем все подкаталоги и файлы каталога к корню TreeView
    AddDirectoriesAndFilesToTreeView(rootDirectory, rootNode, 2);

    // Ваш код...
}

System::Void CppCLRWinFormsProject::Form1::treeView1_AfterExpand(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // Получаем корневой узел
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // Ваш код для обработки раскрытия корневого узла
    // ...
    // Получаем значение свойства Tag из узла
    String^ additionalInfo = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(additionalInfo, rootNode, 2);
}

System::Void CppCLRWinFormsProject::Form1::treeView1_AfterCollapse(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e)
{
    // ПРЕДВАРИТЕЛЬНО ОБНОВЛЯЕМ ЭЛЕМЕНТЫ КАТАЛОГА !!!!!!!!!!!!!!!!!!!!!!!!
    // Получаем корневой узел
    TreeNode^ rootNode = e->Node;
    rootNode->Nodes->Clear();
    // Ваш код для обработки раскрытия корневого узла
    // ...
    // Получаем значение свойства Tag из узла
    String^ additionalInfo = safe_cast<String^>(rootNode->Tag);
    AddDirectoriesAndFilesToTreeView(additionalInfo, rootNode, 2);
    // Получение всех узлов корня в TreeView
    TreeNodeCollection^ rootNodes = e->Node->Nodes;

    // Обход и обработка каждого узла корня
    for each (TreeNode ^ node in rootNodes)
    {
        node->Nodes->Clear();
    }
}