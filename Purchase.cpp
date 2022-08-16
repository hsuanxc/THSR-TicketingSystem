#include "Purchase.h"

using namespace System;
using namespace System::Windows::Forms;

[STAThread]
int main() {
	Application::EnableVisualStyles();
	Application::SetCompatibleTextRenderingDefault(false);
	Application::Run(gcnew Final::Purchase());
	return 0;
}

//his->pick_date->MinDate = System::DateTime::Today;
//this->pick_date->MaxDate = System::DateTime::Today.AddDays(30);