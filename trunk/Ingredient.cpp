//Author : M.O.-A.1

#include "Ingredient.h"


using namespace std;

	Ingredient::Ingredient (int ing_id,int rec_id,float a,string u,string n)  //Ingredients Constructor M.O. A.1
	{
		ingredient_id = ing_id;
		recipe_id = rec_id;
		amt = a;
		units = u;
		name = n;
	}

	string Ingredient::display() const	////Return string consist of Ingredients information M.O. A.1
	{
		stringstream  temp;
		temp << "Ingerdient ID : "  << ingredient_id << "\n" ;
		temp << "Recipe ID :" << recipe_id << "\n";
		temp << "Amount :" << amt << "\n";
		temp << "Units :" << units << "\n";
		temp << "Name :" << name << "\n";
		return temp.str();
	}