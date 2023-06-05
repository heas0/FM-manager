#pragma once
#include <string>
#include <filesystem>
#include <cliext/vector>
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

// ������� ��� ����������� ����� � ������ �����
void CopyDirectory(String^ sourcePath, String^ destinationPath);
// ������� ��� ��������� ������ ������
List<String^>^ PopulateDrives();
// ������� ��� ���������� ������������ � ������ �������� � DataGridView
List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path);
// ������� ��� ���������� ������������ � ������ �������� � ������������� ����� TreeView
void AddDirectoriesAndFilesToTreeView(String^ directoryPath, TreeNode^ parentNode, int depth);
#pragma endregion