//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TForm2 *Form2;
TForm3 *Form3;
//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1Click(TObject *Sender)
{
Form2->Show();
Form1->Hide();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2Click(TObject *Sender)
{
Form3->Show();
Form1->Hide();        
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1MouseEnter(TObject *Sender)
{
Label1->Color=clNavy;
Label1->Font->Color=clCream;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label1MouseLeave(TObject *Sender)
{
Label1->Color=clWhite;
Label1->Font->Color=clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2MouseLeave(TObject *Sender)
{
 Label2->Color=clWhite;
Label2->Font->Color=clBlack;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Label2MouseEnter(TObject *Sender)
{
 Label2->Color=clNavy;
Label2->Font->Color=clCream;
}
//---------------------------------------------------------------------------

