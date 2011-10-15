#include "Menu.h"
#include <iostream>

//additional includes
#include <fstream> //M.O. A.1, L.C., A2, S.X.-A.3, 

using namespace std;

Menu::Menu()
{
}

void Menu::display_main_menu() const 
{
	cout << "\n***************************** \n"; //S.X.-A.3
	cout << "Restaurant Management System \n"; //S.X.-A.3
	cout << "***************************** \n\n"; //S.X.-A.3
	cout << "MAIN MENU : \n"; //S.X.-A.3
	cout << "1. Project Information \n"; //S.X.-A.3
	cout << "2. Read file name then read store data \n"; //S.X.-A.3
	cout << "3. Show Queries \n"; //S.X.-A.3
	cout << "4. Find Queries \n"; //S.X.-A.3
	cout << "5. Update Queries \n"; //S.X.-A.3
	cout << "6. Exit \n \n"; //S.X.-A.3
}
void Menu::display_info() const
{
	cout << "\n=================== \n"; //S.X.-A.3
	cout << "Project Information \n"; //S.X.-A.3
	cout << "==================== \n\n"; //S.X.-A.3
	cout << "This project is a C++ project assignment for CSCE 121 and IF4093. \n"; //S.X.-A.3
	cout << "This project goal is to make a simple restaurant management system. \n"; //S.X.-A.3
	cout << "Project Team Member : \n"; //S.X.-A.3
	cout << "1. Shirley Xiao (ITB) \n"; //S.X.-A.3
	cout << "2. Marvello Oni (ITB) \n"; //S.X.-A.3
	cout << "3. Laura Jin Caflisch (TAMU) \n\n"; //S.X.-A.3
}

void Menu::read()
{
	//cout << "Read file name then read store data \n";  //S.X.-A.3
	readRecipeIng();	//M.O.-A.1	//function for read recipe and ingredients
	readMenuDescr();	//S.X.-A.3  //function for read menu description
	readOrderOrderItem();//L.C., A2 //function for read orders and order items
}

void Menu::show() const 
{
	int choice;
	cout << "Please Select One" << endl;
	cout << "1. Print a recipe menu "<< endl;
	cout << "2. Print all menu items sorted by Chef "<< endl;
	cout << "3. Print all menu items sorted by price"<< endl;
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((0 <= choice) && (choice <= 3)))
			cout<< "Invalid input" << endl;
	}
	while (not((0 <= choice) && (choice <= 3)));
	
	if (choice == 1)
		showAnItemRecipe();
	else if (choice ==2)
		showMenuItem();
	else if (choice ==3)
		showCatagoryItem();
}

void Menu::find() const 
{
	int choice;
	cout << "Please Select One" << endl;
	cout << "1. Display Total sales for a table "<< endl;
	cout << "2. Displat Total sales for a server "<< endl;
	cout << "3. Display Total sales for a menu item"<< endl;
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((1 <= choice) && (choice <= 3)))
			cout<< "Invalid input" << endl;
	}
	while (not((1 <= choice) && (choice <= 3)));
	
	if (choice == 1)
		displayTotalSalesTable();
	else if (choice == 2)
		displayTotalSalesServer();
	else if (choice == 3)
		findMenuItem();
}

void Menu::update()  
{
	int choice;
	cout << "Please Select One" << endl;
	cout << "1. Add new order item to existing order "<< endl;
	cout << "2. Add new menu item to category from existing recipe "<< endl;
	cout << "3. Add new categories"<< endl;
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((1 <= choice) && (choice <= 3)))
			cout<< "Invalid input" << endl;
	}
	while (not((1 <= choice) && (choice <= 3)));
	
	if (choice == 1)
		updateOrderItem();
	else if (choice ==2)
		updateMenuItem();
	else if (choice ==3)
		updateCategories();
}

