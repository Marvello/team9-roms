//============================================================================
// Name        : p1_main.cpp
// Author      : 
// Version     :
// Copyright   : Your copyright notice
// Description : C++ project part I for CSCE 121 and IF4093 
//============================================================================
//

#include "Menu.h"

using namespace std;

int main() {
	try {
	   Menu m;
	   int option;
	   bool exit = false;	////Boolean Variable to check whether user really want to exit M.O. A.1
	   m.display_main_menu();
	   do {
		  cout << "> ";
		  while (!(cin >> option) || option < Menu::Info || option > Menu::Exit) {
			 if (cin.fail()) {    // we found something that wasn’t an integer 
				cin.clear();      // enable us to look at the characters
				char ch;
				while (cin>>ch && !isdigit(ch)) {
				   cerr << "Invalid input; please try again" << endl;
				   cout << "> ";
				}
				cin.unget();
			 } else {  // option < Menu::Info || option > Menu::Exit */
				cerr << "Invalid input; please try again" << endl;
				cout << "> ";
			 }
		  } 
				
		  switch(option) { 
		  case Menu::Info:
			 m.display_info();//display assignment info & your names plus "Project 1"
			 break;
		  case Menu::Read:
			 try {
				m.read();
			 } catch (const Menu::InvalidFile& excp) {
				cerr << excp.what() << endl;
			 } catch (const Menu::InvalidData& excp) {
				cerr << excp.what() << endl;
			 }
			 break;
		  case Menu::Find:
			 m.find();
			 break;
		  case Menu::Show:
			 m.show();
			 break;
		  case Menu::Update:
			 m.update();
			 break;
		  case Menu::Exit:	//Author : M.O.-A.1 //Checking the user input to exit
			{
				char ex; //variable for contain user answer(M.O.)
				do
				{
					cout<< "Are You Sure? (Y/N)" <<endl; //Asking user for input(M.O.)
					cin>> ex;
					if ((ex == 'Y') || (ex == 'y'))
						exit = true; //Change exit value to true and exit the program (M.O.)
					else if ((ex == 'N') || (ex == 'n')) {}
					else
						cerr << "Invalid input; please try again" << endl;
				}
				while ((ex != 'Y') && (ex != 'y') && (ex != 'N') && (ex != 'n'));
				break;
			}
		  }
		  
		//m.display_main_menu(); Delete because already done at the beginning and doesn't need to be done when exit M.O. A.1
	   } while (exit == false);		//M.O.-A.1  //Change the loop condition from option!=Menu::Exit to exit==false
	   return 0;
	}
	catch (exception& e) {
		cerr << e.what() << endl;   
	}
	catch (...) {
		cerr << "unknown exception\n";
	}
}


