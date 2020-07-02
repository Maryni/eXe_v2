//---------------------------------------------------------------------------

#include <vcl.h>
#include <iostream>
#include <cstdlib>
#include <Math.hpp>
#include <math.h>
#pragma hdrstop
using namespace std;

#include "Unit1.h"
#include "Unit3.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;
TForm3 *Form3;
double v,t,t1,t2,r,ves1list,a,spusk,str,z; double n=1;  double lists,pechat,procent,P,tech; double dopProcent=0;
double t5,P1,K2,K3,K4,t4,T; int K,K1,priladka,lak;
double kl,kk,kart,kart_1,kart_2,oth,oth_1,oth_2;
double plenka,pl1,pl2;
double price1,pl1_1,pl2_1,paper_o,paper_1kg,paper_o_price,paper_o_price_f,price_paper,paperkg;
double v_1,vbez,cost1;
double g1,g2,T_f0,T_f1;
String textS[25];
//---------------------------------------------------------------------------
__fastcall TForm3::TForm3(TComponent* Owner)
        : TForm(Owner)
{
int g=0;
     String  save="saves";
     for(int i=0;i<50;i++)
           {
                if(FileExists(save+g+".txt"))
                {
                Memo1->Clear();
                Memo1->Lines->LoadFromFile(save+g+".txt");
                        for(int i=0;i<Memo1->Lines->Count;i++)
                        {
                         textS[i]=Memo1->Lines->Strings[i];
                        }

                 ListBox2->Items->Add(textS[0]);

                        for(int i =0;i<24;i++)
                        {
                        textS[i]="";
                        }
                g++;
                }

        }
}
//---------------------------------------------------------------------------

void __fastcall TForm3::FormClose(TObject *Sender, TCloseAction &Action)
{
Application->Terminate();
}
//---------------------------------------------------------------------------





