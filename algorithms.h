#pragma once
#include <string>
#include <filesystem>
#include <cliext/vector>
using namespace System;
using namespace System::IO;
using namespace System::Collections::Generic;

List<array<String^>^>^ getFileDirectoryForDataGridView(String^ path);