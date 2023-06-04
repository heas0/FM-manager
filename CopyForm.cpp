#include "pch.h"
#include "CopyForm.h"
#include <string>
#include <vector>
#include "algorithms.h"
using namespace System;
using namespace System::IO;
using namespace CppCLR_WinFormsProject1;
System::Void CppCLR_WinFormsProject1::CopyForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        for each (String ^ path in paths) {
            // Копируем файлы
            if (File::Exists(path)) {
                String^ filename = Path::GetFileName(path);
                String^ destinationPath = Path::Combine(textBox1->Text + "\\", filename);
                File::Copy(path, destinationPath);
            }
            // Копируем папки
            else if (Directory::Exists(path)) {
                String^ foldername = Path::GetFileName(path);
                String^ destinationPath = Path::Combine(textBox1->Text + "\\", foldername);
                Directory::CreateDirectory(destinationPath);
                CopyDirectory(path, destinationPath);
            }
        }
    }
    catch (Exception^ e) {
        this->status = e->ToString();
    }
    this->Close();
}
System::Void CppCLR_WinFormsProject1::CopyForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
	this->Close();
}
System::Void CppCLR_WinFormsProject1::CopyForm::CopyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e) {
    // Вызываем событие CopyFormClosed
    CopyFormClosed(sender, e);
}