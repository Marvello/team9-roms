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
	cout << "Show queries \n";
	showCatagoryItem();
}
void Menu::find() const 
{
	cout << "Find queries \n";
	findMenuItem();
}
void Menu::update()  
{
	cout << "Update queries" << endl;
	updateOrderItem();
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
			// cout << ing_id << " " << recipe_id << " " << Ingamt << " " << Ingunits << " " << Ingname;
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

void Menu::showCatagoryItem() const //Author : M.O. B.3a
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
	

	for (int i=0;i<menu_items.size();i++)
		if (menu_items[i].getMenuItemCatID() == CatID)
			temp.push_back(menu_items[i]);

	Menu_Item swap(0, 0,0, "", 0, Description(""));
	int iMin,iPos;
	for (iPos = 0; iPos < temp.size(); iPos++) 
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
	
	
	for (int i=0;i<temp.size();i++)
	{
		cout << "Menu Number " << i << " for " << Catname <<endl;
		cout << "Name : " << temp[i].getMenuItemName() << endl;
		cout << "Price : " << temp[i].getMenuItemPrice() << endl;
		cout << "Description : " << temp[i].getMenuItemDesc() << endl << endl;
	}
}

void Menu::findMenuItem() const //Author : M.O. B.3a
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
	for (int i=0; i<order_items.size();i++)
	{
		if (order_items[i].getOrderItemMenuItemID() == MenuItemID)\
			sum = sum + (order_items[i].getOrderItemProdQty() * MenuItemPrice);
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