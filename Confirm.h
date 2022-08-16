#pragma once
#include <string>

namespace Final {
	using namespace std;
	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Confirm : public System::Windows::Forms::Form
	{
	public:
		Confirm(System::String^ from, System::String^ to, System::String^ date, System::String^ carclass, System::String^ price,
			System::String^ ticketNum, System::String^ departure, System::String^ arrival, System::String^ trainNum)
		{
			InitializeComponent();
			result_from->Text = from;
			result_to->Text = to;
			result_date->Text = date;
			result_class ->Text = carclass;
			result_price->Text = price;
			result_ticketNum->Text = ticketNum;
			result_departure->Text = departure;
			result_arrival->Text = arrival;
			result_trainNum->Text = trainNum;
			int int_price, int_Num, total;
			Int32::TryParse(price, int_price);
			Int32::TryParse(ticketNum, int_Num);
			total = int_price * int_Num;
			System::String^ totalp = total.ToString();
			result_totalPrice->Text = totalp;
		}

	protected:
		~Confirm()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_result_from;
	private: System::Windows::Forms::Label^  label_result_to;
	private: System::Windows::Forms::Label^  label3;
	private: System::Windows::Forms::Label^  result_from;
	private: System::Windows::Forms::Label^  result_to;
	private: System::Windows::Forms::Label^  result_trainNum;
	private: System::Windows::Forms::Label^  label_result_ticketNum;
	private: System::Windows::Forms::Label^  label_result_price;
	private: System::Windows::Forms::Label^  label9;
	private: System::Windows::Forms::Label^  label_result_totalPrice;
	private: System::Windows::Forms::Button^  button1;
	private: System::Windows::Forms::Button^  button2;
	private: System::Windows::Forms::Label^  result_price;
	private: System::Windows::Forms::Label^  result_ticketNum;
	private: System::Windows::Forms::Label^  result_totalPrice;
	private: System::Windows::Forms::Label^  result_departure;
	private: System::Windows::Forms::Label^  result_arrival;
	private: System::Windows::Forms::Label^  result_date;
	private: System::Windows::Forms::Label^  result_class;
	private: System::ComponentModel::Container ^components;

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			this->label_result_from = (gcnew System::Windows::Forms::Label());
			this->label_result_to = (gcnew System::Windows::Forms::Label());
			this->label3 = (gcnew System::Windows::Forms::Label());
			this->result_from = (gcnew System::Windows::Forms::Label());
			this->result_to = (gcnew System::Windows::Forms::Label());
			this->result_trainNum = (gcnew System::Windows::Forms::Label());
			this->label_result_ticketNum = (gcnew System::Windows::Forms::Label());
			this->label_result_price = (gcnew System::Windows::Forms::Label());
			this->label9 = (gcnew System::Windows::Forms::Label());
			this->label_result_totalPrice = (gcnew System::Windows::Forms::Label());
			this->button1 = (gcnew System::Windows::Forms::Button());
			this->button2 = (gcnew System::Windows::Forms::Button());
			this->result_price = (gcnew System::Windows::Forms::Label());
			this->result_ticketNum = (gcnew System::Windows::Forms::Label());
			this->result_totalPrice = (gcnew System::Windows::Forms::Label());
			this->result_departure = (gcnew System::Windows::Forms::Label());
			this->result_arrival = (gcnew System::Windows::Forms::Label());
			this->result_date = (gcnew System::Windows::Forms::Label());
			this->result_class = (gcnew System::Windows::Forms::Label());
			this->SuspendLayout();
			// 
			// label_result_from
			// 
			this->label_result_from->AutoSize = true;
			this->label_result_from->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->label_result_from->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_from->Location = System::Drawing::Point(42, 37);
			this->label_result_from->Name = L"label_result_from";
			this->label_result_from->Size = System::Drawing::Size(74, 31);
			this->label_result_from->TabIndex = 0;
			this->label_result_from->Text = L"From";
			// 
			// label_result_to
			// 
			this->label_result_to->AutoSize = true;
			this->label_result_to->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label_result_to->Location = System::Drawing::Point(413, 36);
			this->label_result_to->Name = L"label_result_to";
			this->label_result_to->Size = System::Drawing::Size(43, 31);
			this->label_result_to->TabIndex = 1;
			this->label_result_to->Text = L"To";
			// 
			// label3
			// 
			this->label3->AutoSize = true;
			this->label3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 65.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->label3->Location = System::Drawing::Point(238, 36);
			this->label3->Name = L"label3";
			this->label3->Size = System::Drawing::Size(134, 109);
			this->label3->TabIndex = 2;
			this->label3->Text = L"→";
			// 
			// result_from
			// 
			this->result_from->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->result_from->AutoSize = true;
			this->result_from->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 25, System::Drawing::FontStyle::Bold));
			this->result_from->Location = System::Drawing::Point(54, 67);
			this->result_from->Name = L"result_from";
			this->result_from->Size = System::Drawing::Size(117, 43);
			this->result_from->TabIndex = 3;
			this->result_from->Text = L"label4";
			// 
			// result_to
			// 
			this->result_to->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->result_to->AutoSize = true;
			this->result_to->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 25, System::Drawing::FontStyle::Bold));
			this->result_to->Location = System::Drawing::Point(432, 67);
			this->result_to->Name = L"result_to";
			this->result_to->Size = System::Drawing::Size(117, 43);
			this->result_to->TabIndex = 4;
			this->result_to->Text = L"label5";
			// 
			// result_trainNum
			// 
			this->result_trainNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->result_trainNum->AutoSize = true;
			this->result_trainNum->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 15, System::Drawing::FontStyle::Bold));
			this->result_trainNum->Location = System::Drawing::Point(280, 43);
			this->result_trainNum->Name = L"result_trainNum";
			this->result_trainNum->Size = System::Drawing::Size(48, 25);
			this->result_trainNum->TabIndex = 5;
			this->result_trainNum->Text = L"888";
			this->result_trainNum->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// label_result_ticketNum
			// 
			this->label_result_ticketNum->AutoSize = true;
			this->label_result_ticketNum->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->label_result_ticketNum->Location = System::Drawing::Point(86, 266);
			this->label_result_ticketNum->Name = L"label_result_ticketNum";
			this->label_result_ticketNum->Size = System::Drawing::Size(130, 31);
			this->label_result_ticketNum->TabIndex = 6;
			this->label_result_ticketNum->Text = L"Ticket No.";
			this->label_result_ticketNum->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label_result_price
			// 
			this->label_result_price->AutoSize = true;
			this->label_result_price->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->label_result_price->Location = System::Drawing::Point(86, 226);
			this->label_result_price->Name = L"label_result_price";
			this->label_result_price->Size = System::Drawing::Size(152, 31);
			this->label_result_price->TabIndex = 7;
			this->label_result_price->Text = L"Price (NTD.)";
			this->label_result_price->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// label9
			// 
			this->label9->AutoSize = true;
			this->label9->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->label9->Location = System::Drawing::Point(86, 286);
			this->label9->Name = L"label9";
			this->label9->Size = System::Drawing::Size(476, 31);
			this->label9->TabIndex = 8;
			this->label9->Text = L"__________________________________________";
			// 
			// label_result_totalPrice
			// 
			this->label_result_totalPrice->AutoSize = true;
			this->label_result_totalPrice->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->label_result_totalPrice->Location = System::Drawing::Point(86, 327);
			this->label_result_totalPrice->Name = L"label_result_totalPrice";
			this->label_result_totalPrice->Size = System::Drawing::Size(153, 31);
			this->label_result_totalPrice->TabIndex = 9;
			this->label_result_totalPrice->Text = L"Total (NTD.)";
			this->label_result_totalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleLeft;
			// 
			// button1
			// 
			this->button1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->button1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold));
			this->button1->Location = System::Drawing::Point(379, 389);
			this->button1->Name = L"button1";
			this->button1->Size = System::Drawing::Size(97, 32);
			this->button1->TabIndex = 10;
			this->button1->Text = L"Confirm";
			this->button1->UseVisualStyleBackColor = false;
			this->button1->Click += gcnew System::EventHandler(this, &Confirm::button1_Click);
			// 
			// button2
			// 
			this->button2->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->button2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 12, System::Drawing::FontStyle::Bold));
			this->button2->Location = System::Drawing::Point(141, 389);
			this->button2->Name = L"button2";
			this->button2->Size = System::Drawing::Size(97, 32);
			this->button2->TabIndex = 11;
			this->button2->Text = L"Cancel";
			this->button2->UseVisualStyleBackColor = false;
			this->button2->Click += gcnew System::EventHandler(this, &Confirm::button2_Click);
			// 
			// result_price
			// 
			this->result_price->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->result_price->AutoSize = true;
			this->result_price->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->result_price->Location = System::Drawing::Point(479, 226);
			this->result_price->Name = L"result_price";
			this->result_price->Size = System::Drawing::Size(28, 31);
			this->result_price->TabIndex = 12;
			this->result_price->Text = L"0";
			this->result_price->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// result_ticketNum
			// 
			this->result_ticketNum->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->result_ticketNum->AutoSize = true;
			this->result_ticketNum->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->result_ticketNum->Location = System::Drawing::Point(479, 266);
			this->result_ticketNum->Name = L"result_ticketNum";
			this->result_ticketNum->Size = System::Drawing::Size(28, 31);
			this->result_ticketNum->TabIndex = 13;
			this->result_ticketNum->Text = L"0";
			this->result_ticketNum->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// result_totalPrice
			// 
			this->result_totalPrice->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((System::Windows::Forms::AnchorStyles::Left | System::Windows::Forms::AnchorStyles::Right));
			this->result_totalPrice->AutoSize = true;
			this->result_totalPrice->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold));
			this->result_totalPrice->Location = System::Drawing::Point(479, 327);
			this->result_totalPrice->Name = L"result_totalPrice";
			this->result_totalPrice->Size = System::Drawing::Size(28, 31);
			this->result_totalPrice->TabIndex = 14;
			this->result_totalPrice->Text = L"0";
			this->result_totalPrice->TextAlign = System::Drawing::ContentAlignment::MiddleRight;
			// 
			// result_departure
			// 
			this->result_departure->AutoSize = true;
			this->result_departure->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->result_departure->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->result_departure->Location = System::Drawing::Point(72, 115);
			this->result_departure->Name = L"result_departure";
			this->result_departure->Size = System::Drawing::Size(76, 31);
			this->result_departure->TabIndex = 15;
			this->result_departure->Text = L"00:00";
			this->result_departure->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// result_arrival
			// 
			this->result_arrival->AutoSize = true;
			this->result_arrival->FlatStyle = System::Windows::Forms::FlatStyle::System;
			this->result_arrival->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 18, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			this->result_arrival->Location = System::Drawing::Point(450, 114);
			this->result_arrival->Name = L"result_arrival";
			this->result_arrival->Size = System::Drawing::Size(76, 31);
			this->result_arrival->TabIndex = 16;
			this->result_arrival->Text = L"00:00";
			this->result_arrival->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// result_date
			// 
			this->result_date->AutoSize = true;
			this->result_date->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 10, System::Drawing::FontStyle::Bold));
			this->result_date->Location = System::Drawing::Point(263, 124);
			this->result_date->Name = L"result_date";
			this->result_date->Size = System::Drawing::Size(84, 18);
			this->result_date->TabIndex = 17;
			this->result_date->Text = L"1999/04/30";
			this->result_date->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// result_class
			// 
			this->result_class->Anchor = static_cast<System::Windows::Forms::AnchorStyles>((((System::Windows::Forms::AnchorStyles::Top | System::Windows::Forms::AnchorStyles::Bottom)
				| System::Windows::Forms::AnchorStyles::Left)
				| System::Windows::Forms::AnchorStyles::Right));
			this->result_class->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 25, System::Drawing::FontStyle::Bold));
			this->result_class->Location = System::Drawing::Point(174, 145);
			this->result_class->Name = L"result_class";
			this->result_class->Size = System::Drawing::Size(254, 43);
			this->result_class->TabIndex = 18;
			this->result_class->Text = L"Non-Reserved";
			this->result_class->TextAlign = System::Drawing::ContentAlignment::MiddleCenter;
			// 
			// Confirm
			// 
			this->AutoScaleDimensions = System::Drawing::SizeF(6, 12);
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->ClientSize = System::Drawing::Size(629, 433);
			this->Controls->Add(this->result_class);
			this->Controls->Add(this->result_date);
			this->Controls->Add(this->result_arrival);
			this->Controls->Add(this->result_departure);
			this->Controls->Add(this->result_totalPrice);
			this->Controls->Add(this->result_ticketNum);
			this->Controls->Add(this->result_price);
			this->Controls->Add(this->button2);
			this->Controls->Add(this->button1);
			this->Controls->Add(this->label_result_totalPrice);
			this->Controls->Add(this->label_result_price);
			this->Controls->Add(this->label_result_ticketNum);
			this->Controls->Add(this->result_trainNum);
			this->Controls->Add(this->result_to);
			this->Controls->Add(this->result_from);
			this->Controls->Add(this->label_result_to);
			this->Controls->Add(this->label_result_from);
			this->Controls->Add(this->label9);
			this->Controls->Add(this->label3);
			this->MaximumSize = System::Drawing::Size(645, 472);
			this->MinimumSize = System::Drawing::Size(645, 472);
			this->Name = L"Confirm";
			this->Text = L"Confirm";
			this->ResumeLayout(false);
			this->PerformLayout();

		}
#pragma endregion
	private: System::Void button2_Click(System::Object^  sender, System::EventArgs^  e) {
		this->Close();
	}
private: System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) {
	String^ msg = String::Concat("Successful Purchase！");
	MessageBox::Show(msg);
	this->Close();
}
};
}
