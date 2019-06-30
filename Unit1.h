//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <Classes.hpp>
#include <Controls.hpp>
#include <StdCtrls.hpp>
#include <Forms.hpp>
#include <ExtCtrls.hpp>
#include <Graphics.hpp>
#include <Buttons.hpp>
#include <MPlayer.hpp>
//---------------------------------------------------------------------------
class TForm1 : public TForm
{
__published:	// IDE-managed Components
        TShape *tlo;
        TImage *pL;
        TTimer *pLdol;
        TTimer *pLgora;
        TImage *pR;
        TTimer *pRgora;
        TTimer *pRdol;
        TImage *b;
        TTimer *Timer_pilka;
        TLabel *tytul;
        TButton *buttonStartGame;
        TLabel *whoWin;
        TLabel *count;
        TLabel *bounceCountLabel;
        TButton *newGame;
        TBitBtn *nextRound;
        TMediaPlayer *Music;
        void __fastcall pLgoraTimer(TObject *Sender);
        void __fastcall pLdolTimer(TObject *Sender);
        void __fastcall FormKeyDown(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall FormKeyUp(TObject *Sender, WORD &Key,
          TShiftState Shift);
        void __fastcall pRgoraTimer(TObject *Sender);
        void __fastcall pRdolTimer(TObject *Sender);
        void __fastcall Timer_pilkaTimer(TObject *Sender);
        void __fastcall buttonStartGameClick(TObject *Sender);
        void __fastcall newGameClick(TObject *Sender);
        void __fastcall nextRoundClick(TObject *Sender);
        void __fastcall FormCreate(TObject *Sender);
private:	// User declarations
public:		// User declarations
        __fastcall TForm1(TComponent* Owner);
};
//---------------------------------------------------------------------------
extern PACKAGE TForm1 *Form1;
//---------------------------------------------------------------------------
#endif
