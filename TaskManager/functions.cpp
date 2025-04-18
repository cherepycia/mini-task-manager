#include "functions.h"
#include <TlHelp32.h>
#include <iostream>
using namespace std;

void ListProcesses() {
   HANDLE hSnap = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
   if (hSnap == INVALID_HANDLE_VALUE) { 
      cerr << "ERROR! Failed to get process snapshot :( \n";
      return;
   }

   PROCESSENTRY32 prEntry;
   prEntry.dwSize = sizeof(PROCESSENTRY32);

   if (Process32First(hSnap, &prEntry)) {
      cout << "PROCESSES LIST: \n";
      do {
         wcout << L"[PID: " << prEntry.th32ProcessID << L"] " << prEntry.szExeFile << endl;
      } while (Process32Next(hSnap, &prEntry));                   
   }
   else {
      cerr << "ERROR! Failed to read process snapshot :(\n";
   }

   CloseHandle(hSnap);
}


bool KillProcess(DWORD pid) {
   HANDLE hProc = OpenProcess(PROCESS_TERMINATE, FALSE, pid);
   if (hProc == NULL) {
      cerr << "ERROR! Failed to open process of PID :( " << pid << " Maybe not enough rights\n";
      return false;
   }

   BOOL result = TerminateProcess(hProc, 0);
   CloseHandle(hProc);
   return result;
}