void Menu::readRecipeIng() //Author : M.O.-A.1
{
	//Supporting variables
	string Ingunits,Ingname, chefname; 
	string Ins,compare;
	int ing_id, recipe_id;
	int ing_count, recipe_count;
	float Ingamt;

	//Initiation for file reading
	ifstream myfile ("Sample_Data/recipes.dat");
	
	//Process for reading the ingredients and recipe
	if (myfile.is_open())
	{
		myfile >> ing_count; // read the amount of Ingredients
		// cout << ing_count <<endl;
		for(int i = 0; i < ing_count; i++) // iteration according to the amount of category listed
		{
			myfile >> ing_id >> recipe_id >> Ingamt >> Ingunits >>Ingname; // read and insert the ingerdients information
			ingredients.push_back(Ingredient(ing_id,recipe_id,Ingamt,Ingunits,Ingname)); // store the information to the ingredients vector
			// cout << ing_id << " " << recipe_id << " " << Ingamt << " " << Ingunits << " " << Ingname <<endl;
		}
		cout << "Read Ingredients SUCCESSFUL"<<endl;
		myfile >> recipe_count; // read the amount of Recipes
		for(int i = 0; i < recipe_count; i++) // iteration according to the amount of recipe listed
		{
			myfile >> recipe_id >> chefname ; // read and insert the recipe information
			myfile >> compare; // read and insert the Instruction
			while (compare != "#") // read the whole instruction until '#' found
			{
				Ins += compare + " "; // adding the text until stopping point has been found
				myfile >> compare; // read and insert the instruction
			}
			recipes.push_back(Recipe(recipe_id,chefname,Ins)); // store the information to the recipe vector
			// Cout << recipe_id << " " << chefname << "\n" << Ins << endl;
			Ins = ""; // clearing the content to be used again later
		}
		cout << "Read Recipe SUCCESSFUL"<<endl;
		myfile.close(); // closing the file
	}

}

void Menu::readOrderOrderItem()//L.C., A2
{
	// string filename;
	char filename[50] ;
	int number;			//number of orders
	int count;			//number of order items
	int order_id, server_id, table_id; //declares first 3 order elements
	int y, m, d, h, min; //declares date and time elements
	int menu_item_id, prod_qty;		//order items elements
	char seat_id;					//order items elements
	cout<< "Enter orders filename :";
	cin >> filename;
	std::ifstream in(filename, ios_base::in);	//opens file

	if (!in.good()){
		cerr << "Failed to open file.\n";
	}
	
	in >> number;
	// cout << number <<endl;
	for(int i = 0; i < number; i++){
		in >> order_id >> server_id >> table_id >> y >> m >> d >> h >> min;
		orders.push_back(Order(order_id, server_id, table_id, Date(y, m, d), Time(h, min)));	//stores data in vector order
		// cout << order_id <<" "<< server_id <<" "<< table_id <<" "<< y <<" "<< m <<" "<< d <<" "<< h <<" "<< min <<" "<<endl;
		}

	in >> count;
	// cout << count <<endl;
	for(int i = 0; i < count; i++){
		in >> seat_id >> order_id >> menu_item_id >> prod_qty;
		order_items.push_back(Order_Item(seat_id, order_id, menu_item_id, prod_qty));		//stores data in vector order_items
		// cout <<seat_id <<" "<< order_id <<" "<< menu_item_id <<" "<< prod_qty<<" "<<endl;
		}

	in.close();
	}

