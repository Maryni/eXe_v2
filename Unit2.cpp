//---------------------------------------------------------------------------

#include <vcl.h>
#include <Math.hpp>
#include <math.h>
#pragma hdrstop

#include "Unit1.h"
#include "Unit2.h"

//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TForm2 *Form2;

extern int indexD;
int F;   double vbez,v,pdv,t,t1,t2,k,norm1,druk1,cost1,paper1,costdruk,costpaper;
double a,a1,a2,a3,a4,a5,a6,a7,a8,a9;
double mg,mo,L1,L2,bum,Day,Ukr,z1,z2,z3;
String textSS[16];
//---------------------------------------------------------------------------
__fastcall TForm2::TForm2(TComponent* Owner)
        : TForm(Owner)
{       int g=0;
     String  save="save";
     for(int i=0;i<50;i++)
           {
                if(FileExists(save+g+".txt"))
                {
                Memo1->Clear();
                Memo1->Lines->LoadFromFile(save+g+".txt");
                for(int i=0;i<Memo1->Lines->Count;i++)
                {
                textSS[i]=Memo1->Lines->Strings[i];
                }

                ListBox2->Items->Add(textSS[0]);

                for(int i =0;i<15;i++)
                {
                textSS[i]="";
                }
                g++;
        }

 }



}
//---------------------------------------------------------------------------

void __fastcall TForm2::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox1Click(TObject *Sender)
{  //if(Edit1->Text!="") {t=StrToFloat(Edit1->Text);}
   ComboBox2->Clear();


   switch (ComboBox1->ItemIndex)
 {
  case 0: k=5;ComboBox2->Items->Add("48(1+1)");ComboBox2->Items->Add("8(2+1)40(1+1)");ComboBox2->Items->Add("16(2+2)32(1+1)");ComboBox2->Items->Add("32(2+1)16(1+1)");ComboBox2->Items->Add("40(2+1)8(1+1)");ComboBox2->Items->Add("48(2+1)");break;
  case 1: k=5;ComboBox2->Items->Add("44(1+1)");ComboBox2->Items->Add("4(2+1)40(1+1)");ComboBox2->Items->Add("16(2+2)28(1+1)");ComboBox2->Items->Add("32(2+1)12(1+1)");ComboBox2->Items->Add("40(2+1)4(1+1)"); ComboBox2->Items->Add("44(2+1)");break;
  case 2: k=4.2;ComboBox2->Items->Add("40(1+1)");ComboBox2->Items->Add("8(2+1)32(1+1)");ComboBox2->Items->Add("16(2+1)24(1+1)");ComboBox2->Items->Add("24(2+1)16(1+1)");ComboBox2->Items->Add("32(2+1)8(1+1)");ComboBox2->Items->Add("40(2+1)");ComboBox2->Items->Add("8(4+1)24(2+1)8(1+1)");ComboBox2->Items->Add("8(4+1)32(2+1)");ComboBox2->Items->Add("8(4+2)32(2+1)");break;
  case 3: k=4.2;ComboBox2->Items->Add("36(1+1)");ComboBox2->Items->Add("4(2+1)32(1+1)");ComboBox2->Items->Add("12(2+1)24(1+1)");ComboBox2->Items->Add("24(2+1)12(1+1)");ComboBox2->Items->Add("32(2+1)4(1+1)");ComboBox2->Items->Add("36(2+1)");ComboBox2->Items->Add("8(4+1)24(2+1)4(1+1)");ComboBox2->Items->Add("8(4+1)28(2+1)");ComboBox2->Items->Add("8(4+2)28(2+1)");break;
  case 4: k=3.4;ComboBox2->Items->Add("32(1+1)");ComboBox2->Items->Add("8(2+1)24(1+1)");ComboBox2->Items->Add("16(2+1)16(1+1)");ComboBox2->Items->Add("24(2+1)8(1+1)");ComboBox2->Items->Add("32(2+1)");ComboBox2->Items->Add("8(4+1)16(2+1)8(1+1)");ComboBox2->Items->Add("8(4+1)24(2+1)");ComboBox2->Items->Add("16(4+1)8(2+1)8(1+1)");ComboBox2->Items->Add("16(4+1)16(2+1)");ComboBox2->Items->Add("8(4+2)8(4+1)16(2+1)");ComboBox2->Items->Add("16(4+2)16(2+1)");break;
  case 5: k=3.4;ComboBox2->Items->Add("28(1+1)");ComboBox2->Items->Add("8(2+1)20(1+1)");ComboBox2->Items->Add("16(2+1)12(1+1)");ComboBox2->Items->Add("24(2+1)4(1+1)");ComboBox2->Items->Add("28(2+1)");ComboBox2->Items->Add("8(4+1)16(2+1)4(1+1)");ComboBox2->Items->Add("8(4+1)20(2+1)");ComboBox2->Items->Add("16(4+1)8(2+1)4(1+1)");ComboBox2->Items->Add("16(4+1)12(2+1)");ComboBox2->Items->Add("8(4+2)8(4+1)12(2+1)");ComboBox2->Items->Add("16(4+2)12(2+1)");break;
  case 6: k=2.6;ComboBox2->Items->Add("24(1+1)");ComboBox2->Items->Add("8(2+1)16(1+1) ");ComboBox2->Items->Add("16(2+1)8(1+1)");ComboBox2->Items->Add("24(2+1)");ComboBox2->Items->Add("8(4+1)16(1+1)");ComboBox2->Items->Add("8(4+1)8(2+1)8(1+1)");ComboBox2->Items->Add("8(4+1)16(2+1)");ComboBox2->Items->Add("16(4+1)8(1+1)");ComboBox2->Items->Add("16(4+1)8(2+1)");ComboBox2->Items->Add("24(4+1)");ComboBox2->Items->Add("8(4+2)16(4+1)");ComboBox2->Items->Add("16(4+2)8(4+1)");ComboBox2->Items->Add("24(4+2)");break;
  case 7: k=2.6;ComboBox2->Items->Add("20(1+1)");ComboBox2->Items->Add("8(2+1)12(1+1)");ComboBox2->Items->Add("16(2+1)4(1+1)");ComboBox2->Items->Add("20(2+1)");ComboBox2->Items->Add("8(4+1)8(2+1)4(1+1)");ComboBox2->Items->Add("8(4+1)12(2+1)");ComboBox2->Items->Add("16(4+1)4(1+1)");ComboBox2->Items->Add("16(4+1)4(2+1)");ComboBox2->Items->Add("20(4+1)");ComboBox2->Items->Add("8(4+2)12(4+1)");ComboBox2->Items->Add("16(4+2)4(4+1)");ComboBox2->Items->Add("20(4+2)");break;
  case 8: k=1.8;ComboBox2->Items->Add("16(1+1)");ComboBox2->Items->Add("8(2+1)8(1+1)");ComboBox2->Items->Add("16(2+1)");ComboBox2->Items->Add("8(2+2)8(2+1)");ComboBox2->Items->Add("16(2+2)");ComboBox2->Items->Add("8(4+2)8(2+1)");ComboBox2->Items->Add("8(4+4)8(1+1)");ComboBox2->Items->Add("8(4+4)8(2+1)");ComboBox2->Items->Add("8(4+1)8(1+1)");ComboBox2->Items->Add("16(4+2)");ComboBox2->Items->Add("8(4+4)8(4+1)");ComboBox2->Items->Add("8(4+4)8(4+2)");break;
  case 9: k=1.8;ComboBox2->Items->Add("12(1+1)");ComboBox2->Items->Add("8(2+1)4(1+1)");ComboBox2->Items->Add("12(2+1)");ComboBox2->Items->Add("8(2+2)4(2+1)");ComboBox2->Items->Add("12(2+2)");ComboBox2->Items->Add("8(4+2)4(2+1)");ComboBox2->Items->Add("8(4+4)4(1+1)");ComboBox2->Items->Add("8(4+4)4(2+1)");ComboBox2->Items->Add("12(4+2)");ComboBox2->Items->Add("8(4+4)4(4+1)");ComboBox2->Items->Add("8(4+4)4(4+2)");break;
  case 10: k=1;ComboBox2->Items->Add("8(1+0)");ComboBox2->Items->Add("8(2+0)");ComboBox2->Items->Add("8(1+1)");ComboBox2->Items->Add("8(2+1)");ComboBox2->Items->Add("8(2+2)");ComboBox2->Items->Add("8(4+1)");ComboBox2->Items->Add("8(4+2)");ComboBox2->Items->Add("8(4+3)");ComboBox2->Items->Add("8(4+4)");break;
  
 }
   

 
}
//---------------------------------------------------------------------------



