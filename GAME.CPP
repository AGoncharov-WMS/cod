//---------------------------------------------------------------------------
//                   Program #0084  Made by -=WMS=-
//                         Description: Game !
//             The project was started at April 14, 2001
//            The project was finished at August 14, 2001
//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
USERES("game.res");
USEFORM("main.cpp", Form1);
//---------------------------------------------------------------------------
WINAPI WinMain(HINSTANCE, HINSTANCE, LPSTR, int)
{
        try
        {
                 Application->Initialize();
                 Application->Title = "Game \"C.O.D. !\"";
                 Application->CreateForm(__classid(TForm1), &Form1);
                 Application->Run();
        }
        catch (Exception &exception)
        {
                 Application->ShowException(&exception);
        }
        return 0;
}
//---------------------------------------------------------------------------
