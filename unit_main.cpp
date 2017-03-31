//---------------------------------------------------------------------------

#include <vcl.h>
#pragma hdrstop

#include "unit_main.h"



#include <stdio.h>
#include <ctime>
#include "FileCtrl.hpp"

#include "core.cpp"
#include "Unit1.h"
#include "Unit2.h"
#include "ABOUT.h"
//---------------------------------------------------------------------------
#pragma package(smart_init)
#pragma resource "*.dfm"
TmpDemo *mpDemo;
bool threadsInit  = false;
takeHashesThread *thThread;
takeHashesThread2 *thThread2;

std::vector<file_struct> fileList;
String dir="E:\\test\\", scanFilePath;
bool dirChoised = false;

void prepareTakingHash();
void updateFileListView();
void updateFileView(int fileID);

void saveDirScan(String fname);

//---------------------------------------------------------------------------
__fastcall TmpDemo::TmpDemo(TComponent* Owner)
	: TForm(Owner)
{
}
//---------------------------------------------------------------------------
void __fastcall TmpDemo::N9Click(TObject *Sender)
{
	fileList = makeDirFileList(dir);
	updateFileListView();
}
//---------------------------------------------------------------------------


void __fastcall TmpDemo::FormShow(TObject *Sender)
{
	sgFiles->Cells[0][0] = "FileName";
	sgFiles->Cells[1][0] = "Size (Bytes)";
	sgFiles->Cells[2][0] = "Hash";
	sgFiles->Cells[3][0] = "Status";
}