void __fastcall TForm2::CheckBox2Click(TObject *Sender)
{
if(ListBox2->ItemIndex>-1)
        {
 int a=0; String save = "save";
 a=ListBox2->ItemIndex;
if(FileExists(save+a+".txt"))
{
 Memo1->Lines->LoadFromFile(save+a+".txt");
 for(int i=0;i<Memo1->Lines->Count;i++)
 {
 textSS[i]=Memo1->Lines->Strings[i];
 }
}

   Edit1->Text =textSS[1];
   ComboBox1->ItemIndex=StrToFloat(textSS[2]);
   CheckBox1->Checked=true;
   ComboBox2->ItemIndex=StrToFloat(textSS[3]);
   Edit4->Text=textSS[4];
   Edit5->Text=textSS[5];
   Edit8->Text=textSS[6];
   Edit9->Text=textSS[7];
   Edit10->Text=textSS[8];
   CheckBox5->Checked=StrToBool(textSS[9]);
   CheckBox6->Checked=StrToBool(textSS[10]);
   CheckBox7->Checked=StrToBool(textSS[11]);
   CheckBox10->Checked=StrToBool(textSS[12]);
   CheckBox9->Checked=StrToBool(textSS[13]);
   CheckBox8->Checked=StrToBool(textSS[14]);
   ComboBox3->ItemIndex=StrToFloat(textSS[15]);
        } RadioButton9->Checked=false;
        
if(Edit1->Text!="") {t=StrToFloat(Edit1->Text);}
if (CheckBox8->Checked==true) {t=t/2;t=ceil(t);}

   if (t>0 && t<=3000) {
   a=90;a1=100;a2=95;a3=110;a4=120;a5=130;a6=150;a7=170;a8=200;a9=220;
     if(CheckBox11->Checked==true)
{
     if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.44615;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.491309;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.536467;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.626784;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.671942;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.717101;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.158971;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.200366;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.241762;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.324552;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.365947;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.407342;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.796528;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.83416;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.871792;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.909424;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.947056;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.984688;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=3.02232;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=3.059952;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=3.097584;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.516875;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.550744;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.584613;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.618482;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.65235;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.686219;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.720088;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.753957;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.787826;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.177011;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.207117;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.237222;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.267328;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.297434;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.327539;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.357645;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.38775;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.417856;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.447962;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.478067;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.904885;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.931227;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.95757;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.983912;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.010254;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.036597;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.062939;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.089282;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.115624;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.141966;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.168309;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.5876;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.610179;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.632758;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.655338;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.655338;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.677917;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.7004966;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.723075;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.745654;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.790813;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.813392;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.835971;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.85855;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.323;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.341816;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.360632;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.379448;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.398264;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.41708;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.435896;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.454712;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.492344;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.51116;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.529976;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.548792;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.028294;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.043347;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.0584;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.073453;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.088506;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.103558;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.118611;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.133664;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.073453;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.148717;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.16377;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.178822;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.771221;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.78251;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.7938;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.80509;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.816379;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.827669;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.838958;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.850248;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.861538;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.872827;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.884117;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.491568;t2=235;F=1;cost1=a;break;
     case 1: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.506621;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.514147;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.521674;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.5292;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.536726;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.544253;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
}
   }
   if (t>3000 && t<=6000) {a=50;a1=60;a2=55;a3=65;a4=70;a5=80;a6=90;a7=100;a8=110;a9=120;
    if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.412282;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.454618;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.496954;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.581626;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.623962;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.666298;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.127925;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.166733;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.205541;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.283157;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.321965;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.360773;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.773008;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.808288;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.843568;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.878848;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.914128;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.949408;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.984688;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=3.019968;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=3.055248;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.495707;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.527459;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.559211;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.590963;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.622715;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.654467;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.686219;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.717971;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.749723;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.161958;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.190182207117;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.218406;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.24663;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.274854;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.303078;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.331302;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.359526;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.38775;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.415974;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.444198;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.891714;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.91641;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.941106;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.965802;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.990498;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.015194;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.03989;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.064586;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.089282;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.113978;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.138674;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.579133;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.600301;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.621469;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.642637;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.642637;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.663805;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.684973;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.706141;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.727309;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.769645;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.790813;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.811981;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.833149;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.315944;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.333584;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.351224;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.368864;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.386504;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.404144;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.421784;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.439424;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.474704;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.492344;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.509984;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.527624;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.024531;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.038643;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.052755;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.066867;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.080979;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.095091;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.109203;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.123315;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.066867;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.137427;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.151539;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.165651;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.7683398;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.778982;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.789566;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.80015;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.810734;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.821318;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.831902;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.842486;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.85307;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.863654;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.874238;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.491098;t2=235;F=1;cost1=a;break;
     case 1: t1=0.498154;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.498154;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.50521;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.512266;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.519322;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.526378;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.533434;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.54049;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }
   if (t>6000 && t<=10000) {a=30;a1=40;a2=35;a3=45;a4=50;a5=55;a6=60;a7=65;a8=70;a9=80;
   if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.378413;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.417926;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.45744;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.536467;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.575981;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.615494;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.096878;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.1333099;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.16932;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.241762;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.277982;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.314203;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.749488;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.782416;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.815344;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.848272;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.8812;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.914128;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.947056;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.979984;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=3.012912;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.474539;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.504174;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.53381;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.563445;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.59308;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.622715;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.65235;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.681986;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.711621;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.146906;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.173248;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.19959;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.225933;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.252275;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.278618;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.30496;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.331302;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.357645;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.383987;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.41033;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.878542;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.901592;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.924642;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.947691;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.970741;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=1.99379;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.01684;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.03989;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.062939;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.085989;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.109038;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.570665;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.590422;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.610179;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.629936;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.629936;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.649693;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.66945;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.689206;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.708963;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.748477;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.768234;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.78799;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.807747;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.308888;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.325352;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.341816;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.35828;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.374744;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.391208;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.407672;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.424136;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.457064;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.473528;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.489992;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.506456;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.020768;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.033939;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.04711;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.060282;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.073453;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.086624;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.099795;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.112966;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.060282;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.126138;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.139309;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.15248;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.765576;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.775454;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.785333;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.795211;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.80509;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.814968;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.824846;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.834725;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.844603;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.854482;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.864369;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.490627;t2=235;F=1;cost1=a;break;
     case 1: t1=0.497213;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.497213;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.503798;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.510384;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.51697;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.523555;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.530141;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.536726;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }
   if (t>10000 && t<=25000) {a=28;a1=32;a2=30;a3=40;a4=45;a5=50;a6=55;a7=60;a8=65;a9=70;
    if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.344544;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.381235;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.417926;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.491309;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.528;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.564691;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.065832;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.099466;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.133099;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.200366;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.234;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.267634;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.725968;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.756544;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.78712;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.817696;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.848272;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.878848;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.909424;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.94;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.970578;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.453371;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.48089;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.508408;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.535926;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.563445;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.590963;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.618482;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.646;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.673518;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.131853;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.156314;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.180774;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.205235;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.229696;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.254157;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.278618;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.303078;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.327539;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.352447962;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.376461;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.865371;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.886774;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.908178;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.929581;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.9950984;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=1.972387;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=1.99379;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.015194;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.036597;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.058;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.079403;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.562198;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.580544;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.59889;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.617235;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.617235;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.635581;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.653926;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.672272723075;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.690618;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.727309;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.745654;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.764;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.782346;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.301832;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.31712;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.332408;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.347696;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.362984;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.378272;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.39356;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.408848;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.439424;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.454712;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.47;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.485288;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.017005;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.029235;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.041466;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.053696;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.065926;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.078157;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.090387;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.102618;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.053696;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.114848;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.127078;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.139309;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.762754;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.771926;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.781099;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.790272;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.799445;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.808618;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.81779;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.826963;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.836136;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.845309;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.854482;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.490157;t2=235;F=1;cost1=a;break;
     case 1: t1=0.496272;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.496272;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.502387;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.508502;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.514618;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.520733;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.526848;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.532963;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }
   if (t>25000 && t<=50000) {a=25;a1=30;a2=27;a3=36;a4=38;a5=40;a6=45;a7=50;a8=55;a9=60;
    if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.310675;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.344544;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.378413;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.44615;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.480019;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.513888;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.034786;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.065832;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.096878;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.158971;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.190018;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3,221064;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.702448;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.730672;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.758896;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.78712;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.815344;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.843568;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.871792;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.900016;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.92824;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.432203;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.457605;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.483006;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.508408;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.53381;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.559211;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.584613;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.610014;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.635416;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.1168;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.139379;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.161958;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.184538;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.207117;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.229696;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.252275;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.274854;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.297434;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.320013;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.342592;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.8522904885;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.871957;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.891714;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.91147;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.931227;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=1.950984;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=1.970741;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=1.990498;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.010254;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.030011;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.049768;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.553731;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.570666;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.5876;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.604534;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.604534;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.621469;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.638403;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.655338;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.672272;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.7906141;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.723075;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.74001;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.756944;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.294776;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.308888;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.323;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.337112;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.351224;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.365336;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.379448;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.39356;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.421784;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.435806;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.450008;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.464120548792;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.013242;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.024531;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.035821;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.04711;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.0584;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.06969;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.080979;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.092269;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.04711;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.103558;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.1114848;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.126138;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.759931;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.768398;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.776866;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.785333;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.7938;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.802267;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.810734;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.819202;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.827669;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.836136;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.844603;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.489686;t2=235;F=1;cost1=a;break;
     case 1: t1=0.495331;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.495331;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.500976;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.506621;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.512266;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.51791;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.523555;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.5292;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }
   if (t>50000 && t<=100000) {a=22;a1=28;a2=24;a3=32;a4=34;a5=36;a6=38;a7=40;a8=44;a9=52;
   if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.242938;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.271162;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.299386;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.355834;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.384058;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.412282;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.972693;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=2.998565;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.024437;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.076181;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.102053;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.127925;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.655408;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.678928;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.702448;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.725968;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.749488;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.773008;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.796528;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.820048;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.843568;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.389867;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.411035;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.432203;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.453371;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.474539;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.495707;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.516875;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.538043;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.559211;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.086694;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.10551;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.124326;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.143142;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.161958;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.180774;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.19959;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.218406;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.237222;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.256038;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.274854;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.825858904885;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.842322;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.858786;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.87525;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.891714;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=1.908178;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=1.924642;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=1.941106;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=1.95757;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=1.974034;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=1.990498;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.536797;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.550909;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.565021;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.579133;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.579133;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.593245;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.607357;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.621469;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.635581;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.663805;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.677917;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.692029;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.706141;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.280664;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.292424;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.304184;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.315944;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.327704;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.339464;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.351224;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.362984;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.386504;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.398264;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.410024;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.421784;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.005715;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.0115123;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.024531;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.033939;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.043347;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.052755;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.062163;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.071571;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.033939;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.080079;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.090387;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.099795;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.754286;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.761342;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.768398;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.775454;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.78251;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.789566;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.796622;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.803678;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.810734;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.81779;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.824846;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.488746;t2=235;F=1;cost1=a;break;
     case 1: t1=0.49345;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.49345;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.498154;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.502858;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.507562;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.512266;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.51697;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.521674;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }
   if (t>100000) {a=20;a1=22;a2=21;a3=26;a4=30;a5=34;a6=36;a7=39;a8=42;a9=46;
    if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.209069;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.23447;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.259872;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.310675;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.336077;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.361478;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.941646;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=2.964931;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=2.988216;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.034786;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.05807;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.081355;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.631888;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.653056;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.674224;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.695392;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.71656;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.737728;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.758896;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.780064;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.801232;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.368699;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.38775;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.406802;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.425853;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.444904;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.463955;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.483006;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.502058;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.521109;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.071642;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.088576;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.10551;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.122445;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.139379;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.156314;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.173248;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.190182;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.207117;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.224051;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.240986;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.812686;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.827504;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.842322;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.857139;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=1.871957;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=1.886774;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=1.901592;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=1.91641;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=1.931227;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=1.946045;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=1.960862;t2=4234;F=18;cost1=a7*2+a3*2;break;                                     //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.52833;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.54103;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.553731;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.566432;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.566432;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.579133;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.591834;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.604534;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.617235;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.642637;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.655338;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.668038;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.680739;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.273608;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.284192;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.294776;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.30536;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.315944;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.326528;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.337112;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.347696;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.368864;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.379448;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.390032;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.400616;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.001952;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.0110419;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.018886;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.027354;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.035821;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.044288;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.052755;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.061222;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.027354;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.06969;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.078157;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.086624;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.751464;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.757814;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.764165;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.770515;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.776866;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.783216;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.789566;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.795917;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.802267;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.808618;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.814968;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.488275;t2=235;F=1;cost1=a;break;
     case 1: t1=0.492509;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.492509;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.496742;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.500976;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.50521;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.509443;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.513677;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.51791;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }
   }

