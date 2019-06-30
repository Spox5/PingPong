//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop
#include "mmsystem.h"

#include "Unit1.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TForm1 *Form1;

int x = -8;
int y = -8;
int pointCountLeft = 0;
int pointCountRight = 0;
AnsiString pointCountLeftString = "";
AnsiString pointCountRightString = "";
int bounceCount = 0;
AnsiString bounceCountString = "";

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
                whoWin->Visible = true;
                whoWin->Caption = "Punkt dla gracza prawego ->";
                pointCountRight++;
                count->Visible = true;
                pointCountRightString = IntToStr(pointCountRight);
                pointCountLeftString = IntToStr(pointCountLeft);
                count->Caption = pointCountLeftString + " : " + pointCountRightString;
                bounceCountLabel->Visible = true;
                bounceCountString = IntToStr(bounceCount);
                bounceCountLabel->Caption = "Iloœæ odbiæ: " + bounceCountString;
                nextRound->Visible = true;
                nextRound->Enabled = true;
                nextRound->Caption = "Nastêpna runda >";
                newGame->Visible = true;
                newGame->Enabled = true;
                newGame->Caption = "Nowa gra";
                Music->Close();
                sndPlaySound("snd/przegrana.wav", SND_ASYNC);
        }
        //odbicie pilki gracza lewego
        else if (b->Top+b->Height/2 > pL->Top && b->Top+b->Height/2 < pL->Top+pL->Height
                && b->Left <= pL->Left + pL->Width)
        {
                if (x<0)
                {
                        x = -x;
                        bounceCount++;
                        sndPlaySound("snd/odbicieL.wav", SND_ASYNC);
                        if (b->Top+b->Height > pL->Top+pL->Height/2 && b->Top < pL->Top+pL->Height/2)
                        {
                                y = y -4;
                                if (Timer_pilka->Interval >= 5)
                                        Timer_pilka->Interval = Timer_pilka->Interval - 4;
                        }
                }
        }

        //przegrana gracza prawego
        if(b->Left >= pR->Left+pR->Width)
        {
                Timer_pilka->Enabled = false;
                b->Visible = false;
                whoWin->Visible = true;
                whoWin->Caption = "<- Punkt dla gracza lewego";
                pointCountLeft++;
                count->Visible = true;
                pointCountRightString = IntToStr(pointCountRight);
                pointCountLeftString = IntToStr(pointCountLeft);
                count->Caption = pointCountLeftString + " : " + pointCountRightString;
                bounceCountLabel->Visible = true;
                bounceCountString = IntToStr(bounceCount);
                bounceCountLabel->Caption = "Iloœæ odbiæ: " + bounceCountString;
                nextRound->Visible = true;
                nextRound->Enabled = true;
                nextRound->Caption = "Nastêpna runda >";
                newGame->Visible = true;
                newGame->Enabled = true;
                newGame->Caption = "Nowa gra";
                Music->Close();
                sndPlaySound("snd/przegrana.wav", SND_ASYNC);
        }
        //odbicie pilki gracza prawego
        else if (b->Top+b->Height/2 > pR->Top && b->Top+b->Height/2 < pR->Top+pR->Height
                && b->Left+b->Width >= pR->Left)
        {
                if (x>0)
                {
                        x = -x;
                        bounceCount++;
                        sndPlaySound("snd/odbicieR.wav", SND_ASYNC);
                        if (b->Top+b->Height > pR->Top+pR->Height/2 && b->Top < pR->Top+pR->Height/2)
                        {
                                y = y - 4;
                                if (Timer_pilka->Interval >= 5)
                                        Timer_pilka->Interval = Timer_pilka->Interval - 4;
                        }
                }
        }
}
//---------------------------------------------------------------------------
void __fastcall TForm1::buttonStartGameClick(TObject *Sender)
{
        buttonStartGame->Enabled = false;
        buttonStartGame->Visible = false;
        tytul->Visible = false;
        Timer_pilka->Enabled = true;
        Timer_pilka->Interval = 30;
}
//---------------------------------------------------------------------------

void __fastcall TForm1::nextRoundClick(TObject *Sender)
{
        x = -8;
        y = -8;
        whoWin->Visible = false;
        count->Visible = false;
        bounceCountLabel->Visible = false;
        bounceCount = 0;
        nextRound->Enabled = false;
        nextRound->Visible = false;
        newGame->Enabled = false;
        newGame->Visible = false;
        Timer_pilka->Enabled = true;
        Timer_pilka->Interval = 30;
        b->Visible = true;
        b->Top = 272;
        b->Left = 440;
        Music->FileName = "snd/menu.wav";
        Music->Open();
        Music->Play();
}
//---------------------------------------------------------------------------

void __fastcall TForm1::newGameClick(TObject *Sender)
{

        if (Application->MessageBox("Czy na pewno chcesz zacz¹æ od nowa?", "PotwierdŸ",
        MB_YESNO | MB_ICONQUESTION) == IDYES)
        {
                x = -8;
                y = -8;
                whoWin->Visible = false;
                pointCountLeft = 0;
                pointCountRight = 0;
                count->Visible = false;
                bounceCountLabel->Visible = false;
                bounceCount = 0;
                nextRound->Enabled = false;
                nextRound->Visible = false;
                newGame->Enabled = false;
                newGame->Visible = false;
                Timer_pilka->Enabled = true;
                Timer_pilka->Interval = 30;
                b->Visible = true;
                b->Top = 272;
                b->Left = 440;
                Music->FileName = "snd/menu.wav";
                Music->Open();
                Music->Play();
        }

}
//---------------------------------------------------------------------------


void __fastcall TForm1::FormCreate(TObject *Sender)
{
        ShowMessage("Witaj w grze PingPong.\n"
        "\n"
        "Lewy gracz steruje wciskaj¹c A oraz Z.\n"
        "Prawy gracz steruje wciskaj¹c strza³ki do góry i w dó³.\n"
        "\n"
        "Dla urozmaicenia zabawy:\n"
        "Kiedy odbijesz pi³kê na œrodku paletki, wówczas zmienisz jej k¹t odbicia i pi³ka przyspieszy.\n"
        "Im d³u¿ej odbijasz, tym pi³ka szybciej przemieszcza siê.\n"
        "Mo¿esz dowolnie zmieniaæ pole gry.\n"
        "\n"
        "Mi³ej zabawy!\n"
        );
        Music->FileName = "snd/menu.wav";
        Music->Open();
        Music->Play();

}
//---------------------------------------------------------------------------


