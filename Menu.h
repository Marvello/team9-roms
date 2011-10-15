#ifndef MENU_H_
#define MENU_H_

#include <iostream>
#include <string>
#include <stdexcept>
#include <vector>
//other types
#include "Category.h"
#include "Menu_Item.h"
#include "Recipe.h"
#include "Ingredient.h"
#include "Instructions.h"
#include "Order.h"
#include "Order_Item.h"
#include "Description.h"	//S.X.-A.3
#include "Time.h" //L.C., A2
#include "Date.h" //L.C., A2

using namespace std;

class Menu {
public:
   struct InvalidData : std::runtime_error {
      InvalidData(): runtime_error("Invalid input data format") {}
   };

   struct InvalidFile : std::runtime_error {
      InvalidFile(): runtime_error("Invalid input file name") {}
   };

   enum Main_menu_options{ Info=1, Read, Show, Find, Update, Exit }; 
		
	Menu();
   
   void display_main_menu() const;
   void display_info() const;//display assignment info & your name plus "Project Part I"
   void read();		 
   void update();
   void show() const;
   void find() const;

private:
   //private data
	void readRecipeIng(); 					//M.O. A.1
	void readOrderOrderItem(); 				//L.C. A.2
	void readMenuDescr(); 					//S.X. A.3
	void showAnItemRecipe() const; 			//S.X. B.1a
	void showMenuItem() const;				//L.C. B.1b
	void showCatagoryItem() const; 			//M.O. B.1c
	void displayTotalSalesTable() const;	//L.C. B.2a
	void displayTotalSalesServer() const; 	//S.X. B.2b
	void findMenuItem() const; 				//M.O. B.2c
	void updateOrderItem(); 				//M.O. B.3a
	void updateMenuItem();					//L.C. B.3b
	void updateCategories(); 				//S.X. B.3c

	
	vector<Category> categories;
	vector<Menu_Item> menu_items;
	vector<Recipe> recipes;
	vector<Ingredient> ingredients;
	vector<Order> orders;
	vector<Order_Item> order_items;
};

#endif //MENU_H_