CheckBox2->Checked=false;
mg=StrToInt(Edit4->Text);
mo=StrToInt(Edit5->Text);
L1=StrToFloat(Edit8->Text);
L2=StrToFloat(Edit9->Text);
bum=StrToFloat(Edit10->Text);
if (ComboBox1->ItemIndex==0)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.344544;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.381235;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.417926;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.491309;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.528;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.564691;t2=4234;F=18;cost1=a3*6;break;
                                                                                                //48
   }
  }
  if (ComboBox1->ItemIndex==1)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=3.065832;t2=2822;F=12;cost1=a2*5;break;
     case 1: t1=3.099466;t2=3058;F=13;cost1=a2*4.2+a3;break;
     case 2: t1=3.133099;t2=3293;F=14;cost1=a4*2+a2*3.4;break;
     case 3: t1=3.200366;t2=3763;F=16;cost1=a3*4+a2*1.8;break;
     case 4: t1=3.234;t2=3998;F=17;cost1=a3*5+a2;break;
     case 5: t1=3.267634;t2=4234;F=18;cost1=a3*6;break;                                           //44
   }
  }
  if (ComboBox1->ItemIndex==2)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.725968;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.756544;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.78712;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.817696;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.848272;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.878848;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.909424;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.94;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.970578;t2=4234;F=18;cost1=a7+a3*4;break;                                        //40
   }
  }
  if (ComboBox1->ItemIndex==3)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.453371;t2=2352;F=10;cost1=a2*4.2;break;
     case 1: t1=2.48089;t2=2587;F=11;cost1=a2*3.4+a3;break;
     case 2: t1=2.508408;t2=2822;F=12;cost1=a3*2+a2*2.6;break;
     case 3: t1=2.535926;t2=3058;F=13;cost1=a3*3+a2*1.8;break;
     case 4: t1=2.563445;t2=3293;F=14;cost1=a3*4+a2;break;
     case 5: t1=2.590963;t2=3528;F=15;cost1=a3*5;break;
     case 6: t1=2.618482;t2=3763;F=16;cost1=a6+a3*3+a2;break;
     case 7: t1=2.646;t2=3998;F=17;cost1=a6+a3*4;break;
     case 8: t1=2.673518;t2=4234;F=18;cost1=a7+a3*4;break;                                    //36
   }
  }
  if (ComboBox1->ItemIndex==4)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=2.177011;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=2.207117;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=2.237222;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=2.267328;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.297434;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.327539;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.357645;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.38775;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.417856;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.447962;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.478067;t2=4234;F=18;cost1=a7*2+a3*2;break;                                    //32
   }
  }
  if (ComboBox1->ItemIndex==5)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.904885;t2=1882;F=8;cost1=a2*3.4;break;
     case 1: t1=1.931227;t2=2117;F=9;cost1=a2*2.6+a3;break;
     case 2: t1=1.95757;t2=2352;F=10;cost1=a3*2+a2*1.8;break;
     case 3: t1=1.983912;t2=2587;F=11;cost1=a3*3+a2;break;
     case 4: t1=2.010254;t2=2822;F=12;cost1=a3*4;break;
     case 5: t1=2.036597;t2=3058;F=13;cost1=a6+a3*2+a2;break;
     case 6: t1=2.062939;t2=3293;F=14;cost1=a6+a3*3;break;
     case 7: t1=2.089282;t2=3528;F=15;cost1=a6*2+a3+a2;break;
     case 8: t1=2.115624;t2=3763;F=16;cost1=a6*2+a3*2;break;
     case 9: t1=2.141966;t2=3998;F=17;cost1=a7+a6+a3*2;break;
     case 10: t1=2.168309;t2=4234;F=18;cost1=a7*2+a3*2;break;                                        //28
   }
  }
  if (ComboBox1->ItemIndex==6)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.5876;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.610179;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.632758;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.655338;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.655338;t2=2117;F=9;cost1=a6+a2*2;break;
     case 5: t1=1.677917;t2=2352;F=10;cost1=a6+a3+a2;break;
     case 6: t1=1.7004966;t2=2587;F=11;cost1=a6+a3*2;break;
     case 7: t1=1.723075;t2=2822;F=12;cost1=a6*2+a2;break;
     case 8: t1=1.745654;t2=3058;F=13;cost1=a6*2+a3;break;
     case 9: t1=1.790813;t2=3528;F=15;cost1=a6*3;break;
     case 10: t1=1.813392;t2=3763;F=16;cost1=a7+a6*2;break;
     case 11: t1=1.835971;t2=3998;F=17;cost1=a7*2+a6;break;
     case 12: t1=1.85855;t2=4234;F=18;cost1=a7*3;break;                                     //24
   }
  }
  if (ComboBox1->ItemIndex==7)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.323;t2=1411;F=6;cost1=a2*2.6;break;
     case 1: t1=1.341816;t2=1646;F=7;cost1=a2*1.8+a3;break;
     case 2: t1=1.360632;t2=1882;F=8;cost1=a3*2+a2;break;
     case 3: t1=1.379448;t2=2117;F=9;cost1=a3*3;break;
     case 4: t1=1.398264;t2=2352;F=10;cost1=a6+a2*2;break;
     case 5: t1=1.41708;t2=2587;F=11;cost1=a6+a3+a2;break;
     case 6: t1=1.435896;t2=2822;F=12;cost1=a6*2+a2;break;
     case 7: t1=1.454712;t2=3058;F=13;cost1=a6*2+a3;break;
     case 8: t1=1.492344;t2=3528;F=15;cost1=a6*3;break;
     case 9: t1=1.51116;t2=3763;F=16;cost1=a7+a6*2;break;
     case 10: t1=1.529976;t2=3998;F=17;cost1=a7*2+a6;break;
     case 11: t1=1.548792;t2=4234;F=18;cost1=a7*3;break;                                  //20
   }
  }
  if (ComboBox1->ItemIndex==8)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=1.028294;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=1.043347;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=1.0584;t2=1508;F=6;cost1=a3*2;break;
     case 3: t1=1.073453;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=1.088506;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=1.103558;t2=2262;F=9;cost1=a7+a3;break;
     case 6: t1=1.118611;t2=2514;F=10;cost1=a9+a2;break;
     case 7: t1=1.133664;t2=2765;F=11;cost1=a9+a3;break;
     case 8: t1=1.073453;t2=1646;F=7;cost1=a6+a2;break;
     case 9: t1=1.148717;t2=3016;F=12;cost1=a7*2;break;
     case 10: t1=1.16377;t2=3268;F=13;cost1=a9+a6;break;
     case 11: t1=1.178822;t2=3519;F=14;cost1=a9+a7;break;                                    //16

   }
  }
  if (ComboBox1->ItemIndex==9)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.771221;t2=941;F=4;cost1=a2*1.8;break;
     case 1: t1=0.78251;t2=1176;F=5;cost1=a3+a2;break;
     case 2: t1=0.7938;t2=1411;F=6;cost1=a3*2;break;
     case 3: t1=0.80509;t2=1646;F=7;cost1=a4+a3;break;
     case 4: t1=0.816379;t2=1882;F=8;cost1=a4*2;break;
     case 5: t1=0.827669;t2=2117;F=9;cost1=a7+a3;break;
     case 6: t1=0.838958;t2=2352;F=10;cost1=a9+a2;break;
     case 7: t1=0.850248;t2=2587;F=11;cost1=a9+a3;break;
     case 8: t1=0.861538;t2=2822;F=12;cost1=a7*2;break;
     case 9: t1=0.872827;t2=3058;F=13;cost1=a9+a6;break;
     case 10: t1=0.884117;t2=3293;F=14;cost1=a9+a7;break;                                //12
   }
  }
  if (ComboBox1->ItemIndex==10)
  {
  switch (ComboBox2->ItemIndex)
   { case 0: t1=0.491568;t2=235;F=1;cost1=a;break;
     case 1: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.506621;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.514147;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.521674;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.5292;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.536726;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.544253;t2=1882;F=8;cost1=a9;break;                                   //8
   }
  }