void __fastcall TForm3::CheckBox1Click(TObject *Sender)
{
if(CheckBox1->Checked==true){ComboBox1->ItemIndex=-1;ComboBox1->Visible=false;Edit3->Visible=true;Edit4->Visible=true;Edit14->Visible=true;}else {ComboBox1->Visible=true;Edit3->Visible=false;Edit4->Visible=false;Edit14->Visible=false;}
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CheckBox2Click(TObject *Sender)
{
if(CheckBox2->Checked==true){ComboBox2->ItemIndex=-1;ComboBox2->Visible=false;Edit5->Visible=true;Edit6->Visible=true;}else {ComboBox2->Visible=true;Edit5->Visible=false;Edit6->Visible=false;}
}
//---------------------------------------------------------------------------



void __fastcall TForm3::CheckBox3Click(TObject *Sender)
{
CheckBox4->Visible=true;
GroupBox3->Hide();
if(ListBox2->ItemIndex>-1)
{
int a=0; String save = "saves";
a=ListBox2->ItemIndex;

if(FileExists(save+a+".txt"))
{
 Memo1->Lines->LoadFromFile(save+a+".txt");
 for(int i=0;i<Memo1->Lines->Count;i++)
 {
 textS[i]=Memo1->Lines->Strings[i];
 }
}

  Edit1->Text=textS[1];
  Edit7->Text=textS[2];
  if(textS[3]==100)
  {
    Edit3->Text=textS[4];
    Edit4->Text=textS[5];
    Edit14->Text=textS[6];
    if(textS[7]==0){ComboBox2->ItemIndex=StrToFloat(textS[8]);}
    if(textS[7]==1){Edit5->Text=textS[8];}


    Edit29->Text=textS[9];
    ComboBox3->ItemIndex=StrToFloat(textS[10]);
    ComboBox4->ItemIndex=StrToFloat(textS[11]);

    if(textS[12]=="1") {RadioButton2->Checked=true;}
    if(textS[12]=="2") {RadioButton3->Checked=true;}

  ComboBox9->ItemIndex=StrToFloat(textS[13]);
  Edit25->Text=textS[14];
  Edit27->Text=textS[15];
  CheckListBox1->Checked[0]=StrToBool(textS[16]);
  CheckListBox1->Checked[1]=StrToBool(textS[17]);
  CheckListBox1->Checked[2]=StrToBool(textS[18]);
  CheckListBox1->Checked[3]=StrToBool(textS[19]);
  CheckListBox1->Checked[4]=StrToBool(textS[20]);
  ComboBox5->ItemIndex=StrToFloat(textS[21]);
  ComboBox6->ItemIndex=StrToFloat(textS[22]);
  ComboBox7->ItemIndex=StrToFloat(textS[23]);



  }
  if(textS[3]==200)
  {
    ComboBox1->ItemIndex=StrToFloat(textS[4]);
    if(textS[5]==0) {ComboBox2->ItemIndex=StrToFloat(textS[6]);}
    if(textS[5]==1) {Edit5->Text=textS[6];}

    Edit29->Text=textS[7];
    ComboBox3->ItemIndex=StrToFloat(textS[8]);
    ComboBox4->ItemIndex=StrToFloat(textS[9]);

    if(textS[10]=="1") {RadioButton2->Checked=true;}
    if(textS[10]=="2") {RadioButton3->Checked=true;}

    ComboBox9->ItemIndex=StrToFloat(textS[11]);
    Edit25->Text=textS[12];
    Edit27->Text=textS[13];
    CheckListBox1->Checked[0]=StrToBool(textS[14]);
    CheckListBox1->Checked[1]=StrToBool(textS[15]);
    CheckListBox1->Checked[2]=StrToBool(textS[16]);
    CheckListBox1->Checked[3]=StrToBool(textS[17]);
    CheckListBox1->Checked[4]=StrToBool(textS[18]);
    ComboBox5->ItemIndex=StrToFloat(textS[19]);
    ComboBox6->ItemIndex=StrToFloat(textS[20]);
    ComboBox7->ItemIndex=StrToFloat(textS[21]);

  }

}




Edit1->Enabled=false;
Edit7->Enabled=false;
Edit29->Enabled=false;
Edit25->Enabled=false;
Edit27->Enabled=false;
CheckListBox1->Enabled=false;
RadioButton2->Enabled=false;
RadioButton3->Enabled=false;

CheckBox1->Enabled=false;
CheckBox2->Enabled=false;
ComboBox4->Enabled=false;
ComboBox5->Enabled=false;
ComboBox6->Enabled=false;
ComboBox7->Enabled=false;
ComboBox9->Enabled=false;
z=16;
t=StrToInt(Edit1->Text);
paper_o=StrToFloat(Edit25->Text);
paper_o_price=StrToFloat(Edit27->Text);
price_paper=StrToFloat(Edit29->Text);
ComboBox1->Enabled=false; if(ComboBox1->ItemIndex==0) {t1=0.84;} else{t1=0.70;} if (ComboBox1->ItemIndex==-1){z=StrToInt(Edit14->Text);t1=StrToFloat(Edit3->Text)/100;}
ComboBox2->Enabled=false; if(ComboBox2->ItemIndex==0) {t2=0.053;} else{t2=0.045;} if (ComboBox2->ItemIndex==-1){t2=StrToFloat(Edit5->Text)/1000;}
ComboBox3->Enabled=false; if(ComboBox3->ItemIndex==0) {r=0.56;} else{r=0.578;} 


a=t1*t2*r;    ves1list=int(a*1000+0.5)/1000.0;
str=StrToFloat(Edit7->Text);
spusk=str/z; double test=spusk;
if (float(spusk)==spusk){v=spusk*t*ves1list;}
else {int(spusk);v=(spusk*t*ves1list)+((t/2)*ves1list); }

spusk=ceil(test);  
Edit2->Text=v;  Edit2->Text=Edit2->Text +" ��";               //����� ������ �� �����
if(RadioButton3->Checked==true)
   {n=500;
   if (t<=5000)procent=1.4;
   if (t>5000 && t<=10000)procent=1.3; else
   if (t>10000 && t<=15000)procent=1.2; else
   if (t>15000 && t<=25000)procent=1.1; else
   if (t>25000 && t<=50000)procent=1.0; else
   if (t>50000 && t<=100000)procent=0.9;else
   if (t>100000)procent=0.8;
   }
/* else if(RadioButton3->Checked==true)
   {n=800;
   if (t<=5000)procent=1.5;
   if (t>5000 && t<=10000)procent=1.4; else
   if (t>10000 && t<=15000)procent=1.3; else
   if (t>15000 && t<=25000)procent=1.2; else
   if (t>25000 && t<=50000)procent=1.1; else
   if (t>50000 && t<=100000)procent=1.0;else
   if (t>100000)procent=0.9;
   }
*/
if(ComboBox4->ItemIndex==0) procent=procent - 0.3;
lists=n*spusk;
Edit8->Text=lists;Edit8->Text=Edit8->Text + " �����"; //����� �� ���

pechat = (2*procent)+3.8; Edit9->Text=pechat;Edit9->Text=Edit9->Text+ " %";
dopProcent=0;
if(CheckListBox1->Checked[0]==true) {dopProcent=dopProcent+1;}
if(CheckListBox1->Checked[1]==true) {dopProcent=dopProcent+0.5;}
if(CheckListBox1->Checked[2]==true) {dopProcent=dopProcent+0.2;}
if(CheckListBox1->Checked[3]==true) {dopProcent=dopProcent+0.2;}
if(CheckListBox1->Checked[4]==true) {dopProcent=dopProcent+0.5;}
Edit10->Text=dopProcent;Edit10->Text=Edit10->Text+ " %";
P=pechat+dopProcent;

tech=((v/100)*P)+(lists*ves1list);
Edit11->Text=tech;Edit11->Text=Edit11->Text+" ��";
double onBlock=v+tech; onBlock=int(onBlock*100+0.5)/100;
Edit12->Text=onBlock;
CheckBox3->Checked=false;
if(Edit2->Text=="0 ��"){Label19->Visible=true;}

//�������
if(ComboBox1->ItemIndex==0){K4=4;}
if(ComboBox1->ItemIndex==1){K4=8;}

if(t1<=0.7){K4=4;} if(t1>=0.84) {K4=8;}
t5=t/K4; Edit15->Text=t5; Edit15->Text=Edit15->Text + " �";
if(ComboBox7->ItemIndex==0){K3=0.75;}
if(ComboBox7->ItemIndex==1){K3=1;}
if (ComboBox5->ItemIndex==0) {K=4;}
if (ComboBox5->ItemIndex==1) {K=5;}
if (ComboBox5->ItemIndex==2) {K=6;}
if (ComboBox5->ItemIndex==-1) {Label19->Visible=true;}
if (ComboBox6->ItemIndex==0)
{  K1=30;
  if (t5<100) {K2=6.7;}
  if (t5>=100 && t5<200) {K2=5.7;}
  if (t5>=200 && t5<300) {K2=5.0;}
  if (t5>=300 && t5<400) {K2=4.8;}
  if (t5>=400 && t5<500) {K2=4.6;}
  if (t5>=500 && t5<1000) {K2=3.5;}
  if (t5>=1000 && t5<2000) {K2=2.8;}
  if (t5>=2000 && t5<3000) {K2=2.0;}
  if (t5>=3000 && t5<4000) {K2=1.6;}
  if (t5>=4000 && t5<5000) {K2=1.4;}
  if (t5>=5000 && t5<10000) {K2=1.1;}
  if (t5>=10000 && t5<=25000) {K2=1.0;}
  if (t5>25000) {K2=0.9;}
}
if (ComboBox6->ItemIndex==1)
{  K1=20;
  if (t5<100) {K2=5.7;}
  if (t5>=100 && t5<200) {K2=4.8;}
  if (t5>=200 && t5<300) {K2=3.7;}
  if (t5>=300 && t5<400) {K2=3.5;}
  if (t5>=400 && t5<500) {K2=3.3;}
  if (t5>=500 && t5<1000) {K2=2.7;}
  if (t5>=1000 && t5<2000) {K2=2.2;}
  if (t5>=2000 && t5<3000) {K2=1.9;}
  if (t5>=3000 && t5<4000) {K2=1.7;}
  if (t5>=4000 && t5<5000) {K2=1.5;}
  if (t5>=5000 && t5<10000) {K2=0.8;}
  if (t5>=10000 && t5<=25000) {K2=0.7;}
  if (t5>25000) {K2=0.5;}
}
if (ComboBox6->ItemIndex==2)
{K1=25;
  if (t5<100) {K2=3.1;}
  if (t5>=100 && t5<200) {K2=3.0;}
  if (t5>=200 && t5<300) {K2=2.9;}
  if (t5>=300 && t5<400) {K2=2.8;}
  if (t5>=400 && t5<500) {K2=2.7;}
  if (t5>=500 && t5<1000) {K2=2.5;}
  if (t5>=1000 && t5<2000) {K2=2.1;}
  if (t5>=2000 && t5<3000) {K2=1.7;}
  if (t5>=3000 && t5<4000) {K2=1.5;}
  if (t5>=4000 && t5<5000) {K2=1.3;}
  if (t5>=5000 && t5<10000) {K2=0.6;}
  if (t5>=10000 && t5<=25000) {K2=0.5;}
  if (t5>25000) {K2=0.4;}
}

priladka = K1*K; Edit16->Text=priladka;Edit16->Text=Edit16->Text + " �";
P1=((t5/100)*((K2+0.4)*5));Edit17->Text=P1;Edit17->Text=Edit17->Text + " �";
t4=ceil(P1+priladka);
Edit18->Text=t4;Edit18->Text=Edit18->Text + " �";


lak=ceil((t5/100)*K3);Edit19->Text=lak;Edit19->Text=Edit19->Text + " �";
T=t5+t4+lak;Edit20->Text=T;Edit20->Text=Edit20->Text+" �";

//������

if(CheckListBox1->Checked[4]==true)
   { switch(ComboBox9->ItemIndex)
       {
     case 0: kart_1=1000.0/105.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800.0/146.0;oth_2=kart_2;kart_2=SimpleRoundTo(kart_2,0);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 1: kart_1=1000.0/105.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/171;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 2: kart_1=1000.0/105.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/183;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 3: kart_1=1000.0/116.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/171;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 4: kart_1=1000.0/126.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/171;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 5: kart_1=1000.0/126.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/206;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 6: kart_1=1000.0/141.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/206;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 7: kart_1=1000.0/141.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/221;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 8: kart_1=1000.0/166.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/221;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 9: kart_1=1000.0/178.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/261;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 10: kart_1=1000.0/166.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=800/246;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.85;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 11: kart_1=1000.0/166.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/266;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1); oth=oth*t;break;
     case 12: kart_1=1000.0/201.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/266;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1);oth=oth*t;break;
     case 13: kart_1=1000.0/201.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/296;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1);oth=oth*t;break;
     case 14: kart_1=1000.0/216.0;oth_1=kart_1;kart_1=floor(kart_1);oth_1=oth_1-kart_1;kart_2=900/296;oth_2=kart_2;kart_2=floor(kart_2);oth_2=oth_2 - kart_2; oth=oth_1+oth_2; kart=kart_1 * kart_2;kl=(t*2)/kart;kl=floor(kl);kl=kl+((kl/100.0)*5);kk=kl*0.96;kk=SimpleRoundTo(kk,-1);oth=oth*t;break;
       }
     Edit13->Text=kl;Edit13->Text=Edit13->Text+ " �";
     Edit21->Text=kk;Edit21->Text=Edit21->Text+ " ��";
     oth=SimpleRoundTo(oth/1000,-2);Edit22->Text=oth; Edit22->Text=Edit22->Text+" ��";
   }
