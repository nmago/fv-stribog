//---------------------------------------------------------------------------

#include <System.hpp>
#pragma hdrstop

#include "Unit1.h"
#include "unit_main.h"
#include <stdio.h>
#include "core.cpp"

#pragma package(smart_init)
//---------------------------------------------------------------------------

//   Important: Methods and properties of objects in VCL can only be
//   used in a method called using Synchronize, for example:
//
//      Synchronize(&UpdateCaption);
//
//   where UpdateCaption could look like:
//
//      void __fastcall takeHashesThread::UpdateCaption()
//      {
//        Form1->Caption = "Updated in a thread";
//      }
//---------------------------------------------------------------------------



__fastcall takeHashesThread::takeHashesThread(bool CreateSuspended)
	: TThread(CreateSuspended)
{
}
//---------------------------------------------------------------------------
void __fastcall takeHashesThread::Execute()
{
	error = false;
	FILE *fp;
	hash = ERROR;

		fp = fopen(ansi(filePath.c_str()),"rb");
		if(fp!= NULL)
			hash = getFileHash(fp);
		else
			error = true;
		//mpDemo->setHash(fileID, hash);
		Synchronize(&sayFinish);


	fclose(fp);

}

void __fastcall takeHashesThread::sayFinish(){
	finishHash(fileID, hash, 1, false);
}
//---------------------------------------------------------------------------
