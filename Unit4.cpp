//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit4.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm4 *Form4;

int g=0,i=0;
//---------------------------------------------------------------------------
__fastcall TForm4::TForm4(TComponent* Owner)
        : TForm(Owner)
{
     Edit1->Text="admin";
     Edit2->Text="0000";
     Form4->Image2->OnClick;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer1Timer(TObject *Sender)
{
if(CheckBox1->Checked==false) Close();
else Timer1->Enabled=false;
}
//---------------------------------------------------------------------------



void __fastcall TForm4::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------







void __fastcall TForm4::Timer2Timer(TObject *Sender)
{
ProgressBar1->Position=ProgressBar1->Position-1;
if(ProgressBar1->Position=='0') Timer2->Enabled=false;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Image2Click(TObject *Sender)
{
if (Edit1->Text=="admin" || Edit1->Text=="Milly" || Edit1->Text=="sergo")
   {
    if (Edit2->Text=="0000" || Edit2->Text=="ser120170" || Edit2->Text=="andrey50604280499")
      {  Timer1->Enabled=false;
        Form1->Show();Form4->Hide();
      } else {ShowMessage("Incorrect password"); i++;Edit3->Visible=true;Edit3->Text=i;Edit2->Text="";}
   }
        else ShowMessage("Incorrect login");
    if (Edit2->Text=="" || Edit1->Text==""){i++;Edit3->Visible=true;Edit3->Text=i;}
   if(i==3)Application->Terminate();
}

//---------------------------------------------------------------------------


void __fastcall TForm4::Image2MouseMove(TObject *Sender, TShiftState Shift,
      int X, int Y)
{
Image2->Picture->LoadFromFile("\PolyCall_Phon3.bmp");
}
//---------------------------------------------------------------------------





void __fastcall TForm4::Label4MouseLeave(TObject *Sender)
{
Label4->Color=clWhite;
Label4->Font->Color=clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Label4Click(TObject *Sender)
{
if (Edit1->Text=="admin" || Edit1->Text=="Milly" || Edit1->Text=="sergo")
   {
    if (Edit2->Text=="0000" ||Edit2->Text=="ser120170" || Edit2->Text=="andrey50604280499")
      {  Timer1->Enabled=false;
        Form1->Show();Form4->Hide();
      } else {Label5->Caption="Incorrect password"; i++;Edit3->Visible=true;Edit3->Text=i; Edit2->Text="";}
   }  else Label5->Caption="Incorrect login";
    if (Edit2->Text=="" || Edit1->Text==""){i++;Edit3->Visible=true;Edit3->Text=i;}
   if(i==4)Application->Terminate();
}
//---------------------------------------------------------------------------


void __fastcall TForm4::Timer3Timer(TObject *Sender)
{
if(Edit1->Left!=200){Edit1->Left=Edit1->Left-1;}
if(Edit2->Left!=200){Edit2->Left=Edit2->Left-1;}
if(Edit3->Left!=328){Edit3->Left=Edit3->Left-1;}
if(Label1->Left!=120){Label1->Left=Label1->Left+1;}
if(Label2->Left!=120){Label2->Left=Label2->Left+1;}
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Timer4Timer(TObject *Sender)
{ 
if(Label4->Left!=336){Label4->Left=Label4->Left-1;}


}
//---------------------------------------------------------------------------

void __fastcall TForm4::Label3Click(TObject *Sender)
{
if (Edit4->Visible==false){Edit4->Visible=true;return;}
if (Edit4->Visible==true){Edit4->Visible=false;return;}
/*ShellExecute(Handle,
                 "open",
                 "http://www.borland.com/",
                 NULL,NULL,SW_SHOWDEFAULT); */
}
//---------------------------------------------------------------------------




void __fastcall TForm4::Edit2KeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
   if(Key == VK_RETURN)
    {
     if (Edit1->Text=="admin" || Edit1->Text=="Milly" || Edit1->Text=="sergo")
   {
    if (Edit2->Text=="0000" ||Edit2->Text=="ser120170" || Edit2->Text=="andrey50604280499")
      {  Timer1->Enabled=false;
        Form1->Show();Form4->Hide();
      } else {Label5->Caption="Incorrect password"; i++;Edit3->Visible=true;Edit3->Text=i;Edit2->Text="";}
   }  else Label5->Caption="Incorrect login";
    if (Edit2->Text=="" || Edit1->Text==""){i++;Edit3->Visible=true;Edit3->Text=i;}
   if(i==4)Application->Terminate();
    }
}
//---------------------------------------------------------------------------

void __fastcall TForm4::Label4MouseEnter(TObject *Sender)
{
Label4->Color=clNavy;
Label4->Font->Color=clCream;        
}
//---------------------------------------------------------------------------



