#pragma once
#include "carInfo.h"
#include "Confirm.h"

namespace Final {

	using namespace System;
	using namespace System::ComponentModel;
	using namespace System::Collections;
	using namespace System::Windows::Forms;
	using namespace System::Data;
	using namespace System::Drawing;

	public ref class Purchase : public System::Windows::Forms::Form
	{
	public:
		Purchase(void)
		{
			InitializeComponent();

			/*load the train informations*/
			car = load_carInfo();
			Stdprice = load_Std_priceInfo();
			Bisprice = load_Bis_priceInfo();
			Freeprice = load_Free_priceInfo();
			
			for (int i = 0;i < 13;i++) {
				for (int j = 0;j < 13;j++) {
					cout << Bisprice[i][j] << ",  ";
				}
				cout << endl;
			}
			for (int i = 0;i < 13;i++) {
				for (int j = 0;j < 13;j++) {
					cout << Stdprice[i][j] << ",  ";
				}
				cout << endl;
			}
			for (int i = 0;i < 13;i++) {
				for (int j = 0;j < 13;j++) {
					cout << Freeprice[i][j] << ",  ";
				}
				cout << endl;
			}
			/*initial value*/
			this->combo_Languague->Text = "English";
			this->combo_from->Text = "Nangang";
			this->combo_to->Text = "Zouying";
			this->pick_Time->Text = "06:00";
			this->combo_class->Text = "Standard";
			this->comboBox_ticketNum->Text = "1";
		}

	protected:
		~Purchase()
		{
			if (components)
			{
				delete components;
			}
		}
	private: System::Windows::Forms::Label^  label_title;
	private: System::Windows::Forms::TabControl^  tabControl;
	private: System::Windows::Forms::TabPage^  tabPage1;
	private: System::Windows::Forms::ComboBox^  combo_class;
	private: System::Windows::Forms::Label^  label_class;
	private: System::Windows::Forms::DateTimePicker^  pick_date;
	private: System::Windows::Forms::Button^  btn_search;
	private: System::Windows::Forms::Label^  label_from;
	private: System::Windows::Forms::Label^  label_time;
	private: System::Windows::Forms::Label^  label4;
	private: System::Windows::Forms::Label^  label_date;
	private: System::Windows::Forms::Label^  label_to;
	private: System::Windows::Forms::ComboBox^  combo_Languague;
	private: System::Windows::Forms::Label^  label16;
	private: System::Windows::Forms::ComboBox^  pick_Time;
	private: System::Windows::Forms::ComboBox^  combo_from;
	private: System::Windows::Forms::ComboBox^  combo_to;
	private: System::Windows::Forms::DataGridView^  InfoShow_en;
	private: System::Windows::Forms::DataGridView^  InfoShow_tw;
	private: System::Windows::Forms::Label^  label1;
	private: System::Windows::Forms::DataGridViewButtonColumn^  BookNow;
	private: System::Windows::Forms::ComboBox^  comboBox_ticketNum;
	private: System::ComponentModel::Container ^components;
	
	private:
		int flag_languague = 0;
		string** car;
		string** Stdprice;
		string** Bisprice;
		string** Freeprice;
		DataSet^ myDataSet = gcnew DataSet("DataTable_info");
		String^ departure;
		String^ arrival;
		String^ trainNum;
		String^ ticket_P;
		Object^ ticketPrice;
	private: System::Windows::Forms::DataGridViewButtonColumn^  Booknow_tw;
			 string** save_info = NULL;
		
		//if the languague change
		void languague_Change() {
			if (combo_from->Text != combo_to->Text) {
				if (this->combo_Languague->Text == "Chinese") {
					if (flag_languague == 1) {
						this->InfoShow_tw->Show();
						this->InfoShow_en->Hide();
					}
					this->label_title->Text = "台灣高鐵 購票系統";
					this->label_from->Text = "起站";
					this->label_to->Text = "迄站";
					this->label_date->Text = "乘車日期";
					this->label_time->Text = "乘車時間";
					this->label_class->Text = "艙等";
					this->btn_search->Text = "搜尋";
				}
				else if (this->combo_Languague->Text == "English") {
					if (flag_languague == 1) {
						this->InfoShow_en->Show();
						this->InfoShow_tw->Hide();
					}
					this->label_title->Text = "Taiwan High Speed Rail Booking System";
					this->label_from->Text = "From";
					this->label_to->Text = "To";
					this->label_date->Text = "Date";
					this->label_time->Text = "Time";
					this->label_class->Text = "Class";
					this->btn_search->Text = "Search";
				}
				flag_languague = 0;
			}
		}

		//search system
		void searchInfo(System::String^from, System::String^to, System::String^dayofweek, System::String^time, System::String^carclass) {
			// if the from and to are same
			if (from == to) {
				InfoShow_en->Hide();
				InfoShow_tw->Hide();
				if (this->combo_Languague->Text == "Chinese") {
					String^ msg = String::Concat("起迄站不可相同！");
					MessageBox::Show(msg);
				}
				else if (this->combo_Languague->Text == "English") {
					String^ msg = String::Concat("The starting and ending stations cannot be the same！");
					MessageBox::Show(msg);
				}
				return;
			}
			int index_from = 0, index_to = 0, index_time = 0, count = 0, count_save=0, flag_languague = 1;
			int index_price_col = 0, index_price_row = 0;
			int flag_search_start = 0, flag_search_end = 0;
			string from_temp, to_temp, time_temp, dayofweek_temp, class_temp, temp, price_temp;
			DataSet^ myDataSet = gcnew DataSet("DataTable_info");
			myDataSet->Tables->Add("Info_en");
			myDataSet->Tables->Add("Info_tw");
			DataTable^ myInfo_en = myDataSet->Tables["Info_en"];
			DataColumn^ c1 = myInfo_en->Columns->Add("Departure", String::typeid);
			DataColumn^ c2 = myInfo_en->Columns->Add("Arrival", String::typeid);
			DataColumn^ c3 = myInfo_en->Columns->Add("Train No.", String::typeid);
			DataColumn^ c4 = myInfo_en->Columns->Add("Price", String::typeid);
			DataTable^ myInfo_tw = myDataSet->Tables["Info_tw"];
			DataColumn^ t1 = myInfo_tw->Columns->Add("出發時間", String::typeid);
			DataColumn^ t2 = myInfo_tw->Columns->Add("抵達時間", String::typeid);
			DataColumn^ t3 = myInfo_tw->Columns->Add("車次", String::typeid);
			DataColumn^ t4 = myInfo_tw->Columns->Add("價格", String::typeid);
			MarshalString(from, from_temp);
			MarshalString(to, to_temp);
			MarshalString(time, time_temp);
			MarshalString(dayofweek, dayofweek_temp);
			MarshalString(carclass, class_temp);
			time_temp.erase(2, 1);

			/*calculate the position of from and to */
			for (int i = 0; i < 12; i++) {
				if (from_temp == car[0][i] || from_temp == car[1][i]) index_from = i;
			}
			for (int i = 0; i < 12; i++) {
				if (to_temp == car[0][i] || to_temp == car[1][i]) index_to = i;
			}

			/*Judge the ticket class*/
			if (class_temp == "Standard") {
				if (index_from <= index_to) {
					index_price_col = index_from;
					index_price_row = index_to;
				}
				else if (index_from >= index_to) {
					index_price_col = index_to;
					index_price_row = index_from;
				}
				ticket_P = gcnew String(Stdprice[index_price_row][index_price_col].c_str());
				price_temp = Stdprice[index_price_row][index_price_col];
			}
			else if (class_temp == "Bussiness") {
				if (index_from <= index_to) {
					index_price_col = index_from;
					index_price_row = index_to;
				}
				else if (index_from >= index_to) {
					index_price_col = index_to;
					index_price_row = index_from;
				}
				cout << index_price_col << ", " << index_price_row << endl;
				ticket_P = gcnew String(Bisprice[index_price_row][index_price_col].c_str());
				price_temp = Bisprice[index_price_row][index_price_col];
			}
			else if (class_temp == "Non-Reserved") {
				if (index_from <= index_to) {
					index_price_col = index_from;
					index_price_row = index_to;
				}
				else if (index_from >= index_to) {
					index_price_col = index_to ;
					index_price_row = index_from;
				}
				cout << index_price_col << ", " << index_price_row << endl;
				ticket_P = gcnew String(Freeprice[index_price_row][index_price_col].c_str());
				price_temp = Freeprice[index_price_row][index_price_col];
			}

			/*S -> N*/
			if (index_from < index_to) {
				flag_search_start = 2;
				flag_search_end = 101;
			}
			/*N -> S*/
			else if (index_from > index_to) {
				for (int i = 0; i < 14; i++) {
					if (from_temp == car[102][i]) {
						index_from = i;
					}
				}
				for (int i = 0; i < 14; i++) {
					if (to_temp == car[102][i]) {
						index_to = i;
					}
				}
				flag_search_start = 103;
				flag_search_end = 195;
			}

			/*Search the informatiom from array and show on datagridview*/
			save_info = new string*[101];
			for (int i = 0;i < 101;i++) save_info[i] = new string[4];
			for (int i = flag_search_start; i < flag_search_end; i++) {
				if (car[i][index_from] != "") {
					temp = car[i][index_from];
					size_t pos = temp.find(":");
					if(pos != temp.npos) temp.erase(pos, 1);
					else if (pos == temp.npos) temp = "0";
					if (stoi(temp) >= stoi(time_temp) && car[i][index_to] != "") {
						string::size_type position = car[i][13].find(dayofweek_temp);
						if (position != car[i][1].npos){
							Object^ c1 = gcnew String(car[i][index_from].c_str());
							Object^ c2 = gcnew String(car[i][index_to].c_str());
							Object^ c3 = gcnew String(car[i][12].c_str());
							Object^ c4 = gcnew String(price_temp.c_str());
							Object^ t1 = gcnew String(car[i][index_from].c_str());
							Object^ t2 = gcnew String(car[i][index_to].c_str());
							Object^ t3 = gcnew String(car[i][12].c_str());
							Object^ t4 = gcnew String(price_temp.c_str());
							myInfo_en->Rows->Add(c1, c2, c3, c4);
							myInfo_tw->Rows->Add(t1, t2, t3, t4);
							save_info[count_save][0] = car[i][index_from].c_str();
							save_info[count_save][1] = car[i][index_to].c_str();
							save_info[count_save][2] = car[i][12].c_str();
							save_info[count_save][3] = price_temp.c_str();
							count_save++;
						}
					}
				}
			}

			/*refresh the data tables and show*/
			this->InfoShow_en->DataSource = myInfo_en;
			this->InfoShow_tw->DataSource = myInfo_tw;
			this->InfoShow_en->Refresh();
			this->InfoShow_tw->Refresh();
			this->InfoShow_en->AutoResizeColumns();
			this->InfoShow_tw->AutoResizeColumns();
			if (this->combo_Languague->Text == "Chinese") {
				this->InfoShow_tw->Show();
				this->InfoShow_en->Hide();
			}
			else if (this->combo_Languague->Text == "English") {
				this->InfoShow_en->Show();
				this->InfoShow_tw->Hide();
			}
			else{
				this->InfoShow_en->Show();
				this->InfoShow_tw->Hide();
			}
		};

		/*convert String^  to std string*/
		void MarshalString(String ^ s, string& os)
		{
			using namespace Runtime::InteropServices;
			const char* chars =
				(const char*)(Marshal::StringToHGlobalAnsi(s)).ToPointer();
			os = chars;
			Marshal::FreeHGlobal(IntPtr((void*)chars));
		};

#pragma region Windows Form Designer generated code
		void InitializeComponent(void)
		{
			System::ComponentModel::ComponentResourceManager^  resources = (gcnew System::ComponentModel::ComponentResourceManager(Purchase::typeid));
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle1 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle2 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle3 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle4 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			System::Windows::Forms::DataGridViewCellStyle^  dataGridViewCellStyle5 = (gcnew System::Windows::Forms::DataGridViewCellStyle());
			this->combo_to = (gcnew System::Windows::Forms::ComboBox());
			this->combo_from = (gcnew System::Windows::Forms::ComboBox());
			this->label_title = (gcnew System::Windows::Forms::Label());
			this->tabControl = (gcnew System::Windows::Forms::TabControl());
			this->tabPage1 = (gcnew System::Windows::Forms::TabPage());
			this->comboBox_ticketNum = (gcnew System::Windows::Forms::ComboBox());
			this->label1 = (gcnew System::Windows::Forms::Label());
			this->pick_Time = (gcnew System::Windows::Forms::ComboBox());
			this->combo_class = (gcnew System::Windows::Forms::ComboBox());
			this->label_class = (gcnew System::Windows::Forms::Label());
			this->pick_date = (gcnew System::Windows::Forms::DateTimePicker());
			this->btn_search = (gcnew System::Windows::Forms::Button());
			this->label_from = (gcnew System::Windows::Forms::Label());
			this->label_time = (gcnew System::Windows::Forms::Label());
			this->label4 = (gcnew System::Windows::Forms::Label());
			this->label_date = (gcnew System::Windows::Forms::Label());
			this->label_to = (gcnew System::Windows::Forms::Label());
			this->combo_Languague = (gcnew System::Windows::Forms::ComboBox());
			this->label16 = (gcnew System::Windows::Forms::Label());
			this->InfoShow_en = (gcnew System::Windows::Forms::DataGridView());
			this->BookNow = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->InfoShow_tw = (gcnew System::Windows::Forms::DataGridView());
			this->Booknow_tw = (gcnew System::Windows::Forms::DataGridViewButtonColumn());
			this->tabControl->SuspendLayout();
			this->tabPage1->SuspendLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoShow_en))->BeginInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoShow_tw))->BeginInit();
			this->SuspendLayout();
			// 
			// combo_to
			// 
			this->combo_to->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->combo_to->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->combo_to, L"combo_to");
			this->combo_to->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				resources->GetString(L"combo_to.Items"), resources->GetString(L"combo_to.Items1"),
					resources->GetString(L"combo_to.Items2"), resources->GetString(L"combo_to.Items3"), resources->GetString(L"combo_to.Items4"),
					resources->GetString(L"combo_to.Items5"), resources->GetString(L"combo_to.Items6"), resources->GetString(L"combo_to.Items7"),
					resources->GetString(L"combo_to.Items8"), resources->GetString(L"combo_to.Items9"), resources->GetString(L"combo_to.Items10"),
					resources->GetString(L"combo_to.Items11")
			});
			this->combo_to->Name = L"combo_to";
			// 
			// combo_from
			// 
			this->combo_from->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->combo_from->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->combo_from, L"combo_from");
			this->combo_from->Items->AddRange(gcnew cli::array< System::Object^  >(12) {
				resources->GetString(L"combo_from.Items"), resources->GetString(L"combo_from.Items1"),
					resources->GetString(L"combo_from.Items2"), resources->GetString(L"combo_from.Items3"), resources->GetString(L"combo_from.Items4"),
					resources->GetString(L"combo_from.Items5"), resources->GetString(L"combo_from.Items6"), resources->GetString(L"combo_from.Items7"),
					resources->GetString(L"combo_from.Items8"), resources->GetString(L"combo_from.Items9"), resources->GetString(L"combo_from.Items10"),
					resources->GetString(L"combo_from.Items11")
			});
			this->combo_from->Name = L"combo_from";
			// 
			// label_title
			// 
			resources->ApplyResources(this->label_title, L"label_title");
			this->label_title->Name = L"label_title";
			// 
			// tabControl
			// 
			this->tabControl->Controls->Add(this->tabPage1);
			this->tabControl->Cursor = System::Windows::Forms::Cursors::Hand;
			resources->ApplyResources(this->tabControl, L"tabControl");
			this->tabControl->Name = L"tabControl";
			this->tabControl->SelectedIndex = 0;
			// 
			// tabPage1
			// 
			this->tabPage1->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->tabPage1->Controls->Add(this->comboBox_ticketNum);
			this->tabPage1->Controls->Add(this->label1);
			this->tabPage1->Controls->Add(this->pick_Time);
			this->tabPage1->Controls->Add(this->combo_class);
			this->tabPage1->Controls->Add(this->label_class);
			this->tabPage1->Controls->Add(this->pick_date);
			this->tabPage1->Controls->Add(this->btn_search);
			this->tabPage1->Controls->Add(this->label_from);
			this->tabPage1->Controls->Add(this->label_time);
			this->tabPage1->Controls->Add(this->combo_from);
			this->tabPage1->Controls->Add(this->label4);
			this->tabPage1->Controls->Add(this->label_date);
			this->tabPage1->Controls->Add(this->combo_to);
			this->tabPage1->Controls->Add(this->label_to);
			resources->ApplyResources(this->tabPage1, L"tabPage1");
			this->tabPage1->ForeColor = System::Drawing::SystemColors::ControlText;
			this->tabPage1->Name = L"tabPage1";
			// 
			// comboBox_ticketNum
			// 
			this->comboBox_ticketNum->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->comboBox_ticketNum->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->comboBox_ticketNum, L"comboBox_ticketNum");
			this->comboBox_ticketNum->Items->AddRange(gcnew cli::array< System::Object^  >(10) {
				resources->GetString(L"comboBox_ticketNum.Items"),
					resources->GetString(L"comboBox_ticketNum.Items1"), resources->GetString(L"comboBox_ticketNum.Items2"), resources->GetString(L"comboBox_ticketNum.Items3"),
					resources->GetString(L"comboBox_ticketNum.Items4"), resources->GetString(L"comboBox_ticketNum.Items5"), resources->GetString(L"comboBox_ticketNum.Items6"),
					resources->GetString(L"comboBox_ticketNum.Items7"), resources->GetString(L"comboBox_ticketNum.Items8"), resources->GetString(L"comboBox_ticketNum.Items9")
			});
			this->comboBox_ticketNum->Name = L"comboBox_ticketNum";
			// 
			// label1
			// 
			resources->ApplyResources(this->label1, L"label1");
			this->label1->Name = L"label1";
			// 
			// pick_Time
			// 
			this->pick_Time->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->pick_Time->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->pick_Time, L"pick_Time");
			this->pick_Time->FormattingEnabled = true;
			this->pick_Time->Items->AddRange(gcnew cli::array< System::Object^  >(40) {
				resources->GetString(L"pick_Time.Items"), resources->GetString(L"pick_Time.Items1"),
					resources->GetString(L"pick_Time.Items2"), resources->GetString(L"pick_Time.Items3"), resources->GetString(L"pick_Time.Items4"),
					resources->GetString(L"pick_Time.Items5"), resources->GetString(L"pick_Time.Items6"), resources->GetString(L"pick_Time.Items7"),
					resources->GetString(L"pick_Time.Items8"), resources->GetString(L"pick_Time.Items9"), resources->GetString(L"pick_Time.Items10"),
					resources->GetString(L"pick_Time.Items11"), resources->GetString(L"pick_Time.Items12"), resources->GetString(L"pick_Time.Items13"),
					resources->GetString(L"pick_Time.Items14"), resources->GetString(L"pick_Time.Items15"), resources->GetString(L"pick_Time.Items16"),
					resources->GetString(L"pick_Time.Items17"), resources->GetString(L"pick_Time.Items18"), resources->GetString(L"pick_Time.Items19"),
					resources->GetString(L"pick_Time.Items20"), resources->GetString(L"pick_Time.Items21"), resources->GetString(L"pick_Time.Items22"),
					resources->GetString(L"pick_Time.Items23"), resources->GetString(L"pick_Time.Items24"), resources->GetString(L"pick_Time.Items25"),
					resources->GetString(L"pick_Time.Items26"), resources->GetString(L"pick_Time.Items27"), resources->GetString(L"pick_Time.Items28"),
					resources->GetString(L"pick_Time.Items29"), resources->GetString(L"pick_Time.Items30"), resources->GetString(L"pick_Time.Items31"),
					resources->GetString(L"pick_Time.Items32"), resources->GetString(L"pick_Time.Items33"), resources->GetString(L"pick_Time.Items34"),
					resources->GetString(L"pick_Time.Items35"), resources->GetString(L"pick_Time.Items36"), resources->GetString(L"pick_Time.Items37"),
					resources->GetString(L"pick_Time.Items38"), resources->GetString(L"pick_Time.Items39")
			});
			this->pick_Time->Name = L"pick_Time";
			// 
			// combo_class
			// 
			this->combo_class->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->combo_class->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->combo_class, L"combo_class");
			this->combo_class->FormattingEnabled = true;
			this->combo_class->Items->AddRange(gcnew cli::array< System::Object^  >(3) {
				resources->GetString(L"combo_class.Items"), resources->GetString(L"combo_class.Items1"),
					resources->GetString(L"combo_class.Items2")
			});
			this->combo_class->Name = L"combo_class";
			// 
			// label_class
			// 
			resources->ApplyResources(this->label_class, L"label_class");
			this->label_class->Name = L"label_class";
			// 
			// pick_date
			// 
			this->pick_date->CalendarMonthBackground = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			resources->ApplyResources(this->pick_date, L"pick_date");
			this->pick_date->Format = System::Windows::Forms::DateTimePickerFormat::Custom;
			this->pick_date->Name = L"pick_date";
			this->pick_date->MinDate = System::DateTime::Today;
			this->pick_date->MaxDate = System::DateTime::Today.AddDays(30);
			// 
			// btn_search
			// 
			this->btn_search->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(252)), static_cast<System::Int32>(static_cast<System::Byte>(163)),
				static_cast<System::Int32>(static_cast<System::Byte>(17)));
			resources->ApplyResources(this->btn_search, L"btn_search");
			this->btn_search->Name = L"btn_search";
			this->btn_search->UseVisualStyleBackColor = false;
			this->btn_search->Click += gcnew System::EventHandler(this, &Purchase::btn_search_Click);
			// 
			// label_from
			// 
			resources->ApplyResources(this->label_from, L"label_from");
			this->label_from->Name = L"label_from";
			// 
			// label_time
			// 
			resources->ApplyResources(this->label_time, L"label_time");
			this->label_time->Name = L"label_time";
			// 
			// label4
			// 
			resources->ApplyResources(this->label4, L"label4");
			this->label4->Name = L"label4";
			// 
			// label_date
			// 
			resources->ApplyResources(this->label_date, L"label_date");
			this->label_date->Name = L"label_date";
			// 
			// label_to
			// 
			resources->ApplyResources(this->label_to, L"label_to");
			this->label_to->Name = L"label_to";
			// 
			// combo_Languague
			// 
			this->combo_Languague->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)));
			this->combo_Languague->DropDownStyle = System::Windows::Forms::ComboBoxStyle::DropDownList;
			resources->ApplyResources(this->combo_Languague, L"combo_Languague");
			this->combo_Languague->FormattingEnabled = true;
			this->combo_Languague->Items->AddRange(gcnew cli::array< System::Object^  >(2) {
				resources->GetString(L"combo_Languague.Items"),
					resources->GetString(L"combo_Languague.Items1")
			});
			this->combo_Languague->Name = L"combo_Languague";
			this->combo_Languague->SelectedIndexChanged += gcnew System::EventHandler(this, &Purchase::combo_languaguechange);
			// 
			// label16
			// 
			resources->ApplyResources(this->label16, L"label16");
			this->label16->Name = L"label16";
			// 
			// InfoShow_en
			// 
			this->InfoShow_en->AllowUserToAddRows = false;
			this->InfoShow_en->AllowUserToDeleteRows = false;
			this->InfoShow_en->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->InfoShow_en->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			dataGridViewCellStyle1->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle1->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle1->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 13, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle1->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle1->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataGridViewCellStyle1->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle1->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->InfoShow_en->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle1;
			this->InfoShow_en->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->InfoShow_en->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->BookNow });
			dataGridViewCellStyle2->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle2->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle2->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9));
			dataGridViewCellStyle2->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle2->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataGridViewCellStyle2->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle2->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InfoShow_en->DefaultCellStyle = dataGridViewCellStyle2;
			resources->ApplyResources(this->InfoShow_en, L"InfoShow_en");
			this->InfoShow_en->Name = L"InfoShow_en";
			this->InfoShow_en->ReadOnly = true;
			dataGridViewCellStyle3->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle3->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle3->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9.75F, System::Drawing::FontStyle::Regular, System::Drawing::GraphicsUnit::Point,
				static_cast<System::Byte>(136)));
			dataGridViewCellStyle3->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle3->SelectionBackColor = System::Drawing::SystemColors::Highlight;
			dataGridViewCellStyle3->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle3->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->InfoShow_en->RowHeadersDefaultCellStyle = dataGridViewCellStyle3;
			this->InfoShow_en->RowTemplate->Height = 24;
			this->InfoShow_en->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Purchase::datagrid_click);
			// 
			// BookNow
			// 
			resources->ApplyResources(this->BookNow, L"BookNow");
			this->BookNow->Name = L"BookNow";
			this->BookNow->ReadOnly = true;
			this->BookNow->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->BookNow->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// InfoShow_tw
			// 
			this->InfoShow_tw->AllowUserToAddRows = false;
			this->InfoShow_tw->AllowUserToDeleteRows = false;
			this->InfoShow_tw->AutoSizeColumnsMode = System::Windows::Forms::DataGridViewAutoSizeColumnsMode::Fill;
			this->InfoShow_tw->BackgroundColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(229)),
				static_cast<System::Int32>(static_cast<System::Byte>(229)), static_cast<System::Int32>(static_cast<System::Byte>(229)));
			dataGridViewCellStyle4->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle4->BackColor = System::Drawing::SystemColors::Control;
			dataGridViewCellStyle4->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 13, System::Drawing::FontStyle::Bold));
			dataGridViewCellStyle4->ForeColor = System::Drawing::SystemColors::WindowText;
			dataGridViewCellStyle4->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataGridViewCellStyle4->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle4->WrapMode = System::Windows::Forms::DataGridViewTriState::True;
			this->InfoShow_tw->ColumnHeadersDefaultCellStyle = dataGridViewCellStyle4;
			this->InfoShow_tw->ColumnHeadersHeightSizeMode = System::Windows::Forms::DataGridViewColumnHeadersHeightSizeMode::AutoSize;
			this->InfoShow_tw->Columns->AddRange(gcnew cli::array< System::Windows::Forms::DataGridViewColumn^  >(1) { this->Booknow_tw });
			dataGridViewCellStyle5->Alignment = System::Windows::Forms::DataGridViewContentAlignment::MiddleCenter;
			dataGridViewCellStyle5->BackColor = System::Drawing::SystemColors::Window;
			dataGridViewCellStyle5->Font = (gcnew System::Drawing::Font(L"微軟正黑體", 9));
			dataGridViewCellStyle5->ForeColor = System::Drawing::SystemColors::ControlText;
			dataGridViewCellStyle5->SelectionBackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(255)),
				static_cast<System::Int32>(static_cast<System::Byte>(128)), static_cast<System::Int32>(static_cast<System::Byte>(0)));
			dataGridViewCellStyle5->SelectionForeColor = System::Drawing::SystemColors::HighlightText;
			dataGridViewCellStyle5->WrapMode = System::Windows::Forms::DataGridViewTriState::False;
			this->InfoShow_tw->DefaultCellStyle = dataGridViewCellStyle5;
			resources->ApplyResources(this->InfoShow_tw, L"InfoShow_tw");
			this->InfoShow_tw->Name = L"InfoShow_tw";
			this->InfoShow_tw->ReadOnly = true;
			this->InfoShow_tw->RowTemplate->Height = 24;
			this->InfoShow_tw->CellDoubleClick += gcnew System::Windows::Forms::DataGridViewCellEventHandler(this, &Purchase::datagrid_click);
			// 
			// Booknow_tw
			// 
			resources->ApplyResources(this->Booknow_tw, L"Booknow_tw");
			this->Booknow_tw->Name = L"Booknow_tw";
			this->Booknow_tw->ReadOnly = true;
			this->Booknow_tw->Resizable = System::Windows::Forms::DataGridViewTriState::True;
			this->Booknow_tw->SortMode = System::Windows::Forms::DataGridViewColumnSortMode::Automatic;
			// 
			// Purchase
			// 
			resources->ApplyResources(this, L"$this");
			this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
			this->BackColor = System::Drawing::Color::FromArgb(static_cast<System::Int32>(static_cast<System::Byte>(238)), static_cast<System::Int32>(static_cast<System::Byte>(155)),
				static_cast<System::Int32>(static_cast<System::Byte>(0)));
			this->Controls->Add(this->InfoShow_en);
			this->Controls->Add(this->InfoShow_tw);
			this->Controls->Add(this->combo_Languague);
			this->Controls->Add(this->label16);
			this->Controls->Add(this->tabControl);
			this->Controls->Add(this->label_title);
			this->Name = L"Purchase";
			this->tabControl->ResumeLayout(false);
			this->tabPage1->ResumeLayout(false);
			this->tabPage1->PerformLayout();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoShow_en))->EndInit();
			(cli::safe_cast<System::ComponentModel::ISupportInitialize^>(this->InfoShow_tw))->EndInit();
			this->ResumeLayout(false);
			this->PerformLayout();

		}

