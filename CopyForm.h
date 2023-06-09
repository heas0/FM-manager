#pragma once
#include <cliext/list>
namespace CppCLR_WinFormsProject1 {
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Collections::Generic;
	using namespace cliext;
	/// <summary>
	/// ������ ��� CopyForm
	/// </summary>
	public ref class CopyForm : public System::Windows::Forms::Form
	{
	public:
		CopyForm(List<String^>^ paths, String^ outputPath)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			//
			this->paths = paths;
			this->outputPath = outputPath;
			this->label1->Text += this->paths->Count.ToString() + ") �:";
			this->textBox1->Text = this->outputPath;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Left = (System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width - this->Width) / 2;
			this->Top = (System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height - this->Height) / 2;
		}

	protected:
		/// <summary>
		/// ���������� ��� ������������ �������.
		/// </summary>
		~CopyForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Button^ button1;
	protected:
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Label^ label1;

	private:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent(void)
		{
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(171, 95);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 0;
			this->button1->Text = L"��";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &CopyForm::button1_Click);
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(252, 95);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 1;
			this->button2->Text = L"���";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &CopyForm::button2_Click);
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(15, 42);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(290, 20);
			this->textBox1->TabIndex = 2;
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12, 26);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(110, 13);
			this->label1->TabIndex = 3;
			this->label1->Text = L"���������� ����� (";
			// 
			// CopyForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(339, 122);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"CopyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Text = L"CopyForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &CopyForm::CopyForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
	public:  event System::EventHandler^ CopyFormClosed;
	private: System::Void CopyForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: List<String^>^ paths;
	private: String^ outputPath;
	public: String^ status = gcnew String("Ok");
};
}
#pragma endregion