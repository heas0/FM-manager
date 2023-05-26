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
    if (e->KeyCode == Keys::Enter)
    {
        if (IsPathValidAndExists(this->textBox1->Text)) {
            this->label1->Text = " ";
            this->dataGridView1->Rows->Clear();
            for each (array<String^> ^ rows in getFileDirectoryForDataGridView(this->label1->Text + this->textBox1->Text)) {
                this->dataGridView1->Rows->Add(rows);
            }
        }
        else {
            this->label1->Text = "c:\\";
            if (IsPathValidAndExists(this->label1->Text + this->textBox1->Text)) {
                this->label1->Text = " ";
                this->dataGridView1->Rows->Clear();
                for each (array<String^> ^ rows in getFileDirectoryForDataGridView(this->label1->Text + this->textBox1->Text)) {
                    this->dataGridView1->Rows->Add(rows);
                }
            }
            else {
                //"���� �� ������(^_^)"
                CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm();
                newProblemForm->Show();
            }
        }
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::TextBox2_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
    {
        this->dataGridView2->Rows->Clear();
        for each (array<String^> ^ rows in getFileDirectoryForDataGridView(this->label2->Text + this->textBox2->Text)) {
            this->dataGridView2->Rows->Add(rows);
        }
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}