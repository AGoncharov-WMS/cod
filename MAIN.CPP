//---------------------------------------------------------------------------
#include <vcl.h>
#pragma hdrstop

#include "main.h"
#include "registry.hpp"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

extern int Col1=-1,Row1=-1,kk=0,tim=0,n=3,m=9,nom=1;
extern char sm=' ';

void CheckOnReg(void)
{
 TRegistry *Reg=new TRegistry;
 Reg->RootKey = HKEY_CURRENT_USER;
 Reg->OpenKey("Software",false);
 if (!Reg->KeyExists("WMSoftware"))
  Reg->CreateKey("WMSoftware");
 Reg->OpenKey("WMSoftware",false);
 if (!Reg->KeyExists("COD"))
 {
  Reg->CreateKey("COD");
  Reg->OpenKey("COD",false);
  Reg->CreateKey("Customizations");
  Reg->OpenKey("Customizations",false);
  Reg->WriteString("CurrentGame","01");
  Reg->WriteString("CurPlayerName","Stranger");
  Reg->WriteString("01 time","99999");
  Reg->WriteString("01 name","Stranger");
  Reg->WriteString("01 kol","99999");
  Reg->WriteString("02 time","99999");
  Reg->WriteString("02 name","Stranger");
  Reg->WriteString("02 kol","99999");
  Reg->WriteString("03 time","99999");
  Reg->WriteString("03 name","Stranger");
  Reg->WriteString("03 kol","99999");
  Reg->WriteString("04 time","99999");
  Reg->WriteString("04 name","Stranger");
  Reg->WriteString("04 kol","99999");
  Reg->WriteString("05 time","99999");
  Reg->WriteString("05 name","Stranger");
  Reg->WriteString("05 kol","99999");
 }
 delete Reg;
}

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
 CheckOnReg();
 TRegistry *Reg=new TRegistry;
 Reg->RootKey = HKEY_CURRENT_USER;
 Reg->OpenKey("Software",false);
 Reg->OpenKey("WMSoftware",false);
 Reg->OpenKey("COD",false);
 Reg->OpenKey("Customizations",false);
 AnsiString astrm=Reg->ReadString("CurrentGame");
 Edit1->Text=Reg->ReadString("CurPlayerName");
 if (astrm=="01")
 {
  ComboBox1->Text="1 (3x9)";
  Label3->Caption=Reg->ReadString("01 name");
  Label16->Caption=Reg->ReadString("01 time");
  Label14->Caption=Reg->ReadString("01 kol");
 }
 if (astrm=="02")
 {
  ComboBox1->Text="2 (6x9)";
  Label3->Caption=Reg->ReadString("02 name");
  Label16->Caption=Reg->ReadString("02 time");
  Label14->Caption=Reg->ReadString("02 kol");
 }
 if (astrm=="03")
 {
  ComboBox1->Text="3 (10x9)";
  Label3->Caption=Reg->ReadString("03 name");
  Label16->Caption=Reg->ReadString("03 time");
  Label14->Caption=Reg->ReadString("03 kol");
 }
 if (astrm=="04")
 {
  ComboBox1->Text="4 (3x18)";
  Label3->Caption=Reg->ReadString("04 name");
  Label16->Caption=Reg->ReadString("04 time");
  Label14->Caption=Reg->ReadString("04 kol");
 }
 if (astrm=="05")
 {
  ComboBox1->Text="5 (5x18)";
  Label3->Caption=Reg->ReadString("05 name");
  Label16->Caption=Reg->ReadString("05 time");
  Label14->Caption=Reg->ReadString("05 kol");
 }
 delete Reg;
}
//---------------------------------------------------------------------------

