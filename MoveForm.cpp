#include "pch.h"
#include "MoveForm.h"
#include <string>
#include <vector>
#include <Windows.h>
#include "algorithms.h"
#include "ProblemForm.h"
using namespace System;
using namespace System::IO;
using namespace CppCLR_WinFormsProject1;

System::Void CppCLR_WinFormsProject1::MoveForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        for each (String ^ path in paths) {
            // �������� �����
            if (File::Exists(path)) {
                // �������� ��� ����
                String^ filename = Path::GetFileName(path);
                // ��������� ���� ��� ����������� ����
                String^ destinationPath = Path::Combine(outputPath, filename);
                // ���������� ����
                File::Move(path, destinationPath);
            }
            // �������� �����
            else if (Directory::Exists(path)) {
                // �������� ��� ��������
                String^ foldername = Path::GetFileName(path);
                // ��������� ���� ��� ����������� ��������
                String^ destinationPath = Path::Combine(outputPath, foldername);
                // ���������� �������
                Directory::Move(path, destinationPath);
            }
        }
    }
    catch (Exception^ e) {
        this->status = e->ToString();
    }
    this->Close();
}
System::Void CppCLR_WinFormsProject1::MoveForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void CppCLR_WinFormsProject1::MoveForm::MoveForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    MoveFormClosed(sender, e);
}
