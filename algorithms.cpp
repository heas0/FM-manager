#include "algorithms.h"
#include "pch.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

List<String^>^ PopulateDrives()
{
    // Получаем список всех доступных дисков
    array<DriveInfo^>^ drives = DriveInfo::GetDrives();
    // Создаём список, содержащий пути дисков. 
    List<String^>^ pathDrives = gcnew List<String^>();
    // добавляем путь к диску в массив
    for each (DriveInfo ^ drive in drives)
    {
        pathDrives->Add(drive->Name);

    }
    return pathDrives;
}

List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path)
{
    List<array<String^>^>^ result = gcnew List<array<String^>^>();

    try
    {
        array<String^>^ subdirectoryEntries = Directory::GetDirectories(path);

        for each (String ^ directoryName in subdirectoryEntries)
        {
            try
            {
                DirectoryInfo^ dirInfo = gcnew DirectoryInfo(directoryName);
                String^ dirName = dirInfo->Name;
                String^ dirType = "";
                String^ dirSize = "<Папка>";
                String^ dirTime = dirInfo->LastWriteTime.ToString();
                String^ dirAttributes = dirInfo->Attributes.ToString();

                array<String^>^ rowData = gcnew array<String^>(5) { dirName, dirType, dirSize, dirTime, dirAttributes };
                result->Add(rowData);
            }
            catch (UnauthorizedAccessException^)
            {
                // Ignore this directory and continue with the next one
                continue;
            }
        }

        array<String^>^ fileEntries = Directory::GetFiles(path);

        for each (String ^ fileName in fileEntries)
        {
            try
            {
                FileInfo^ fileInfo = gcnew FileInfo(fileName);
                String^ fName = fileInfo->Name;
                String^ fileType = fileInfo->Extension->Substring(1);
                String^ fileSize = fileInfo->Length.ToString();
                String^ fileTime = fileInfo->LastWriteTime.ToString();
                String^ fileAttributes = fileInfo->Attributes.ToString();

                array<String^>^ rowData = gcnew array<String^>(5) { fName, fileType, fileSize, fileTime, fileAttributes };
                result->Add(rowData);
            }
            catch (UnauthorizedAccessException^)
            {
                // Ignore this file and continue with the next one
                continue;
            }
        }
    }
    catch (Exception^)
    {
        throw safe_cast<String^>("Ошибка чтения файла");
    }

    return result;
}
void AddDirectoriesAndFilesToTreeView(String^ directoryPath, TreeNode^ parentNode, int depth)
{
    //node->Tag = "Дополнительная информация";

    // Получение значения свойства Tag из узла
    //String^ additionalInfo = safe_cast<String^>(node->Tag);
    if (depth <= 0) {
        return;
    }
    try
    {
        // Получаем подкаталоги
        array<String^>^ directories = Directory::GetDirectories(directoryPath);
        // Добавляем подкаталоги в качестве дочерних узлов
        for each (String ^ directory in directories)
        {
            try
            {
                DirectoryInfo^ dirInfo = gcnew DirectoryInfo(directory);
                String^ dirName = dirInfo->Name;
                TreeNode^ directoryNode = gcnew TreeNode(dirName);
                directoryNode->Tag = directory;
                parentNode->Nodes->Add(directoryNode);
                AddDirectoriesAndFilesToTreeView(directory, directoryNode, depth - 1);
            }
            catch (UnauthorizedAccessException^)
            {
                continue;
                // Обработка ошибки доступа к подкаталогу
                // Можно добавить соответствующую логику обработки ошибок здесь
            }
        }

        // Получаем файлы
        array<String^>^ files = Directory::GetFiles(directoryPath);

        // Добавляем файлы в качестве дочерних узлов
        for each (String ^ file in files)
        {
            try
            {
                String^ fileName = Path::GetFileName(file);
                TreeNode^ fileNode = gcnew TreeNode(fileName);
                parentNode->Nodes->Add(fileNode);
            }
            catch (UnauthorizedAccessException^)
            {
                continue;
                // Обработка ошибки доступа к файлу
                // Можно добавить соответствующую логику обработки ошибок здесь
            }
        }
    }
    catch (Exception^ ex)
    {
        return;
        // Обработка ошибок при доступе к файлам/каталогам
        // Можно добавить соответствующую логику обработки ошибок здесь
    }
}