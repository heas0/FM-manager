#include "pch.h"
#include "MoveForm.h"
#include <string>
#include <vector>
#include "algorithms.h"
using namespace System;
using namespace System::IO;
using namespace CppCLR_WinFormsProject1;

System::Void CppCLR_WinFormsProject1::MoveForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        for each (String ^ path in paths) {
            // Перемещаем файлы
            if (File::Exists(path)) {
                // Получаем имя файл
                String^ filename = Path::GetFileName(path);
                // Формируем путь для перемещения файл
                String^ destinationPath = Path::Combine(textBox1->Text + "\\", filename);
                // Перемещаем Файл
                File::Move(path, destinationPath);
            }
            // Перемещаем папки
            else if (Directory::Exists(path)) {
                // Получаем имя каталога
                String^ foldername = Path::GetFileName(path);
                // Формируем путь для перемещения каталога
                String^ destinationPath = Path::Combine(textBox1->Text + "\\", foldername);
                // Перемещаем каталог
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