if(RadioButton1->Checked==true){t1=0.514618;t2=1176;F=5;cost1=a6;RadioButton1->Checked=false;}
if(RadioButton2->Checked==true){t1=0.514618;t2=1176;F=5;cost1=a6;RadioButton1->Checked=false;}
if(RadioButton3->Checked==true){t1=1.029235;t2=1176;F=5;cost1=a3+a2;RadioButton1->Checked=false;}
if(RadioButton4->Checked==true)  {t1=1.017005;t2=941;F=4;cost1=a2*1.8;RadioButton1->Checked=false;}
if(RadioButton5->Checked==true)  {t1=1.017005;t2=941;F=4;cost1=a2*1.8;RadioButton1->Checked=false;}
if(RadioButton6->Checked==true){t1=1.017005;t2=941;F=4;cost1=a2*1.8;RadioButton1->Checked=false;}
if(RadioButton7->Checked==true){t1=0.785333;t2=1646;F=7;cost1=a4+a3;RadioButton1->Checked=false;}
if(RadioButton8->Checked==true){t1=0.502387;t2=706;F=3;cost1=a3;RadioButton1->Checked=false;}
if(CheckBox7->Checked==true) {t1=1.017005;t2=941;F=4;cost1=a2*1.8;}
if(CheckBox9->Checked==true && CheckBox5->Checked==true || CheckBox6->Checked==true)
{
switch(ComboBox3->ItemIndex)
  {
    case 0: t1=0.490157;t2=235;F=1;cost1=a;break;
     case 1: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 2: t1=0.499094;t2=470;F=2;cost1=a2;break;
     case 3: t1=0.502387;t2=706;F=3;cost1=a3;break;
     case 4: t1=0.508502;t2=941;F=4;cost1=a4;break;
     case 5: t1=0.514618;t2=1176;F=5;cost1=a6;break;
     case 6: t1=0.520733;t2=1411;F=6;cost1=a7;break;
     case 7: t1=0.526848;t2=1646;F=7;cost1=a8;break;
     case 8: t1=0.532963;t2=1882;F=8;cost1=a9;break;
  }
}
if (CheckBox11->Checked==true)
{
if(RadioButton1->Checked==true && t<=3000){t1=0.521674;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>3000 && t<=6000){t1=0.519322;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>6000 && t<=10000){t1=0.51697;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>10000 && t<=25000){t1=0.514618;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>25000 && t<=50000){t1=0.512266;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>50000 && t<=100000){t1=0.507562;t2=1176;F=5;cost1=a6;} else if(RadioButton1->Checked==true && t>100000){t1=0.50521;t2=1176;F=5;cost1=a6;}
if(RadioButton2->Checked==true && t<=3000){t1=0.514618;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>3000 && t<=6000){t1=0.519322;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>6000 && t<=10000){t1=0.51697;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>10000 && t<=25000){t1=0.514618;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>25000 && t<=50000){t1=0.512266;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>50000 && t<=100000){t1=0.507562;t2=1176;F=5;cost1=a6;} else if(RadioButton2->Checked==true && t>100000){t1=0.50521;t2=1176;F=5;cost1=a6;}
if(RadioButton3->Checked==true && t<=3000){t1=1.043347;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>3000 && t<=6000){t1=1.038643;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>6000 && t<=10000){t1=1.033939;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>10000 && t<=25000){t1=1.029235;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>25000 && t<=50000){t1=1.024531;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>50000 && t<=100000){t1=1.0115123;t2=1176;F=5;cost1=a3+a2;} else if(RadioButton3->Checked==true && t>100000){t1=1.0110419;t2=1176;F=5;cost1=a3+a2;}
if(RadioButton4->Checked==true && t<=3000)  {t1=1.028294;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>3000 && t<=6000)  {t1=1.024531;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>6000 && t<=10000)  {t1=1.020768;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>10000 && t<=25000)  {t1=1.017005;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>25000 && t<=50000)  {t1=1.013242;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>50000 && t<=100000)  {t1=1.005715;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>100000)  {t1=1.001952;t2=941;F=4;cost1=a2*1.8;}
if(RadioButton5->Checked==true && t<=3000)  {t1=1.028294;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>3000 && t<=6000)  {t1=1.024531;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>6000 && t<=10000)  {t1=1.020768;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>10000 && t<=25000)  {t1=1.017005;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>25000 && t<=50000)  {t1=1.013242;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>50000 && t<=100000)  {t1=1.005715;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>100000)  {t1=1.001952;t2=941;F=4;cost1=a2*1.8;}
if(RadioButton6->Checked==true && t<=3000){t1=1.028294;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>3000 && t<=6000)  {t1=1.024531;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>6000 && t<=10000)  {t1=1.020768;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>10000 && t<=25000)  {t1=1.017005;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>25000 && t<=50000)  {t1=1.013242;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>50000 && t<=100000)  {t1=1.005715;t2=941;F=4;cost1=a2*1.8;} else if(RadioButton4->Checked==true && t>100000)  {t1=1.001952;t2=941;F=4;cost1=a2*1.8;}
if(RadioButton7->Checked==true && t<=3000){t1=0.80509;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>3000 && t<=6000){t1=0.80015;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>6000 && t<=10000){t1=0.795211;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>10000 && t<=25000){t1=0.790272;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>25000 && t<=50000){t1=0.785333;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>50000 && t<=100000){t1=0.775454;t2=1646;F=7;cost1=a4+a3;} else if(RadioButton7->Checked==true && t>100000){t1=0.770515;t2=1646;F=7;cost1=a4+a3;}
if(RadioButton8->Checked==true && t<=3000){t1=0.506621;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>3000 && t<=6000){t1=0.50521;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>6000 && t<=10000){t1=0.503798;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>10000 && t<=25000){t1=0.502387;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>25000 && t<=50000){t1=0.500976;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>50000 && t<=100000){t1=0.498154;t2=706;F=3;cost1=a3;} else if(RadioButton8->Checked==true && t>100000){t1=0.496742;t2=706;F=3;cost1=a3;}
//if(CheckBox7->Checked==true && t<=3000) {t1=1.017005;t2=941;F=4;cost1=a2*1.8;}

}