void Menu::readMenuDescr() //Author : S.X.-A.3
{
	//Supporting variables
	int i;
	int cat_count, cat_id;	//cat_count = amount of category in list, cat_id = category ID
	int menu_count, item_id, rec_id;  //menu_count = amount of menu in list, item_id = menu item id list, rec_id = recipe ID 
	string item_name;  //item_name = menu item name,
	float price;  //price = menu item price
	string cat_name;	// cat_name = category name
	string desc, word;	// desc = description about the menu

	//Initiation for file reading
	ifstream file ("Sample_Data/catmenu.dat");

	//Process for reading the menu category and description
	if (file.is_open())
	{
		file >> cat_count; // read the amount of menu category
		for (i=0; i<cat_count; i++) //iteration according to the amount of category listed
		{
			file >> cat_id >> cat_name; //read and insert the category id and category name
			categories.push_back(Category(cat_id, cat_name)); //store the information to the categories vector
		}

		file >> menu_count; //read the amount of menu items
		for(i=0; i<menu_count; i++) //iteration according to the amount of menu items
		{
			file >> item_id >> cat_id >> rec_id >> item_name >> price;	//read and insert the menu information except description
			file >> word;	//read and insert the description

			while (word != "#") //read the whole description until "#" found
			{
				desc += word + " ";	//adding the text until stopping point has been found
				file >> word; //read and insert the description
			}
			menu_items.push_back(Menu_Item(item_id,cat_id,rec_id,item_name,price,Description(desc)));
			desc = "";	//clearing the content to be used again later			
		}
		file.close();	//closing the file
	}
	cout << "Read and store menu category and description successfully \n\n";
}

void Menu::showCatagoryItem() const //Author : M.O. B.1c
{
	string Catname;
	int CatID;
	bool found = false;
	vector<Menu_Item> temp;
	do 
	{
		cout << "Please Catagory name :";
		cin >> Catname; //request for the catagory name
		for(int i=0;i<categories.size();i++) //For every catagory in the vector 
			if (categories[i].getCatName()== Catname) //Check if the entry catagory is in the vector
				{
					found = true;
					CatID = categories[i].getCatID(); //Save the catagory ID in variable
				}
		if (!found)
			cout << "Catagory is invalid"<<endl; //Tell User if the catagory is not found
	}
	while (found == false); //Repeat entry until the catagory is valid
	

	for (int i=0;i<menu_items.size();i++) //For every menu items in vector
		if (menu_items[i].getMenuItemCatID() == CatID) //if Menu items have same catagory as user input
			temp.push_back(menu_items[i]); //Save the menu items in temp vector

	Menu_Item swap(0, 0,0, "", 0, Description(""));
	int iMin,iPos;
	for (iPos = 0; iPos < temp.size(); iPos++) //Sort the temp vector
	{
		iMin = iPos;
		for (int i = iPos+1; i < temp.size(); i++) 
		{
			if (temp[i].getMenuItemPrice() < temp[iMin].getMenuItemPrice()) 
			{
				iMin = i;
			}
		}
 
		if ( iMin != iPos ) 
		{
			swap = temp[iPos];
			temp[iPos] = temp[iMin];
			temp[iMin] = swap;
		}
	}
	
	
	for (int i=0;i<temp.size();i++) //Print Every menu items in temp vector
	{
		cout << "Menu Number " << i << " for " << Catname <<endl;
		cout << "Name : " << temp[i].getMenuItemName() << endl;
		cout << "Price : " << temp[i].getMenuItemPrice() << endl;
		cout << "Description : " << temp[i].getMenuItemDesc() << endl << endl;
	}
}

void Menu::findMenuItem() const //Author : M.O. B.2c
{
	string MenuItemName;
	int MenuItemID;
	double MenuItemPrice;
	bool found = false;
	do 
	{
		cout << "Please enter Menu Item name :";
		cin >> MenuItemName; //request for the catagory name
		for(int i=0;i<menu_items.size();i++) //For every catagory in the vector 
			if (menu_items[i].getMenuItemName()== MenuItemName) //Check if the entry catagory is in the vector
				{
					found = true; 
					MenuItemID = menu_items[i].getMenuItemID(); //Save the catagory ID in variable
					MenuItemPrice = menu_items[i].getMenuItemPrice();
				}
		if (!found)
			cout << "Catagory is invalid"<<endl; //Tell User if the catagory is not found
	}
	while (found == false); //Repeat entry until the catagory is valid
	
	double sum = 0;
	for (int i=0; i<order_items.size();i++) //for every items in orders item vector
	{
		if (order_items[i].getOrderItemMenuItemID() == MenuItemID) //if orders item have the same menu item ID
			sum = sum + (order_items[i].getOrderItemProdQty() * MenuItemPrice); //Sum the price times the quantity
	}
	cout << "Total Sales for " << MenuItemName << " are $ " << sum <<endl;
}

