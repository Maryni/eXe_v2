//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "sha224.h"
#include "Unit2.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm5 *Form5;
TForm2 *Form2;
TForm3 *Form3;
int indexD=0;
//---------------------------------------------------------------------------
__fastcall TForm5::TForm5(TComponent* Owner)
        : TForm(Owner)
{
Form5->GroupBox1->OnClick;
}
//---------------------------------------------------------------------------
void __fastcall TForm5::GroupBox1Click(TObject *Sender)
{
Label2->Caption=indexD;
Label2->Show();
}
//---------------------------------------------------------------------------

