#pragma once
#include "../Operation/TestCore.h"

namespace BigCalculator {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	/// <summary>
	/// Summary for CalculatorGUI
	/// </summary>
	public ref class CalculatorGUI : public System::Windows::Forms::Form
	{
	public:
		CalculatorGUI(void)
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
		~CalculatorGUI()
		{
			if (components)
			{
				delete components;
			}
		}

	private:

	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::TextBox^  textBox1;
	private: System::Windows::Forms::Button^  number1;
	private: System::Windows::Forms::Button^  number2;
	private: System::Windows::Forms::Button^  number3;
	private: System::Windows::Forms::Button^  number4;
	private: System::Windows::Forms::Button^  number5;




	private: System::Windows::Forms::Button^  number6;

	private: System::Windows::Forms::Button^  number7;

	private: System::Windows::Forms::Button^  number8;

	private: System::Windows::Forms::Button^  number9;
	private: System::Windows::Forms::Button^  number0;
	private: System::Windows::Forms::Button^  numberPot;
	private: System::Windows::Forms::Button^  operatorRBricket;
	private: System::Windows::Forms::Button^  operatorLBricket;






	private: System::Windows::Forms::Button^  operatorResult;
	private: System::Windows::Forms::Button^  operatorAdd;
	private: System::Windows::Forms::Button^  operatorSub;
	private: System::Windows::Forms::Button^  operatorMult;

	private: System::Windows::Forms::Button^  operatorDivide;
	private: System::Windows::Forms::Button^  controlDelete;
	private: System::Windows::Forms::Button^  controlClear;
	private: System::Windows::Forms::Button^  operatorPow;
	private: System::Windows::Forms::Button^  operatorImag;









	private: System::Windows::Forms::Button^  operatorFactorial;


		/// <summary>
		/// Required designer variable.
		/// </summary>
		System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		/// <summary>
		/// Required method for Designer support - do not modify
		/// the contents of this method with the code editor.
		/// </summary>
		void InitializeComponent(void){
			this->number1 = (gcnew System::Windows::Forms::Button());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->textBox1 = (gcnew System::Windows::Forms::TextBox());
			this->number2 = (gcnew System::Windows::Forms::Button());
			this->number3 = (gcnew System::Windows::Forms::Button());
			this->number4 = (gcnew System::Windows::Forms::Button());
			this->number5 = (gcnew System::Windows::Forms::Button());
			this->number6 = (gcnew System::Windows::Forms::Button());
			this->number7 = (gcnew System::Windows::Forms::Button());
			this->number8 = (gcnew System::Windows::Forms::Button());
			this->number9 = (gcnew System::Windows::Forms::Button());
			this->number0 = (gcnew System::Windows::Forms::Button());
			this->numberPot = (gcnew System::Windows::Forms::Button());
			this->operatorRBricket = (gcnew System::Windows::Forms::Button());
			this->operatorLBricket = (gcnew System::Windows::Forms::Button());
			this->operatorResult = (gcnew System::Windows::Forms::Button());
			this->operatorAdd = (gcnew System::Windows::Forms::Button());
			this->operatorSub = (gcnew System::Windows::Forms::Button());
			this->operatorMult = (gcnew System::Windows::Forms::Button());
			this->operatorDivide = (gcnew System::Windows::Forms::Button());
			this->controlDelete = (gcnew System::Windows::Forms::Button());
			this->controlClear = (gcnew System::Windows::Forms::Button());
			this->operatorPow = (gcnew System::Windows::Forms::Button());
			this->operatorImag = (gcnew System::Windows::Forms::Button());
			this->operatorFactorial = (gcnew System::Windows::Forms::Button());
			this->SuspendLayout();
			// 
			// number1
			// 
			this->number1->Location = System::Drawing::Point(76,363);
			this->number1->Name = L"number1";
			this->number1->Size = System::Drawing::Size(50,40);
			this->number1->TabIndex = 0;
			this->number1->Text = L"1";
			this->number1->UseVisualStyleBackColor = true;
			this->number1->Click += gcnew System::EventHandler(this,&CalculatorGUI::number1_Click);
			// 
			// label1
			// 
			this->label1->AutoSize = true;
			this->label1->Location = System::Drawing::Point(12,9);
			this->label1->Name = L"label1";
			this->label1->Size = System::Drawing::Size(35,13);
			this->label1->TabIndex = 1;
			this->label1->Text = L"label1";
			// 
			// textBox1
			// 
			this->textBox1->Location = System::Drawing::Point(12,25);
			this->textBox1->Multiline = true;
			this->textBox1->Name = L"textBox1";
			this->textBox1->Size = System::Drawing::Size(297,181);
			this->textBox1->TabIndex = 2;
			this->textBox1->TextAlign = System::Windows::Forms::HorizontalAlignment::Right;
			// 
			// number2
			// 
			this->number2->Location = System::Drawing::Point(132,363);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(50,40);
			this->number2->TabIndex = 3;
			this->number2->Text = L"2";
			this->number2->UseVisualStyleBackColor = true;
			this->number2->Click += gcnew System::EventHandler(this,&CalculatorGUI::number2_Click);
			// 
			// number3
			// 
			this->number3->Location = System::Drawing::Point(188,363);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(50,40);
			this->number3->TabIndex = 4;
			this->number3->Text = L"3";
			this->number3->UseVisualStyleBackColor = true;
			this->number3->Click += gcnew System::EventHandler(this,&CalculatorGUI::number3_Click);
			// 
			// number4
			// 
			this->number4->Location = System::Drawing::Point(76,317);
			this->number4->Name = L"number4";
			this->number4->Size = System::Drawing::Size(50,40);
			this->number4->TabIndex = 5;
			this->number4->Text = L"4";
			this->number4->UseVisualStyleBackColor = true;
			this->number4->Click += gcnew System::EventHandler(this,&CalculatorGUI::number4_Click);
			// 
			// number5
			// 
			this->number5->Location = System::Drawing::Point(132,317);
			this->number5->Name = L"number5";
			this->number5->Size = System::Drawing::Size(50,40);
			this->number5->TabIndex = 6;
			this->number5->Text = L"5";
			this->number5->UseVisualStyleBackColor = true;
			this->number5->Click += gcnew System::EventHandler(this,&CalculatorGUI::number5_Click);
			// 
			// number6
			// 
			this->number6->Location = System::Drawing::Point(188,317);
			this->number6->Name = L"number6";
			this->number6->Size = System::Drawing::Size(50,40);
			this->number6->TabIndex = 7;
			this->number6->Text = L"6";
			this->number6->UseVisualStyleBackColor = true;
			this->number6->Click += gcnew System::EventHandler(this,&CalculatorGUI::number6_Click);
			// 
			// number7
			// 
			this->number7->Location = System::Drawing::Point(76,271);
			this->number7->Name = L"number7";
			this->number7->Size = System::Drawing::Size(50,40);
			this->number7->TabIndex = 8;
			this->number7->Text = L"7";
			this->number7->UseVisualStyleBackColor = true;
			this->number7->Click += gcnew System::EventHandler(this,&CalculatorGUI::number7_Click);
			// 
			// number8
			// 
			this->number8->Location = System::Drawing::Point(132,271);
			this->number8->Name = L"number8";
			this->number8->Size = System::Drawing::Size(50,40);
			this->number8->TabIndex = 9;
			this->number8->Text = L"8";
			this->number8->UseVisualStyleBackColor = true;
			this->number8->Click += gcnew System::EventHandler(this,&CalculatorGUI::number8_Click);
			// 
			// number9
			// 
			this->number9->Location = System::Drawing::Point(188,271);
			this->number9->Name = L"number9";
			this->number9->Size = System::Drawing::Size(50,40);
			this->number9->TabIndex = 10;
			this->number9->Text = L"9";
			this->number9->UseVisualStyleBackColor = true;
			this->number9->Click += gcnew System::EventHandler(this,&CalculatorGUI::number9_Click);
			// 
			// number0
			// 
			this->number0->Location = System::Drawing::Point(132,409);
			this->number0->Name = L"number0";
			this->number0->Size = System::Drawing::Size(50,40);
			this->number0->TabIndex = 11;
			this->number0->Text = L"0";
			this->number0->UseVisualStyleBackColor = true;
			this->number0->Click += gcnew System::EventHandler(this,&CalculatorGUI::number0_Click);
			// 
			// numberPot
			// 
			this->numberPot->Location = System::Drawing::Point(76,408);
			this->numberPot->Name = L"numberPot";
			this->numberPot->Size = System::Drawing::Size(50,40);
			this->numberPot->TabIndex = 12;
			this->numberPot->Text = L".";
			this->numberPot->UseVisualStyleBackColor = true;
			this->numberPot->Click += gcnew System::EventHandler(this,&CalculatorGUI::numberPot_Click);
			// 
			// operatorRBricket
			// 
			this->operatorRBricket->Location = System::Drawing::Point(76,225);
			this->operatorRBricket->Name = L"operatorRBricket";
			this->operatorRBricket->Size = System::Drawing::Size(50,40);
			this->operatorRBricket->TabIndex = 13;
			this->operatorRBricket->Text = L")";
			this->operatorRBricket->UseVisualStyleBackColor = true;
			this->operatorRBricket->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorRBricket_Click);
			// 
			// operatorLBricket
			// 
			this->operatorLBricket->Location = System::Drawing::Point(15,225);
			this->operatorLBricket->Name = L"operatorLBricket";
			this->operatorLBricket->Size = System::Drawing::Size(50,40);
			this->operatorLBricket->TabIndex = 14;
			this->operatorLBricket->Text = L"(";
			this->operatorLBricket->UseVisualStyleBackColor = true;
			this->operatorLBricket->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorLBricket_Click);
			// 
			// operatorResult
			// 
			this->operatorResult->Location = System::Drawing::Point(188,409);
			this->operatorResult->Name = L"operatorResult";
			this->operatorResult->Size = System::Drawing::Size(121,40);
			this->operatorResult->TabIndex = 15;
			this->operatorResult->Text = L"=";
			this->operatorResult->UseVisualStyleBackColor = true;
			this->operatorResult->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorResult_Click);
			// 
			// operatorAdd
			// 
			this->operatorAdd->Location = System::Drawing::Point(259,363);
			this->operatorAdd->Name = L"operatorAdd";
			this->operatorAdd->Size = System::Drawing::Size(50,40);
			this->operatorAdd->TabIndex = 16;
			this->operatorAdd->Text = L"+";
			this->operatorAdd->UseVisualStyleBackColor = true;
			this->operatorAdd->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorAdd_Click);
			// 
			// operatorSub
			// 
			this->operatorSub->Location = System::Drawing::Point(259,317);
			this->operatorSub->Name = L"operatorSub";
			this->operatorSub->Size = System::Drawing::Size(50,40);
			this->operatorSub->TabIndex = 17;
			this->operatorSub->Text = L"-";
			this->operatorSub->UseVisualStyleBackColor = true;
			this->operatorSub->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorSub_Click);
			// 
			// operatorMult
			// 
			this->operatorMult->Location = System::Drawing::Point(259,271);
			this->operatorMult->Name = L"operatorMult";
			this->operatorMult->Size = System::Drawing::Size(50,40);
			this->operatorMult->TabIndex = 18;
			this->operatorMult->Text = L"*";
			this->operatorMult->UseVisualStyleBackColor = true;
			this->operatorMult->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorMult_Click);
			// 
			// operatorDivide
			// 
			this->operatorDivide->Location = System::Drawing::Point(259,225);
			this->operatorDivide->Name = L"operatorDivide";
			this->operatorDivide->Size = System::Drawing::Size(50,40);
			this->operatorDivide->TabIndex = 19;
			this->operatorDivide->Text = L"/";
			this->operatorDivide->UseVisualStyleBackColor = true;
			this->operatorDivide->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorDivide_Click);
			// 
			// controlDelete
			// 
			this->controlDelete->Location = System::Drawing::Point(188,225);
			this->controlDelete->Name = L"controlDelete";
			this->controlDelete->Size = System::Drawing::Size(50,40);
			this->controlDelete->TabIndex = 20;
			this->controlDelete->Text = L"DEL";
			this->controlDelete->UseVisualStyleBackColor = true;
			this->controlDelete->Click += gcnew System::EventHandler(this,&CalculatorGUI::controlDelete_Click);
			// 
			// controlClear
			// 
			this->controlClear->Location = System::Drawing::Point(132,225);
			this->controlClear->Name = L"controlClear";
			this->controlClear->Size = System::Drawing::Size(50,40);
			this->controlClear->TabIndex = 21;
			this->controlClear->Text = L"CLR";
			this->controlClear->UseVisualStyleBackColor = true;
			this->controlClear->Click += gcnew System::EventHandler(this,&CalculatorGUI::controlClear_Click);
			// 
			// operatorPow
			// 
			this->operatorPow->Location = System::Drawing::Point(15,317);
			this->operatorPow->Name = L"operatorPow";
			this->operatorPow->Size = System::Drawing::Size(50,40);
			this->operatorPow->TabIndex = 22;
			this->operatorPow->Text = L"^";
			this->operatorPow->UseVisualStyleBackColor = true;
			this->operatorPow->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorPow_Click);
			// 
			// operatorImag
			// 
			this->operatorImag->Location = System::Drawing::Point(15,271);
			this->operatorImag->Name = L"operatorImag";
			this->operatorImag->Size = System::Drawing::Size(50,40);
			this->operatorImag->TabIndex = 23;
			this->operatorImag->Text = L"i";
			this->operatorImag->UseVisualStyleBackColor = true;
			this->operatorImag->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorImag_Click);
			// 
			// operatorFactorial
			// 
			this->operatorFactorial->Location = System::Drawing::Point(15,363);
			this->operatorFactorial->Name = L"operatorFactorial";
			this->operatorFactorial->Size = System::Drawing::Size(50,40);
			this->operatorFactorial->TabIndex = 24;
			this->operatorFactorial->Text = L"!";
			this->operatorFactorial->UseVisualStyleBackColor = true;
			this->operatorFactorial->Click += gcnew System::EventHandler(this,&CalculatorGUI::operatorFactorial_Click);
			// 
			// CalculatorGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6,13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321,476);
			this->Controls->Add(this->operatorFactorial);
			this->Controls->Add(this->operatorImag);
			this->Controls->Add(this->operatorPow);
			this->Controls->Add(this->controlClear);
			this->Controls->Add(this->controlDelete);
			this->Controls->Add(this->operatorDivide);
			this->Controls->Add(this->operatorMult);
			this->Controls->Add(this->operatorSub);
			this->Controls->Add(this->operatorAdd);
			this->Controls->Add(this->operatorResult);
			this->Controls->Add(this->operatorLBricket);
			this->Controls->Add(this->operatorRBricket);
			this->Controls->Add(this->numberPot);
			this->Controls->Add(this->number0);
			this->Controls->Add(this->number9);
			this->Controls->Add(this->number8);
			this->Controls->Add(this->number7);
			this->Controls->Add(this->number6);
			this->Controls->Add(this->number5);
			this->Controls->Add(this->number4);
			this->Controls->Add(this->number3);
			this->Controls->Add(this->number2);
			this->Controls->Add(this->textBox1);
			this->Controls->Add(this->label1);
			this->Controls->Add(this->number1);
			this->Name = L"CalculatorGUI";
			this->Text = L"BigCalculator";
			this->Load += gcnew System::EventHandler(this,&CalculatorGUI::CalculatorGUI_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: System::Void CalculatorGUI_Load(System::Object^  sender, System::EventArgs^  e) {
}

private: System::Void number0_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number0->Text;
}
private: System::Void number1_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number1->Text;
}
private: System::Void number2_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number2->Text;
}
private: System::Void number3_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number3->Text;
}
private: System::Void number4_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number4->Text;
}
private: System::Void number5_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number5->Text;
}
private: System::Void number6_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number6->Text;
}
private: System::Void number7_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number7->Text;
}
private: System::Void number8_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number8->Text;
}
private: System::Void number9_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->number9->Text;
}
private: System::Void numberPot_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->numberPot->Text;
}