void Menu::updateOrderItem() //Author : M.O. B.3a
{
	int OrdID; //Contain Order ID
	char SeatID; //Contain Temp Seat ID
	int MenuItem; //Contain Temp Menu Item
	int Qty; //Contain Temp Menu Item
	bool found = false; //For Check user entry
	do 
	{
		cout << "Please Enter Order ID :";
		cin >> OrdID; //request for the order id
		for(int i=0;i<orders.size();i++) //For every order in the vector 
			if (orders[i].getOrdID()== OrdID) //Check if the entry order is on the vector
				found = true;
		if (!found) 
			cout << "Order ID is invalid"<<endl; //Tell User if the order is not found
	}
	while (found == false); //Repeat entry until the order id is valid
		
	cout << "Enter number of seat : "; 
	cin >> SeatID; //Request for the seat ID
	
	found = false; //Reinitialize boolean found to false
	do 
	{
		cout << "Enter Menu Item : ";
		cin >> MenuItem; //Request for the Menu Item
		for(int i=0;i<menu_items.size();i++) //For every menu items in the vector 
			if (menu_items[i].getMenuItemID() == MenuItem) //Check if the entry menu items is on the vector
				found = true;
		if (!found) 
			cout << "Menu Items is invalid"<<endl; //Tell User if the menu items is not found
	}
	while (found == false); //Repeat entry until the order id is valid
	

	cout << "Enter number of quantity : ";
	cin >> Qty; //Request for the quantity
	order_items.push_back(Order_Item(SeatID,OrdID,MenuItem,Qty)); //Push the order item to the vector
	cout<< "Adding Order item success" << endl;
}

void Menu::showAnItemRecipe() const	//Author : S.X.-B.1a
{
	//Supporting variables
	int itemID;
	int i;
	string itemName;
	//Description itemDescr;
	string ingre;
	int recipeID;
	bool found = false;

	//check whether there is empty vectors for vectors that are used
	if(menu_items.empty() || recipes.empty() || ingredients.empty())
	{
		cout << "Please use the read menu first.";
	}
	else
	{
		cout << "Input a menu item ID : ";
		cin >> itemID; //request for the menu item ID

		for (i=0; i<menu_items.size(); i++) //itteration in menu_items vector
		{
			if (!found) //if it still not found
			{
				if (itemID == menu_items[i].getMenuItemID()) //check if the entry menu item is in the vector
				{
					found = true;
					itemName = menu_items[i].getMenuItemName(); //store the menu item name in variable
					Description itemDescr = menu_items[i].getMenuItemDesc(); //store the menu item description in variable
					recipeID = menu_items[i].getMenuItemRecipeID(); //store the menu item recipe id in variable
					cout << itemName << endl << itemDescr.display() << endl << endl; //display the item name and item description
				}
			}
		}
		
		if (itemID == 0) //check if the itemID is not in the vector
		{
			cout << "Invalid menu item ID";
		}
		
		found = false;
		cout << "Ingredients : " << endl;
		for (i=0; i<ingredients.size(); i++) //itteration in ingredients vector
		{
				if (recipeID == ingredients[i].GetRecipeID()) //check if the recipe id is in the vector
				{
					ingre = ingredients[i].GetName();  //store the menu item ingredients in variable
					cout << ingre <<endl; //display the item ingredients
				}
		}
		cout << endl;
			
		found = false;
		for (i=0; i<recipes.size(); i++) //itteration in recipes vector
		{
			if (!found) //if it still not found
			{
				if (recipeID == recipes[i].getRecipeID()) //check if the recipe id is in the vector
				{
					found = true;
					Instructions instruct = recipes[i].getRecipeInstr(); //store the menu item instruction in variable
					cout << endl <<endl << "Instruction : " << instruct.display() << endl; //display the item instruction
				}
			}
		}
	}
	//cout << itemName << endl << itemDescr.display() << endl << endl << ingre << endl << endl << instruct.display();

}

