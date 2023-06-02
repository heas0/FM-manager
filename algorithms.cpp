#include "algorithms.h"
#include "pch.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

List<String^>^ PopulateDrives()
{
    // �������� ������ ���� ��������� ������
    array<DriveInfo^>^ drives = DriveInfo::GetDrives();
    // ������ ������, ���������� ���� ������. 
    List<String^>^ pathDrives = gcnew List<String^>();
    // ��������� ���� � ����� � ������
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
                String^ dirSize = "<�����>";
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
        throw safe_cast<String^>("������ ������ �����");
    }

    return result;
}
void AddDirectoriesAndFilesToTreeView(String^ directoryPath, TreeNode^ parentNode, int depth)
{
    //node->Tag = "�������������� ����������";

    // ��������� �������� �������� Tag �� ����
    //String^ additionalInfo = safe_cast<String^>(node->Tag);
    if (depth <= 0) {
        return;
    }
    try
    {
        // �������� �����������
        array<String^>^ directories = Directory::GetDirectories(directoryPath);
        // ��������� ����������� � �������� �������� �����
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
                // ��������� ������ ������� � �����������
                // ����� �������� ��������������� ������ ��������� ������ �����
            }
        }

        // �������� �����
        array<String^>^ files = Directory::GetFiles(directoryPath);

        // ��������� ����� � �������� �������� �����
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
                // ��������� ������ ������� � �����
                // ����� �������� ��������������� ������ ��������� ������ �����
            }
        }
    }
    catch (Exception^ ex)
    {
        return;
        // ��������� ������ ��� ������� � ������/���������
        // ����� �������� ��������������� ������ ��������� ������ �����
    }
}