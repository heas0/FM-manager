#pragma once
#include <string>
#include <filesystem>
#include <cliext/vector>
#include <string>
#include <filesystem>
#include <cliext/vector>
#include "algorithms.h"
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;
using namespace System::Windows::Forms;

List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path);
// ������� ��� ���������� ������������ � ������ �������� � ������������� ����� TreeView
void AddDirectoriesAndFilesToTreeView(String^ directoryPath, TreeNode^ parentNode, int depth);
