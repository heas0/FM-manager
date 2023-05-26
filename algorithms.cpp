#include "algorithms.h"
#include "pch.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path)
{
    List<array<String^>^>^ result = gcnew List<array<String^>^>();
    try {
        array<String^>^ fileEntries = Directory::GetFiles(path);
        array<String^>^ subdirectoryEntries = Directory::GetDirectories(path);
        for each (String ^ directoryName in subdirectoryEntries)
        {
            DirectoryInfo^ dirInfo = gcnew DirectoryInfo(directoryName);
            String^ dirName = dirInfo->Name;
            String^ dirType = " ";
            String^ dirSize = "<Папка>"; // Каталог не имеет размера
            String^ dirTime = dirInfo->LastWriteTime.ToString();
            String^ dirAttributes = dirInfo->Attributes.ToString();
            array<String^>^ rowData = gcnew array<String^>(5);
            rowData[0] = dirName;
            rowData[1] = dirType;
            rowData[2] = dirSize;
            rowData[3] = dirTime;
            rowData[4] = dirAttributes;
            result->Add(rowData);
        }
        for each (String ^ fileName in fileEntries)
        {
            FileInfo^ fileInfo = gcnew FileInfo(fileName);
            String^ fileName = fileInfo->Name;
            String^ fileType = " ";
            String^ fileSize = fileInfo->Length.ToString();
            String^ fileTime = fileInfo->LastWriteTime.ToString();
            String^ fileAttributes = fileInfo->Attributes.ToString();
            array<String^>^ rowData = gcnew array<String^>(5);
            rowData[0] = fileName;
            rowData[1] = fileType;
            rowData[2] = fileSize;
            rowData[3] = fileTime; 
            rowData[4] = fileAttributes;
            result->Add(rowData);
        }
    }
    catch (Exception^ e) {
        String^ error = gcnew String("Файл не найден");
        throw error;
    }
    return result;
}