private: System::Void operatorAdd_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorAdd->Text;
}
private: System::Void operatorSub_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorSub->Text;
}
private: System::Void operatorMult_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorMult->Text;
}
private: System::Void operatorDivide_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorDivide->Text;
}
private: System::Void operatorLBricket_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorLBricket->Text;
}
private: System::Void operatorRBricket_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorRBricket->Text;
}
private: System::Void operatorFactorial_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorFactorial->Text;
}
private: System::Void operatorPow_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorPow->Text;
}
private: System::Void operatorImag_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text += this->operatorImag->Text;
}

private: System::Void controlDelete_Click(System::Object^  sender, System::EventArgs^  e) {
	if (this->textBox1->Text->Length > 0) {
		this->textBox1->Text = this->textBox1->Text->Remove(this->textBox1->Text->Length - 1);
	}
}
private: System::Void controlClear_Click(System::Object^  sender, System::EventArgs^  e) {
	this->textBox1->Text = "";

}
private: System::Void operatorResult_Click(System::Object^  sender,System::EventArgs^  e){
	const char* chars = (const char*)(System::Runtime::InteropServices::Marshal::StringToHGlobalAnsi(this->textBox1->Text)).ToPointer();
	String^ str = gcnew String(TestCore::CalQ(chars).c_str());
	this->textBox1->Text = str;
	delete str;
}
};
}
