#ifndef MENU_ITEM_H_
#define MENU_ITEM_H_

#include <string>

// other types
#include "Description.h"			//S.X.-A.3	//uncomment once you have added the type definition
using namespace std;

struct Menu_Item
{
public:
	// constructors
	Menu_Item (int id, int cat, int rec, string n, double amt, Description s)	//S.X.-A.3  //uncomment once you have added the type definition
		: menu_item_id(id), cat_id(cat), recipe_id(rec), menu_item_name(n), price(amt), descr(s) {};  //S.X.-A.3

   // utility functions
	string display() const;

private:
   //constants
     
   // private data
	int menu_item_id;
	int cat_id;
	int recipe_id;
	string menu_item_name;
	double price;
	Description descr;			//S.X.-A.3  //uncomment once you have added the type definition
};


#endif //MENU_ITEM_H_
