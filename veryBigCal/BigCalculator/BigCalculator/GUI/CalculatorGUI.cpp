#include "CalculatorGUI.h"

int main(array<System::String^> ^args) {
	BigCalculator::Application::EnableVisualStyles();
	BigCalculator::Application::SetCompatibleTextRenderingDefault(false);
	BigCalculator::Application::Run(gcnew BigCalculator::CalculatorGUI());
	return 0;
}

