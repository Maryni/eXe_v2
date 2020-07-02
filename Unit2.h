//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <DB.hpp>
#include <DBClient.hpp>
#include <DBLocal.hpp>
#include <DBLocalS.hpp>
#include <Provider.hpp>
#include <SqlExpr.hpp>
#include <FMTBcd.hpp>
#include <DBCtrls.hpp>

//---------------------------------------------------------------------------
class TForm2 : public TForm
{
__published:	// IDE-managed Components
        TLabel *Label1;
        TEdit *Edit1;
        TComboBox *ComboBox1;
        TLabel *Label2;
        TLabel *Label3;
        TComboBox *ComboBox2;
        TCheckBox *CheckBox1;
        TGroupBox *GroupBox1;
        TLabel *Label4;
        TEdit *Edit2;
        TCheckBox *CheckBox2;
        TLabel *Label5;
        TEdit *Edit3;
        TLabel *Label6;
        TLabel *Label7;
        TEdit *Edit4;
        TEdit *Edit5;
        TLabel *Label8;
        TLabel *Label9;
        TLabel *Label10;
        TEdit *Edit6;
        TLabel *Label11;
        TEdit *Edit7;
        TLabel *Label12;
        TEdit *Edit8;
        TLabel *Label13;
        TEdit *Edit9;
        TLabel *Label14;
        TEdit *Edit10;
        TLabel *Label15;
        TEdit *Edit11;
        TLabel *Label16;
        TLabel *Label17;
        TLabel *Label18;
        TLabel *Label19;
        TEdit *Edit12;
        TEdit *Edit13;
        TEdit *Edit14;
        TCheckBox *CheckBox3;
        TGroupBox *GroupBox2;
        TCheckBox *CheckBox4;
        TRadioButton *RadioButton1;
        TRadioButton *RadioButton2;
        TRadioButton *RadioButton3;
        TRadioButton *RadioButton4;
        TRadioButton *RadioButton5;
        TRadioButton *RadioButton6;
        TRadioButton *RadioButton7;
        TRadioButton *RadioButton8;
        TGroupBox *GroupBox3;
        TCheckBox *CheckBox5;
        TCheckBox *CheckBox6;
        TCheckBox *CheckBox7;
        TCheckBox *CheckBox8;
        TLabel *Label20;
        TComboBox *ComboBox3;
        TCheckBox *CheckBox9;
        TCheckBox *CheckBox10;
        TLabel *Label21;
        TEdit *Edit15;
        TCheckBox *CheckBox11;
        TLabel *Label22;
        TGroupBox *GroupBox4;
        TListBox *ListBox1;
        TLabel *Label23;
        TLabel *Label24;
        TLabel *Label25;
        TCheckBox *CheckBox12;
        TEdit *Edit16;
        TLabel *Label26;
        TRadioButton *RadioButton9;
        TCheckBox *CheckBox13;
        TMemo *Memo1;
        TListBox *ListBox2;
        TClientDataSet *ClientDataSet1;
        TIntegerField *ClientDataSet1id;
        TStringField *ClientDataSet1Name;
        TIntegerField *ClientDataSet1IntegerField1;
        TIntegerField *ClientDataSet1Field2;
        TIntegerField *ClientDataSet1Field3;
        TFloatField *ClientDataSet1Field4;
        TFloatField *ClientDataSet1Field5;
        TFloatField *ClientDataSet1Field6;
        TFloatField *ClientDataSet1Field7;
        TFloatField *ClientDataSet1Field8;
        TBooleanField *ClientDataSet1Field9;
        TBooleanField *ClientDataSet1Field10;
        TBooleanField *ClientDataSet1Field11;
        TBooleanField *ClientDataSet1Field12;
        TBooleanField *ClientDataSet1Field13;
        TBooleanField *ClientDataSet1BooleanField14;
        TBooleanField *ClientDataSet1Field15;
        TSQLClientDataSet *SQLClientDataSet1;
        TIntegerField *SQLClientDataSet1id;
        TSQLDataSet *SQLDataSet1;
        TIntegerField *SQLDataSet1id;
        TStringField *SQLDataSet1Name;
        TIntegerField *SQLDataSet1Field1;
        TIntegerField *SQLDataSet1Field2;
        TIntegerField *SQLDataSet1Field3;
        TFloatField *SQLDataSet1Field4;
        TFloatField *SQLDataSet1Field5;
        TFloatField *SQLDataSet1Field6;
        TFloatField *SQLDataSet1Field7;
        TFloatField *SQLDataSet1Field8;
        TBooleanField *SQLDataSet1Field9;
        TBooleanField *SQLDataSet1Field10;
        TBooleanField *SQLDataSet1Field11;
        TBooleanField *SQLDataSet1Field12;
        TBooleanField *SQLDataSet1Field13;
        TBooleanField *SQLDataSet1Field14;
        TBooleanField *SQLDataSet1Field15;
        TDataSource *DataSource1;
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall CheckBox1Click(TObject *Sender);
        void __fastcall CheckBox2Click(TObject *Sender);
        void __fastcall CheckBox3Click(TObject *Sender);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit4KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit8KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit9KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit10KeyPress(TObject *Sender, char &Key);
        void __fastcall Edit5KeyPress(TObject *Sender, char &Key);
        void __fastcall ListBox1Click(TObject *Sender);
        void __fastcall CheckBox12Click(TObject *Sender);
        void __fastcall CheckBox13Click(TObject *Sender);
        void __fastcall FormActivate(TObject *Sender);
        void __fastcall RadioButton9DblClick(TObject *Sender);
        void __fastcall GroupBox2DblClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm2(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm2 *Form2;
//---------------------------------------------------------------------------
#endif
 