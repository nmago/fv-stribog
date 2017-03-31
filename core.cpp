#include <string>
#include <vector>
#include <windows.h>
#include <comdef.h>

#include "stribog/Stribog.h"
#include "stribog/Stribog.cpp"

struct file_struct{
	String name, sbHash;
	long long size;
	bool hashing, hashComplete;
};

String getFileHash(FILE *fp);
std::vector<file_struct> makeDirFileList(String path);
char *ansi(wchar_t *unicode);

char *ansi(wchar_t *unicode){
    UnicodeString str=UnicodeString(unicode);
	AnsiString result=str;
	return result.c_str();
}

std::vector<file_struct> makeDirFileList(String path){
	const wchar_t * fn = (path+"*").c_str();
	std::vector<file_struct> fileList;
	WIN32_FIND_DATA FindFileData;
	HANDLE hf;
	hf=FindFirstFile(fn, &FindFileData);
	if (hf!=INVALID_HANDLE_VALUE){
		FindNextFile(hf,&FindFileData);
		FindNextFile(hf,&FindFileData);
		do{
			const bool is_directory = (FindFileData.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) != 0;
			if(is_directory) continue;
			file_struct file;
			file.name = FindFileData.cFileName;
			file.size = FindFileData.nFileSizeLow;
			fileList.insert(fileList.end(), file);

			//;
		}
		while (FindNextFile(hf,&FindFileData)!=0);
		FindClose(hf);
	}
	return fileList;
}

void setNullByte(byte *b, int size){
	for(int i = 0; i < size; i++){
		b[i] = 0;
	}
}

String getFileHash(FILE *fp){
	//FILE *fp;
	const int buffSize = 1 ; //8 κα

	byte buff[buffSize];
	STRIBOG_CTX ctx;

	byte hashOut[64];
	String hash = "";

	//fp = fopen ("test.txt","r+b");
	STRIBOG_init(&ctx);
	//fwrite(&a,sizeof(int),1,fp);
	while(fread(&buff, 1, buffSize, fp)){
		//setNullByte(buff, buffSize);
		STRIBOG_add(&ctx, buff, buffSize);
	}

	STRIBOG_finalize(&ctx, hashOut);
	//ShowMessage("out=" + IntToStr((int) hashOut[0]));


	for (int i = 0; i < 64; i++){
		int iv = (int)hashOut[i] &0xFF;
		hash = hash + IntToHex(iv, 2);
	}


	return hash;
}