//---------------------------------------------------------------------------

#ifndef Unit1H
#define Unit1H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class takeHashesThread : public TThread
{
private:
	void __fastcall takeHashesThread::sayFinish();
	unsigned int thisBuff, ofBuffs;
	String hash;
protected:
	void __fastcall Execute();
public:
	String filePath;
	bool error;
	unsigned int fileID;
	__fastcall takeHashesThread(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