#pragma endregion
private: System::Void btn_search_Click(System::Object^  sender, System::EventArgs^  e) {
	flag_languague = 1;
	System::String^ from = Final::Purchase::combo_from->Text->ToString();
	System::String^ to = Final::Purchase::combo_to->Text->ToString();
	System::String^ dayofweek = Final::Purchase::pick_date->Value.DayOfWeek.ToString();
	System::String^ time = Final::Purchase::pick_Time->Text->ToString();
	System::String^ carclass = Final::Purchase::combo_class->Text->ToString();
	string temp_week;
	MarshalString(dayofweek, temp_week);
	if (temp_week == "Monday") temp_week = "1";
	else if (temp_week == "Tuesday") temp_week = "2";
	else if (temp_week == "Wednesday") temp_week = "3";
	else if (temp_week == "Thursday") temp_week = "4";
	else if (temp_week == "Friday") temp_week = "5";
	else if (temp_week == "Saturday") temp_week = "6";
	else if (temp_week == "Sunday") temp_week = "7";
	String^ week = gcnew String(temp_week.c_str());
	searchInfo(from, to, week, time, carclass);
}

private: System::Void combo_languaguechange(System::Object^  sender, System::EventArgs^  e) {
		languague_Change();
}

private: System::Void datagrid_click(System::Object^  sender, System::Windows::Forms::DataGridViewCellEventArgs^  e) {
	if (e->RowIndex != -1 && e->ColumnIndex != -1 && e->ColumnIndex != 1 && e->ColumnIndex != 2 && e->ColumnIndex != 3 && e->ColumnIndex != 4) {
		flag_languague = 0;
		cout << e->RowIndex << endl;
		System::String^ from = Final::Purchase::combo_from->Text->ToString();
		System::String^ to = Final::Purchase::combo_to->Text->ToString();
		System::String^ date = Final::Purchase::pick_date->Text->ToString();
		System::String^ carclass = Final::Purchase::combo_class->Text->ToString();
		System::String^ ticketNum = Final::Purchase::comboBox_ticketNum->Text->ToString();
		String^ departure = gcnew String(save_info[e->RowIndex][0].c_str());
		String^ arrival = gcnew String(save_info[e->RowIndex][1].c_str());
		String^ trainNum = gcnew String(save_info[e->RowIndex][2].c_str());
		delete[] save_info;
		Confirm ^ booking = gcnew Confirm(from, to, date, carclass, ticket_P, ticketNum, departure, arrival, trainNum);
		booking->Show();
		InfoShow_en->Hide();
		InfoShow_tw->Hide();
	}
}

};
}