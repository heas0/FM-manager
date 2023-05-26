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
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm("���� �� ������");
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
            this->label3->Text = this->label2->Text + this->textBox2->Text;
            this->dataGridView1->Rows->Clear();
            for each (array<String^> ^ rows in getFileDirectoryForDataGridView(this->label2->Text + this->textBox2->Text)) {
                this->dataGridView2->Rows->Add(rows);
            }
        }
        catch (String^ e) {
            this->textBox2->Text = "";
            CppCLR_WinFormsProject1::ProblemForm^ newProblemForm = gcnew CppCLR_WinFormsProject1::ProblemForm(e);
            newProblemForm->Show();
        }
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}