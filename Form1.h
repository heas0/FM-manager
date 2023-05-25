#pragma once

namespace CppCLRWinFormsProject {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for Form1
	/// </summary>
	public ref class Form1 : public System::Windows::Forms::Form
	{
	public:
		Form1(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~Form1()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::MenuStrip^ menuStrip1;
	private: System::Windows::Forms::ToolStripMenuItem^ menuToolStripMenuItem;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem2;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem3;
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem4;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::ComponentModel::IContainer^ components;
		   /// <summary>
		   /// Required designer variable.
		   /// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		   void InitializeComponent(void)
		   {
			   System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(Form1::typeid));
			   this->menuStrip1 = (gcnew System::Windows::Forms::MenuStrip());
			   this->menuToolStripMenuItem = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripMenuItem2 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripMenuItem3 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStripMenuItem4 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			   this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->menuStrip1->SuspendLayout();
			   this->toolStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->menuToolStripMenuItem });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1024, 24);
			   this->menuStrip1->TabIndex = 0;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // menuToolStripMenuItem
			   // 
			   this->menuToolStripMenuItem->DropDownItems->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(3) {
				   this->toolStripMenuItem2,
					   this->toolStripMenuItem3, this->toolStripMenuItem4
			   });
			   this->menuToolStripMenuItem->Name = L"menuToolStripMenuItem";
			   this->menuToolStripMenuItem->Size = System::Drawing::Size(50, 20);
			   this->menuToolStripMenuItem->Text = L"Menu";
			   // 
			   // toolStripMenuItem2
			   // 
			   this->toolStripMenuItem2->Name = L"toolStripMenuItem2";
			   this->toolStripMenuItem2->Size = System::Drawing::Size(80, 22);
			   this->toolStripMenuItem2->Text = L"1";
			   // 
			   // toolStripMenuItem3
			   // 
			   this->toolStripMenuItem3->Name = L"toolStripMenuItem3";
			   this->toolStripMenuItem3->Size = System::Drawing::Size(80, 22);
			   this->toolStripMenuItem3->Text = L"2";
			   // 
			   // toolStripMenuItem4
			   // 
			   this->toolStripMenuItem4->Name = L"toolStripMenuItem4";
			   this->toolStripMenuItem4->Size = System::Drawing::Size(80, 22);
			   this->toolStripMenuItem4->Text = L"3";
			   // 
			   // toolStrip1
			   // 
			   this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			   this->toolStrip1->Location = System::Drawing::Point(0, 24);
			   this->toolStrip1->Name = L"toolStrip1";
			   this->toolStrip1->Size = System::Drawing::Size(1024, 25);
			   this->toolStrip1->TabIndex = 1;
			   this->toolStrip1->Text = L"toolStrip1";
			   // 
			   // toolStripButton1
			   // 
			   this->toolStripButton1->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton1.Image")));
			   this->toolStripButton1->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton1->Name = L"toolStripButton1";
			   this->toolStripButton1->Size = System::Drawing::Size(23, 22);
			   this->toolStripButton1->Text = L"toolStripButton1";
			   this->toolStripButton1->ToolTipText = L"Добавление нового элемента";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1024, 640);
			   this->Controls->Add(this->toolStrip1);
			   this->Controls->Add(this->menuStrip1);
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"Form1";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->toolStrip1->ResumeLayout(false);
			   this->toolStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion

};
}