void Menu::displayTotalSalesServer() const	//Author : S.X.-B.2b
{
	//Supporting varibles
	int i, k;
	int j = 0;
	int l = 0;
	int ServerID;
	int* OrderID = new int[50];
	int* MenuItemID = new int[50];
	bool found = false;
	double totalOrder = 0;

	cout << "Input server ID : ";
	cin >> ServerID; //request for the order server ID

	cout << "Total sales in that Server : ";
	
	//cout << orders[0].getServerID();
	for (i=0; i<orders.size(); i++) //itteration in orders vector
	{
		if (!found) //if it still not found
		{
			if (ServerID == orders[i].getOrdServerID()) //check if the server id is in the vector
			{
				OrderID[j] = orders[i].getOrdID(); //store the menu item instruction in array of integer
				//cout << OrderID[j];
				j++;
			}
		}
	}
	
	found = false;
	for (i=0; i<order_items.size(); i++) //itteration in order_items vector
	{
		if (!found) //if it still not found
		{
			for (k=0; k<j; k++)  //itteration in array of integer of OrderID
			{
				if (OrderID[k] == order_items[i].getOrderItemID()) //check if the order id is in the vector
				{
					//totalOrder++; //add the amount of total order
					MenuItemID[l] = order_items[i].getOrderItemMenuItemID();
					l++;
				}
			}
		}
	}
	
	found = false;
	for (i=0; i<menu_items.size(); i++)
	{
		if(!found)
		{
			for (k=0; k<l; k++)
			{
				if (MenuItemID[k] == menu_items[i].getMenuItemID())
				{
					totalOrder = totalOrder + menu_items[i].getMenuItemPrice();
				}
			}
		}
	}
	cout << "$ " << totalOrder << endl << endl;  //Display total order for the server
}

void Menu::updateCategories()	//Author : S.X.-B.3c
{
	//Supporting variable
	int a;
	int i;
	int cat_count_new;
	int cat_count, cat_id;	//cat_count = amount of category in list, cat_id = category ID
	string cat_name;	// cat_name = category name

	ifstream file ("Sample_Data/catmenu.dat"); //open database

	if(file.is_open()) //when the file is open
	{
		cout << "How many category do you want to add?" << endl; 
		cin >> a; //request the amount of category that wants to add
		file >> cat_count; //read the amount of category
		cat_count_new = cat_count + a; //store the new amount of category
		
		for (i=0; i<cat_count; i++) //iteration according to the amount of category listed
		{
			file >> cat_id >> cat_name; //read and insert the category id and category name
			categories.push_back(Category(cat_id, cat_name)); //store the information to the categories vector
		}
		
		for (i=cat_count; i<cat_count_new; i++) //itteration according to the amount of new category
		{
			cout << "Category ID : ";
			cin >> cat_id;
			cout << "Category Name : ";
			cin >> cat_name;
			categories.push_back(Category(cat_id, cat_name)); //store the new category to the categories vector
		}

		cout << "Adding categories success."<<endl;
	}
	else
	{
		cout << "File could not be opened successfully.";
	}
	//cout << "success";

}

