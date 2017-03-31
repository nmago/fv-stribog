//---------------------------------------------------------------------------

#ifndef unit_mainH
#define unit_mainH
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
#include <Vcl.Controls.hpp>
#include <Vcl.StdCtrls.hpp>
#include <Vcl.Forms.hpp>
#include <Vcl.Menus.hpp>
#include <Vcl.Grids.hpp>
#include <Vcl.CheckLst.hpp>
#include <Vcl.ComCtrls.hpp>
#include <Vcl.ExtCtrls.hpp>
#include <IniFiles.hpp>
#include <Vcl.Dialogs.hpp>

//---------------------------------------------------------------------------
class TmpDemo : public TForm
{
__published:	// IDE-managed Components
	TMainMenu *MainMenu1;
	TMenuItem *N1;
	TMenuItem *N2;
	TMenuItem *N3;
	TMenuItem *N4;
	TMenuItem *N5;
	TMenuItem *N6;
	TMenuItem *N7;
	TMenuItem *N8;
	TMenuItem *N11;
	TStringGrid *sgFiles;
	TStatusBar *StatusBar;
	TPanel *Panel1;
	TButton *Button1;
	TMemo *Memo;
	TProgressBar *ProgressBar;
	TPopupMenu *PopupMenu;
	TMenuItem *N12;
	TSaveDialog *SaveDialog;
	TFileOpenDialog *FileOpenDialog1;
	TFileOpenDialog *ScanFileOpenDialog;
	TMenuItem *N13;
	TCheckBox *chbLog;
	void __fastcall N9Click(TObject *Sender);
	void __fastcall FormShow(TObject *Sender);
	void __fastcall N11Click(TObject *Sender);
	void __fastcall sgFilesMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y);
	void __fastcall N5Click(TObject *Sender);
	void __fastcall N2Click(TObject *Sender);
	void __fastcall Button1Click(TObject *Sender);
	void __fastcall N4Click(TObject *Sender);
	void __fastcall N13Click(TObject *Sender);
	void __fastcall N7Click(TObject *Sender);
	void __fastcall chbLogClick(TObject *Sender);
private:	// User declarations
public:		// User declarations
	__fastcall TmpDemo(TComponent* Owner);
};
void finishHash(unsigned int fileID, String hash, int threadID, bool error);
//---------------------------------------------------------------------------
extern PACKAGE TmpDemo *mpDemo;
//---------------------------------------------------------------------------
#endif
