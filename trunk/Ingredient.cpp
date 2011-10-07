//Author : M.O.-A.1

#include "Ingredient.h"
#include <iostream>
#include <sstream>

using namespace std;

	Ingredient::Ingredient (int ing_id,int rec_id,float a,string u,string n) 
	{
		ingredient_id = ing_id;
		recipe_id = rec_id;
		amt = a;
		units = u;
		name = n;
	}

	string Ingredient::display() const	//S.X.-A.3
	{
		stringstream  temp;
		temp << "Ingerdient ID : "  << ingredient_id << "\n" ;
		temp << "Recipe ID :" << recipe_id << "\n";
		temp << "Amount :" << amt << "\n";
		temp << "Units :" << units << "\n";
		temp << "Name :" << name << "\n";
		return temp.str();
	}