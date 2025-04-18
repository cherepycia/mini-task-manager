#include <iostream>
#include "functions.h"
using namespace std;


int main() {
   while (true) {
      ListProcesses();

      cout << "Enter PID of process you want to end or 0 to exit\n";
      DWORD pid;
      cin >> pid;
      if (pid == 0) break;

      if (KillProcess(pid)) {
         cout << "Process completed.\n";
      }
      else {
         cout << "ERROR! Failed to complete the process :( \n";
      }

      cout << "\n Type Enter to refresh... \n";
      cin.ignore();
      cin.get();
      system("cls");
   }

   return 0;
}