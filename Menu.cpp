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
	cout << "4. Print all order IDs and the tab price sorted by date" << endl;
	cout << "5. Print all menu item in a given order by price" << endl;
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((0 <= choice) && (choice <= 5)))
			cout<< "Invalid input" << endl;
	}
	while (not((0 <= choice) && (choice <= 5)));
	
	if (choice == 1)
		showAnItemRecipe();
	else if (choice ==2)
		showMenuItem();
	else if (choice ==3)
		showCatagoryItem();
	else if (choice ==4)
		ListOrderByDate();
	else if (choice ==5)
		ListItemByPrice();
}

void Menu::find() const 
{
	int choice;
	cout << "Please Select One" << endl;
	cout << "1. Display Total sales for a table "<< endl;
	cout << "2. Displat Total sales for a server "<< endl;
	cout << "3. Display Total sales for a menu item"<< endl;
	cout << "4. Display the top five selling menu items by revenue regardless of category"<< endl;//LC - C.2(c)
	cout << "5. Display the order with the largest tab price"<< endl;//LC - C.2(c)
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((1 <= choice) && (choice <= 5)))
			cout<< "Invalid input" << endl;
	}
	while (not((1 <= choice) && (choice <=5))); //3 changed to 5, LC
	
	if (choice == 1)
		displayTotalSalesTable();
	else if (choice == 2)
		displayTotalSalesServer();
	else if (choice == 3)
		findMenuItem();
	else if (choice == 4)     //LC - C.2(c)
		displayTop5MenuItems();
	else if (choice == 5)	//LC - C.2(c)
		displayTopOrderTabPrice();
}

