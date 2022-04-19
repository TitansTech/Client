//#include "SCFMain2.h"

#include "SCFVShop.h"
#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;
using namespace System::IO;
using namespace System::Net;
using namespace System::Text;
namespace SCFMain2 {

	/// <summary>
	/// Resumen de winVip
	///
	/// ADVERTENCIA: si cambia el nombre de esta clase, deberá cambiar la
	///          propiedad 'Nombre de archivos de recursos' de la herramienta de compilación de recursos administrados
	///          asociada con todos los archivos .resx de los que depende esta clase. De lo contrario,
	///          los diseñadores no podrán interactuar correctamente con los
	///          recursos adaptados asociados con este formulario.
	/// </summary>
	public ref class winVip : public System::Windows::Forms::Form
	{
	public:

		winVip(void)
		{
			InitializeComponent();
			//
			//TODO: agregar código de constructor aquí
			//
		}

	protected:
		/// <summary>
		/// Limpiar los recursos que se estén utilizando.
		/// </summary>
		~winVip()
		{
			if (components)
			{
				delete components;
			}
		}





	protected: 


	private: System::Windows::Forms::Label^  label5;
	private: System::Windows::Forms::Label^  label4;
	public: System::Windows::Forms::ComboBox^  comboType;
	private: 
	public: System::Windows::Forms::ComboBox^  comboIndex;






	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::Label^  label3;

	private: System::Windows::Forms::CheckBox^  checkLuck;

	private: System::Windows::Forms::CheckBox^  checkSkill;

	private: System::Windows::Forms::PictureBox^  pictureBox1;
	public: System::Windows::Forms::ComboBox^  comboOpt;
	public: System::Windows::Forms::ComboBox^  comboLevel;
	private: 




	private: System::Windows::Forms::CheckBox^  checkExc1;
	private: System::Windows::Forms::CheckBox^  checkExc6;


	private: System::Windows::Forms::CheckBox^  checkExc2;
	private: System::Windows::Forms::CheckBox^  checkExc5;


	private: System::Windows::Forms::CheckBox^  checkExc3;
	private: System::Windows::Forms::CheckBox^  checkExc4;
	private: System::Windows::Forms::Label^  pLuck;

	private: System::Windows::Forms::Label^  pSkill;

	private: System::Windows::Forms::Label^  pOpt;
	private: System::Windows::Forms::Label^  pLvl;
	private: System::Windows::Forms::Label^  pIndex;
	private: System::Windows::Forms::Label^  pExc;
	private: System::Windows::Forms::Label^  label2;
	private: System::Windows::Forms::Label^  label6;
	private: System::Windows::Forms::Label^  pTotal;
	private: System::Windows::Forms::Label^  label7;
	private: System::Windows::Forms::Label^  credits;
	private: System::Windows::Forms::Button^  ok;
	private: System::Windows::Forms::Timer^  timer1;
	public: System::Windows::Forms::ComboBox^  comboHarmony;
	private: 
	private: System::Windows::Forms::Label^  pHarmony;
	private: System::Windows::Forms::ToolTip^  toolTip1;
	public: 

	private: 
	private: System::ComponentModel::IContainer^  components;






	private:
		/// <summary>
		/// Variable del diseñador requerida.
		/// </summary>


#pragma region Windows Form Designer generated code
		/// <summary>
		/// Método necesario para admitir el Diseñador. No se puede modificar
		/// el contenido del método con el editor de código.
		/// </summary>
		void InitializeComponent(void)
		{
			this->components = (gcnew System::ComponentModel::Container());
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(winVip::typeid));
			this->pExc = (gcnew System::Windows::Forms::Label());
			this->checkExc1 = (gcnew System::Windows::Forms::CheckBox());
			this->checkExc6 = (gcnew System::Windows::Forms::CheckBox());
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->checkExc2 = (gcnew System::Windows::Forms::CheckBox());
			this->pLuck = (gcnew System::Windows::Forms::Label());
			this->checkExc5 = (gcnew System::Windows::Forms::CheckBox());
			this->pSkill = (gcnew System::Windows::Forms::Label());
			this->checkExc3 = (gcnew System::Windows::Forms::CheckBox());
			this->pOpt = (gcnew System::Windows::Forms::Label());
			this->checkExc4 = (gcnew System::Windows::Forms::CheckBox());
			this->pLvl = (gcnew System::Windows::Forms::Label());
			this->pIndex = (gcnew System::Windows::Forms::Label());
			this->comboOpt = (gcnew System::Windows::Forms::ComboBox());
			this->comboLevel = (gcnew System::Windows::Forms::ComboBox());
			this->pictureBox1 = (gcnew System::Windows::Forms::PictureBox());
			this->label5 = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->comboType = (gcnew System::Windows::Forms::ComboBox());
			this->comboIndex = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->checkLuck = (gcnew System::Windows::Forms::CheckBox());
			this->checkSkill = (gcnew System::Windows::Forms::CheckBox());
			this->label6 = (gcnew System::Windows::Forms::Label());
			this->pTotal = (gcnew System::Windows::Forms::Label());
			this->label7 = (gcnew System::Windows::Forms::Label());
			this->credits = (gcnew System::Windows::Forms::Label());
			this->ok = (gcnew System::Windows::Forms::Button());
			this->timer1 = (gcnew System::Windows::Forms::Timer(this->components));
			this->comboHarmony = (gcnew System::Windows::Forms::ComboBox());
			this->pHarmony = (gcnew System::Windows::Forms::Label());
			this->toolTip1 = (gcnew System::Windows::Forms::ToolTip(this->components));
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->BeginInit();
			this->SuspendLayout();
			// 
			// pExc
			// 
			this->pExc->AutoSize = true;
			this->pExc->BackColor = System::Drawing::Color::Transparent;
			this->pExc->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pExc->ForeColor = System::Drawing::Color::LightGray;
			this->pExc->Location = System::Drawing::Point(189, 238);
			this->pExc->Name = L"pExc";
			this->pExc->Size = System::Drawing::Size(14, 15);
			this->pExc->TabIndex = 32;
			this->pExc->Text = L"0";
			// 
			// checkExc1
			// 
			this->checkExc1->AutoSize = true;
			this->checkExc1->BackColor = System::Drawing::Color::Transparent;
			this->checkExc1->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc1->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc1->Location = System::Drawing::Point(15, 261);
			this->checkExc1->Name = L"checkExc1";
			this->checkExc1->Size = System::Drawing::Size(15, 14);
			this->checkExc1->TabIndex = 20;
			this->checkExc1->UseVisualStyleBackColor = false;
			this->checkExc1->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc1_CheckedChanged);
			// 
			// checkExc6
			// 
			this->checkExc6->AutoSize = true;
			this->checkExc6->BackColor = System::Drawing::Color::Transparent;
			this->checkExc6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc6->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc6->Location = System::Drawing::Point(15, 376);
			this->checkExc6->Name = L"checkExc6";
			this->checkExc6->Size = System::Drawing::Size(15, 14);
			this->checkExc6->TabIndex = 25;
			this->checkExc6->UseVisualStyleBackColor = false;
			this->checkExc6->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc6_CheckedChanged);
			// 
			// label2
			// 
			this->label2->AutoSize = true;
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label2->ForeColor = System::Drawing::Color::LightGray;
			this->label2->Location = System::Drawing::Point(13, 238);
			this->label2->Name = L"label2";
			this->label2->Size = System::Drawing::Size(105, 15);
			this->label2->TabIndex = 31;
			this->label2->Text = L"Excellent Options:";
			// 
			// checkExc2
			// 
			this->checkExc2->AutoSize = true;
			this->checkExc2->BackColor = System::Drawing::Color::Transparent;
			this->checkExc2->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc2->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc2->Location = System::Drawing::Point(15, 284);
			this->checkExc2->Name = L"checkExc2";
			this->checkExc2->Size = System::Drawing::Size(15, 14);
			this->checkExc2->TabIndex = 21;
			this->checkExc2->UseVisualStyleBackColor = false;
			this->checkExc2->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc2_CheckedChanged);
			// 
			// pLuck
			// 
			this->pLuck->AutoSize = true;
			this->pLuck->BackColor = System::Drawing::Color::Transparent;
			this->pLuck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pLuck->ForeColor = System::Drawing::Color::LightGray;
			this->pLuck->Location = System::Drawing::Point(189, 191);
			this->pLuck->Name = L"pLuck";
			this->pLuck->Size = System::Drawing::Size(14, 15);
			this->pLuck->TabIndex = 30;
			this->pLuck->Text = L"0";
			// 
			// checkExc5
			// 
			this->checkExc5->AutoSize = true;
			this->checkExc5->BackColor = System::Drawing::Color::Transparent;
			this->checkExc5->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc5->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc5->Location = System::Drawing::Point(15, 353);
			this->checkExc5->Name = L"checkExc5";
			this->checkExc5->Size = System::Drawing::Size(15, 14);
			this->checkExc5->TabIndex = 24;
			this->checkExc5->UseVisualStyleBackColor = false;
			this->checkExc5->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc5_CheckedChanged);
			// 
			// pSkill
			// 
			this->pSkill->AutoSize = true;
			this->pSkill->BackColor = System::Drawing::Color::Transparent;
			this->pSkill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pSkill->ForeColor = System::Drawing::Color::LightGray;
			this->pSkill->Location = System::Drawing::Point(189, 167);
			this->pSkill->Name = L"pSkill";
			this->pSkill->Size = System::Drawing::Size(14, 15);
			this->pSkill->TabIndex = 29;
			this->pSkill->Text = L"0";
			// 
			// checkExc3
			// 
			this->checkExc3->AutoSize = true;
			this->checkExc3->BackColor = System::Drawing::Color::Transparent;
			this->checkExc3->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc3->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc3->Location = System::Drawing::Point(15, 307);
			this->checkExc3->Name = L"checkExc3";
			this->checkExc3->Size = System::Drawing::Size(15, 14);
			this->checkExc3->TabIndex = 22;
			this->checkExc3->UseVisualStyleBackColor = false;
			this->checkExc3->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc3_CheckedChanged);
			// 
			// pOpt
			// 
			this->pOpt->AutoSize = true;
			this->pOpt->BackColor = System::Drawing::Color::Transparent;
			this->pOpt->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pOpt->ForeColor = System::Drawing::Color::LightGray;
			this->pOpt->Location = System::Drawing::Point(189, 144);
			this->pOpt->Name = L"pOpt";
			this->pOpt->Size = System::Drawing::Size(14, 15);
			this->pOpt->TabIndex = 28;
			this->pOpt->Text = L"0";
			// 
			// checkExc4
			// 
			this->checkExc4->AutoSize = true;
			this->checkExc4->BackColor = System::Drawing::Color::Transparent;
			this->checkExc4->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkExc4->ForeColor = System::Drawing::Color::LightGray;
			this->checkExc4->Location = System::Drawing::Point(15, 330);
			this->checkExc4->Name = L"checkExc4";
			this->checkExc4->Size = System::Drawing::Size(15, 14);
			this->checkExc4->TabIndex = 23;
			this->checkExc4->UseVisualStyleBackColor = false;
			this->checkExc4->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkExc4_CheckedChanged);
			// 
			// pLvl
			// 
			this->pLvl->AutoSize = true;
			this->pLvl->BackColor = System::Drawing::Color::Transparent;
			this->pLvl->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pLvl->ForeColor = System::Drawing::Color::LightGray;
			this->pLvl->Location = System::Drawing::Point(189, 117);
			this->pLvl->Name = L"pLvl";
			this->pLvl->Size = System::Drawing::Size(14, 15);
			this->pLvl->TabIndex = 27;
			this->pLvl->Text = L"0";
			// 
			// pIndex
			// 
			this->pIndex->AutoSize = true;
			this->pIndex->BackColor = System::Drawing::Color::Transparent;
			this->pIndex->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pIndex->ForeColor = System::Drawing::Color::LightGray;
			this->pIndex->Location = System::Drawing::Point(189, 89);
			this->pIndex->Name = L"pIndex";
			this->pIndex->Size = System::Drawing::Size(14, 15);
			this->pIndex->TabIndex = 26;
			this->pIndex->Text = L"0";
			// 
			// comboOpt
			// 
			this->comboOpt->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboOpt->FormattingEnabled = true;
			this->comboOpt->Location = System::Drawing::Point(51, 139);
			this->comboOpt->Name = L"comboOpt";
			this->comboOpt->Size = System::Drawing::Size(131, 21);
			this->comboOpt->TabIndex = 19;
			this->comboOpt->SelectedIndexChanged += gcnew System::EventHandler(this, &winVip::comboOpt_SelectedIndexChanged);
			// 
			// comboLevel
			// 
			this->comboLevel->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboLevel->FormattingEnabled = true;
			this->comboLevel->Location = System::Drawing::Point(51, 112);
			this->comboLevel->Name = L"comboLevel";
			this->comboLevel->Size = System::Drawing::Size(131, 21);
			this->comboLevel->TabIndex = 18;
			this->comboLevel->SelectedIndexChanged += gcnew System::EventHandler(this, &winVip::comboLevel_SelectedIndexChanged);
			// 
			// pictureBox1
			// 
			this->pictureBox1->BackColor = System::Drawing::Color::Transparent;
			this->pictureBox1->ErrorImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"pictureBox1.ErrorImage")));
			this->pictureBox1->Location = System::Drawing::Point(252, 58);
			this->pictureBox1->Name = L"pictureBox1";
			this->pictureBox1->Size = System::Drawing::Size(97, 122);
			this->pictureBox1->SizeMode = System::Windows::Forms::PictureBoxSizeMode::StretchImage;
			this->pictureBox1->TabIndex = 17;
			this->pictureBox1->TabStop = false;
			// 
			// label5
			// 
			this->label5->AutoSize = true;
			this->label5->BackColor = System::Drawing::Color::Transparent;
			this->label5->ForeColor = System::Drawing::Color::LightGray;
			this->label5->Location = System::Drawing::Point(12, 88);
			this->label5->Name = L"label5";
			this->label5->Size = System::Drawing::Size(27, 13);
			this->label5->TabIndex = 14;
			this->label5->Text = L"Item";
			// 
			// label4
			// 
			this->label4->AutoSize = true;
			this->label4->BackColor = System::Drawing::Color::Transparent;
			this->label4->ForeColor = System::Drawing::Color::LightGray;
			this->label4->Location = System::Drawing::Point(12, 61);
			this->label4->Name = L"label4";
			this->label4->Size = System::Drawing::Size(31, 13);
			this->label4->TabIndex = 13;
			this->label4->Text = L"Type";
			// 
			// comboType
			// 
			this->comboType->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboType->FormattingEnabled = true;
			this->comboType->Location = System::Drawing::Point(51, 58);
			this->comboType->Name = L"comboType";
			this->comboType->Size = System::Drawing::Size(131, 21);
			this->comboType->TabIndex = 2;
			this->comboType->SelectedIndexChanged += gcnew System::EventHandler(this, &winVip::comboType_SelectedIndexChanged);
			// 
			// comboIndex
			// 
			this->comboIndex->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboIndex->FormattingEnabled = true;
			this->comboIndex->Location = System::Drawing::Point(51, 85);
			this->comboIndex->Name = L"comboIndex";
			this->comboIndex->Size = System::Drawing::Size(131, 21);
			this->comboIndex->TabIndex = 3;
			this->comboIndex->SelectedIndexChanged += gcnew System::EventHandler(this, &winVip::comboItem_SelectedIndexChanged);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::LightGray;
			this->label1->Location = System::Drawing::Point(12, 114);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(33, 13);
			this->label1->TabIndex = 4;
			this->label1->Text = L"Level";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->BackColor = System::Drawing::Color::Transparent;
			this->label3->ForeColor = System::Drawing::Color::LightGray;
			this->label3->Location = System::Drawing::Point(12, 142);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(24, 13);
			this->label3->TabIndex = 10;
			this->label3->Text = L"Opt";
			// 
			// checkLuck
			// 
			this->checkLuck->AutoSize = true;
			this->checkLuck->BackColor = System::Drawing::Color::Transparent;
			this->checkLuck->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkLuck->ForeColor = System::Drawing::Color::LightGray;
			this->checkLuck->Location = System::Drawing::Point(15, 189);
			this->checkLuck->Name = L"checkLuck";
			this->checkLuck->Size = System::Drawing::Size(52, 19);
			this->checkLuck->TabIndex = 9;
			this->checkLuck->Text = L"Luck";
			this->checkLuck->UseVisualStyleBackColor = false;
			this->checkLuck->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkLuck_CheckedChanged);
			// 
			// checkSkill
			// 
			this->checkSkill->AutoSize = true;
			this->checkSkill->BackColor = System::Drawing::Color::Transparent;
			this->checkSkill->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->checkSkill->ForeColor = System::Drawing::Color::LightGray;
			this->checkSkill->Location = System::Drawing::Point(15, 166);
			this->checkSkill->Name = L"checkSkill";
			this->checkSkill->Size = System::Drawing::Size(49, 19);
			this->checkSkill->TabIndex = 8;
			this->checkSkill->Text = L"Skill";
			this->checkSkill->UseVisualStyleBackColor = false;
			this->checkSkill->CheckedChanged += gcnew System::EventHandler(this, &winVip::checkSkill_CheckedChanged);
			// 
			// label6
			// 
			this->label6->AutoSize = true;
			this->label6->BackColor = System::Drawing::Color::Transparent;
			this->label6->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->label6->ForeColor = System::Drawing::Color::White;
			this->label6->Location = System::Drawing::Point(214, 410);
			this->label6->Name = L"label6";
			this->label6->Size = System::Drawing::Size(48, 16);
			this->label6->TabIndex = 33;
			this->label6->Text = L"Total:";
			// 
			// pTotal
			// 
			this->pTotal->AutoSize = true;
			this->pTotal->BackColor = System::Drawing::Color::Transparent;
			this->pTotal->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9.75F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pTotal->ForeColor = System::Drawing::Color::White;
			this->pTotal->Location = System::Drawing::Point(257, 410);
			this->pTotal->Name = L"pTotal";
			this->pTotal->Size = System::Drawing::Size(16, 16);
			this->pTotal->TabIndex = 34;
			this->pTotal->Text = L"0";
			// 
			// label7
			// 
			this->label7->AutoSize = true;
			this->label7->BackColor = System::Drawing::Color::Transparent;
			this->label7->Font = (gcnew System::Drawing::Font(L"Arial", 9.75F, System::Drawing::FontStyle::Bold));
			this->label7->ForeColor = System::Drawing::Color::Yellow;
			this->label7->ImeMode = System::Windows::Forms::ImeMode::NoControl;
			this->label7->Location = System::Drawing::Point(127, 12);
			this->label7->Name = L"label7";
			this->label7->Size = System::Drawing::Size(111, 16);
			this->label7->TabIndex = 35;
			this->label7->Text = L"SCFMT VipShop";
			// 
			// credits
			// 
			this->credits->AutoSize = true;
			this->credits->BackColor = System::Drawing::Color::Transparent;
			this->credits->ForeColor = System::Drawing::Color::Lime;
			this->credits->Location = System::Drawing::Point(31, 33);
			this->credits->Name = L"credits";
			this->credits->Size = System::Drawing::Size(48, 13);
			this->credits->TabIndex = 36;
			this->credits->Text = L"Credits:0";
			// 
			// ok
			// 
			this->ok->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"ok.BackgroundImage")));
			this->ok->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ok->FlatStyle = System::Windows::Forms::FlatStyle::Flat;
			this->ok->Location = System::Drawing::Point(144, 401);
			this->ok->Name = L"ok";
			this->ok->Size = System::Drawing::Size(59, 32);
			this->ok->TabIndex = 37;
			this->ok->UseVisualStyleBackColor = true;
			this->ok->Click += gcnew System::EventHandler(this, &winVip::ok_Click);
			// 
			// timer1
			// 
			this->timer1->Enabled = true;
			this->timer1->Interval = 1000;
			this->timer1->Tick += gcnew System::EventHandler(this, &winVip::timer1_Tick);
			// 
			// comboHarmony
			// 
			this->comboHarmony->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			this->comboHarmony->FormattingEnabled = true;
			this->comboHarmony->Location = System::Drawing::Point(15, 213);
			this->comboHarmony->Name = L"comboHarmony";
			this->comboHarmony->Size = System::Drawing::Size(167, 21);
			this->comboHarmony->TabIndex = 38;
			this->comboHarmony->SelectedIndexChanged += gcnew System::EventHandler(this, &winVip::comboHarmony_SelectedIndexChanged);
			// 
			// pHarmony
			// 
			this->pHarmony->AutoSize = true;
			this->pHarmony->BackColor = System::Drawing::Color::Transparent;
			this->pHarmony->Font = (gcnew System::Drawing::Font(L"Microsoft Sans Serif", 9, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point, 
				static_cast<System::Byte>(0)));
			this->pHarmony->ForeColor = System::Drawing::Color::LightGray;
			this->pHarmony->Location = System::Drawing::Point(189, 215);
			this->pHarmony->Name = L"pHarmony";
			this->pHarmony->Size = System::Drawing::Size(14, 15);
			this->pHarmony->TabIndex = 39;
			this->pHarmony->Text = L"0";
			// 
			// toolTip1
			// 
			this->toolTip1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)), static_cast<System::Int32>(static_cast<System::Byte>(255)), 
				static_cast<System::Int32>(static_cast<System::Byte>(192)));
			this->toolTip1->ToolTipIcon = System::Windows::Forms::ToolTipIcon::Info;
			this->toolTip1->ToolTipTitle = L"Item Info:";
			// 
			// winVip
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackgroundImage = (cli::safe_cast<System::Drawing::Image^  >(resources->GetObject(L"$this.BackgroundImage")));
			this->BackgroundImageLayout = System::Windows::Forms::ImageLayout::Stretch;
			this->ClientSize = System::Drawing::Size(361, 443);
			this->Controls->Add(this->pHarmony);
			this->Controls->Add(this->comboHarmony);
			this->Controls->Add(this->ok);
			this->Controls->Add(this->credits);
			this->Controls->Add(this->label7);
			this->Controls->Add(this->pTotal);
			this->Controls->Add(this->label6);
			this->Controls->Add(this->pExc);
			this->Controls->Add(this->checkExc1);
			this->Controls->Add(this->label4);
			this->Controls->Add(this->checkExc6);
			this->Controls->Add(this->checkSkill);
			this->Controls->Add(this->label2);
			this->Controls->Add(this->checkLuck);
			this->Controls->Add(this->checkExc2);
			this->Controls->Add(this->label3);
			this->Controls->Add(this->pLuck);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->checkExc5);
			this->Controls->Add(this->comboIndex);
			this->Controls->Add(this->pSkill);
			this->Controls->Add(this->comboType);
			this->Controls->Add(this->checkExc3);
			this->Controls->Add(this->label5);
			this->Controls->Add(this->pOpt);
			this->Controls->Add(this->pictureBox1);
			this->Controls->Add(this->checkExc4);
			this->Controls->Add(this->comboLevel);
			this->Controls->Add(this->pLvl);
			this->Controls->Add(this->comboOpt);
			this->Controls->Add(this->pIndex);
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"winVip";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->StartPosition = System::Windows::Forms::FormStartPosition::CenterScreen;
			this->Text = L"SCFVipShop";
			this->TopMost = true;
			this->Load += gcnew System::EventHandler(this, &winVip::winVip_Load);
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^  >(this->pictureBox1))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: int GetTotal()
			 {
				 int Total = Convert::ToInt32(this->pOpt->Text) + Convert::ToInt32(this->pLvl->Text) + Convert::ToInt32(this->pLuck->Text) + Convert::ToInt32(this->pSkill->Text) + Convert::ToInt32(this->pExc->Text) + Convert::ToInt32(this->pIndex->Text);
				 if(this->comboHarmony->SelectedIndex > 0)
					 Total += VShop.pHarmony;
				 char buf[512]={0};
				 wsprintf(buf,"%d",Total);
				 this->pTotal->Text = (gcnew String(buf));	
				 return Total;
			 }
	private: void SetMax()
			 {				 
				 char buf[512]={0};
				 this->comboLevel->Items->Clear();
				 this->comboType->Items->Clear();

				 for(int i=0;i<VShop.TypeCount;i++)
				 {
				 	this->comboType->Items->Add(gcnew String(VShop.item[i].Name));
				 }
				 this->comboType->SelectedIndex = 0;
				 //this->comboIndex->Items->Clear();

				 for(int i=0;i<VShop.MaxLevel+1;i++)
				 {
					wsprintf(buf,"%d",i);
					this->comboLevel->Items->Add(gcnew String(buf));
				 }
				 comboOpt->Items->Clear();
				 for(int i=0;i<VShop.MaxOpt+1;i++)
				 {
					wsprintf(buf,"%d",i*4);
					this->comboOpt->Items->Add(gcnew String(buf));
				 }
				 if(VShop.MaxSkill == 0)
					 this->checkSkill->Enabled = false;
				 
				 if(VShop.MaxLuck == 0)
					 this->checkLuck->Enabled = false;

				 if(VShop.MaxExc == 0)
				 {				 
					checkExc1->Enabled = false;
					checkExc2->Enabled = false;
					checkExc3->Enabled = false;
					checkExc4->Enabled = false;
					checkExc5->Enabled = false;
					checkExc6->Enabled = false;
				 }
				 wsprintf(buf,"Credits:%d",VShop.VipMoney);
				 this->credits->Text = (gcnew String(buf));
			 }
	 private: void SetHarmony()
		{	
			this->comboHarmony->Items->Clear();
			this->comboHarmony->Items->Add("No Harmony");		
			if(VShop.MaxHarmony == 1)
			{
				if(this->comboType->SelectedIndex >= 0 && this->comboType->SelectedIndex <= 4)
				{
					this->comboHarmony->Items->Add("Min Attack Power");
					this->comboHarmony->Items->Add("Max Attack Power");
					this->comboHarmony->Items->Add("Strength Requirement");
					this->comboHarmony->Items->Add("Agility Requirement");
					this->comboHarmony->Items->Add("Attack (Max,Min)");
					this->comboHarmony->Items->Add("Critical Damage");
					this->comboHarmony->Items->Add("Skill Power");
					this->comboHarmony->Items->Add("Attack % Rate");
					this->comboHarmony->Items->Add("SD - Rate");
					this->comboHarmony->Items->Add("SD Ignore Rate");
				}else if(this->comboType->SelectedIndex >= 6 && this->comboType->SelectedIndex <= 11)
				{
					this->comboHarmony->Items->Add("Defense Power");
					this->comboHarmony->Items->Add("Max AG");
					this->comboHarmony->Items->Add("Max HP");
					this->comboHarmony->Items->Add("HP Auto Rate");
					this->comboHarmony->Items->Add("MP Auto Rate");
					this->comboHarmony->Items->Add("Defense Success Rate");
					this->comboHarmony->Items->Add("Damage Reduction Rate");
					this->comboHarmony->Items->Add("SD Rate");
				}else if(this->comboType->SelectedIndex == 5)
				{
					this->comboHarmony->Items->Add("Magic Power");
					this->comboHarmony->Items->Add("Strength Requirement");
					this->comboHarmony->Items->Add("Agility Requirement");
					this->comboHarmony->Items->Add("Skill Power");
					this->comboHarmony->Items->Add("Critical Damage");
					this->comboHarmony->Items->Add("SD - Rate");
					this->comboHarmony->Items->Add("Attack % Rate");
					this->comboHarmony->Items->Add("SD Ignore Rate");
				}
			}
			this->comboHarmony->SelectedIndex = 0;
		}

	private: System::Void winVip_Load(System::Object^  sender, System::EventArgs^  e) {
				this->SetMax();
				this->comboLevel->SelectedIndex = 0;
				this->comboOpt->SelectedIndex = 0;
				this->checkSkill->Checked =false;
				this->checkLuck->Checked =false;
				this->checkExc1->Checked =false;
				this->checkExc2->Checked =false;
				this->checkExc3->Checked =false;
				this->checkExc4->Checked =false;
				this->checkExc5->Checked =false;
				this->checkExc6->Checked =false;
				this->checkExcCount=0;
				SetHarmony();
			 }
	private: void ItemChange()
			 {
				int ItemValue = VShop.item[this->comboType->SelectedIndex].item[this->comboIndex->SelectedIndex].Price;
				char buf[512]={0};
				wsprintf(buf,"%d",ItemValue);
				this->pIndex->Text = (gcnew String(buf));

				char sbuf[2048]={0};
				int Type = this->comboType->SelectedIndex;
				if(Type == 7)
					Type = 8;
				else if(Type >8 && Type < 12)
					Type = 8;
				wsprintf(sbuf,"http://www.mugalaxy.net/items/%d-%d.jpg",Type,VShop.item[this->comboType->SelectedIndex].item[this->comboIndex->SelectedIndex].Index);
				this->pictureBox1->ImageLocation = gcnew String(sbuf);
				this->toolTip1->SetToolTip(this->pictureBox1,gcnew String(VShop.item[this->comboType->SelectedIndex].item[this->comboIndex->SelectedIndex].Equiped));

				if(VShop.item[this->comboType->SelectedIndex].item[this->comboIndex->SelectedIndex].Skill > 0)
				{
					this->checkSkill->Enabled = true;
				}else
				{
					this->checkSkill->Enabled = false;
				}
				
				this->GetTotal();
			 }
	private: System::Void comboItem_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
				ItemChange();
			 }

