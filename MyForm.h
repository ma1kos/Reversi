#pragma once

namespace Revers {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;
	using namespace System::Drawing::Drawing2D;
	using namespace System::Collections::Generic;

	/// <summary>
	/// Сводка для MyForm
	/// </summary>
	public ref class MyForm : public System::Windows::Forms::Form
	{
	public:
		MyForm(void)
		{
			InitializeComponent();
			//
			//TODO: добавьте код конструктора
			//
		}

	protected:
		/// <summary>
		/// Освободить все используемые ресурсы.
		/// </summary>
		~MyForm()
		{
			if (components)
			{
				delete components;
			}
		}


	public: System::Windows::Forms::PictureBox^ pictureBox1;
	private: System::Windows::Forms::Button^ button1;
	private: System::Windows::Forms::Label^ label1;
	private: System::Windows::Forms::Label^ label2;
	private: System::Windows::Forms::Label^ label3;
	private: System::Windows::Forms::Label^ label4;
	private: System::Windows::Forms::Label^ label5;
	private: System::Windows::Forms::Label^ label6;
	private: System::Windows::Forms::Label^ LCP;
	private: System::Windows::Forms::Label^ LCC;
	private: System::Windows::Forms::Label^ COBP;
	private: System::Windows::Forms::Label^ COBC;
	private: System::Windows::Forms::Panel^ panel1;
	private: System::Windows::Forms::ComboBox^ comboBox1;
	private: System::Windows::Forms::Label^ label7;





	public:

	protected:

	protected:


	private:
		/// <summary>
		/// Обязательная переменная конструктора.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Требуемый метод для поддержки конструктора — не изменяйте 
		/// содержимое этого метода с помощью редактора кода.
		/// </summary>
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^ resources = (gcnew System::ComponentModel::ComponentResourceManager(MyForm::typeid));
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->LCP = (gcnew System::Windows::Forms::Label());
			this->LCC = (gcnew System::Windows::Forms::Label());
			this->COBP = (gcnew System::Windows::Forms::Label());
			this->COBC = (gcnew System::Windows::Forms::Label());
			this->panel1 = (gcnew System::Windows::Forms::Panel());
			this->comboBox1 = (gcnew System::Windows::Forms::ComboBox());
			this->label7 = (gcnew System::Windows::Forms::Label());
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->BeginInit();
			this->panel1->SuspendLayout();
			this->SuspendLayout();
			// 
			// pictureBox1
			// 
			this->pictureBox1->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->pictureBox1->Image = (cli::safe_cast<System::Drawing::Image^>(resources->GetObject(L"pictureBox1.Image")));
			this->pictureBox1->Location = System::Drawing::Point(30, 30);
			this->pictureBox1->Margin = System::Windows::Forms::Padding(0);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(600, 600);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::CenterImage;
			this->pictureBox1->TabIndex = 2;
			this->pictureBox1->TabStop = false;
			this->pictureBox1->MouseUp += gcnew System::Windows::Forms::MouseEventHandler(this, &MyForm::pictureBox1_MouseUp);
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::SystemColors::GradientActiveCaption;
			this->button1->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Center;
			this->button1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->button1->Location = System::Drawing::Point(691, 560);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(530, 56);
			this->button1->TabIndex = 3;
			this->button1->Text = L"Начать";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &MyForm::button1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label1->Location = System::Drawing::Point(105, 14);
			this->label1->Margin = System::Windows::Forms::Padding(105, 0, 105, 0);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(320, 29);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Кол-во оставшихся фишек";
			// 
			// label2
			// 
			this->label2->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->label2->AutoSize = true;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label2->Location = System::Drawing::Point(96, 53);
			this->label2->Margin = System::Windows::Forms::Padding(96, 0, 3, 0);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(88, 29);
			this->label2->TabIndex = 5;
			this->label2->Text = L"Игрок:";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label3->Location = System::Drawing::Point(313, 53);
			this->label3->Margin = System::Windows::Forms::Padding(3, 0, 96, 0);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(153, 29);
			this->label3->TabIndex = 6;
			this->label3->Text = L"Компьютер:";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label4->Location = System::Drawing::Point(207, 147);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(70, 29);
			this->label4->TabIndex = 7;
			this->label4->Text = L"Счёт";
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label5->Location = System::Drawing::Point(96, 201);
			this->label5->Margin = System::Windows::Forms::Padding(96, 0, 3, 0);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(88, 29);
			this->label5->TabIndex = 8;
			this->label5->Text = L"Игрок:";
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 14, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label6->Location = System::Drawing::Point(313, 201);
			this->label6->Margin = System::Windows::Forms::Padding(3, 0, 96, 0);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(153, 29);
			this->label6->TabIndex = 9;
			this->label6->Text = L"Компьютер:";
			// 
			// LCP
			// 
			this->LCP->AutoSize = true;
			this->LCP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LCP->Location = System::Drawing::Point(112, 112);
			this->LCP->Margin = System::Windows::Forms::Padding(140, 30, 3, 0);
			this->LCP->Name = L"LCP";
			this->LCP->Size = System::Drawing::Size(55, 39);
			this->LCP->TabIndex = 10;
			this->LCP->Text = L"30";
			// 
			// LCC
			// 
			this->LCC->AutoSize = true;
			this->LCC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 20, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->LCC->Location = System::Drawing::Point(357, 112);
			this->LCC->Margin = System::Windows::Forms::Padding(140, 30, 3, 0);
			this->LCC->Name = L"LCC";
			this->LCC->Size = System::Drawing::Size(55, 39);
			this->LCC->TabIndex = 11;
			this->LCC->Text = L"30";
			// 
			// COBP
			// 
			this->COBP->AutoSize = true;
			this->COBP->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->COBP->Location = System::Drawing::Point(124, 260);
			this->COBP->Margin = System::Windows::Forms::Padding(3, 30, 3, 0);
			this->COBP->Name = L"COBP";
			this->COBP->Size = System::Drawing::Size(43, 48);
			this->COBP->TabIndex = 12;
			this->COBP->Text = L"2";
			// 
			// COBC
			// 
			this->COBC->AutoSize = true;
			this->COBC->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 25, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->COBC->Location = System::Drawing::Point(369, 260);
			this->COBC->Margin = System::Windows::Forms::Padding(3, 30, 3, 0);
			this->COBC->Name = L"COBC";
			this->COBC->Size = System::Drawing::Size(43, 48);
			this->COBC->TabIndex = 13;
			this->COBC->Text = L"2";
			// 
			// panel1
			// 
			this->panel1->Controls->Add(this->COBC);
			this->panel1->Controls->Add(this->COBP);
			this->panel1->Controls->Add(this->LCC);
			this->panel1->Controls->Add(this->LCP);
			this->panel1->Controls->Add(this->label6);
			this->panel1->Controls->Add(this->label5);
			this->panel1->Controls->Add(this->label4);
			this->panel1->Controls->Add(this->label3);
			this->panel1->Controls->Add(this->label2);
			this->panel1->Controls->Add(this->label1);
			this->panel1->Location = System::Drawing::Point(691, 30);
			this->panel1->Name = L"panel1";
			this->panel1->Size = System::Drawing::Size(530, 326);
			this->panel1->TabIndex = 14;
			// 
			// comboBox1
			// 
			this->comboBox1->DisplayMember = L"1";
			this->comboBox1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 12, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->comboBox1->FormattingEnabled = true;
			this->comboBox1->Items->AddRange(gcnew cli::array< System::Object^  >(4) { L"Ну очень легко", L"Низкая", L"Средняя", L"Высокая" });
			this->comboBox1->Location = System::Drawing::Point(1009, 451);
			this->comboBox1->MaxDropDownItems = 3;
			this->comboBox1->Name = L"comboBox1";
			this->comboBox1->Size = System::Drawing::Size(212, 33);
			this->comboBox1->TabIndex = 15;
			this->comboBox1->Tag = L"";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 15, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(204)));
			this->label7->Location = System::Drawing::Point(854, 455);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(149, 29);
			this->label7->TabIndex = 16;
			this->label7->Text = L"Сложность:";
			// 
			// MyForm
			// 
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::None;
			this->AutoSizeMode = System::Windows::Forms::AutoSizeMode::GrowAndShrink;
			this->ClientSize = System::Drawing::Size(1262, 673);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->comboBox1);
			this->Controls->Add(this->panel1);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->pictureBox1);
			this->Icon = (cli::safe_cast<System::Drawing::Icon^>(resources->GetObject(L"$this.Icon")));
			this->Name = L"MyForm";
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"Реверси";
			this->Load += gcnew System::EventHandler(this, &MyForm::MyForm_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->pictureBox1))->EndInit();
			this->panel1->ResumeLayout(false);
			this->panel1->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private:
		Graphics^ gr;
		SolidBrush^ Green;
		SolidBrush^ Black;
	public: 


	private: System::Void pictureBox1_MouseUp(System::Object^ sender, System::Windows::Forms::MouseEventArgs^ e);
	private: void displayBoard();
		/* {
		int i; int j; int x; int y;
		i = e->X / 75; j = e->Y / 75;
		this->CoordX->Text = i.ToString();
		this->CoordY->Text = j.ToString();
		DrawEl(xy(i), j*75+7);
	}*/
		  // void DrawEl(int xCoord, int yCoord){}
		  // {
			//	SolidBrush^ myBrush = gcnew SolidBrush(Color::Red);
			//	Graphics^ gr;
				//gr = this->pictureBox1->CreateGraphics();
				//gr->FillEllipse(myBrush, xCoord, yCoord, 60, 60);
		  // }

	private: System::Void button1_Click(System::Object^ sender, System::EventArgs^ e);
	private: int getPlayer();
		   int getOppPlayer();
		   void changeCoins(char colour, int row, int col, int deltaRow, int deltaCol);
		   bool checkFlip(char colour, int row, int col, int deltaRow, int deltaCol);
		   bool isValidMove(int row, int col);
		   void flipCoins(char colourF, int rowF, int colF);
		   void makeMove(int row, int col);
		   void turnComp();
		   int minimax(int depth, int plr);
		   int sum();
		   bool isGameOver();
	private: System::Void MyForm_Load(System::Object^ sender, System::EventArgs^ e) {
		comboBox1->SelectedIndex = 0;
	}
};
}