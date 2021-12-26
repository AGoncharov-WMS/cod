//---------------------------------------------------------------------------
#ifndef mainH
#define mainH
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Menus.hpp>
#include <ComCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <Grids.hpp>
#include <ExtCtrls.hpp>
#include <jpeg.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:    // IDE-managed Components
        TPanel *Panel1;
        TPanel *Panel3;
        TImage *Image1;
        TPanel *Panel2;
        TLabel *Label1;
        TLabel *Label16;
        TTimer *Timer1;
        TStringGrid *StringGrid1;
        TImage *Image2;
        TComboBox *ComboBox1;
        TSpeedButton *SpeedButton1;
        TSpeedButton *SpeedButton3;
        TSpeedButton *SpeedButton4;
        TEdit *Edit1;
        TLabel *Label2;
        TLabel *Label3;
        TLabel *Label4;
        TPanel *Panel4;
        TButton *Button1;
        TLabel *Label5;
        TLabel *Label6;
        TLabel *Label7;
        TButton *Button2;
        TPanel *Panel5;
        TLabel *Label10;
        TLabel *Label11;
        TPanel *Panel6;
        TPanel *Panel7;
        TLabel *Label12;
        TLabel *Label14;
        TLabel *Label15;
        TStatusBar *StatusBar1;
        void __fastcall SpeedButton1Click(TObject *Sender);
        void __fastcall Button1Click(TObject *Sender);
        void __fastcall Button2Click(TObject *Sender);
        void __fastcall Timer1Timer(TObject *Sender);
        void __fastcall StringGrid1MouseUp(TObject *Sender,
          TMouseButton Button, TShiftState Shift, int X, int Y);
        void __fastcall Edit1KeyPress(TObject *Sender, char &Key);
        void __fastcall SpeedButton3Click(TObject *Sender);
        void __fastcall FormClose(TObject *Sender, TCloseAction &Action);
        void __fastcall SpeedButton4Click(TObject *Sender);
private:        // User declarations
public:         // User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
