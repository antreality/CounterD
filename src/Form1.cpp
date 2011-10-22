#include "stdafx.h"
#include "Form1.h"

using namespace CounterD;

Form1::Form1()
{
  InitializeComponent();
  TimeFormatStr = "dd-MMM-yyyy hh:mm:ss";
  bHourlySound = true; // temporarily set to true before adding option setting dlg

  this->Text = "CountD: " + System::DateTime::Now.ToString("dd-MMM-yyyy hh:mm:ss tt");
  System::String^ timeStr = System::DateTime::Now.ToString(TimeFormatStr);
  this->labelStartTime->Text = "Last Start: NA";
  this->labelStopTime->Text = "Last Stop: NA";
  this->labelProgramStart->Text = "Program Start: " + timeStr;
  this->timerTask1->Interval = 1000; // millisec
  this->timerTask1->Enabled = true;

  /*
  this->backgroundWorker = gcnew System::ComponentModel::BackgroundWorker; 
  backgroundWorker->DoWork += gcnew DoWorkEventHandler( this, &Form1::backgroundWorker_DoWork ); 
  this->backgroundWorker->WorkerReportsProgress = false;
  this->backgroundWorker->WorkerSupportsCancellation = false;
  */
}

System::Void Form1::EnableComponents(System::Boolean bTaskStart)
{
  if (bTaskStart == true)
  {
    this->buttonStart->Enabled = false;
    this->buttonReset->Enabled = false;
    this->buttonStop->Enabled = true;

    this->textHour->ReadOnly = true;
    this->textMin->ReadOnly = true;
    this->textSec->ReadOnly = true;

    bCountDown = true;

    this->labelStartTime->Text = "Last Start: "
      + System::DateTime::Now.ToString(TimeFormatStr);
  }
  else
  {
    this->buttonStart->Enabled = true;
    this->buttonReset->Enabled = true;
    this->buttonStop->Enabled = false;

    this->textHour->ReadOnly = false;
    this->textMin->ReadOnly = false;
    this->textSec->ReadOnly = false;

    bCountDown = false;

    this->labelStopTime->Text = "Last Stop: "
      + System::DateTime::Now.ToString(TimeFormatStr);
  }
}

System::Void Form1::timerTask1_Tick(System::Object^  sender, System::EventArgs^  e)
{
  // Clock Function
  this->Text = System::DateTime::Now.ToString("hh:mm:ss tt dd-MMM-yyyy") + " [CountD]";
  if (bHourlySound && !(System::DateTime::Now.Minute) && !(System::DateTime::Now.Second))
  {
    DoReminder(2);
  }    
  // Count Down Function
  if (!bCountDown) return;
  i32TotalTime--;
  if (i32TotalTime == 0)
  {
    this->textSec->Text = L"00";
    this->EnableComponents(false);
    
    DoReminder(3);
    // Start the asynchronous operation.
    //this->backgroundWorker->RunWorkerAsync();
    return;
  }
  //this->Text = L"Count Down Timer " + i32TotalTime.ToString();

  if (0 == i32Sec)
  {
    i32Sec = 59;
    if (0 == i32Min)
    {
      if (0 != i32Hour)
      {
        i32Min = 59;
        i32Hour--;
        this->textHour->Text = i32Hour.ToString("D2");
      }
    }
    else
    {
      i32Min--;
    }
    this->textMin->Text = i32Min.ToString("D2");
  }
  else
  {
    i32Sec--;
  }
  this->textSec->Text = i32Sec.ToString("D2");

  /*i32Sec = (i32TotalTime % 3600) % 60;
  i32Hour = i32TotalTime / 3600;
  i32Min = (i32TotalTime % 3600) / 60;*/
}

System::Void Form1::buttonStart_Click(System::Object^  sender, System::EventArgs^  e)
{
  i32Hour = Int32::Parse(this->textHour->Text);
  i32Min = Int32::Parse(this->textMin->Text);
  i32Sec = Int32::Parse(this->textSec->Text);
  if (i32Hour < 0 || i32Min < 0 || i32Sec < 0)
	  return; // do nothing
  i32TotalTime = i32Hour * 3600 + i32Min * 60 + i32Sec;
  if (i32TotalTime == 0) // do nothing
    return;

  this->textHour->Text = i32Hour.ToString("D2");
  this->textMin->Text = i32Min.ToString("D2");
  this->textSec->Text = i32Sec.ToString("D2");

  this->EnableComponents(true);
  DoReminder(1);
}

System::Void Form1::DoReminder(int nTime)
{
  SoundPlayer ^sndPlayer = gcnew SoundPlayer();
  sndPlayer->SoundLocation = System::Environment::GetEnvironmentVariable("WINDIR") + "\\Media\\Chimes.wav";
  //this->Text = System::Environment::GetEnvironmentVariable("WINDIR"); // debug
  for (int i = 0; i < nTime; i++)
  {    
    //SystemSounds::Asterisk->Play();
    //PlaySound((LPCTSTR)SND_ALIAS_SYSTEMASTERISK, NULL, SND_ALIAS_ID);
    sndPlayer->PlaySync();
    //sndPlayer->Play();
  }
}