void Menu::update()  
{
	int choice;
	cout << "Please Select One" << endl;
	cout << "1. Add new order item to existing order "<< endl;
	cout << "2. Add new menu item to category from existing recipe "<< endl;
	cout << "3. Add new categories"<< endl;	
	cout << "4. Add new menu item to category from existing recipe "<< endl;
	cout << "5. Add new categories"<< endl;
	cout << "6. Delete Orders"<< endl;
	cout << "7. Delete menu items from catagory"<< endl;
	cout << "0. exit"<< endl;
	cout << ">>"; 
	do
	{
		cin >> choice;
		if (not ((1 <= choice) && (choice <= 7)))
			cout<< "Invalid input" << endl;
	}
	while (not((1 <= choice) && (choice <= 7)));
	
	if (choice == 1)
		updateOrderItem();
	else if (choice ==2)
		updateMenuItem();
	else if (choice ==3)
		updateCategories();	
	else if (choice ==4)
		updateOrder();
	else if (choice ==5)
		updateMenuItem2();
	else if (choice ==6)
		deleteOrder();
	else if (choice ==7)
		deleteMenuItem();
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
	int* OrderID = new int[100];
	int* MenuItemID = new int[100];
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

void Menu::ListOrderByDate() const			//S.X. - C.1a
{
	//vector<Date> OrderDate;
	//vector<int> OrderID;
	int* OrderID = new int[100];
	Date* OrderDate = new Date[100];
	double* OrderPrice = new double[100];
	int* MenuItemID = new int[100];
	double* ItemPrice = new double[100];
	int temp;
	Date temp2;
	double temp3;
	int f=0;
	int g=0;
	int k=0;
	int p =0;
	double Price;
	bool before = false;
	int MenuItem;
	//int y, m, d;
	
	for (int i=0; i<orders.size(); i++)
	{
		OrderID[f] = orders[f].getOrdID();
		OrderDate[f] = orders[f].getOrdDate();
		/*for (int j=0; j<order_items.size(); j++)	//find the same menu item id in order item vector
		{
			if (OrderID[f] == order_items[j].getOrderItemID())
			{
				MenuItemID[k] = order_items[j].getOrderItemMenuItemID();
				//cout << MenuItemID[k] << endl;
				for (int m=0; m<menu_items.size(); m++)
				{
					if (MenuItemID[k] == menu_items[m].getMenuItemID())
					{
						Price = Price + menu_items[m].getMenuItemPrice();
						//cout << Price << endl;
					}
				}
				
			}
			//ItemPrice[k] = Price;
			k++;
			//p++;
			//Price = 0;
		}*/
		
		//k=0;
		/*for (int j=0; j<menu_items.size(); j++)
		{
			if (MenuItemID[j] == menu_items[j].getMenuItemID())
			{
				Price = Price + menu_items[j].getMenuItemPrice();
			}
			//k++;
		}*/
		//ItemPrice[f] = Price;	//make a list for price
		//cout << OrderID[f];
		f++;
		//OrderID.push_back(orders[f].getOrdID());
		//f++;
		//OrderDate.push_back(orders[g].getOrdDate());
		//g++;
	}
	
	for (int i=0; i<f-1; i++)
	{
		for (int j=i+1; j<f; j++)
		{
			if(orders[j].getOrdDate().getYear() < orders[i].getOrdDate().getYear()) 
			{
				before = true;
			}
			else if(orders[j].getOrdDate().getYear() == orders[i].getOrdDate().getYear())
			{
				if(orders[j].getOrdDate().getMonth() < orders[i].getOrdDate().getMonth()) 
				{
					before = true;
				}
				else if(orders[j].getOrdDate().getMonth() == orders[i].getOrdDate().getMonth())
					if (orders[j].getOrdDate().getDay() < orders[i].getOrdDate().getDay()) 
					{
						before = true;
					}
			}
			
			if (before = true)
			{
				temp = OrderID[j];
				OrderID[j] = OrderID[i];
				OrderID[i] = temp;
				
				temp2 = OrderDate[j];
				OrderDate[j] = OrderDate[i];
				OrderDate[i] = temp2;
				
				//temp3 = ItemPrice[j];
				//ItemPrice[j] = ItemPrice[i];
				//ItemPrice[i] = temp3;
			}
		}
	}
	
	for (int i=0; i<f; i++)
	{
		for (int j=0; j<order_items.size(); j++)
		{
			if (OrderID[i] == order_items[j].getOrderItemID())
			{
				for (int v=0; v<menu_items.size(); v++)
				{
					if (order_items[j].getOrderItemID() == menu_items[v].getMenuItemID())
					{
						Price += menu_items[v].getMenuItemPrice();
					}
				}
			}
		}
		ItemPrice[i] = Price;
		//OrderID[f] = orders[f].getOrdID();
		cout << OrderID[i] << " " << OrderDate[i].getDay() << "-" << OrderDate[i].getMonth() << "-" << OrderDate[i].getYear() << " " << "$" << ItemPrice[i] << endl;
	}
}

void Menu::ListItemByPrice() const	//S.X. - C.1b
{
	//Supporting variables
	double priceA, priceB;
	long double* ItemPrice = new long double[500];
	int* ItemID = new int[500];
	int temp;
	double temp2;
	int f=0;
	
	for (int i=0; i<menu_items.size(); i++)
	{
		priceA = 0;
		ItemID[f] = menu_items[f].getMenuItemID();	//make a list for menu item id
		for (int j=0; j<order_items.size(); j++)	//find the same menu item id in order item vector
		{
			if (ItemID[f] == order_items[j].getOrderItemMenuItemID())
			{
				priceA = priceA + menu_items[f].getMenuItemPrice()*order_items[j].getOrderItemProdQty();	//multiple quantity ordered with menu item price
			}
		}
		ItemPrice[f] = priceA;	//make a list for price
		//cout << ItemID[f] << " " << ItemPrice[f];
		f++;
	}
	
	//Bubble sorting based on quantity price
	for (int i=0; i<f; i++)
	{
		for (int j=f-1; j>=i; j--)
		{
			if (ItemPrice[j] > ItemPrice[j-1])
			{
				temp = ItemID[j];
				ItemID[j] = ItemID[j-1];
				ItemID[j-1] = temp;
				
				temp2 = ItemPrice[j];
				ItemPrice[j] = ItemPrice[j-1];
				ItemPrice[j-1] = temp2;
			}
		}
	}
	for (int i=0; i<f-1; i++)
	{
		//OrderID[f] = orders[f].getOrdID();
		cout << ItemID[i] << " " << "$" << ItemPrice[i] << endl;
	}
}

void Menu::displayTop5MenuItems() const 	//L.C., C.2-c
{
	int quant=0;	
	double price;
	int menuitem;
	double revenue;
	vector<double> itemrevenues;
	for (int i=0; i<menu_items.size();i++)    //finds menu items for every order and the amount spent on each menu item, then adds them together
	{
		quant=0;
		price = menu_items[i].getMenuItemPrice();
		//cout << price << endl;
		menuitem = menu_items[i].getMenuItemID();
		for (int j=0; j<orders.size();j++)
		{
			if (menuitem == order_items[j].getOrderItemMenuItemID())
			{
				quant += order_items[j].getOrderItemProdQty(); //adds quantity for each order
			}
		}
		//cout << quant << endl;
		revenue = price*quant;
		//cout << revenue << endl;
		itemrevenues.push_back(revenue);  //vector containing the revenues from each menu item
	}
	double maxrevenue;
	vector<double>tempitemrevenues = itemrevenues;
	vector<int> positions;
	maxrevenue=tempitemrevenues[0];
	int position = 0;
	//cout << "Positions: \n";
	for (int j=0; j<itemrevenues.size(); j++) //sorts item revenues and keeps track of their positions
	{
		for (int i=0; i<itemrevenues.size(); i++) //finds current maximum revenue and its position in itemrevenues
		{
			if (tempitemrevenues[i]>=maxrevenue)
			{
				maxrevenue=tempitemrevenues[i];
				position = i;
			}
		}
		maxrevenue=-1;
		tempitemrevenues[position]=0; //once position i is found, the revenue in that position is set to 0 in tempitemrevenues order to find the position for the next highest revenue
		//cout << position << endl;
		positions.push_back(position);
	}
	int top1, top2, top3, top4, top5;
	top1 = positions[0]; //position in itemrevenues with menu item of highest revenue
	top2 = positions[1];
	top3 = positions[2];
	top4 = positions[3];
	top5 = positions[4];
	cout << "Top 5 Selling Menu Items by Revenue \n";
	cout << menu_items[top1].getMenuItemName() << " $" << itemrevenues[top1] <<endl; //positions[0]
	cout << menu_items[top2].getMenuItemName() << " $" << itemrevenues[top2] <<endl;//positions[1]
	cout << menu_items[top3].getMenuItemName() << " $" << itemrevenues[top3] <<endl; //positions[2]
	cout << menu_items[top4].getMenuItemName() << " $" << itemrevenues[top4] <<endl; //positions[3]
	cout << menu_items[top5].getMenuItemName() << " $" << itemrevenues[top5] <<endl; //positions[4]
}

void Menu::displayTopOrderTabPrice() const 	//L.C., C.2-d
{
	int quant=0;
	double price=0; 
	double tabprice=0;
	int menuitem;
	int orderid;
	vector<double> tabprices;
	for (int i=0; i<order_items.size();i++) //finds tab prices for each order
	{
		tabprice=0;
		orderid = order_items[i].getOrderItemID();
		for (int j=0; j<order_items.size(); j++)
		{
			if(orderid == order_items[j].getOrderItemID())
			{
				quant = order_items[j].getOrderItemProdQty(); //finds quantity of order item in an order
				menuitem = order_items[j].getOrderItemMenuItemID(); //finds the menu item ordered
				for(int k=0; k<menu_items.size(); k++)
				{
					if(menuitem == menu_items[k].getMenuItemID())
						price = menu_items[k].getMenuItemPrice();  //finds the price of the menu item ordered
				}
				tabprice += quant*price; //adds on amount spent for each menu item ordered
				quant = 0;   //reset quant and price to 0 before running loop again
				price = 0;
				//cout << menuitem << endl;
				//cout << tabprice << endl;
			}
		}
		//cout << orderid << endl;
		//cout << tabprice << endl;
		tabprices.push_back(tabprice);
	}

	double maxtabprice;
	vector<double>temptabprices = tabprices;
	vector<int> positions;
	maxtabprice=temptabprices[0];
	int position = 0;
	//cout << "Positions: \n";
	for (int j=0; j<tabprices.size(); j++) //sorts order tab prices and keeps track of their positions
	{
		for (int i=0; i<tabprices.size(); i++)
		{
			if (temptabprices[i]>=maxtabprice)	//once position i is found, the tab price in that position is set to 0 in temptabprices order to find the position for the next highest tab price
			{
				maxtabprice=temptabprices[i];
				position = i;
			}
		}
		maxtabprice=-1;
		temptabprices[position]=0;
		//cout << position << endl;
		positions.push_back(position);
	}
	int top1;
	top1 = positions[0];	//position in tab prices with order of highest revenue
	cout << "Order with largest tab price: \n";
	cout << order_items[top1].getOrderItemID() << " $" << tabprices[top1] <<endl; //positions[0]
}

void Menu::updateRecipe(int RecipeID)		//M.O. C.3f
{
	string ChefName;  //Variable that contain user entry Chef Name
	string Ins = ""; //Variable that contain user entry Instruction
	string temp;
	bool valid = false;
	
	cout<< ">>Please enter Chef Name : "; 
	cin >> ChefName; //Request for user entry
	cout<< ">>Please enter instruction end with # : " << endl;
	do //While Instruction don't end with #
	{
		cin >> temp; //request for user entry Instruction
		Ins = Ins + " " + temp;
	}
	while (Ins.at(Ins.length()-1)!= '#');
	recipes.push_back(Recipe(RecipeID,ChefName,Instructions(Ins))); //Insert Recipe to Recipes vector
}

void Menu::updateMenuItem2()				//M.O. C.3f
{
	cout << "Update Menu Items" << endl;
	int MItemID; //Variable that contain user entry Menu Item ID
	int CatID; //Variable that contain user entry Catagory ID
	int RecID; //Variable that contain user entry Recipe ID
	string MItemName; //Variable that contain user entry Menu Item Name
	double Price; //Variable that contain user entry MEnu Item Price
	string descr,temp; //Variable that contain user entry Description
	
	cout<< ">>Please enter menu item ID : ";
	cin >> MItemID; //request for MEnu Item ID
	cout<< "Catagories";
	for(int i=1; i =categories.size();i++)
		cout << i << ". " << categories[i-1].getCatID() << "\t"	 <<categories[i-1].getCatName() << endl; //Show all possible catagory
	cout << ">>Please enter catagory ID : ";
	cin >> CatID; //request for user entry catagory ID
	cout << ">>Please enter Recipe ID : ";
	cin >> RecID; //request for user entry recipe ID
	updateRecipe(RecID); //Call the procedure Update Recipe to add new recipe
	cout << ">>Please enter menu item name : "; 
	cin >> MItemName; ////request for user entry Menu Item Name
	cout << ">>Please enter menu item price : ";
	cin >> Price; //request for user entry Menu Item Price
	cout<< ">>Please enter description end with # : " << endl;
	do 
	{
		cin >> temp; //request for user entry Description into temp description
		descr = descr + " " + temp; //Adding Description with the temp description
	}
	while (descr.at(descr.length()-1)!= '#'); // while the description not end by '#'
	menu_items.push_back(Menu_Item(MItemID,CatID,RecID,MItemName,Price,Description(descr))); //Insert the MEnu Item into vector
	cout << "Menu Item has successfully Added" <<endl;
}

void Menu::updateOrder()					//M.O. C.3e
{
	int OrdID;  //Variable that contain user entry Order ID
	int TableID; //Variable that contain user entry Table ID
	int DateDD, DateMM, DateYY;  //Variable that contain user entry Date
	int TimeHH, TimeMM; //Variable that contain user entry Time
	bool valid = false; //Variable used to check whether the user entry valid or not
	
	cout<< ">>Add Order" << endl;
	cout<< ">>Please enter order ID : ";
	cin >> Ord; //request for user entry Order ID	
	cout<< ">>Please enter server ID : ";
	cin >> ServerID; //request for user entry Server ID
	cout<< ">>Please enter table ID : ";
	cin >> TableID; //request for user entry Table ID
	do 
	{
		cout<< ">>Please enter date seperate by space(DD MM YY) : ";
		cin >> DateDD >> DateMM >>DateYY; //request for user entry Date
		if ((1 <= DateDD) and (DateDD <= 31) and (1 <= DateMM) and (DateMM<= 12)) //Check is the Date valid
			valid = true;
		else 
			cout << ">>Date is invalid. Please try again" <<endl;
	}
	while (!valid);  //while the date is invalid
	valid = false;
	do 
	{
	cout<< ">>Please enter time seperate by space(HH MM) : ";
	cin >> TimeHH >> TimeMM; //request for user entry Time
		if ((0 <= TimeHH) and (TimeHH <= 23) and (0 <= TimeMM) and (TimeMM<= 59))//Check is the Time Valid
			valid = true;
		else 
			cout << ">>Time is invalid. Please try again" <<endl;
	}
	while (!valid);  //while the time is invalid

	valid = false;
	
	orders.push_back(Order(OrdID,ServerID,TableID,Date(DateDD,DateMM,DateYY),Time(TimeHH,TimeMM))); //Added the new Order into vector
	cout << ">>NEW order added"<<endl;
}

void Menu::deleteOrder()					//M.O. C.3
{
	int OrdID;   //Variable that contain user entry Order ID ID
	bool found = false; //Variable to check whether Order ID exist
	vector<Order>::iterator tempIterator;  //Variable to iterate the vector
	vector<Order>::iterator idx; //Variable contain Order ID posisition

	cout << "Delete Order Query"<<endl;
	cout << "Please enter Order ID : ";
	cin >> OrdID;  //Request for user entry order ID

	for (tempIterator = orders.begin() ;tempIterator !=orders.end() ;++tempIterator) //For every element inside the vector
		if ((*tempIterator).getOrdID() == OrdID){ //If The Order ID is the same with user entry
			idx = tempIterator; //Save the position to idx
			found = true; //And found == true
		}

	if (found) //if Posisition found
		{
			// cout << orders.size(); //for Debugging purpose
			orders.erase(idx); //Erase the order ID index idx
			// cout << orders.size(); //for Debugging purpose
			cout<< OrdID << " is successfully deleted." <<endl;
		}
	else //if not found
		cout << "Order ID " << OrdID << " not found" <<endl; //tell the user order id not found
}

void Menu::deleteMenuItem()					//M.O. C.3
{
	int MenuItemID, CatagoryID; //Variable that contain user entry Menu Item ID  and catagory ID
	bool found = false; //Variable to check whether Order ID exist
	vector<Menu_Item>::iterator tempIterator;//Variable to iterate the vector
	vector<Menu_Item>::iterator idx;//Variable contain Order ID posisition

	cout << "Delete Menu Item from Catagory Query"<<endl;
	cout << "Please enter Menu Item ID";
	cin >> MenuItemID;//Request for user entry menu item ID
	cout << "Please enter Catagory ID";
	cin >> CatagoryID;//Request for user entry catagory ID
	
	for (tempIterator = menu_items.begin() ;tempIterator !=menu_items.end() ;++tempIterator) //For every element inside the vector
	{
		if (((*tempIterator).getMenuItemID() == MenuItemID) and ((*tempIterator).getMenuItemCatID() == CatagoryID)) {//If The menu item ID and catagory ID is the same with user entry 
			idx = tempIterator;//Save the position to idx
			found = true;//And found == true
		}
	}
	
	if (found) //if Posisition found
		{
			// menu_items.size(); //for Debugging purpose
			menu_items.erase(idx); //Erase the menu item in index idx
			// menu_items.size(); //for Debugging purpose
			cout<< "Menu item with ID " << MenuItemID << "from catagory ID " << CatagoryID << " is successfully deleted." <<endl;
		}
	else //if Posisition not found
		cout << "Menu Item ID " << MenuItemID << " from catagory " << CatagoryID << " not found" <<endl; //tell the user order id not found
}
