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
	   int option;	//Variable to check whether user really want to exit or not
	   bool exit = false;	//M.O.-A.1

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
				char ex;
				cout<< "Are You Sure? (Y/N)" <<endl;
				cin>> ex;
				if ((ex == 'Y') || (ex == 'y'))  
					exit = true;
				break;
			 }
		  }
		  
		  m.display_main_menu();
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