void CheckOnWin(void)
{
 Form1->StringGrid1->Enabled=false;
 Form1->Timer1->Enabled=false;
 TRegistry *Reg=new TRegistry;
 Reg->RootKey = HKEY_CURRENT_USER;
 Reg->OpenKey("Software",false);
 Reg->OpenKey("WMSoftware",false);
 Reg->OpenKey("COD",false);
 Reg->OpenKey("Customizations",false);
 AnsiString astrm=Reg->ReadString("CurrentGame");
 if (Form1->Panel5->Visible==false)
 {
  int tmm=StrToInt(Reg->ReadString(astrm+" time"));
  if ((StrToInt(Reg->ReadString(astrm+" kol"))>StrToInt(Form1->Label10->Caption)) || (StrToInt(Reg->ReadString(astrm+" kol"))==StrToInt(Form1->Label10->Caption) && tim<tmm))
   {
    Reg->WriteString(astrm+" name",Form1->Edit1->Text);
    Reg->WriteString(astrm+" time",IntToStr(tim));
    Reg->WriteString(astrm+" kol",StrToInt(Form1->Label10->Caption));
   }
 }
 astrm=Form1->ComboBox1->Text;
 Form1->StringGrid1->Enabled=true;
 if (astrm=="1 (3x9)")
 {
  n=3;
  m=9;
  Reg->WriteString("CurrentGame","01");
  Form1->Label3->Caption=Reg->ReadString("01 name");
  Form1->Label16->Caption=Reg->ReadString("01 time");
  Form1->Label14->Caption=Reg->ReadString("01 kol");
 }
 if (astrm=="2 (6x9)")
 {
  n=6;
  m=9;
  Reg->WriteString("CurrentGame","02");
  Form1->Label3->Caption=Reg->ReadString("02 name");
  Form1->Label16->Caption=Reg->ReadString("02 time");
  Form1->Label14->Caption=Reg->ReadString("02 kol");
 }
 if (astrm=="3 (10x9)")
 {
  n=10;
  m=9;
  Reg->WriteString("CurrentGame","03");
  Form1->Label3->Caption=Reg->ReadString("03 name");
  Form1->Label16->Caption=Reg->ReadString("03 time");
  Form1->Label14->Caption=Reg->ReadString("03 kol");
 }
 if (astrm=="4 (3x18)")
 {
  n=3;
  m=18;
  Reg->WriteString("CurrentGame","04");
  Form1->Label3->Caption=Reg->ReadString("04 name");
  Form1->Label16->Caption=Reg->ReadString("04 time");
  Form1->Label14->Caption=Reg->ReadString("04 kol");
 }
 if (astrm=="5 (5x18)")
 {
  n=5;
  m=18;
  Reg->WriteString("CurrentGame","05");
  Form1->Label3->Caption=Reg->ReadString("05 name");
  Form1->Label16->Caption=Reg->ReadString("05 time");
  Form1->Label14->Caption=Reg->ReadString("05 kol");
 }
 delete Reg;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton1Click(TObject *Sender)
{
 CheckOnWin();
 Timer1->Enabled=true;
 int l=1,prz=1;
 kk=n*m;
 tim=0;
 Panel5->Visible=false;
 Image1->Visible=false;
 Image2->Visible=false;
 Label11->Caption=tim;
 StringGrid1->RowCount=n;
 StringGrid1->ColCount=m;
 for (int i=0;i<n;i++)
 {
  for (int j=0;j<m;j++)
  {
   if (l%10==0)
   {
    l++;
    prz=1;
   }
   if (prz==1)
   {
    if (((l-l%10)/10)!=0)
     StringGrid1->Cells[j][i]=AnsiString((l-l%10)/10);
    else
    {
     StringGrid1->Cells[j][i]=AnsiString(l);
     l++;
    }
    prz=2;
   }
   else
    if (prz==2)
    {
     StringGrid1->Cells[j][i]=AnsiString(l%10);
     prz=1;
     l++;
    }
  }
 }
 Label10->Caption=kk;
 Col1=Row1=-1;
 StatusBar1->Panels->Items[1]->Text="New game started !";
}
//---------------------------------------------------------------------------

void __fastcall TForm1::StringGrid1MouseUp(TObject *Sender,
      TMouseButton Button, TShiftState Shift, int X, int Y)
{
 int Column,Row,prz;
 if (Button==mbRight)
 {
  Col1=Row1=-1;
  StatusBar1->Panels->Items[1]->Text="Reset !";
  return;
 }
  StringGrid1->MouseToCell(X,Y,Column,Row);
 try
 {
  if (StringGrid1->Cells[Column][Row]==' ')
   return;
 }
 catch (...)
 {
  return;
 }
 if (Col1==-1 && Row1==-1)
 {
  Col1=Column;
  Row1=Row;
  StatusBar1->Panels->Items[1]->Text="Digit: "+StringGrid1->Cells[Col1][Row1];
 }
 else
  if (Col1==Column && Row1==Row)
   return;
  else
   if ((StringGrid1->Cells[Col1][Row1]==StringGrid1->Cells[Column][Row]) || (StrToInt(StringGrid1->Cells[Col1][Row1])+StrToInt(StringGrid1->Cells[Column][Row])==10))
   {
    prz=1;
    if (Col1==Column)
    {
     if (Row>Row1)
      for (int i=Row1+1;i<Row;i++)
       if (StringGrid1->Cells[Col1][i]!=sm)
        prz=0;
     if (Row<Row1)
      for (int i=Row+1;i<Row1;i++)
       if (StringGrid1->Cells[Col1][i]!=sm)
        prz=0;
     goto next;
    }
    if (Row1==Row)
    {
     if (Column>Col1)
      for (int i=Col1+1;i<Column;i++)
       if (StringGrid1->Cells[i][Row]!=sm)
        prz=0;
     if (Column<Col1)
      for (int i=Column+1;i<Col1;i++)
       if (StringGrid1->Cells[i][Row]!=sm)
        prz=0;
      goto next;
     }
     if (Row>Row1)
     {
      int i=Row1,j=Col1+1;
      while (i<=Row)
      {
       if (j>=StringGrid1->ColCount)
       {
        j=0;
        i++;
       }
       if (i==Row && j==Column)
        break;
       if (StringGrid1->Cells[j][i]!=sm)
       {
        prz=0;
        break;
       }
       j++;
      }
      goto next;
     }
     if (Row<Row1)
     {
      int i=Row,j=Column+1;
      while (i<=Row1)
      {
       if (j>=StringGrid1->ColCount)
       {
        j=0;
        i++;
       }
       if (i==Row1 && j==Col1)
        break;
       if (StringGrid1->Cells[j][i]!=sm)
       {
        prz=0;
        break;
       }
       j++;
      }
     }
next:
    if (prz==1)
    {
     kk-=2;
     Label10->Caption=kk;
     StringGrid1->Cells[Col1][Row1]=sm;
     StringGrid1->Cells[Column][Row]=sm;
     Col1=Row1=-1;
     StatusBar1->Panels->Items[1]->Text="Not bad !";
    }
  }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button1Click(TObject *Sender)
{
 if (Panel5->Visible==false)
 {
  if (kk==0)
  {
   TRegistry *Reg=new TRegistry;
   Reg->RootKey = HKEY_CURRENT_USER;
   Reg->OpenKey("Software",false);
   Reg->OpenKey("WMSoftware",false);
   Reg->OpenKey("COD",false);
   Reg->OpenKey("Customizations",false);
   AnsiString astrm=Reg->ReadString("CurrentGame");
   int tmm=StrToInt(Reg->ReadString(astrm+" time"));
   int tkl=StrToInt(Reg->ReadString(astrm+" kol"));
   if ((tim<tmm && tkl==0) || (tkl>0))
   {
    Reg->WriteString(astrm+" name",Edit1->Text);
    Reg->WriteString(astrm+" time",IntToStr(tim));
    Reg->WriteString(astrm+" kol","000");
    Label3->Caption=Edit1->Text;
    Label16->Caption=IntToStr(tim);
    Label14->Caption="000";
   }
   delete Reg;
   Panel5->Visible=true;
   Image2->Visible=true;
   Timer1->Enabled=false;
   return;
  }
  int WRow=StringGrid1->RowCount,WCol=StringGrid1->ColCount;
  int sch=WCol-1,NRow,NCol;
  for (int i=WCol-1;i>=0;i--)
   if (StringGrid1->Cells[i][WRow-1]=="  ")
    sch--;
  if (sch==WCol-1)
  {
   StringGrid1->RowCount++;
   NRow=WRow;
   NCol=0;
  }
  else
   {
    NRow=WRow-1;
    NCol=sch+1;
   }
  for (int i=0;i<WRow-1;i++)
   for (int j=0;j<WCol;j++)
    if (StringGrid1->Cells[j][i]!=sm)
    {
     StringGrid1->Cells[NCol][NRow]=StringGrid1->Cells[j][i];
     NCol++;
     kk++;
     if (NCol==WCol)
     {
      StringGrid1->RowCount++;
      NRow++;
      NCol=0;
     }
    }
   for (int j=0;j<=sch;j++)
    if (StringGrid1->Cells[j][WRow-1]!=sm)
    {
     StringGrid1->Cells[NCol][NRow]=StringGrid1->Cells[j][WRow-1];
     NCol++;
     kk++;
     if (NCol==WCol && StringGrid1->Cells[WCol-1][WRow-1]!="  ")
     {
      StringGrid1->RowCount++;
      NRow++;
      NCol=0;
     }
    }
  for (int j=NCol;j<WCol;j++)
   StringGrid1->Cells[j][NRow]="  ";
  if (StringGrid1->Cells[0][NRow]=="  ")
   StringGrid1->RowCount--;
  Label10->Caption=kk;
  StatusBar1->Panels->Items[1]->Text="Your chance to win are fade down !";
  Col1=Row1=-1;
 }
}
//---------------------------------------------------------------------------


void __fastcall TForm1::Timer1Timer(TObject *Sender)
{
 if (Panel5->Visible==false)
 {
  tim++;
  Label11->Caption=tim;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Button2Click(TObject *Sender)
{
 Timer1->Enabled=false;
 Button1->Enabled=false;
 SpeedButton1->Enabled=false;
 SpeedButton3->Enabled=false;
 SpeedButton4->Enabled=false;
 ComboBox1->Enabled=false;
 StringGrid1->Enabled=false;
 Edit1->Enabled=true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Edit1KeyPress(TObject *Sender, char &Key)
{
 if (toascii(Key)==13)
 {
  if (Edit1->Text=="")
  {
   ShowMessage("Please enter your name !");
   return;
  }
  TRegistry *Reg=new TRegistry;
  Reg->RootKey = HKEY_CURRENT_USER;
  Reg->OpenKey("Software",false);
  Reg->OpenKey("WMSoftware",false);
  Reg->OpenKey("COD",false);
  Reg->OpenKey("Customizations",false);
  Reg->WriteString("CurPlayerName",Edit1->Text);
  delete Reg;
  Edit1->Enabled=false;
  StringGrid1->Enabled=true;
  Button1->Enabled=true;
  SpeedButton1->Enabled=true;
  SpeedButton3->Enabled=true;
  SpeedButton4->Enabled=true;
  ComboBox1->Enabled=true;
  Timer1->Enabled=true;
 }
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton3Click(TObject *Sender)
{
 Application->HelpFile="COD.hlp";
 Application->HelpCommand(HELP_CONTENTS,1);
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormClose(TObject *Sender, TCloseAction &Action)
{
 CheckOnWin();
 if(Application->MessageBox("Are you shure want to quit?","Warning!",MB_YESNO)==mrYes)
  Action=caFree;
 else
  Action=caNone;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::SpeedButton4Click(TObject *Sender)
{
 Close();       
}
//---------------------------------------------------------------------------