private: System::Void comboType_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 if(this->comboType->SelectedIndex >= 0)
			 {	
				 SetHarmony();
				 ItemChange();
				 this->checkExc1->Enabled = true;
				 this->checkExc2->Enabled = true;
				 this->checkExc3->Enabled = true;
				 this->checkExc4->Enabled = true;
				 this->checkExc5->Enabled = true;
				 this->checkExc6->Enabled = true;

				 if(VShop.MaxLevel > 0)
					this->comboLevel->Enabled = true;
				 if(VShop.MaxOpt > 0)
					this->comboOpt->Enabled = true;
				 if(VShop.MaxLuck == 1)
					this->checkLuck->Enabled = true;

				 int TypeNum=this->comboType->SelectedIndex;
				 this->comboIndex->Items->Clear();
				 for(int i=0;i<VShop.item[TypeNum].IndexCount;i++)
				 {
				 	 this->comboIndex->Items->Add(gcnew String(VShop.item[TypeNum].item[i].Name));
				 }
				 if(this->comboType->SelectedIndex < 7)
				 {
					 this->checkExc1->Text = ("Increases Mana after monster +mana/8");
					 this->checkExc2->Text = ("Increases Live after monster +live/8");
					 this->checkExc3->Text = ("Increase attacking(wizardry)speed +7");
					 this->checkExc4->Text = ("Increase dmg +2%");
					 this->checkExc5->Text = ("Increase dmg +level/20");
					 this->checkExc6->Text = ("Execllent damage rate +10%");
					 if(VShop.MaxSkill == 1)
						this->checkSkill->Enabled = true;
				 }else
				 {
					this->checkSkill->Enabled = false;
					int ItemIndex = VShop.item[this->comboType->SelectedIndex].item[this->comboIndex->SelectedIndex].Index;
				    if((this->comboType->SelectedIndex >= 7 && this->comboType->SelectedIndex <=11) || (this->comboType->SelectedIndex == 13 && (ItemIndex == 30 || (ItemIndex >=8 && ItemIndex <=13) || (ItemIndex >=20 && ItemIndex <=28))) || (this->comboType->SelectedIndex == 12 && ((ItemIndex >= 0 && ItemIndex <=6) || (ItemIndex >= 36 && ItemIndex <=43) || (ItemIndex >= 200 && ItemIndex <=263))) )
					{						
						this->checkExc1->Text = ("Increases Zen After hunt +40%");
						this->checkExc2->Text = ("Defense success rate +10%");
						this->checkExc3->Text = ("Reflect damage +5%");
						this->checkExc4->Text = ("Damage decrease +4%");
						this->checkExc5->Text = ("Increase Mana 4%");
						this->checkExc6->Text = ("Increase HP +4%");
					}else
					{
						this->checkExc1->Enabled = false;
						this->checkExc2->Enabled = false;
						this->checkExc3->Enabled = false;
						this->checkExc4->Enabled = false;
						this->checkExc5->Enabled = false;
						this->checkExc6->Enabled = false;
						this->comboLevel->Enabled = false;
						this->comboOpt->Enabled = false;
						this->checkLuck->Enabled = false;
					}
				 }
			 }		
		 }
		 private: int checkExcCount;

		 private: void ExcCheck(bool Value)
		 {
			 if(Value==true)
			 {
				 checkExcCount++;
				 
				if(checkExcCount >= VShop.MaxExc)
				{
					if(checkExc1->Checked == false)
						checkExc1->Enabled = false;
					if(checkExc2->Checked == false)
						checkExc2->Enabled = false;
					if(checkExc3->Checked == false)
						checkExc3->Enabled = false;
					if(checkExc4->Checked == false)
						checkExc4->Enabled = false;
					if(checkExc5->Checked == false)
						checkExc5->Enabled = false;
					if(checkExc6->Checked == false)
						checkExc6->Enabled = false;
				}
			 }else
			 {
				 checkExcCount--;
				 
				if(checkExcCount < VShop.MaxExc)
				{
					if(checkExc1->Enabled == false)
						checkExc1->Enabled = true;
					if(checkExc2->Enabled == false)
						checkExc2->Enabled = true;
					if(checkExc3->Enabled == false)
						checkExc3->Enabled = true;
					if(checkExc4->Enabled == false)
						checkExc4->Enabled = true;
					if(checkExc5->Enabled == false)
						checkExc5->Enabled = true;
					if(checkExc6->Enabled == false)
						checkExc6->Enabled = true;
				}
			 }
			 char buf[512]={0};
			 wsprintf(buf,"%d",VShop.pExc*checkExcCount);
			 this->pExc->Text = (gcnew String(buf));
			 this->GetTotal();
		 }

