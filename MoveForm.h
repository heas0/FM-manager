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

	/// <summary>
	/// Сводка для MoveForm
	/// </summary>
	public ref class MoveForm : public System::Windows::Forms::Form
	{
	public:
		MoveForm(List<String^>^ paths, String^ outputPath)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
			this->paths = paths;
			this->outputPath = outputPath;
			this->label1->Text += this->paths->Count.ToString() + ") в:";
			this->textBox1->Text = this->outputPath;
			this->StartPosition = System::Windows::Forms::FormStartPosition::Manual;
			this->Left = (System::Windows::Forms::Screen::PrimaryScreen->Bounds.Width - this->Width) / 2;
			this->Top = (System::Windows::Forms::Screen::PrimaryScreen->Bounds.Height - this->Height) / 2;
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MoveForm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^ label1;
	protected:
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::Button^ button2;
	private: System::Windows::Forms::Button^ button1;

	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container^ components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(9, 30);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(118, 13);
			this->label1->TabIndex = 7;
			this->label1->Text = L"Переместить файлы (";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12, 46);
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(290, 20);
			this->textBox1->TabIndex = 6;
			// 
			// button2
			// 
			this->button2->Location = System::Drawing::Point(249, 99);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(75, 23);
			this->button2->TabIndex = 5;
			this->button2->Text = L"Нет";
			this->button2->UseVisualStyleBackColor = true;
			this->button2->Click += gcnew System::EventHandler(this, &MoveForm::button2_Click);
			// 
			// button1
			// 
			this->button1->Location = System::Drawing::Point(168, 99);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(75, 23);
			this->button1->TabIndex = 4;
			this->button1->Text = L"Да";
			this->button1->UseVisualStyleBackColor = true;
			this->button1->Click += gcnew System::EventHandler(this, &MoveForm::button1_Click);
			// 
			// MoveForm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(352, 138);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Name = L"MoveForm";
			this->Text = L"MoveForm";
			this->FormClosing += gcnew System::Windows::Forms::FormClosingEventHandler(this, &MoveForm::MoveForm_FormClosing);
			this->ResumeLayout(false);
			this->PerformLayout();
		}
	public:  event System::EventHandler^ MoveFormClosed;
	private: System::Void MoveForm_FormClosing(System::Object^ sender, System::Windows::Forms::FormClosingEventArgs^ e);
	private: List<String^>^ paths;
	private: String^ outputPath;
	public: String^ status = gcnew String("Ok");
	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: System::Void button2_Click(System::Object^ sender, System::EventArgs^ e);
};
}
#pragma endregion