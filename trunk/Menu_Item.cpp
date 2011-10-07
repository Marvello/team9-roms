//Author : S.X.-A.3

#include "Menu_Item.h"
#include <iostream>
#include <sstream>

string Menu_Item::display() const
{
	stringstream temp;
	//Description d;
	temp << "Menu ID : " << menu_item_id << "\n";
	temp << "Category ID : " << cat_id << "\n";
	temp << "Recipe ID : " << recipe_id << "\n";
	temp << "Menu Item Name : " << menu_item_name << "\n";
	temp << "Menu Item Price : " << price << "\n";
	temp << "Menu Description : " << descr.display() << "\n";
	return temp.str();
}