#pragma once
#include <string>
#include <filesystem>
#include <cliext/vector>
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

// Функция для копирования папки в другую папку
void CopyDirectory(String^ sourcePath, String^ destinationPath);
// Функция для получения списка дисков
List<String^>^ PopulateDrives();
// Функция для добавления подкаталогов и файлов каталога в DataGridView
List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path);
// Функция для добавления подкаталогов и файлов каталога к существующему корню TreeView
void AddDirectoriesAndFilesToTreeView(String^ directoryPath, TreeNode^ parentNode, int depth);
#pragma endregion