#include <iostream>
#include <Windows.h>
#include <map>
#include <stack>
#include <vector>
#include <string>

#define WIN32_LEAN_AND_MEAN

using namespace std;

class Scan	{

private:
		map<int, char> L;
		

public:
	char chDrive;
	Scan()	{
	}

	/*
		Problem:

			Buffer overflow at line (GetLogicalDriveStrings) when the retrieved hard drive are above than
			100 which lead to buffer overflow(overwrite the lpBuffer[100])

		What does it cause:
			Denial of Service 


		returns number of hard drives and
		hard-drives
		struct(key and value)
	*/
	void Get_Drives()	{
		char lpBuffer[100] = {0};
		int i, j=0;

		GetLogicalDrives();
		GetLogicalDriveStrings(100, (LPWSTR)lpBuffer);

		for(i = 0;i<100;i++)	{
			if(lpBuffer[i] >= 'A' && lpBuffer[i] <= 'Z')	{
				this->L[j] = lpBuffer[i];
				j++;
			}
		}
	}

	bool ListFiles(wstring path, wstring mask, vector<wstring>& files) {
		HANDLE hFind = INVALID_HANDLE_VALUE;
		WIN32_FIND_DATA ffd;
		wstring spec;
		stack<wstring> directories;

		directories.push(path);
		files.clear();

		while (!directories.empty()) {
			path = directories.top();
			spec = path + L"\\" + mask;
			directories.pop();

			hFind = FindFirstFile(spec.c_str(), &ffd);
			if (hFind == INVALID_HANDLE_VALUE)  {
				return false;
			} 

			do {
				if (wcscmp(ffd.cFileName, L".") != 0 && 
					wcscmp(ffd.cFileName, L"..") != 0) {
					if (ffd.dwFileAttributes & FILE_ATTRIBUTE_DIRECTORY) {
						directories.push(path + L"\\" + ffd.cFileName);
					}
					else {
						files.push_back(path + L"\\" + ffd.cFileName);
					}
				}
			} while (FindNextFile(hFind, &ffd) != 0);

			if (GetLastError() != ERROR_NO_MORE_FILES) {
				FindClose(hFind);
				return false;
			}

			FindClose(hFind);
			hFind = INVALID_HANDLE_VALUE;
		}

		return true;
	}

	/*
		printMenu()
		desc:
			printing menu
	*/
	void printMenu()	{
		cout<<"[+]Scanning Hard Drives.."<<endl;
		PrintHardDrives();
		
		cout<<"[+]Enter Your choice: ";
		cin>>this->chDrive;
		//ValidateChar();
		

	}
	
	/*
		ValidateChar()
		desc:
			check if the choosed hard-drive is a word 
	*/
	bool ValidateChar()	{
		if(this->chDrive < 'A' && this->chDrive > 'Z')	{
			cout<<"Wrong Hard Drive"<<endl;
			return false;
		}
		return true;
	}

	//Print hard drives
	void PrintHardDrives()	{
		map<int, char>::iterator i;

		for(i=this->L.begin();i != this->L.end();i++)	{
			cout<<"#"<<i->first<<": "<<i->second<<endl;
			
		}
	}
	
	//return handle to a specific file
	HANDLE SpecificFile(wstring sPath)	{
		return CreateFile(sPath, GENERIC_READ, 1, NULL, OPEN_EXISTING);
	}

	/*
	gets 3 parameters = number of the specified hard drive, array of signatures
	*/
	bool DoScan(int n, char arr, int c)	{
	
		return true;
	}

	/*

		returns a array of viruses-signatures

	*/
	char *GetSignatures()	{
			
	}

	~Scan()	{
		
	}

};

int main()	{
	Scan obj;
	vector<wstring> vFiles;

	obj.Get_Drives();
	obj.printMenu();
	//cout<<obj.chDrive<<endl;
	
	if (obj.ListFiles(L"c:\\", L"*", vFiles)) {
		for (vector<wstring>::iterator it = vFiles.begin(); it != files.end();it++)	{
			wcout << it->c_str() << endl;
		}
	}
	
	delete obj;
	return 0;
}