// ������
 if (ComboBox7->ItemIndex==1)
       {
         switch (ComboBox9->ItemIndex)
         {
          case 0:pl1=107;pl2=140;break;
          case 1:pl1=107;pl2=165;break;
          case 2:pl1=107;pl2=177;break;
          case 3:pl1=118;pl2=165;break;
          case 4:pl1=128;pl2=165;break;
          case 5:pl1=128;pl2=200;break;
          case 6:pl1=143;pl2=200;break;
          case 7:pl1=143;pl2=215;break;
          case 8:pl1=168;pl2=215;break;
          case 9:pl1=180;pl2=255;break;
          case 10:pl1=168;pl2=240;break;
          case 11:pl1=168;pl2=260;break;
          case 12:pl1=203;pl2=260;break;
          case 13:pl1=203;pl2=290;break;
          case 14:pl1=218;pl2=290;break;
         }
         pl1=(pl1*2)+32;pl2=pl2+30;
         plenka=((pl1/1000)*(pl2/1000))*t*1.15;
         plenka=ceil(plenka);
         Edit23->Text=plenka;
         Edit23->Text=Edit23->Text+" �.��.";
       }
//����

 switch (ComboBox9->ItemIndex)
     {                                                    //�������
          case 0:pl1=107;pl2=140;g1=0.6;g2=0.90;break;
          case 1:pl1=107;pl2=165;g1=0.7;g2=0.90;break;
          case 2:pl1=107;pl2=177;g1=0.75;g2=0.90;break;
          case 3:pl1=118;pl2=165;g1=0.70;g2=1.00;break;
          case 4:pl1=128;pl2=165;g1=0.70;g2=1.08;break;
          case 5:pl1=128;pl2=200;g1=0.84;g2=1.08;break;
          case 6:pl1=143;pl2=200;g1=0.60;g2=0.84;break;
          case 7:pl1=143;pl2=215;g1=0.60;g2=0.90;break;
          case 8:pl1=168;pl2=215;g1=0.70;g2=0.90;break;
          case 9:pl1=180;pl2=255;g1=0.75;g2=0.90;break;
          case 10:pl1=168;pl2=240;g1=0.70;g2=1.00;break;
          case 11:pl1=168;pl2=260;g1=0.70;g2=1.08;break;
          case 12:pl1=203;pl2=260;g1=0.84;g2=1.08;break;
          case 13:pl1=203;pl2=290;g1=0.60;g2=0.84;break;
          case 14:pl1=218;pl2=290;g1=0.60;g2=0.90;break;
     }
         pl1_1=pl1/1000;pl2_1=pl2/1000;paper_o=paper_o/1000;
         paper_1kg=pl1_1*pl2_1*paper_o;  paper_o_price_f=paper_1kg*paper_o_price;

         paperkg=StrToFloat(Edit12->Text); price1=paperkg*price_paper;
         vbez=price1+paper_o_price_f;
         v_1=vbez*1.2;                                       //�� 1 ��
         cost1=v_1/t; cost1=SimpleRoundTo(cost1,-2);
        Edit24->Text=cost1; Edit24->Text=Edit24->Text+" ���";

        

        paper_o=StrToFloat(Edit25->Text);
        paper_o=paper_o/1000;
        T_f0=T;   //������ �� ����� + ��� ����� + ���������/�����
        T_f1=T_f0*g1*g2*paper_o;
        T_f1=SimpleRoundTo(T_f1,-2);
        Edit31->Text=T_f1; Edit31->Text=Edit31->Text+" �";
 
   
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CheckBox4Click(TObject *Sender)
{
Edit1->Enabled=true;Edit1->Text="";
Edit2->Enabled=true;Edit2->Text="";
Edit7->Enabled=true;Edit7->Text="";
Edit8->Enabled=true;Edit8->Text="";
Edit9->Enabled=true;Edit9->Text="";
Edit10->Enabled=true;Edit10->Text="";
Edit11->Enabled=true;Edit11->Text="";
Edit12->Enabled=true;Edit12->Text="";
Edit14->Enabled=true;Edit14->Text="";
Edit15->Enabled=true;Edit15->Text="";
Edit16->Enabled=true;Edit16->Text="";
Edit17->Enabled=true;Edit17->Text="";
Edit18->Enabled=true;Edit18->Text="";
Edit19->Enabled=true;Edit19->Text="";
Edit20->Enabled=true;Edit20->Text="";
Edit3->Enabled=true;Edit3->Text="";
Edit4->Enabled=true;Edit4->Text="";
Edit5->Enabled=true;Edit5->Text="";
Edit14->Enabled=true;Edit14->Text="";
Edit13->Enabled=true;Edit13->Text="";
Edit21->Enabled=true;Edit21->Text="";
Edit22->Enabled=true;Edit22->Text="";
Edit24->Enabled=true;Edit24->Text="";
Edit25->Enabled=true;Edit25->Text="";
Edit27->Enabled=true;Edit27->Text="";
Edit29->Enabled=true;Edit29->Text="";
Edit31->Enabled=true;Edit31->Text="";

ComboBox1->ItemIndex=-1;ComboBox1->Enabled=true;
ComboBox2->ItemIndex=-1;ComboBox2->Enabled=true;
ComboBox3->ItemIndex=-1;ComboBox3->Enabled=true;
ComboBox4->ItemIndex=-1;ComboBox4->Enabled=true;
ComboBox5->ItemIndex=-1;ComboBox5->Enabled=true;
ComboBox6->ItemIndex=-1;ComboBox6->Enabled=true;
ComboBox7->ItemIndex=-1;ComboBox7->Enabled=true;
ComboBox9->ItemIndex=-1;ComboBox9->Enabled=true;
CheckBox3->Checked=false;CheckBox4->Checked=false;
CheckBox4->Checked=false;CheckBox4->Visible=false;
RadioButton2->Checked=false;
RadioButton3->Checked=false;
CheckListBox1->Checked[0]=false;
CheckListBox1->Checked[1]=false;
CheckListBox1->Checked[2]=false;
CheckListBox1->Checked[3]=false;
CheckListBox1->Checked[4]=false;
CheckBox1->Enabled=true;CheckBox1->Checked=false;
CheckBox2->Enabled=true;CheckBox2->Checked=false;Label19->Visible=false;
}
//---------------------------------------------------------------------------








