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
	int getMenuItemID() const; //Return Menu Item ID 				M.O. B.3a B.1c	S.X.-B.1a	LC - B.2a
	int getMenuItemCatID() const; //Return Menu Item ID 			M.O. B.1c		S.X.-B.1a	LC - B.2a
	int getMenuItemRecipeID() const;//Return Menu Item Recipe ID 	M.O. B.1c		S.X.-B.1a	LC - B.2a
	string getMenuItemName() const; //Return Menu Item Name 		M.O. B.2c		S.X.-B.1a	LC - B.2a
	double getMenuItemPrice() const; //Return Menu Item price 		M.O. B.2c		S.X.-B.1a	LC - B.2a
	string getMenuItemDesc() const; //Return Menu Item price 		M.O. B.1c		S.X.-B.1a	LC - B.2a
	
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
