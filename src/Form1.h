#pragma once


namespace CounterD
{

  using namespace System;
  using namespace System::ComponentModel;
  using namespace System::Collections;
  using namespace System::Windows::Forms;
  using namespace System::Data;
  using namespace System::Drawing;
  using namespace System::Media;
  using namespace System::Threading;

  /// <summary>
  /// Summary for Form1
  ///
  /// WARNING: If you change the name of this class, you will need to change the
  ///          'Resource File Name' property for the managed resource compiler tool
  ///          associated with all .resx files this class depends on.  Otherwise,
  ///          the designers will not be able to interact properly with localized
  ///          resources associated with this form.
  /// </summary>
  public ref class Form1 : public System::Windows::Forms::Form
  {
  public:
    Form1(void);


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
  private:
    System::Windows::Forms::TextBox^  textHour;
  private:
    System::Windows::Forms::TextBox^  textMin;
  private:
    System::Windows::Forms::TextBox^  textSec;
  private:
    System::Windows::Forms::Button^  buttonStart;
  private:
    System::Windows::Forms::Button^  buttonStop;
  private:
    System::Windows::Forms::Button^  buttonReset;
  private:
    System::Windows::Forms::Timer^  timerTask1;
  private:
    System::ComponentModel::IContainer^  components;
  private:
    System::ComponentModel::BackgroundWorker^ backgroundWorker;



  private:
    /// <summary>
    /// Required designer variable.
    /// </summary>
    UInt32 u32TotalTime, u32Hour, u32Min, u32Sec;
    Boolean bCountDown;
    Boolean bHourlySound;
    Boolean bMidTimeSound;
    UInt32 u32MidTime;
    System::String^ TimeFormatStr;
  private:
    System::Windows::Forms::Label^  label1;
  private:
    System::Windows::Forms::Label^  label2;
  private:
    System::Windows::Forms::Label^  label3;
  private:
    System::Windows::Forms::Label^  label4;
  private:
    System::Windows::Forms::Label^  labelStartTime;
  private:
    System::Windows::Forms::Label^  labelStopTime;
  private:
    System::Windows::Forms::Label^  labelProgramStart;
  private: System::Windows::Forms::Button^  button1;

  private:
    System::Windows::Forms::Label^  label5;


#pragma region Windows Form Designer generated code
    /// <summary>
    /// Required method for Designer support - do not modify
    /// the contents of this method with the code editor.
    /// </summary>
    void InitializeComponent(void)
    {
		this->components = (gcnew System::ComponentModel::Container());
		this->textHour = (gcnew System::Windows::Forms::TextBox());
		this->textMin = (gcnew System::Windows::Forms::TextBox());
		this->textSec = (gcnew System::Windows::Forms::TextBox());
		this->buttonStart = (gcnew System::Windows::Forms::Button());
		this->buttonStop = (gcnew System::Windows::Forms::Button());
		this->buttonReset = (gcnew System::Windows::Forms::Button());
		this->timerTask1 = (gcnew System::Windows::Forms::Timer(this->components));
		this->label1 = (gcnew System::Windows::Forms::Label());
		this->label2 = (gcnew System::Windows::Forms::Label());
		this->label3 = (gcnew System::Windows::Forms::Label());
		this->label4 = (gcnew System::Windows::Forms::Label());
		this->label5 = (gcnew System::Windows::Forms::Label());
		this->labelStartTime = (gcnew System::Windows::Forms::Label());
		this->labelStopTime = (gcnew System::Windows::Forms::Label());
		this->labelProgramStart = (gcnew System::Windows::Forms::Label());
		this->button1 = (gcnew System::Windows::Forms::Button());
		this->SuspendLayout();
		// 
		// textHour
		// 
		this->textHour->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->textHour->Location = System::Drawing::Point(49, 25);
		this->textHour->Name = L"textHour";
		this->textHour->Size = System::Drawing::Size(38, 26);
		this->textHour->TabIndex = 1;
		this->textHour->Text = L"00";
		this->textHour->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textMin
		// 
		this->textMin->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->textMin->Location = System::Drawing::Point(120, 25);
		this->textMin->Name = L"textMin";
		this->textMin->Size = System::Drawing::Size(38, 26);
		this->textMin->TabIndex = 2;
		this->textMin->Text = L"00";
		this->textMin->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
		// 
		// textSec
		// 
		this->textSec->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->textSec->Location = System::Drawing::Point(191, 25);
		this->textSec->Name = L"textSec";
		this->textSec->Size = System::Drawing::Size(38, 26);
		this->textSec->TabIndex = 3;
      this->textSec->Text = L"10";
		this->textSec->TextAlign = System::Windows::Forms::HorizontalAlignment::Center;
      //this->textSec->TextChanged += gcnew System::EventHandler(this, &Form1::textSec_TextChanged);
		// 
		// buttonStart
		// 
		this->buttonStart->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->buttonStart->Location = System::Drawing::Point(14, 70);
		this->buttonStart->Name = L"buttonStart";
		this->buttonStart->Size = System::Drawing::Size(75, 23);
		this->buttonStart->TabIndex = 4;
		this->buttonStart->Text = L"Start";
		this->buttonStart->UseVisualStyleBackColor = true;
		this->buttonStart->Click += gcnew System::EventHandler(this, &Form1::buttonStart_Click);
		// 
		// buttonStop
		// 
		this->buttonStop->Enabled = false;
		this->buttonStop->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->buttonStop->Location = System::Drawing::Point(102, 70);
		this->buttonStop->Name = L"buttonStop";
		this->buttonStop->Size = System::Drawing::Size(75, 23);
		this->buttonStop->TabIndex = 5;
		this->buttonStop->Text = L"Stop";
		this->buttonStop->UseVisualStyleBackColor = true;
		this->buttonStop->Click += gcnew System::EventHandler(this, &Form1::buttonStop_Click);
		// 
		// buttonReset
		// 
		this->buttonReset->Font = (gcnew System::Drawing::Font(L"Courier New", 12, System::Drawing::FontStyle::Bold));
		this->buttonReset->Location = System::Drawing::Point(190, 70);
		this->buttonReset->Name = L"buttonReset";
		this->buttonReset->Size = System::Drawing::Size(75, 23);
		this->buttonReset->TabIndex = 6;
		this->buttonReset->Text = L"Reset";
		this->buttonReset->UseVisualStyleBackColor = true;
		this->buttonReset->Click += gcnew System::EventHandler(this, &Form1::buttonReset_Click);
		// 
		// timerTask1
		// 
		this->timerTask1->Tick += gcnew System::EventHandler(this, &Form1::timerTask1_Tick);
		// 
		// label1
		// 
		this->label1->AutoSize = true;
		this->label1->Location = System::Drawing::Point(49, 6);
		this->label1->Name = L"label1";
		this->label1->Size = System::Drawing::Size(39, 13);
		this->label1->TabIndex = 6;
		this->label1->Text = L"HOUR";
		// 
		// label2
		// 
		this->label2->AutoSize = true;
		this->label2->Location = System::Drawing::Point(117, 6);
		this->label2->Name = L"label2";
		this->label2->Size = System::Drawing::Size(27, 13);
		this->label2->TabIndex = 7;
		this->label2->Text = L"MIN";
		// 
		// label3
		// 
		this->label3->AutoSize = true;
		this->label3->Location = System::Drawing::Point(188, 6);
		this->label3->Name = L"label3";
		this->label3->Size = System::Drawing::Size(28, 13);
		this->label3->TabIndex = 8;
		this->label3->Text = L"SEC";
		// 
		// label4
		// 
		this->label4->AutoSize = true;
		this->label4->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->label4->Location = System::Drawing::Point(93, 26);
		this->label4->Name = L"label4";
		this->label4->Size = System::Drawing::Size(21, 22);
		this->label4->TabIndex = 9;
		this->label4->Text = L":";
		// 
		// label5
		// 
		this->label5->AutoSize = true;
		this->label5->Font = (gcnew System::Drawing::Font(L"Courier New", 14.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->label5->Location = System::Drawing::Point(164, 25);
		this->label5->Name = L"label5";
		this->label5->Size = System::Drawing::Size(21, 22);
		this->label5->TabIndex = 10;
		this->label5->Text = L":";
		// 
		// labelStartTime
		// 
		this->labelStartTime->AutoSize = true;
		this->labelStartTime->Location = System::Drawing::Point(14, 113);
		this->labelStartTime->Name = L"labelStartTime";
		this->labelStartTime->Size = System::Drawing::Size(100, 13);
		this->labelStartTime->TabIndex = 11;
		this->labelStartTime->Text = L"Last Start: 00:00:00";
		// 
		// labelStopTime
		// 
		this->labelStopTime->AutoSize = true;
		this->labelStopTime->Location = System::Drawing::Point(14, 126);
		this->labelStopTime->Name = L"labelStopTime";
		this->labelStopTime->Size = System::Drawing::Size(100, 13);
		this->labelStopTime->TabIndex = 12;
		this->labelStopTime->Text = L"Last Stop: 00:00:00";
		// 
		// labelProgramStart
		// 
		this->labelProgramStart->AutoSize = true;
		this->labelProgramStart->Location = System::Drawing::Point(14, 139);
		this->labelProgramStart->Name = L"labelProgramStart";
		this->labelProgramStart->Size = System::Drawing::Size(119, 13);
		this->labelProgramStart->TabIndex = 13;
		this->labelProgramStart->Text = L"Program Start: 00:00:00";
		// 
		// button1
		// 
		this->button1->Font = (gcnew System::Drawing::Font(L"Courier New", 8.25F, System::Drawing::FontStyle::Bold, System::Drawing::GraphicsUnit::Point, 
			static_cast<System::Byte>(0)));
		this->button1->Location = System::Drawing::Point(219, 113);
		this->button1->Name = L"button1";
		this->button1->Size = System::Drawing::Size(58, 45);
		this->button1->TabIndex = 0;
		this->button1->Text = L"Test Signal";
		this->button1->UseVisualStyleBackColor = true;
		this->button1->Click += gcnew System::EventHandler(this, &Form1::button1_Click);
		// 
		// Form1
		// 
		this->AutoScaleDimensions = System::Drawing::SizeF(6, 13);
		this->AutoScaleMode = System::Windows::Forms::AutoScaleMode::Font;
		this->ClientSize = System::Drawing::Size(279, 163);
		this->Controls->Add(this->button1);
		this->Controls->Add(this->labelProgramStart);
		this->Controls->Add(this->labelStopTime);
		this->Controls->Add(this->labelStartTime);
		this->Controls->Add(this->label5);
		this->Controls->Add(this->label4);
		this->Controls->Add(this->label3);
		this->Controls->Add(this->label2);
		this->Controls->Add(this->label1);
		this->Controls->Add(this->buttonReset);
		this->Controls->Add(this->buttonStop);
		this->Controls->Add(this->buttonStart);
		this->Controls->Add(this->textSec);
		this->Controls->Add(this->textMin);
		this->Controls->Add(this->textHour);
		this->Name = L"Form1";
		this->Text = L"Count Down Timer";
		this->ResumeLayout(false);
		this->PerformLayout();

	}
#pragma endregion
  private:
    System::Void EnableComponents(System::Boolean bTaskStart);
  private:
    System::Void timerTask1_Tick(System::Object^  sender, System::EventArgs^  e);
  private:
    System::Void buttonStart_Click(System::Object^  sender, System::EventArgs^  e);
  private:
    System::Void buttonReset_Click(System::Object^  sender, System::EventArgs^  e)
    {
      this->textHour->Text = L"00";
      this->textMin->Text = L"00";
      this->textSec->Text = L"10";
    }
  private:
    System::Void buttonStop_Click(System::Object^  sender, System::EventArgs^  e)
    {
      this->EnableComponents(false);
    }

  private: 
    System::Void button1_Click(System::Object^  sender, System::EventArgs^  e) 
    {
      RunSoundThread(1);
    }

  private:
    static void DoReminder(System::Object ^oData);
    void RunSoundThread(int nTime)
    {
      Thread^ newThread = gcnew
                Thread(gcnew ParameterizedThreadStart(Form1::DoReminder));
      newThread->Start(nTime);
    }
  };
}