void __fastcall TForm3::CheckBox5Click(TObject *Sender)
{
GroupBox3->Show();
CheckBox6->Show();




//Edit1->Text=5000;
//Edit7->Text=100;
//ComboBox1->ItemIndex=0;
//ComboBox2->ItemIndex=0;
//ComboBox3->ItemIndex=0;
//ComboBox4->ItemIndex=0;
//RadioButton3->Checked=true;
//ComboBox9->ItemIndex=0;
//Edit29->Text=10;
//Edit25->Text=100;
//Edit27->Text=100;
                //CheckListBox1->Checked[0]=true;
                //CheckListBox1->Checked[1]=true;
                //CheckListBox1->Checked[2]=true;
                //CheckListBox1->Checked[3]=true;
                //CheckListBox1->Checked[4]=true;
//ComboBox5->ItemIndex=0;
//ComboBox6->ItemIndex=0;
//ComboBox7->ItemIndex=0;
}
//---------------------------------------------------------------------------

void __fastcall TForm3::CheckBox13Click(TObject *Sender)
{
int j=0;  String save="saves";

GroupBox3->Hide();

  String saveName;
  saveName = Edit32->Text;
  String saves[24];
  saves[0]=saveName;
  saves[1]=Edit1->Text;
  saves[2]=Edit7->Text;
  if(CheckBox1->Checked==true)
  {
    saves[3] = 100;
    saves[4] = Edit3->Text;
    saves[5] = Edit4->Text;
    saves[6] = Edit14->Text;
  }else   {saves[3]=200; saves[4]=ComboBox1->ItemIndex;  }
   if(CheckBox1->Checked==true && CheckBox2->Checked==true )
  {  saves[7]=1;
     saves[8] = Edit5->Text;
  }else  if(CheckBox1->Checked == false&&CheckBox2->Checked==true) {saves[3]=200;saves[4] = ComboBox1->ItemIndex; saves[5]=1;saves[6]=Edit5->Text; }else
  if (CheckBox1->Checked == false&&CheckBox2->Checked==false)
        {
        saves[3]=200;
        saves[4]=ComboBox1->ItemIndex;
        saves[5]=0;
        saves[6]=ComboBox2->ItemIndex;
        }
  if(CheckBox1->Checked==false)
  {
  saves[7]=Edit29->Text;
  saves[8]=ComboBox3->ItemIndex;
  saves[9]=ComboBox4->ItemIndex;

  if(RadioButton2->Checked)saves[10]="1";
  if(RadioButton3->Checked)saves[10]="2";

  saves[11]=ComboBox9->ItemIndex;
  saves[12]=Edit25->Text;
  saves[13]=Edit27->Text;
  saves[14]=BoolToStr(CheckListBox1->Checked[0]);
  saves[15]=BoolToStr(CheckListBox1->Checked[1]);
  saves[16]=BoolToStr(CheckListBox1->Checked[2]);
  saves[17]=BoolToStr(CheckListBox1->Checked[3]);
  saves[18]=BoolToStr(CheckListBox1->Checked[4]);
  saves[19]=ComboBox5->ItemIndex;
  saves[20]=ComboBox6->ItemIndex;
  saves[21]=ComboBox7->ItemIndex;
  }else
    {
  saves[9]=Edit29->Text;
  saves[10]=ComboBox3->ItemIndex;
  saves[11]=ComboBox4->ItemIndex;

  if(RadioButton2->Checked)saves[12]="1";
  if(RadioButton3->Checked)saves[12]="2";

  saves[13]=ComboBox9->ItemIndex;
  saves[14]=Edit25->Text;
  saves[15]=Edit27->Text;
  saves[16]=BoolToStr(CheckListBox1->Checked[0]);
  saves[17]=BoolToStr(CheckListBox1->Checked[1]);
  saves[18]=BoolToStr(CheckListBox1->Checked[2]);
  saves[19]=BoolToStr(CheckListBox1->Checked[3]);
  saves[20]=BoolToStr(CheckListBox1->Checked[4]);
  saves[21]=ComboBox5->ItemIndex;
  saves[22]=ComboBox6->ItemIndex;
  saves[23]=ComboBox7->ItemIndex;
    }
        Memo1->Clear();
        for(int i =0;i<25;i++)
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

void __fastcall TForm3::CheckBox7Click(TObject *Sender)
{
GroupBox2->Hide();
}
//---------------------------------------------------------------------------


