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
	private: System::Windows::Forms::ToolStripMenuItem^ toolStripMenuItem1;
	private: System::Windows::Forms::SplitContainer^ splitContainer3;
	private: System::Windows::Forms::DataGridView^ dataGridView2;
	private: System::Windows::Forms::ToolStrip^ toolStrip2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton5;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton2;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton3;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton4;
	private: System::Windows::Forms::ToolStripButton^ toolStripButton6;
	private: System::Windows::Forms::TreeView^ treeView2;
	private: System::Windows::Forms::SplitContainer^ splitContainer2;

	private: System::Windows::Forms::SplitContainer^ splitContainer1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column6;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column7;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column8;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column9;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column10;





	private: System::Windows::Forms::ToolStripButton^ toolStripButton1;
	private: System::Windows::Forms::ToolStrip^ toolStrip1;

	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::TextBox^ textBox2;
	private: System::Windows::Forms::TextBox^ textBox1;
	private: System::Windows::Forms::DataGridView^ dataGridView1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column1;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column2;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column3;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column4;
	private: System::Windows::Forms::DataGridViewTextBoxColumn^ Column5;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::ComponentModel::BackgroundWorker^ backgroundWorker1;
	private: System::Windows::Forms::TreeView^ treeView1;









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
			   this->toolStripMenuItem1 = (gcnew System::Windows::Forms::ToolStripMenuItem());
			   this->splitContainer3 = (gcnew System::Windows::Forms::SplitContainer());
			   this->dataGridView2 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column6 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column7 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column8 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column9 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column10 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label4 = (gcnew System::Windows::Forms::Label());
			   this->textBox2 = (gcnew System::Windows::Forms::TextBox());
			   this->label2 = (gcnew System::Windows::Forms::Label());
			   this->toolStrip2 = (gcnew System::Windows::Forms::ToolStrip());
			   this->toolStripButton5 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripButton2 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripButton3 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripButton4 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStripButton6 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->treeView2 = (gcnew System::Windows::Forms::TreeView());
			   this->splitContainer2 = (gcnew System::Windows::Forms::SplitContainer());
			   this->treeView1 = (gcnew System::Windows::Forms::TreeView());
			   this->dataGridView1 = (gcnew System::Windows::Forms::DataGridView());
			   this->Column1 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column2 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column3 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column4 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->Column5 = (gcnew System::Windows::Forms::DataGridViewTextBoxColumn());
			   this->label3 = (gcnew System::Windows::Forms::Label());
			   this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			   this->label1 = (gcnew System::Windows::Forms::Label());
			   this->splitContainer1 = (gcnew System::Windows::Forms::SplitContainer());
			   this->toolStripButton1 = (gcnew System::Windows::Forms::ToolStripButton());
			   this->toolStrip1 = (gcnew System::Windows::Forms::ToolStrip());
			   this->backgroundWorker1 = (gcnew System::ComponentModel::BackgroundWorker());
			   this->menuStrip1->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->BeginInit();
			   this->splitContainer3->Panel1->SuspendLayout();
			   this->splitContainer3->Panel2->SuspendLayout();
			   this->splitContainer3->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->BeginInit();
			   this->toolStrip2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->BeginInit();
			   this->splitContainer2->Panel1->SuspendLayout();
			   this->splitContainer2->Panel2->SuspendLayout();
			   this->splitContainer2->SuspendLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->BeginInit();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->BeginInit();
			   this->splitContainer1->Panel1->SuspendLayout();
			   this->splitContainer1->Panel2->SuspendLayout();
			   this->splitContainer1->SuspendLayout();
			   this->toolStrip1->SuspendLayout();
			   this->SuspendLayout();
			   // 
			   // menuStrip1
			   // 
			   this->menuStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripMenuItem1 });
			   this->menuStrip1->Location = System::Drawing::Point(0, 0);
			   this->menuStrip1->Name = L"menuStrip1";
			   this->menuStrip1->Size = System::Drawing::Size(1024, 24);
			   this->menuStrip1->TabIndex = 4;
			   this->menuStrip1->Text = L"menuStrip1";
			   // 
			   // toolStripMenuItem1
			   // 
			   this->toolStripMenuItem1->Name = L"toolStripMenuItem1";
			   this->toolStripMenuItem1->Size = System::Drawing::Size(53, 20);
			   this->toolStripMenuItem1->Text = L"Меню";
			   this->toolStripMenuItem1->Click += gcnew System::EventHandler(this, &Form1::toolStripMenuItem1_Click);
			   // 
			   // splitContainer3
			   // 
			   this->splitContainer3->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer3->Location = System::Drawing::Point(0, 0);
			   this->splitContainer3->Name = L"splitContainer3";
			   // 
			   // splitContainer3.Panel1
			   // 
			   this->splitContainer3->Panel1->Controls->Add(this->dataGridView2);
			   this->splitContainer3->Panel1->Controls->Add(this->label4);
			   this->splitContainer3->Panel1->Controls->Add(this->textBox2);
			   this->splitContainer3->Panel1->Controls->Add(this->label2);
			   this->splitContainer3->Panel1->Controls->Add(this->toolStrip2);
			   // 
			   // splitContainer3.Panel2
			   // 
			   this->splitContainer3->Panel2->Controls->Add(this->treeView2);
			   this->splitContainer3->Size = System::Drawing::Size(520, 591);
			   this->splitContainer3->SplitterDistance = 474;
			   this->splitContainer3->TabIndex = 0;
			   // 
			   // dataGridView2
			   // 
			   this->dataGridView2->AllowUserToAddRows = false;
			   this->dataGridView2->AllowUserToDeleteRows = false;
			   this->dataGridView2->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView2->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->Column6,
					   this->Column7, this->Column8, this->Column9, this->Column10
			   });
			   this->dataGridView2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->dataGridView2->Location = System::Drawing::Point(25, 36);
			   this->dataGridView2->Name = L"dataGridView2";
			   this->dataGridView2->ReadOnly = true;
			   this->dataGridView2->Size = System::Drawing::Size(449, 555);
			   this->dataGridView2->TabIndex = 2;
			   // 
			   // Column6
			   // 
			   this->Column6->HeaderText = L"Имя";
			   this->Column6->Name = L"Column6";
			   this->Column6->ReadOnly = true;
			   this->Column6->Width = 200;
			   // 
			   // Column7
			   // 
			   this->Column7->HeaderText = L"Тип";
			   this->Column7->Name = L"Column7";
			   this->Column7->ReadOnly = true;
			   // 
			   // Column8
			   // 
			   this->Column8->HeaderText = L"Размер";
			   this->Column8->Name = L"Column8";
			   this->Column8->ReadOnly = true;
			   // 
			   // Column9
			   // 
			   this->Column9->HeaderText = L"Дата";
			   this->Column9->Name = L"Column9";
			   this->Column9->ReadOnly = true;
			   // 
			   // Column10
			   // 
			   this->Column10->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   this->Column10->HeaderText = L"Атрибуты";
			   this->Column10->Name = L"Column10";
			   this->Column10->ReadOnly = true;
			   // 
			   // label4
			   // 
			   this->label4->AutoSize = true;
			   this->label4->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label4->Location = System::Drawing::Point(25, 23);
			   this->label4->Name = L"label4";
			   this->label4->Size = System::Drawing::Size(31, 13);
			   this->label4->TabIndex = 5;
			   this->label4->Text = L"Путь";
			   // 
			   // textBox2
			   // 
			   this->textBox2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->textBox2->Location = System::Drawing::Point(57, 0);
			   this->textBox2->Name = L"textBox2";
			   this->textBox2->Size = System::Drawing::Size(474, 20);
			   this->textBox2->TabIndex = 4;
			   this->textBox2->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::TextBox2_KeyDown);
			   // 
			   // label2
			   // 
			   this->label2->AutoSize = true;
			   this->label2->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label2->Location = System::Drawing::Point(25, 0);
			   this->label2->Name = L"label2";
			   this->label2->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			   this->label2->Size = System::Drawing::Size(26, 23);
			   this->label2->TabIndex = 3;
			   this->label2->Text = L"c:\\";
			   // 
			   // toolStrip2
			   // 
			   this->toolStrip2->Dock = System::Windows::Forms::DockStyle::Left;
			   this->toolStrip2->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(5) {
				   this->toolStripButton5,
					   this->toolStripButton2, this->toolStripButton3, this->toolStripButton4, this->toolStripButton6
			   });
			   this->toolStrip2->Location = System::Drawing::Point(0, 0);
			   this->toolStrip2->Name = L"toolStrip2";
			   this->toolStrip2->Padding = System::Windows::Forms::Padding(1, 150, 1, 0);
			   this->toolStrip2->Size = System::Drawing::Size(25, 591);
			   this->toolStrip2->TabIndex = 1;
			   this->toolStrip2->Text = L"toolStrip2";
			   // 
			   // toolStripButton5
			   // 
			   this->toolStripButton5->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton5->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton5.Image")));
			   this->toolStripButton5->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton5->Name = L"toolStripButton5";
			   this->toolStripButton5->Size = System::Drawing::Size(20, 20);
			   this->toolStripButton5->Text = L"toolStripButton5";
			   // 
			   // toolStripButton2
			   // 
			   this->toolStripButton2->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton2->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton2.Image")));
			   this->toolStripButton2->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton2->Name = L"toolStripButton2";
			   this->toolStripButton2->Size = System::Drawing::Size(20, 20);
			   this->toolStripButton2->Text = L"toolStripButton2";
			   // 
			   // toolStripButton3
			   // 
			   this->toolStripButton3->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton3->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton3.Image")));
			   this->toolStripButton3->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton3->Name = L"toolStripButton3";
			   this->toolStripButton3->Size = System::Drawing::Size(20, 20);
			   this->toolStripButton3->Text = L"toolStripButton3";
			   // 
			   // toolStripButton4
			   // 
			   this->toolStripButton4->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton4->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton4.Image")));
			   this->toolStripButton4->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton4->Name = L"toolStripButton4";
			   this->toolStripButton4->Size = System::Drawing::Size(20, 20);
			   this->toolStripButton4->Text = L"toolStripButton4";
			   // 
			   // toolStripButton6
			   // 
			   this->toolStripButton6->DisplayStyle = System::Windows::Forms::ToolStripItemDisplayStyle::Image;
			   this->toolStripButton6->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"toolStripButton6.Image")));
			   this->toolStripButton6->ImageTransparentColor = System::Drawing::Color::Magenta;
			   this->toolStripButton6->Name = L"toolStripButton6";
			   this->toolStripButton6->Size = System::Drawing::Size(20, 20);
			   this->toolStripButton6->Text = L"toolStripButton6";
			   // 
			   // treeView2
			   // 
			   this->treeView2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->treeView2->Location = System::Drawing::Point(0, 0);
			   this->treeView2->Name = L"treeView2";
			   this->treeView2->Size = System::Drawing::Size(42, 591);
			   this->treeView2->TabIndex = 0;
			   // 
			   // splitContainer2
			   // 
			   this->splitContainer2->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer2->Location = System::Drawing::Point(0, 0);
			   this->splitContainer2->Name = L"splitContainer2";
			   // 
			   // splitContainer2.Panel1
			   // 
			   this->splitContainer2->Panel1->Controls->Add(this->treeView1);
			   // 
			   // splitContainer2.Panel2
			   // 
			   this->splitContainer2->Panel2->Controls->Add(this->dataGridView1);
			   this->splitContainer2->Panel2->Controls->Add(this->label3);
			   this->splitContainer2->Panel2->Controls->Add(this->textBox1);
			   this->splitContainer2->Panel2->Controls->Add(this->label1);
			   this->splitContainer2->Size = System::Drawing::Size(500, 591);
			   this->splitContainer2->SplitterDistance = 96;
			   this->splitContainer2->TabIndex = 0;
			   // 
			   // treeView1
			   // 
			   this->treeView1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->treeView1->Location = System::Drawing::Point(0, 0);
			   this->treeView1->Name = L"treeView1";
			   this->treeView1->Size = System::Drawing::Size(96, 591);
			   this->treeView1->TabIndex = 0;
			   this->treeView1->AfterCollapse += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterCollapse);
			   this->treeView1->AfterExpand += gcnew System::Windows::Forms::TreeViewEventHandler(this, &Form1::treeView1_AfterExpand);
			   // 
			   // dataGridView1
			   // 
			   this->dataGridView1->AllowUserToAddRows = false;
			   this->dataGridView1->AllowUserToDeleteRows = false;
			   this->dataGridView1->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			   this->dataGridView1->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(5) {
				   this->Column1,
					   this->Column2, this->Column3, this->Column4, this->Column5
			   });
			   this->dataGridView1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->dataGridView1->Location = System::Drawing::Point(0, 36);
			   this->dataGridView1->Margin = System::Windows::Forms::Padding(3, 10, 3, 3);
			   this->dataGridView1->Name = L"dataGridView1";
			   this->dataGridView1->ReadOnly = true;
			   this->dataGridView1->Size = System::Drawing::Size(400, 555);
			   this->dataGridView1->TabIndex = 0;
			   // 
			   // Column1
			   // 
			   this->Column1->HeaderText = L"Имя";
			   this->Column1->Name = L"Column1";
			   this->Column1->ReadOnly = true;
			   this->Column1->Width = 200;
			   // 
			   // Column2
			   // 
			   this->Column2->HeaderText = L"Тип";
			   this->Column2->Name = L"Column2";
			   this->Column2->ReadOnly = true;
			   // 
			   // Column3
			   // 
			   this->Column3->HeaderText = L"Размер";
			   this->Column3->Name = L"Column3";
			   this->Column3->ReadOnly = true;
			   // 
			   // Column4
			   // 
			   this->Column4->HeaderText = L"Дата";
			   this->Column4->Name = L"Column4";
			   this->Column4->ReadOnly = true;
			   // 
			   // Column5
			   // 
			   this->Column5->AutoSizeMode = System::Windows::Forms::DataGridViewAutoSizeColumnMode::Fill;
			   this->Column5->HeaderText = L"Атрибуты";
			   this->Column5->Name = L"Column5";
			   this->Column5->ReadOnly = true;
			   // 
			   // label3
			   // 
			   this->label3->AutoSize = true;
			   this->label3->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label3->Location = System::Drawing::Point(0, 23);
			   this->label3->Name = L"label3";
			   this->label3->Size = System::Drawing::Size(31, 13);
			   this->label3->TabIndex = 7;
			   this->label3->Text = L"Путь";
			   // 
			   // textBox1
			   // 
			   this->textBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>(((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Left)
				   | System::Windows::Forms::AnchorStyles::Right));
			   this->textBox1->Location = System::Drawing::Point(32, 0);
			   this->textBox1->Name = L"textBox1";
			   this->textBox1->Size = System::Drawing::Size(368, 20);
			   this->textBox1->TabIndex = 6;
			   this->textBox1->KeyDown += gcnew System::Windows::Forms::KeyEventHandler(this, &Form1::TextBox1_KeyDown);
			   // 
			   // label1
			   // 
			   this->label1->AutoSize = true;
			   this->label1->Dock = System::Windows::Forms::DockStyle::Top;
			   this->label1->Location = System::Drawing::Point(0, 0);
			   this->label1->Name = L"label1";
			   this->label1->Padding = System::Windows::Forms::Padding(5, 5, 0, 5);
			   this->label1->Size = System::Drawing::Size(26, 23);
			   this->label1->TabIndex = 5;
			   this->label1->Text = L"c:\\";
			   // 
			   // splitContainer1
			   // 
			   this->splitContainer1->Dock = System::Windows::Forms::DockStyle::Fill;
			   this->splitContainer1->Location = System::Drawing::Point(0, 49);
			   this->splitContainer1->Name = L"splitContainer1";
			   // 
			   // splitContainer1.Panel1
			   // 
			   this->splitContainer1->Panel1->Controls->Add(this->splitContainer2);
			   // 
			   // splitContainer1.Panel2
			   // 
			   this->splitContainer1->Panel2->Controls->Add(this->splitContainer3);
			   this->splitContainer1->Size = System::Drawing::Size(1024, 591);
			   this->splitContainer1->SplitterDistance = 500;
			   this->splitContainer1->TabIndex = 2;
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
			   // toolStrip1
			   // 
			   this->toolStrip1->Items->AddRange(gcnew cli::array< System::Windows::Forms::ToolStripItem^  >(1) { this->toolStripButton1 });
			   this->toolStrip1->Location = System::Drawing::Point(0, 24);
			   this->toolStrip1->Name = L"toolStrip1";
			   this->toolStrip1->Size = System::Drawing::Size(1024, 25);
			   this->toolStrip1->TabIndex = 1;
			   this->toolStrip1->Text = L"toolStrip1";
			   // 
			   // Form1
			   // 
			   this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			   this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			   this->ClientSize = System::Drawing::Size(1024, 640);
			   this->Controls->Add(this->splitContainer1);
			   this->Controls->Add(this->toolStrip1);
			   this->Controls->Add(this->menuStrip1);
			   this->Cursor = System::Windows::Forms::Cursors::Arrow;
			   this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			   this->MainMenuStrip = this->menuStrip1;
			   this->Name = L"Form1";
			   this->Text = L"File Manager";
			   this->menuStrip1->ResumeLayout(false);
			   this->menuStrip1->PerformLayout();
			   this->splitContainer3->Panel1->ResumeLayout(false);
			   this->splitContainer3->Panel1->PerformLayout();
			   this->splitContainer3->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer3))->EndInit();
			   this->splitContainer3->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView2))->EndInit();
			   this->toolStrip2->ResumeLayout(false);
			   this->toolStrip2->PerformLayout();
			   this->splitContainer2->Panel1->ResumeLayout(false);
			   this->splitContainer2->Panel2->ResumeLayout(false);
			   this->splitContainer2->Panel2->PerformLayout();
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer2))->EndInit();
			   this->splitContainer2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->dataGridView1))->EndInit();
			   this->splitContainer1->Panel1->ResumeLayout(false);
			   this->splitContainer1->Panel2->ResumeLayout(false);
			   (cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->splitContainer1))->EndInit();
			   this->splitContainer1->ResumeLayout(false);
			   this->toolStrip1->ResumeLayout(false);
			   this->toolStrip1->PerformLayout();
			   this->ResumeLayout(false);
			   this->PerformLayout();

		   }
#pragma endregion
		  private: System::Void TextBox1_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		  private: System::Void TextBox2_KeyDown(System::Object^ sender, System::Windows::Forms::KeyEventArgs^ e);
		  private: System::Void toolStripMenuItem1_Click(System::Object^ sender, System::EventArgs^ e);
		  private: System::Void treeView1_AfterExpand(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
		  private: System::Void treeView1_AfterCollapse(System::Object^ sender, System::Windows::Forms::TreeViewEventArgs^ e);
};
}
