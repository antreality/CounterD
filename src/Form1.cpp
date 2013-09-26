#include "stdafx.h"
#include "Form1.h"

using namespace CounterD;

Form1::Form1()
{
  InitializeComponent();
  TimeFormatStr = "dd-MMM-yyyy hh:mm:ss";
  bHourlySound = true; // temporarily set to true before adding option setting dlg
  bMidTimeSound = true; // true for now. TODO: configurable through UI.
  u32MidTime = 0;

  this->Text = "CountD: " + System::DateTime::Now.ToString("dd-MMM-yyyy hh:mm:ss tt");
  System::String^ timeStr = System::DateTime::Now.ToString(TimeFormatStr);
  this->labelStartTime->Text = "Last Start: NA";
  this->labelStopTime->Text = "Last Stop: NA";
  this->labelProgramStart->Text = "Program Start: " + timeStr;
  this->timerTask1->Interval = 1000; // millisec
  this->timerTask1->Enabled = true;
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
    RunSoundThread(2);
  }    
  // Count Down Function
  if (!bCountDown) return;
  u32TotalTime--;
  if (u32TotalTime == 0)
  {
    this->textSec->Text = L"00";
    this->EnableComponents(false);
    RunSoundThread(3);
    return;
  }

  // Mid Time up check
  if (bMidTimeSound && u32MidTime && u32TotalTime == u32MidTime)
  {
    RunSoundThread(1); //DoReminder(1);
    u32MidTime = 0; // reset
  }
  //this->Text = L"Count Down Timer " + u32TotalTime.ToString();

  if (0 == u32Sec)
  {
    u32Sec = 59;
    if (0 == u32Min)
    {
      if (0 != u32Hour)
      {
        u32Min = 59;
        u32Hour--;
        this->textHour->Text = u32Hour.ToString("D2");
      }
    }
    else
    {
      u32Min--;
    }
    this->textMin->Text = u32Min.ToString("D2");
  }
  else
  {
    u32Sec--;
  }
  this->textSec->Text = u32Sec.ToString("D2");

  /*u32Sec = (u32TotalTime % 3600) % 60;
  u32Hour = u32TotalTime / 3600;
  u32Min = (u32TotalTime % 3600) / 60;*/
}

System::Void Form1::buttonStart_Click(System::Object^  sender, System::EventArgs^  e)
{
  try
  {
    u32Hour = UInt32::Parse(this->textHour->Text);
    u32Min = UInt32::Parse(this->textMin->Text);
    u32Sec = UInt32::Parse(this->textSec->Text);
    u32TotalTime = u32Hour * 3600 + u32Min * 60 + u32Sec;
    if (u32TotalTime >= 2)
    {
      u32MidTime = u32TotalTime / 2; // Integer division
    }
    if (u32TotalTime != 0) // do nothing
    {
  this->EnableComponents(true);
  DoReminder(1);
}
  }
  catch(...)
  {
    // finally block will do reset to zero of all fields
  }
  finally
  {
    this->textHour->Text = u32Hour.ToString("D2");
    this->textMin->Text = u32Min.ToString("D2");
    this->textSec->Text = u32Sec.ToString("D2");
  }  
}

void Form1::DoReminder(System::Object ^oData)
{
  SoundPlayer ^sndPlayer = gcnew SoundPlayer();
  sndPlayer->SoundLocation = System::Environment::GetEnvironmentVariable("WINDIR") + "\\Media\\Chimes.wav";
  //this->Text = System::Environment::GetEnvironmentVariable("WINDIR"); // debug
  int nTime = (int) oData;
  for (int i = 0; i < nTime; i++)
  {    
    //SystemSounds::Asterisk->Play();
    //PlaySound((LPCTSTR)SND_ALIAS_SYSTEMASTERISK, NULL, SND_ALIAS_ID);
    sndPlayer->PlaySync();
    //sndPlayer->Play();
    //System::Threading::Thread::Sleep(500);
  }
}