norm1=(((t*t1)+t2)/t)*1000; norm1=SimpleRoundTo(norm1,-1);  Edit2->Text=norm1; Edit2->Text=Edit2->Text+" кг";

druk1=F*k; Edit3->Text=druk1; Edit3->Text=cost1;  Edit3->Text=Edit3->Text+" грн";
paper1=((norm1*t)/1000)*(mg/1000);paper1=SimpleRoundTo(paper1,0); Edit6->Text=paper1;
costdruk=(F*L1*4+paper1/1000*L2+cost1*t/1000);costdruk=SimpleRoundTo(costdruk,-2);Edit7->Text=costdruk;
costpaper=paper1*bum;costpaper=SimpleRoundTo(costpaper,-2);Edit11->Text=costpaper;
vbez=costdruk+costpaper;vbez=SimpleRoundTo(vbez,-2); Edit12->Text=vbez;
if(CheckBox10->Checked==true) {vbez=vbez+(t*0.3);}
v=vbez*1.2;v=SimpleRoundTo(v,-2); Edit13->Text=v;
pdv=v-vbez;pdv=SimpleRoundTo(pdv,-2); Edit14->Text=pdv;

double price1 = v/t;  price1=SimpleRoundTo(price1,-3);  Edit15->Text=price1;
CheckBox12->Show();
}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox3Click(TObject *Sender)
{
  Edit1->Text="";
  Edit2->Text="";
  Edit3->Text="";
  Edit6->Text="";
  Edit7->Text="";
  Edit11->Text="";
  Edit12->Text="";
  Edit13->Text="";
  Edit14->Text="";
  Edit15->Text="";
  CheckBox1->Checked=false;
  ComboBox1->ItemIndex=-1;
  RadioButton1->Checked=false;
  RadioButton2->Checked=false;
  RadioButton3->Checked=false;
  RadioButton4->Checked=false;
  RadioButton5->Checked=false;
  RadioButton6->Checked=false;
  RadioButton7->Checked=false;
  RadioButton8->Checked=false;

}
//---------------------------------------------------------------------------






