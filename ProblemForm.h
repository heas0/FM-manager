#pragma once

namespace CppCLR_WinFormsProject1 {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// —водка дл€ ProblemForm
	/// </summary>
	public ref class ProblemForm : public System::Windows::Forms::Form
	{
	public:
		ProblemForm(String^ Problem)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			// 
			this->label1->Text = Problem;
		}
	protected:
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
		~ProblemForm()
		{
			if (components)
			{
				delete components;
			}

		}
		/// <summary>
		/// ќб€зательна€ переменна€ конструктора.
		/// </summary>
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::ImageList^ imageList1;
	private: System::Windows::Forms::PictureBox^ pictureBox1;

	private: System::ComponentModel::IContainer^ components;



#pragma region Windows Form Designer generated code
		/// <summary>
		/// “ребуемый метод дл€ поддержки конструктора Ч не измен€йте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent()
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(ProblemForm::typeid));
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->imageList1 = (gcnew System::Windows::Forms::ImageList(this->components));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->ImageAlign = System::Drawing::ContentAlignment::TopLeft;
			this->label1->Location = System::Drawing::Point(84, 49);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(47, 13);
			this->label1->TabIndex = 0;
			this->label1->Text = L"ќшибка";
			// 
			// imageList1
			// 
			this->imageList1->ColorDepth = System::Windows::Forms::ColorDepth::Depth8Bit;
			this->imageList1->ImageSize = System::Drawing::Size(16, 16);
			this->imageList1->TransparentColor = System::Drawing::Color::Transparent;
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
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(301, 103);
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
