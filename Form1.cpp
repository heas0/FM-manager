#include "pch.h"
#include "Form1.h"
#include <iostream>
#include <string>
#include <filesystem>
#include <cliext/vector>
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

List<array<String^>^>^ ListDirectoryContents(String^ path);

System::Void CppCLRWinFormsProject::Form1::TextBox2_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
    {
        // ������� ��������� ����
        for each (array<String^> ^ rows in ListDirectoryContents("C:\\" + this->textBox1->Text)) {
            this->dataGridView2->Rows->Add(rows);
        }
        textBox1->Text = "";
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

System::Void CppCLRWinFormsProject::Form1::TextBox1_KeyDown(Object^ sender, KeyEventArgs^ e)
{
    if (e->KeyCode == Keys::Enter)
    {
        // ������� ��������� ����
        for each (array<String^> ^ rows in ListDirectoryContents("C:\\" + this->textBox1->Text)) {
            this->dataGridView1->Rows->Add(rows);
        }
        textBox1->Text = "";
        // �������� ������� ��� ������������, ����� �������� �������������� ��������� ������� Enter
        e->Handled = true;
        e->SuppressKeyPress = true;
    }
}

List<array<String^>^>^ ListDirectoryContents(String^ path)
{
    int i = 0;
    array<String^>^ fileEntries = Directory::GetFiles(path);
    array<String^>^ subdirectoryEntries = Directory::GetDirectories(path);
    List<array<String^>^>^ result = gcnew List<array<String^>^>();
    for each (String ^ fileName in fileEntries)
    {
        array<String^>^ rowData = rowData = gcnew array<String^>(5);
        rowData[0] = fileName; // ��������� ����� � ������ �������
        rowData[1] = "�����";
        rowData[2] = System::Convert::ToString(i++);
        result->Add(rowData);
    }
    for each (String ^ subdirectoryName in subdirectoryEntries)
    {
        array<String^>^ rowData = rowData = gcnew array<String^>(5);
        rowData[0] = subdirectoryName; // ��������� ����� � ������ �������
        rowData[1] = "����";
        rowData[2] = System::Convert::ToString(i++);
        result->Add(rowData);
    }
    return result;
}
