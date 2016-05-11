
#include "stdafx.h"

#include <windows.h>
#include <commctrl.h>
#include <stdio.h>
#include <iostream>
#include <cstring>
#include <string>
#include <vector>
#include <fstream>
#include <algorithm>
using namespace std;

char chrome[] = "chrome";
char exitSmallString[] = "exit";
char  exitBigString[] = "Exit";

int main(int argc, char *argv[]) {

	cout << "\nRunning Shell\n" << "\n" << endl;




	while (true) {


		string input = "";     // Used to get input from the user
		char* cinput = NULL;  // Used to store C-style version of the input




							  // ------------------- Variables used for tokenizing a command into words --------------------------------
		char* savedTokens[256] = { NULL };  // The actual derived tokens
		int nTokens = 0;   // To store the number of tokens

		cout << "$: ";
		getline(cin, input);	// Getting input from user


		cinput = new char[input.size() + 1];
		strcpy(cinput, input.c_str());    	// Getting C-style version of user's input


		char* tokens = strtok(cinput, " ");


		while (tokens != NULL) {

			// Use strdup here since you want to deep copy the C-string into savedtokens and not just its pointer

			savedTokens[nTokens] = _strdup(tokens);
			nTokens++;
			tokens = strtok(NULL, " ");
		} // Done tokenizing the command into arguments

		if (strcmp(exitSmallString, savedTokens[0]) == 0 || strcmp(exitBigString, savedTokens[0]) == 0) {
			cout << "Have a great day! Shell shutting down." << endl;
			return 0;
		}
		else if (strcmp(chrome, savedTokens[0]) == 0) {
			cout << "Redirecting..." << endl;
			string url = input.substr(input.find(" "), input.length());
			ShellExecuteA(0, 0, "chrome.exe", url.c_str(), 0, SW_SHOWMAXIMIZED);
		}

		else if (strcmp("openfile", savedTokens[0]) == 0) {
			string file = input.substr(input.find(" "), input.length());
			const char* c = file.c_str();
			system(c);

		}
		else if (strcmp("google", savedTokens[0]) == 0) {
			cout << "Redirecting..." << endl;
			string url = input.substr(input.find(" "), input.length());
			string querry = "http://www.google.com/search?q=";
			replace(url.begin(), url.end(), ' ', '+');
			/*for (int i=0;i < url.length();i++)
			{
			cout<<querry<<endl;
			querry+=url.substr(i,url.find(" ")-7)+"+";
			i=url.find(" ")-7;
			}*/
			querry += url;
			cout << querry << endl;
			ShellExecuteA(0, 0, "chrome.exe", querry.c_str(), 0, SW_SHOWMAXIMIZED);
		}
		else if (strcmp("help", savedTokens[0]) == 0) {
			cout << "chrome        enter chrome with a url to open chorme to that link" << endl;
			cout << "openfile        enter openfile with the name of the exe to open that program" << endl;
			cout << "google        enter google plus your search to initiate a google search" << endl;
			cout << "exit        enter exit to leave the shell" << endl;
			cout << "help        enter help to view your options" << endl;
			cout << "enter any other command and it will enter that command into command prompt" << endl;

		}


		else {
			system(input.c_str());
		}
		cout << endl;
	}
}
