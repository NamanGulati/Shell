#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include "resource.h"
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
using namespace std;
HINSTANCE hInst;

BOOL CALLBACK DlgMain(HWND hwndDlg, UINT uMsg, WPARAM wParam, LPARAM lParam)
{
    switch(uMsg)
    {
    case WM_INITDIALOG:
    {
    }
    return TRUE;

    case WM_CLOSE:
    {
        EndDialog(hwndDlg, 0);
    }
    return TRUE;

    case WM_COMMAND:
    {
        switch(LOWORD(wParam))
        {
        }
    }
    return TRUE;
    }
    return FALSE;
}


bool checkfile(){
    if (!ifstream("dat.txt"))
        {
        ofstream file("dat.txt");
        }
}

int APIENTRY WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
    hInst=hInstance;
    InitCommonControls();
    return DialogBox(hInst, MAKEINTRESOURCE(DLG_MAIN), NULL, (DLGPROC)DlgMain);
}
using namespace std;


// --------------------  Strings used in comparison -----------------------------------------------------
// NOTE: The reason why I am using those is to avoid the rare occasion when comparison doesn't work properly
char chrome []= "chrome";
char exitSmallString[]  = "exit";
char  exitBigString[] = "Exit";

int main (int argc, char *argv [ ] ) {

cout << "\nRunning Shell\n" << "\n" << endl;




while ( true ) {

checkfile()

string input = "";     // Used to get input from the user
char* cinput = NULL;  // Used to store C-style version of the input




// ------------------- Variables used for tokenizing a command into words --------------------------------
    char* savedTokens[256] = {NULL};  // The actual derived tokens
    int nTokens = 0;   // To store the number of tokens

    cout << "$: ";
    getline (cin, input);	// Getting input from user


    cinput = new char [input.size()+1];
    strcpy (cinput, input.c_str());    	// Getting C-style version of user's input


    char* tokens = strtok (cinput," ");


         while (tokens != NULL ) {

          // Use strdup here since you want to deep copy the C-string into savedtokens and not just its pointer

                   savedTokens[nTokens] = strdup(tokens);
                   nTokens++;
                   tokens = strtok(NULL," ");
           } // Done tokenizing the command into arguments

           if(strcmp(exitSmallString, savedTokens[0]) == 0 || strcmp(exitBigString, savedTokens[0]) == 0){
           cout << "Have a great day! Shell shutting down." << endl;
           return 0;
           }
           else if(strcmp(chrome, savedTokens[0]) == 0){
          cout<< "Redirecting..."<< endl;
            string url = input.substr(input.find(" "),input.length());
          ShellExecuteA(0,0,"chrome.exe",url.c_str(),0,SW_SHOWMAXIMIZED);
           }
           else if(strcmp("openfile", savedTokens[0]) == 0){
                string file = input.substr(input.find(" "),input.length());
                cout<<"\n\nSorry, the google and openfile commands are not fully developed yet"<<endl;
                //file+=".exe";
            ShellExecuteA(0,0,file.c_str(),"",0,SW_SHOWMAXIMIZED);
           }
           else if(strcmp("google", savedTokens[0]) == 0){
            cout<< "Redirecting..."<< endl;
            cout<<"\n\nSorry,the google and openfile commands are not fully developed yet"<<endl;
            string url = input.substr(input.find(" "),input.length());
          ShellExecuteA(0,0,"chrome.exe",url.c_str(),0,SW_SHOWMAXIMIZED);
           }
           else if (strcmp("help", savedTokens[0]) == 0){
            cout<<"chrome        enter chrome with a url to open chorme to that link"<<endl;
            cout<<"openfile        enter openfile with the name of the exe to open that program"<<endl;
            cout<<"google        enter google plus your search to initiate a google search"<<endl;
            cout<<"exit        enter exit to leave the shell"<<endl;
            cout<<"help        enter help to view your options"<<endl;
            cout<<"enter any other command and it will enter that command into command prompt"<<endl;

           }
           else if(strcmp("email", savedTokens[0]) == 0){
                list<string> lines;
string t;
while ( !file.eof() )//read everything in the file
{
   getline(file,t);//store a line in 't'
   lines.push_back( t );//add 't' to the list
}
string first_line = *lines.begin();//get the first element of the list
if ( first_line.find('1')!=string::npos )//check if it has '1'
   cout << first_line;//print it
           }
           else{
            //cout<< "Command Not Found"<<endl;
            system(input.c_str());
           }
           cout<<endl;
}
}
