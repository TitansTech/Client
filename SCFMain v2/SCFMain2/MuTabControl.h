#pragma once

using namespace System;
using namespace System::ComponentModel;
using namespace System::Collections;
using namespace System::Windows::Forms;
using namespace System::Data;
using namespace System::Drawing;


namespace SCFMain2 {

	/// <summary>
	/// Summary for SCFMain2
	/// </summary>
	///
	/// WARNING: If you change the name of this class, you will need to change the
	///          'Resource File Name' property for the managed resource compiler tool
	///          associated with all .resx files this class depends on.  Otherwise,
	///          the designers will not be able to interact properly with localized
	///          resources associated with this form.
	public ref class MuTabControl : public System::Windows::Forms::Form
	{
	public:
		MuTabControl(void)
		{
			InitializeComponent();
			//
			//TODO: Add the constructor code here
			//
		}
 void MarryInfo(LPSTR Name, int Num)
		 {
			 char buf[512]={0};
			 wsprintf(buf,"%d Zen",Num);
			 this->marryString->Text = gcnew String(Name);
			 this->divorceCostZen->Text = gcnew String(buf);
		 }

	protected:
		/// <summary>
		/// Clean up any resources being used.
		/// </summary>
		~MuTabControl()
		{
			if (components)
			{
				delete components;
			}
		}

	private: System::Windows::Forms::Label^  label2;
	public: System::Windows::Forms::TabControl^  infoTabber;
	private: 

	private: System::Windows::Forms::TabPage^  marriageTab;




	private: System::Windows::Forms::Button^  marryBtn;
	private: System::Windows::Forms::TextBox^  marryTextBox;

	private: System::Windows::Forms::Button^  traceBtn;
	private: System::Windows::Forms::Button^  forcedivorceBtn;
	private: System::Windows::Forms::Button^  divorceBtn;
	private: System::Windows::Forms::Label^  marryString;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TabPage^  botpetTab;
	private: System::Windows::Forms::TabPage^  miscTab;
	private: System::Windows::Forms::Button^  postBtn;
	private: System::Windows::Forms::TextBox^  postTextBox;
	private: System::Windows::Forms::Label^  traceCostZen;

	private: System::Windows::Forms::Label^  traceCostLabel;
	private: System::Windows::Forms::Label^  divorceCostZen;


	private: System::Windows::Forms::Label^  divorceLabel;
	private: System::Windows::Forms::Label^  fDivorceCostZen;
	private: System::Windows::Forms::Label^  fDivorceCostLabel;
	private: System::Windows::Forms::TabPage^  vipTab;
	private: System::Windows::Forms::TableLayoutPanel^  tableLayoutPanel1;
	private: System::Windows::Forms::Label^  marryLocation;

	private: System::ComponentModel::IContainer^  components;


















	protected: 

	private:
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
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(MuTabControl::typeid));
			this->label2 = (gcnew System::Windows::Forms::Label());
			this->infoTabber = (gcnew System::Windows::Forms::TabControl());
			this->marriageTab = (gcnew System::Windows::Forms::TabPage());
			this->marryLocation = (gcnew System::Windows::Forms::Label());
			this->tableLayoutPanel1 = (gcnew System::Windows::Forms::TableLayoutPanel());
			this->fDivorceCostZen = (gcnew System::Windows::Forms::Label());
			this->fDivorceCostLabel = (gcnew System::Windows::Forms::Label());
			this->traceCostZen = (gcnew System::Windows::Forms::Label());
			this->traceCostLabel = (gcnew System::Windows::Forms::Label());
			this->divorceCostZen = (gcnew System::Windows::Forms::Label());
			this->divorceLabel = (gcnew System::Windows::Forms::Label());
			this->marryBtn = (gcnew System::Windows::Forms::Button());
			this->marryTextBox = (gcnew System::Windows::Forms::TextBox());
			this->traceBtn = (gcnew System::Windows::Forms::Button());
			this->forcedivorceBtn = (gcnew System::Windows::Forms::Button());
			this->divorceBtn = (gcnew System::Windows::Forms::Button());
			this->marryString = (gcnew System::Windows::Forms::Label());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->botpetTab = (gcnew System::Windows::Forms::TabPage());
			this->vipTab = (gcnew System::Windows::Forms::TabPage());
			this->miscTab = (gcnew System::Windows::Forms::TabPage());
			this->postBtn = (gcnew System::Windows::Forms::Button());
			this->postTextBox = (gcnew System::Windows::Forms::TextBox());
			this->infoTabber->SuspendLayout();
			this->marriageTab->SuspendLayout();
			this->miscTab->SuspendLayout();
			this->SuspendLayout();
			// 
			// label2
			// 
			resources->ApplyResources(this->label2, L"label2");
			this->label2->BackColor = System::Drawing::Color::Transparent;
			this->label2->ForeColor = System::Drawing::Color::Yellow;
			this->label2->Name = L"label2";
			// 
			// infoTabber
			// 
			this->infoTabber->Controls->Add(this->marriageTab);
			this->infoTabber->Controls->Add(this->botpetTab);
			this->infoTabber->Controls->Add(this->vipTab);
			this->infoTabber->Controls->Add(this->miscTab);
			resources->ApplyResources(this->infoTabber, L"infoTabber");
			this->infoTabber->Name = L"infoTabber";
			this->infoTabber->SelectedIndex = 0;
			// 
			// marriageTab
			// 
			this->marriageTab->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->marriageTab, L"marriageTab");
			this->marriageTab->Controls->Add(this->marryLocation);
			this->marriageTab->Controls->Add(this->tableLayoutPanel1);
			this->marriageTab->Controls->Add(this->fDivorceCostZen);
			this->marriageTab->Controls->Add(this->fDivorceCostLabel);
			this->marriageTab->Controls->Add(this->traceCostZen);
			this->marriageTab->Controls->Add(this->traceCostLabel);
			this->marriageTab->Controls->Add(this->divorceCostZen);
			this->marriageTab->Controls->Add(this->divorceLabel);
			this->marriageTab->Controls->Add(this->marryBtn);
			this->marriageTab->Controls->Add(this->marryTextBox);
			this->marriageTab->Controls->Add(this->traceBtn);
			this->marriageTab->Controls->Add(this->forcedivorceBtn);
			this->marriageTab->Controls->Add(this->divorceBtn);
			this->marriageTab->Controls->Add(this->marryString);
			this->marriageTab->Controls->Add(this->label1);
			this->marriageTab->ForeColor = System::Drawing::Color::DimGray;
			this->marriageTab->Name = L"marriageTab";
			this->marriageTab->UseVisualStyleBackColor = true;
			// 
			// marryLocation
			// 
			resources->ApplyResources(this->marryLocation, L"marryLocation");
			this->marryLocation->BackColor = System::Drawing::Color::Transparent;
			this->marryLocation->ForeColor = System::Drawing::Color::Silver;
			this->marryLocation->Name = L"marryLocation";
			// 
			// tableLayoutPanel1
			// 
			resources->ApplyResources(this->tableLayoutPanel1, L"tableLayoutPanel1");
			this->tableLayoutPanel1->Name = L"tableLayoutPanel1";
			// 
			// fDivorceCostZen
			// 
			resources->ApplyResources(this->fDivorceCostZen, L"fDivorceCostZen");
			this->fDivorceCostZen->ForeColor = System::Drawing::Color::DarkGray;
			this->fDivorceCostZen->Name = L"fDivorceCostZen";
			// 
			// fDivorceCostLabel
			// 
			resources->ApplyResources(this->fDivorceCostLabel, L"fDivorceCostLabel");
			this->fDivorceCostLabel->BackColor = System::Drawing::Color::Transparent;
			this->fDivorceCostLabel->ForeColor = System::Drawing::Color::Silver;
			this->fDivorceCostLabel->Name = L"fDivorceCostLabel";
			// 
			// traceCostZen
			// 
			resources->ApplyResources(this->traceCostZen, L"traceCostZen");
			this->traceCostZen->ForeColor = System::Drawing::Color::DarkGray;
			this->traceCostZen->Name = L"traceCostZen";
			// 
			// traceCostLabel
			// 
			resources->ApplyResources(this->traceCostLabel, L"traceCostLabel");
			this->traceCostLabel->BackColor = System::Drawing::Color::Transparent;
			this->traceCostLabel->ForeColor = System::Drawing::Color::Silver;
			this->traceCostLabel->Name = L"traceCostLabel";
			// 
			// divorceCostZen
			// 
			resources->ApplyResources(this->divorceCostZen, L"divorceCostZen");
			this->divorceCostZen->ForeColor = System::Drawing::Color::DarkGray;
			this->divorceCostZen->Name = L"divorceCostZen";
			this->divorceCostZen->Click += gcnew System::EventHandler(this, &MuTabControl::divorceCostLabel_Click);
			// 
			// divorceLabel
			// 
			resources->ApplyResources(this->divorceLabel, L"divorceLabel");
			this->divorceLabel->BackColor = System::Drawing::Color::Transparent;
			this->divorceLabel->ForeColor = System::Drawing::Color::Silver;
			this->divorceLabel->Name = L"divorceLabel";
			// 
			// marryBtn
			// 
			resources->ApplyResources(this->marryBtn, L"marryBtn");
			this->marryBtn->Name = L"marryBtn";
			this->marryBtn->UseVisualStyleBackColor = true;
			this->marryBtn->Click += gcnew System::EventHandler(this, &MuTabControl::marryBtn_Click);
			// 
			// marryTextBox
			// 
			resources->ApplyResources(this->marryTextBox, L"marryTextBox");
			this->marryTextBox->Name = L"marryTextBox";
			// 
			// traceBtn
			// 
			resources->ApplyResources(this->traceBtn, L"traceBtn");
			this->traceBtn->Name = L"traceBtn";
			this->traceBtn->UseVisualStyleBackColor = true;
			// 
			// forcedivorceBtn
			// 
			resources->ApplyResources(this->forcedivorceBtn, L"forcedivorceBtn");
			this->forcedivorceBtn->Name = L"forcedivorceBtn";
			this->forcedivorceBtn->UseVisualStyleBackColor = true;
			// 
			// divorceBtn
			// 
			resources->ApplyResources(this->divorceBtn, L"divorceBtn");
			this->divorceBtn->Name = L"divorceBtn";
			this->divorceBtn->UseVisualStyleBackColor = true;
			// 
			// marryString
			// 
			resources->ApplyResources(this->marryString, L"marryString");
			this->marryString->ForeColor = System::Drawing::Color::DarkGray;
			this->marryString->Name = L"marryString";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->BackColor = System::Drawing::Color::Transparent;
			this->label1->ForeColor = System::Drawing::Color::Silver;
			this->label1->Name = L"label1";
			// 
			// botpetTab
			// 
			this->botpetTab->BackColor = System::Drawing::Color::Transparent;
			resources->ApplyResources(this->botpetTab, L"botpetTab");
			this->botpetTab->ForeColor = System::Drawing::Color::DimGray;
			this->botpetTab->Name = L"botpetTab";
			this->botpetTab->UseVisualStyleBackColor = true;
			// 
			// vipTab
			// 
			resources->ApplyResources(this->vipTab, L"vipTab");
			this->vipTab->Name = L"vipTab";
			this->vipTab->UseVisualStyleBackColor = true;
			// 
			// miscTab
			// 
			resources->ApplyResources(this->miscTab, L"miscTab");
			this->miscTab->Controls->Add(this->postBtn);
			this->miscTab->Controls->Add(this->postTextBox);
			this->miscTab->ForeColor = System::Drawing::Color::DimGray;
			this->miscTab->Name = L"miscTab";
			this->miscTab->UseVisualStyleBackColor = true;
			// 
			// postBtn
			// 
			resources->ApplyResources(this->postBtn, L"postBtn");
			this->postBtn->Name = L"postBtn";
			this->postBtn->UseVisualStyleBackColor = true;
			// 
			// postTextBox
			// 
			resources->ApplyResources(this->postTextBox, L"postTextBox");
			this->postTextBox->Name = L"postTextBox";
			// 
			// MuTabControl
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->Controls->Add(this->infoTabber);
			this->Controls->Add(this->label2);
			this->Cursor = System::Windows::Forms::Cursors::Default;
			this->FormBorderStyle = System::Windows::Forms::FormBorderStyle::FixedToolWindow;
			this->MaximizeBox = false;
			this->MinimizeBox = false;
			this->Name = L"MuTabControl";
			this->ShowIcon = false;
			this->ShowInTaskbar = false;
			this->TopMost = true;
			this->infoTabber->ResumeLayout(false);
			this->marriageTab->ResumeLayout(false);
			this->marriageTab->PerformLayout();
			this->miscTab->ResumeLayout(false);
			this->miscTab->PerformLayout();
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void label1_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
	private: System::Void divorceCostLabel_Click(System::Object^  sender, System::EventArgs^  e) {
			 }
private: System::Void dataGridView1_CellContentClick(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
		 }

private: System::Void marryBtn_Click(System::Object^  sender, System::EventArgs^  e) {
		 }
};
}
