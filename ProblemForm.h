#pragma once

namespace CppCLR_WinFormsProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// ������ ��� ProblemForm
	/// </summary>
	public ref class ProblemForm : public System::Windows::Forms::Form
	{
	public:
		ProblemForm(String^ Problem)
		{
			InitializeComponent();
			//
			//TODO: �������� ��� ������������
			// 
			this->label1->Text = Problem;
		}
	protected:
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
		~ProblemForm()
		{
			if (components)
			{
				delete components;
			}

		}
		/// <summary>
		/// ������������ ���������� ������������.
		/// </summary>
	private: System::Windows::Forms::Label^ label1;

	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// ��������� ����� ��� ��������� ������������ � �� ��������� 
		/// ���������� ����� ������ � ������� ��������� ����.
		/// </summary>
		void InitializeComponent()
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProblemForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(84, 19);
			this->label1->MaximumSize = System::Drawing::Size(200, 120);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 17);
			this->label1->TabIndex = 0;
			this->label1->Text = L"������";
			this->label1->UseCompatibleTextRendering = true;
			// 
			// pictureBox1
			// 
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(12, 19);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(66, 72);
			this->pictureBox1->TabIndex = 1;
			this->pictureBox1->TabStop = false;
			// 
			// ProblemForm
			// 
			this->StartPosition = FormStartPosition::Manual;
			this->Left = (Screen::PrimaryScreen->Bounds.Width - this->Width) / 2;
			this->Top = (Screen::PrimaryScreen->Bounds.Height - this->Height) / 2;
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(284, 111);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->label1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"ProblemForm";
			this->Text = L"ProblemForm";
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
	
#pragma endregion
	};
}