void __fastcall TForm2::Edit1KeyPress(TObject *Sender, char &Key)
{
if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit4KeyPress(TObject *Sender, char &Key)
{
if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;        
}
//---------------------------------------------------------------------------



void __fastcall TForm2::Edit8KeyPress(TObject *Sender, char &Key)
{
if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit9KeyPress(TObject *Sender, char &Key)
{
if((Key!=VK_BACK)&&(Key<'0'||Key>'9'))Key=0;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit10KeyPress(TObject *Sender, char &Key)
{
 if ((Key >= '0') && (Key <= '9'))
    return;
  if ( (Key == ',') && (!Edit10->Text.AnsiPos(",")))
    return;
  if (Key == VK_BACK) 
    return;
  Beep();
  Key = 0;
}
//---------------------------------------------------------------------------

void __fastcall TForm2::Edit5KeyPress(TObject *Sender, char &Key)
{
if((Key!=VK_BACK)&&(Key<'0'||Key>'9')&&(Edit5->Text=="0" && Key=='0'))Key=0;        
}
//---------------------------------------------------------------------------

void __fastcall TForm2::ListBox1Click(TObject *Sender)
{

if (ListBox1->ItemIndex==0){Label1->Font->Size=12;Label2->Font->Size=12;Label3->Font->Size=12;Label4->Font->Size=12;Label5->Font->Size=12;Label6->Font->Size=12;Label7->Font->Size=12;Label8->Font->Size=12;Label9->Font->Size=12;Label10->Font->Size=12;Label11->Font->Size=12;Label12->Font->Size=12;Label13->Font->Size=12;Label14->Font->Size=12;Label15->Font->Size=12;Label17->Font->Size=12;Label18->Font->Size=12;Label19->Font->Size=12;Label20->Font->Size=12;Label21->Font->Size=12;CheckBox1->Font->Size=12;CheckBox2->Font->Size=12;CheckBox3->Font->Size=12;CheckBox4->Font->Size=12;CheckBox5->Font->Size=12;CheckBox6->Font->Size=12;CheckBox7->Font->Size=12;CheckBox8->Font->Size=12;CheckBox9->Font->Size=12;CheckBox10->Font->Size=12;CheckBox11->Font->Size=12;RadioButton1->Font->Size=12;RadioButton2->Font->Size=12;RadioButton3->Font->Size=12;RadioButton4->Font->Size=12;RadioButton5->Font->Size=12;RadioButton6->Font->Size=12;
RadioButton7->Font->Size=12;RadioButton8->Font->Size=12;}
if (ListBox1->ItemIndex==1){Label1->Font->Size=10;Label2->Font->Size=10;Label3->Font->Size=10;Label4->Font->Size=10;Label5->Font->Size=10;Label6->Font->Size=10;Label7->Font->Size=10;Label8->Font->Size=10;Label9->Font->Size=10;Label10->Font->Size=10;Label11->Font->Size=10;Label12->Font->Size=10;Label13->Font->Size=10;Label14->Font->Size=10;Label15->Font->Size=10;Label17->Font->Size=10;Label18->Font->Size=10;Label19->Font->Size=10;Label20->Font->Size=10;Label21->Font->Size=10;CheckBox1->Font->Size=10;CheckBox2->Font->Size=10;CheckBox3->Font->Size=10;CheckBox4->Font->Size=10;CheckBox5->Font->Size=10;CheckBox6->Font->Size=10;CheckBox7->Font->Size=10;CheckBox8->Font->Size=10;CheckBox9->Font->Size=10;CheckBox10->Font->Size=10;CheckBox11->Font->Size=10;RadioButton1->Font->Size=10;RadioButton2->Font->Size=10;RadioButton3->Font->Size=10;RadioButton4->Font->Size=10;RadioButton5->Font->Size=10;RadioButton6->Font->Size=10;
RadioButton7->Font->Size=10;RadioButton8->Font->Size=10;}
}
//---------------------------------------------------------------------------



void __fastcall TForm2::CheckBox12Click(TObject *Sender)
{
if(Edit1->Text!="" && ComboBox1->ItemIndex!=-1 && ComboBox2->ItemIndex!=-1)
        {
         CheckBox12->Checked=false;
         CheckBox12->Hide();
         CheckBox13->Show();
         Label26->Show();
         Edit16->Show();
        } else
        ShowMessage("Вы ввели не все данные");


}
//---------------------------------------------------------------------------

void __fastcall TForm2::CheckBox13Click(TObject *Sender)
{       int j=0;  String save="save";

        CheckBox13->Hide();
         Label26->Hide();
         Edit16->Hide();

  String saveName;
  saveName = Edit16->Text;
  String saves[16];
  saves[0]=saveName;
  saves[1]=Edit1->Text;
  saves[2]=ComboBox1->ItemIndex;
  saves[3]=ComboBox2->ItemIndex;
  saves[4]=Edit4->Text;
  saves[5]=Edit5->Text;
  saves[6]=Edit8->Text;
  saves[7]=Edit9->Text;
  saves[8]=Edit10->Text;
  saves[9]=BoolToStr(CheckBox5->Checked);
  saves[10]=BoolToStr(CheckBox6->Checked);
  saves[11]=BoolToStr(CheckBox7->Checked);
  saves[12]=BoolToStr(CheckBox10->Checked);
  saves[13]=BoolToStr(CheckBox9->Checked);
  saves[14]=BoolToStr(CheckBox8->Checked);
  saves[15]=ComboBox3->ItemIndex;
  RadioButton9->Caption=saveName;
  RadioButton9->Show();
        Memo1->Clear();
        for(int i =0;i<16;i++)
        {
        Memo1->Lines->Add(saves[i]);
        }
           for(int i=0;i<50;i++)
           {
                if(FileExists(save+j+".txt")) j++;
            }
        Memo1->Lines->SaveToFile(save+j+".txt");
        j++;
}
//---------------------------------------------------------------------------



void __fastcall TForm2::FormActivate(TObject *Sender)
{
//if(FileExists("save.txt"))
 //{
   //RadioButton9->Show();
   //Memo1->Lines->LoadFromFile("save.txt");
   //RadioButton9->Caption=Memo1->Lines->IndexOf(0);
   //Edit1->Text =Memo1->Lines->IndexOf(1);
   //ComboBox1->ItemIndex=Memo1->Lines->IndexOf(2);
   //ComboBox2->ItemIndex=Memo1->Lines->IndexOf(3);
   //Edit4->Text=Memo1->Lines->IndexOf(4);
   //Edit5->Text=Memo1->Lines->IndexOf(5);
   //Edit8->Text=Memo1->Lines->IndexOf(6);
   //Edit9->Text=Memo1->Lines->IndexOf(7);
   //Edit10->Text=Memo1->Lines->IndexOf(8);
   //CheckBox5->Checked=StrToBool(Memo1->Lines->IndexOf(9));
   //CheckBox6->Checked=StrToBool(Memo1->Lines->IndexOf(10));
   //CheckBox7->Checked=StrToBool(Memo1->Lines->IndexOf(11));
   //CheckBox10->Checked=StrToBool(Memo1->Lines->IndexOf(12));
   //CheckBox9->Checked=StrToBool(Memo1->Lines->IndexOf(13));
   //CheckBox8->Checked=StrToBool(Memo1->Lines->IndexOf(14));
   //ComboBox3->ItemIndex=Memo1->Lines->IndexOf(15);;
  //}
}
//---------------------------------------------------------------------------

void __fastcall TForm2::RadioButton9DblClick(TObject *Sender)
{
Memo1->Visible==true  ? Memo1->Hide() : Memo1->Show();


}
//---------------------------------------------------------------------------





void __fastcall TForm2::GroupBox2DblClick(TObject *Sender)
{
  Memo1->Show();      
}
//---------------------------------------------------------------------------