void Menu::showMenuItem() const
{
	cout << "Enter the name of the chef \n";
	string chefname;
	int recipe=0;
	string itemname;
	double itemprice;
	string description;
	cin >> chefname;
	for(int i=0; i<recipes.size(); i++)
		{
		//cout << recipes[i].Get_Chef_Name() << endl;
		if (chefname==recipes[i].getRecipeChefName())
			{
				recipe = recipes[i].getRecipeID();
				for(int j=0; j<menu_items.size(); j++)
				{
					if(recipe==menu_items[j].getMenuItemRecipeID())
					{
						cout << menu_items[j].getMenuItemName() << '\t' <<
							    menu_items[j].getMenuItemPrice() << '\t' <<
								menu_items[j].getMenuItemDesc() << endl;
					}
				}
			}
		}
	//End of Chef Query
}

void Menu::displayTotalSalesTable() const	//L.C. B.2a
{
		//total sales for a given table - B.2a
	int tablenum = 0;
	int ordernum = 0;
	int menuitem = 0;
	int quant = 0;
	double itemprice = 0;
	double sales = 0;
	int order_id, server_id, table_id; //declares first 3 order elements
	int y, m, d, h, min; //declares date and time elements
	int menu_item_id, prod_qty;		//order items elements
	char seat_id;	//order items elements
	int tablesales=0;
	cout << "Please enter Menu Order Table ID :";
	cin >> tablenum ;
	for(int i = 0; i<orders.size(); i++)
		{
			//tablenum = orders[i].Get_Table_Id();
		if (tablenum==orders[i].getOrdTableID())
		{
		//cout << i;
		ordernum=orders[i].getOrdID();
		//cout << ordernum<< "\n";
		}
	}
	for(int j = 0; j<order_items.size(); j++)
	{
		if (ordernum==order_items[j].getOrderItemID())
		{
			menuitem=order_items[j].getOrderItemMenuItemID();
			quant=order_items[j].getOrderItemProdQty();
			//cout << menuitem<< "\n";
			//cout << quant<< "\n";
			for (int k =0; k<menu_items.size(); k++)
			{
					if(menuitem==menu_items[k].getMenuItemID()) 
						{
							itemprice=menu_items[k].getMenuItemPrice();
					}
			}
			//cout << itemprice<< "\n";
			sales += quant*itemprice;
		}
		//cout << menuitem<< "\n";
		//cout << quant<< "\n";
	}
	cout<< sales<< "\n";
}

void Menu::updateMenuItem()					//L.C. B.3b
{
	cout << "Update queries \n";
	// New Menu Item -L.C., B.3B
	int cat_option;
	int cat_id;	//cat_id = category ID
	int item_id, rec_id;  //item_id = menu item id list, rec_id = recipe ID 
	string item_name;  //item_name = menu item name,
	float price;  //price = menu item price
	string cat_name;	// cat_name = category name
	string desc, word;	// desc = description about the menu
	cout << "Enter an existing recipe id: \n";
	cin >> rec_id;
	cout << "Choose a Menu Category: \n";
	cout << "1. Appetizers \n";
	cout << "2. Entrees \n";
	cout << "3. Desserts \n";
	cout << "4. Drinks \n";
	cin >> cat_option;
	if (cat_option=1)
			 cat_id=1010;
	if (cat_option=2)
			 cat_id=1901;
	if (cat_option=3)
			 cat_id=1576;
	if (cat_option=4)
		 cat_id=1320;
	cout << "Enter a menu item id: \n";
	cin >> item_id;
	cout << "Enter a menu item name: \n";
	cin >> item_name;
	cout << "Enter a price: \n";
	cin >> price;
	cout << "Enter a description followed by '#': \n";
	cin >> word;	//read and insert the description ---->borrowed from ReadMenuDescr read function (S.X.)
	while (word != "#") //read the whole description until "#" found
	{
		desc += word + " ";	//adding the text until stopping point has been found
		cin >> word; //read and insert the description
	}
	Description description = desc; // initiate description variable
	desc = "";	//clearing the content to be used again later
	menu_items.push_back(Menu_Item(item_id, cat_id, rec_id, item_name, price, description));
}