private: System::Void checkExc1_CheckedChanged(System::Object^  sender, System::EventArgs^  e) 
		 {
			 this->ExcCheck(checkExc1->Checked);
		 }
private: System::Void checkExc2_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->ExcCheck(checkExc2->Checked);
		 }
private: System::Void checkExc3_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->ExcCheck(checkExc3->Checked);
		 }
private: System::Void checkExc4_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->ExcCheck(checkExc4->Checked);
		 }
private: System::Void checkExc5_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->ExcCheck(checkExc5->Checked);
		 }
private: System::Void checkExc6_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 this->ExcCheck(checkExc6->Checked);
		 }
private: System::Void comboLevel_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 char buf[512]={0};
			 wsprintf(buf,"%d",VShop.pLevel*Convert::ToInt32(this->comboLevel->Text));
			 this->pLvl->Text = (gcnew String(buf));
			 this->GetTotal();
		 }
private: System::Void comboOpt_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 char buf[512]={0};
			 wsprintf(buf,"%d",(VShop.pOpt/4)*Convert::ToInt32(this->comboOpt->Text));
			 this->pOpt->Text = (gcnew String(buf));
			 this->GetTotal();
		 }
private: System::Void checkSkill_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 char buf[512]={0};
			 if(checkSkill->Checked == true)
			 {
				wsprintf(buf,"%d",VShop.pSkill);
				this->pSkill->Text = (gcnew String(buf));
			 }else
			 {
				 this->pSkill->Text = "0";
			 }
			 this->GetTotal();
		 }
