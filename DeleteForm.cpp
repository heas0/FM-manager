#include "pch.h"
#include "DeleteForm.h"
#include <string>
#include <vector>
#include "algorithms.h"
using namespace System;
using namespace System::IO;
using namespace CppCLR_WinFormsProject1;

System::Void CppCLR_WinFormsProject1::DeleteForm::button1_Click(System::Object^ sender, System::EventArgs^ e)
{
    try {
        for each (String ^ path in paths) {
            if (File::Exists(path)) {
                File::Delete(path);
            }
            else if (Directory::Exists(path)) {
                Directory::Delete(path, true);
            }
        }
    }
    catch (Exception^ e) {
        this->status = e->ToString();
    }
    this->Close();
}

System::Void CppCLR_WinFormsProject1::DeleteForm::button2_Click(System::Object^ sender, System::EventArgs^ e)
{
    this->Close();
}

System::Void CppCLR_WinFormsProject1::DeleteForm::DeleteForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e)
{
    DeleteFormClosed(sender, e);
}