void prepareTakingHash(){
	//if(!threadsInit){
		thThread = new takeHashesThread(true);
		thThread2 = new takeHashesThread2(true);
		threadsInit = true;
	//}

	for(int i = 0; i < (int)fileList.size(); i ++){
		fileList[i].hashing = false;
		fileList[i].hashComplete = false;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N11Click(TObject *Sender)
{
	StatusBar->Panels->Items[0]->Text = "Processing..";
	ProgressBar->Visible = true;
	ProgressBar->Max = (int)fileList.size();
	ProgressBar->Position=0;

	prepareTakingHash();

	if((int)fileList.size() > 0){
		fileList[0].hashing = true;
		thThread->filePath = dir + fileList[0].name;
		thThread->fileID = 0;
		thThread->Start();
		Memo->Lines->Add("Thread1 taking hash of file #"+ IntToStr(0));
		if((int)fileList.size() > 1){
			fileList[1].hashing = true;
			thThread2->filePath = dir + fileList[1].name;
			thThread2->fileID = 1;
			thThread2->Start();
			Memo->Lines->Add("Thread1 taking hash of file #"+ IntToStr(1));
		}

	}
}

void finishHash(unsigned int fileID, String hash, int threadID, bool error){
	bool comp = true;
	if(!error){
		fileList[fileID].sbHash = hash;
		fileList[fileID].hashComplete = true;
		updateFileView(fileID);
		mpDemo->ProgressBar->Position++;
		mpDemo->Memo->Lines->Add("Thread "+IntToStr(threadID)+" complete hash of file #"+ IntToStr((int)fileID));
	}else{
		fileList[fileID].hashing = false;
		mpDemo->Memo->Lines->Add(">>>>>>"+IntToStr(threadID)+" ERROR: cannot hashing file #"+ IntToStr((int)fileID));
	}

	for(int i = 0; i < (int) fileList.size(); i++){
		if(!fileList[i].hashing){
			fileList[i].hashing = true;
			if(threadID == 1){
				thThread = new takeHashesThread(true);
				thThread->filePath = dir + fileList[i].name;
				thThread->fileID = i;
				thThread->Start();
				mpDemo->Memo->Lines->Add("Thread1 taking hash of file #"+ IntToStr(i));
			}else{
				thThread2 = new takeHashesThread2(true);
				thThread2->filePath = dir + fileList[i].name;
				thThread2->fileID = i;
				thThread2->Start();
				mpDemo->Memo->Lines->Add("Thread2 taking hash of file #"+ IntToStr(i));
			}
			break;
		}
		if(!fileList[i].hashComplete) comp = false;
	}

	if(comp){
		mpDemo->StatusBar->Panels->Items[0]->Text = "";
		mpDemo->ProgressBar->Visible = false;
	}
}

void updateFileListView(){
	for(int i = 0; i < (int)fileList.size(); i++){
		mpDemo->sgFiles->RowCount++;
		updateFileView(i);
	}
}

void updateFileView(int fileID){
	int i = fileID + 1;
	mpDemo->sgFiles->Cells[0][i] = fileList[fileID].name;
	mpDemo->sgFiles->Cells[1][i] = fileList[fileID].size;
	mpDemo->sgFiles->Cells[2][i] = fileList[fileID].sbHash;
	mpDemo->sgFiles->Cells[3][i] = "Unknown";
}
//---------------------------------------------------------------------------

void saveDirScan(String fname){
	TIniFile *ini = new TIniFile(fname);
	String SecParams = "params";
	int fileCount = (int) fileList.size();

	ini->WriteString(SecParams, "dir", dir);
	ini->WriteInteger(SecParams, "filecount", fileCount);

	for(int i = 0; i < fileCount; i++){
		String SecFile = "file" + IntToStr(i);

		ini->WriteString(SecFile, "name", fileList[i].name);
		ini->WriteInteger(SecFile, "size", fileList[i].size);
		ini->WriteString(SecFile, "hash", fileList[i].sbHash);
	}
	ini->Free();

}




void __fastcall TmpDemo::sgFilesMouseDown(TObject *Sender, TMouseButton Button, TShiftState Shift,
          int X, int Y)
{
	sgFiles->MouseCoord(X,Y);
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N5Click(TObject *Sender)
{
	SaveDialog->FileName = "newscan.scfl";
	if(SaveDialog->Execute()){
		saveDirScan(SaveDialog->FileName);
	}
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N2Click(TObject *Sender)
{
	sgFiles->RowCount = 1;
	String Path;
	if (SelectDirectory("Choise folder", "Desktop", Path, TSelectDirExtOpts() << sdNewUI << sdValidateDir << sdShowEdit << sdNewFolder, 0)){
		dir = Path + "\\";
		fileList = makeDirFileList(dir);
		updateFileListView();
		N5->Enabled = true;
		N11->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::Button1Click(TObject *Sender)
{
	if(FileOpenDialog1->Execute()){
		FILE *fp;
		fp = fopen(ansi(FileOpenDialog1->FileName.c_str()),"rb");
		ShowMessage(getFileHash(fp));
		fclose(fp);
	}
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N4Click(TObject *Sender)
{
	if(ScanFileOpenDialog->Execute()){
		scanFilePath = ScanFileOpenDialog->FileName;
		TIniFile *ini = new TIniFile(scanFilePath);

		String SecParams = "params";
		int fileCount = ini->ReadInteger(SecParams, "filecount", 0);
		dir = ini->ReadString(SecParams, "dir", "");
		fileList.reserve(fileCount);

		for(int i = 0; i < fileCount; i++){
			String SecFile = "file" + IntToStr(i);
			fileList[i].name = ini->ReadString(SecFile, "name", "error");
			fileList[i].size = ini->ReadInteger(SecFile, "size", 0);
			fileList[i].sbHash = ini->ReadString(SecFile, "hash", "Unknown");
		}

		updateFileListView();

		ini->Free();
		N5->Enabled = true;
		N11->Enabled = true;
	}
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N13Click(TObject *Sender)
{
AboutBox->Show();
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::N7Click(TObject *Sender)
{
	Application->Terminate();
}
//---------------------------------------------------------------------------

void __fastcall TmpDemo::chbLogClick(TObject *Sender)
{
	if(chbLog->Checked){
		Memo->Visible = true;
	}else{
        Memo->Visible = false;
    }
}
//---------------------------------------------------------------------------