private: System::Void checkLuck_CheckedChanged(System::Object^  sender, System::EventArgs^  e) {
			 char buf[512]={0};
			 if(checkLuck->Checked == true)
			 {
				wsprintf(buf,"%d",VShop.pLuck);
				this->pLuck->Text = (gcnew String(buf));
			 }else
			 {
				 this->pLuck->Text = "0";
			 }
			 this->GetTotal();
		 }
private: int GetExcNum()
		 {
			 int tmp=0; 
			 if (checkExc1->Checked == true)
				 tmp = tmp + Math::Pow(2, 0);
			 if (checkExc2->Checked == true)
				 tmp = tmp + Math::Pow(2, 1);
			 if (checkExc3->Checked == true)
				 tmp = tmp + Math::Pow(2, 2);
			 if (checkExc4->Checked == true)
				 tmp = tmp + Math::Pow(2, 3);
			 if (checkExc5->Checked == true)
				 tmp = tmp + Math::Pow(2, 4);
			 if (checkExc6->Checked == true)
				 tmp = tmp + Math::Pow(2, 5);
			 return tmp;
		 }

private: System::Void ok_Click(System::Object^  sender, System::EventArgs^  e) {
			 if(this->GetTotal() > VShop.VipMoney)
			 {
				 return;
			 }
			 if(this->comboIndex->SelectedIndex < 0)
				 return;
			 int iLuck = 0;
			 int iSkill = 0;
			 if(this->checkLuck->Checked == true)
				 iLuck = 1;
			 if(this->checkSkill->Checked == true)
				 iSkill = 1;
			 int iType = this->comboType->SelectedIndex;
			 int iIndex = VShop.item[iType].item[this->comboIndex->SelectedIndex].Index;
			 VShop.Send(iType,iIndex,Convert::ToInt32(this->comboLevel->Text),Convert::ToInt32(this->comboOpt->Text),iLuck,iSkill,GetExcNum(),Convert::ToInt32(this->comboHarmony->SelectedIndex));
			 
			 this->Close();
		 }
private: System::Void timer1_Tick(System::Object^  sender, System::EventArgs^  e) {
			timer1->Enabled = true;
			if(VShop.NeedClose == true)
			{
				VShop.NeedClose = false;
				
				this->Close();
			}
		 }
private: System::Void comboHarmony_SelectedIndexChanged(System::Object^  sender, System::EventArgs^  e) {
			 if(this->comboHarmony->SelectedIndex > 0)
			 {
				char buf[512]={0};
				wsprintf(buf,"%d",VShop.pHarmony);
				this->pHarmony->Text = (gcnew String(buf));
			 }else
			    this->pHarmony->Text =(gcnew String("0"));

			 this->GetTotal();
		 }
};
}
