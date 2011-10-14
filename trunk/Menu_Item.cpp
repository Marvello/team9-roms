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

int Menu_Item::getMenuItemID() const//Return Menu Item ID M.O. B.3a, B.2c
{
	return menu_item_id;
	
}

int Menu_Item::getMenuItemCatID() const //Return Menu Item ID M.O. B.3a, B.2c
{
	return cat_id;
}

string Menu_Item::getMenuItemName() const//Return Menu Item Name M.O. B.2c
{
	return menu_item_name;
}

double Menu_Item::getMenuItemPrice() const//Return Menu Item price M.O. B.2c
{
	return price;
}

string Menu_Item::getMenuItemDesc() const //Return Menu Item price M.O. B.1c
{
	return descr.display();
}