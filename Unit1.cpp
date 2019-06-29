//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;

//---------------------------------------------------------------------------
__fastcall TForm1::TForm1(TComponent* Owner)
        : TForm(Owner)
{
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pLgoraTimer(TObject *Sender)
{
        if(pL->Top > 10) pL->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pLdolTimer(TObject *Sender)
{
        if(pL->Top+pL->Height < tlo->Top+tlo->Height - 10) pL->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyDown(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41) pLgora->Enabled = true;
        if (Key == 0x5A) pLdol->Enabled = true;
        if (Key == VK_UP) pRgora->Enabled = true;
        if (Key == VK_DOWN) pRdol->Enabled = true;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pRgoraTimer(TObject *Sender)
{
        if(pR->Top > 10) pR->Top -= 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::pRdolTimer(TObject *Sender)
{
        if(pR->Top+pR->Height < tlo->Top+tlo->Height - 10) pR->Top += 10;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::FormKeyUp(TObject *Sender, WORD &Key,
      TShiftState Shift)
{
        if (Key == 0x41) pLgora->Enabled = false;
        if (Key == 0x5A) pLdol->Enabled = false;
        if (Key == VK_UP) pRgora->Enabled = false;
        if (Key == VK_DOWN) pRdol->Enabled = false;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::Timer_pilkaTimer(TObject *Sender)
{
        b->Left += x;
        b->Top += y;

        //odbij od gornej sciany
        if(b->Top-5 <= tlo->Top) y = -y;

        //odbij od dolnej sciany
        if(b->Top+b->Height+5 >= tlo->Top+tlo->Height) y = -y;

        //przegrana gracza lewego
        if(b->Left <= pL->Left)
        {
                Timer_pilka->Enabled = false;
                b->Visible = false;
        }
        //odbicie pilki gracza lewego
        else if (b->Top+b->Height/2 > pL->Top && b->Top+b->Height/2 < pL->Top+pL->Height
                && b->Left <= pL->Left + pL->Width)
        {
                if (x<0) x = -x;
        }

        //przegrana gracza prawego
        if(b->Left >= pR->Left+pR->Width)
        {
                Timer_pilka->Enabled = false;
                b->Visible = false;
        }
        //odbicie pilki gracza prawego
        else if (b->Top+b->Height/2 > pR->Top && b->Top+b->Height/2 < pR->Top+pR->Height
                && b->Left+b->Width >= pR->Left)
        {
                if (x>0) x = -x;
        }
}
//---------------------------------------------------------------------------
