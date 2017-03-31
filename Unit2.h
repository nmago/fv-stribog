//---------------------------------------------------------------------------

#ifndef Unit2H
#define Unit2H
//---------------------------------------------------------------------------
#include <System.Classes.hpp>
//---------------------------------------------------------------------------
class takeHashesThread2 : public TThread
{
private:
	void __fastcall takeHashesThread2::sayFinish();
	String hash;
protected:
	void __fastcall Execute();
public:
	String filePath;
	bool error;
	unsigned int fileID;
	__fastcall takeHashesThread2(bool CreateSuspended);
};
//---------------------------------------------------------------------------
#endif
