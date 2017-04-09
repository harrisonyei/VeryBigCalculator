#pragma once

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
	private: System::Windows::Forms::Button^  operatorProduct;
	private: System::Windows::Forms::Button^  operatorDivide;
	private: System::Windows::Forms::Button^  controlDelete;
	private: System::Windows::Forms::Button^  controlClear;
	private: System::Windows::Forms::Button^  operatorPow;
	private: System::Windows::Forms::Button^  operatorImag;









	private: System::Windows::Forms::Button^  operatorFactorial;

	private: System::Windows::Forms::Button^  signPI;
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
			this->operatorProduct = (gcnew System::Windows::Forms::Button());
			this->operatorDivide = (gcnew System::Windows::Forms::Button());
			this->controlDelete = (gcnew System::Windows::Forms::Button());
			this->controlClear = (gcnew System::Windows::Forms::Button());
			this->operatorPow = (gcnew System::Windows::Forms::Button());
			this->operatorImag = (gcnew System::Windows::Forms::Button());
			this->operatorFactorial = (gcnew System::Windows::Forms::Button());
			this->signPI = (gcnew System::Windows::Forms::Button());
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
			// 
			// number2
			// 
			this->number2->Location = System::Drawing::Point(132,363);
			this->number2->Name = L"number2";
			this->number2->Size = System::Drawing::Size(50,40);
			this->number2->TabIndex = 3;
			this->number2->Text = L"2";
			this->number2->UseVisualStyleBackColor = true;
			// 
			// number3
			// 
			this->number3->Location = System::Drawing::Point(188,363);
			this->number3->Name = L"number3";
			this->number3->Size = System::Drawing::Size(50,40);
			this->number3->TabIndex = 4;
			this->number3->Text = L"3";
			this->number3->UseVisualStyleBackColor = true;
			// 
			// number4
			// 
			this->number4->Location = System::Drawing::Point(76,317);
			this->number4->Name = L"number4";
			this->number4->Size = System::Drawing::Size(50,40);
			this->number4->TabIndex = 5;
			this->number4->Text = L"4";
			this->number4->UseVisualStyleBackColor = true;
			// 
			// number5
			// 
			this->number5->Location = System::Drawing::Point(132,317);
			this->number5->Name = L"number5";
			this->number5->Size = System::Drawing::Size(50,40);
			this->number5->TabIndex = 6;
			this->number5->Text = L"5";
			this->number5->UseVisualStyleBackColor = true;
			// 
			// number6
			// 
			this->number6->Location = System::Drawing::Point(188,317);
			this->number6->Name = L"number6";
			this->number6->Size = System::Drawing::Size(50,40);
			this->number6->TabIndex = 7;
			this->number6->Text = L"6";
			this->number6->UseVisualStyleBackColor = true;
			// 
			// number7
			// 
			this->number7->Location = System::Drawing::Point(76,271);
			this->number7->Name = L"number7";
			this->number7->Size = System::Drawing::Size(50,40);
			this->number7->TabIndex = 8;
			this->number7->Text = L"7";
			this->number7->UseVisualStyleBackColor = true;
			// 
			// number8
			// 
			this->number8->Location = System::Drawing::Point(132,271);
			this->number8->Name = L"number8";
			this->number8->Size = System::Drawing::Size(50,40);
			this->number8->TabIndex = 9;
			this->number8->Text = L"8";
			this->number8->UseVisualStyleBackColor = true;
			// 
			// number9
			// 
			this->number9->Location = System::Drawing::Point(188,271);
			this->number9->Name = L"number9";
			this->number9->Size = System::Drawing::Size(50,40);
			this->number9->TabIndex = 10;
			this->number9->Text = L"9";
			this->number9->UseVisualStyleBackColor = true;
			// 
			// number0
			// 
			this->number0->Location = System::Drawing::Point(132,409);
			this->number0->Name = L"number0";
			this->number0->Size = System::Drawing::Size(50,40);
			this->number0->TabIndex = 11;
			this->number0->Text = L"0";
			this->number0->UseVisualStyleBackColor = true;
			// 
			// numberPot
			// 
			this->numberPot->Location = System::Drawing::Point(188,409);
			this->numberPot->Name = L"numberPot";
			this->numberPot->Size = System::Drawing::Size(50,40);
			this->numberPot->TabIndex = 12;
			this->numberPot->Text = L".";
			this->numberPot->UseVisualStyleBackColor = true;
			// 
			// operatorRBricket
			// 
			this->operatorRBricket->Location = System::Drawing::Point(76,409);
			this->operatorRBricket->Name = L"operatorRBricket";
			this->operatorRBricket->Size = System::Drawing::Size(50,40);
			this->operatorRBricket->TabIndex = 13;
			this->operatorRBricket->Text = L")";
			this->operatorRBricket->UseVisualStyleBackColor = true;
			// 
			// operatorLBricket
			// 
			this->operatorLBricket->Location = System::Drawing::Point(20,409);
			this->operatorLBricket->Name = L"operatorLBricket";
			this->operatorLBricket->Size = System::Drawing::Size(50,40);
			this->operatorLBricket->TabIndex = 14;
			this->operatorLBricket->Text = L"(";
			this->operatorLBricket->UseVisualStyleBackColor = true;
			// 
			// operatorResult
			// 
			this->operatorResult->Location = System::Drawing::Point(259,409);
			this->operatorResult->Name = L"operatorResult";
			this->operatorResult->Size = System::Drawing::Size(50,40);
			this->operatorResult->TabIndex = 15;
			this->operatorResult->Text = L"=";
			this->operatorResult->UseVisualStyleBackColor = true;
			// 
			// operatorAdd
			// 
			this->operatorAdd->Location = System::Drawing::Point(259,363);
			this->operatorAdd->Name = L"operatorAdd";
			this->operatorAdd->Size = System::Drawing::Size(50,40);
			this->operatorAdd->TabIndex = 16;
			this->operatorAdd->Text = L"+";
			this->operatorAdd->UseVisualStyleBackColor = true;
			// 
			// operatorSub
			// 
			this->operatorSub->Location = System::Drawing::Point(259,317);
			this->operatorSub->Name = L"operatorSub";
			this->operatorSub->Size = System::Drawing::Size(50,40);
			this->operatorSub->TabIndex = 17;
			this->operatorSub->Text = L"-";
			this->operatorSub->UseVisualStyleBackColor = true;
			// 
			// operatorProduct
			// 
			this->operatorProduct->Location = System::Drawing::Point(259,271);
			this->operatorProduct->Name = L"operatorProduct";
			this->operatorProduct->Size = System::Drawing::Size(50,40);
			this->operatorProduct->TabIndex = 18;
			this->operatorProduct->Text = L"*";
			this->operatorProduct->UseVisualStyleBackColor = true;
			// 
			// operatorDivide
			// 
			this->operatorDivide->Location = System::Drawing::Point(259,225);
			this->operatorDivide->Name = L"operatorDivide";
			this->operatorDivide->Size = System::Drawing::Size(50,40);
			this->operatorDivide->TabIndex = 19;
			this->operatorDivide->Text = L"/";
			this->operatorDivide->UseVisualStyleBackColor = true;
			// 
			// controlDelete
			// 
			this->controlDelete->Location = System::Drawing::Point(188,225);
			this->controlDelete->Name = L"controlDelete";
			this->controlDelete->Size = System::Drawing::Size(50,40);
			this->controlDelete->TabIndex = 20;
			this->controlDelete->Text = L"DEL";
			this->controlDelete->UseVisualStyleBackColor = true;
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
			this->operatorPow->Location = System::Drawing::Point(15,271);
			this->operatorPow->Name = L"operatorPow";
			this->operatorPow->Size = System::Drawing::Size(50,40);
			this->operatorPow->TabIndex = 22;
			this->operatorPow->Text = L"^";
			this->operatorPow->UseVisualStyleBackColor = true;
			// 
			// operatorImag
			// 
			this->operatorImag->Location = System::Drawing::Point(15,225);
			this->operatorImag->Name = L"operatorImag";
			this->operatorImag->Size = System::Drawing::Size(50,40);
			this->operatorImag->TabIndex = 23;
			this->operatorImag->Text = L"i";
			this->operatorImag->UseVisualStyleBackColor = true;
			// 
			// operatorFactorial
			// 
			this->operatorFactorial->Location = System::Drawing::Point(15,317);
			this->operatorFactorial->Name = L"operatorFactorial";
			this->operatorFactorial->Size = System::Drawing::Size(50,40);
			this->operatorFactorial->TabIndex = 24;
			this->operatorFactorial->Text = L"!";
			this->operatorFactorial->UseVisualStyleBackColor = true;
			// 
			// signPI
			// 
			this->signPI->Location = System::Drawing::Point(15,363);
			this->signPI->Name = L"signPI";
			this->signPI->Size = System::Drawing::Size(50,40);
			this->signPI->TabIndex = 25;
			this->signPI->Text = L"PI";
			this->signPI->UseVisualStyleBackColor = true;
			// 
			// CalculatorGUI
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6,13);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->ClientSize = System::Drawing::Size(321,476);
			this->Controls->Add(this->signPI);
			this->Controls->Add(this->operatorFactorial);
			this->Controls->Add(this->operatorImag);
			this->Controls->Add(this->operatorPow);
			this->Controls->Add(this->controlClear);
			this->Controls->Add(this->controlDelete);
			this->Controls->Add(this->operatorDivide);
			this->Controls->Add(this->operatorProduct);
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
			this->Text = L"MyForm";
			this->Load += gcnew System::EventHandler(this,&CalculatorGUI::MyForm_Load);
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
private: 
	System::Void MyForm_Load(System::Object^  sender,System::EventArgs^  e){
	}
};
}
