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
	
	int Ingredient::GetIngID() const	//Author : S.X.-B.1a
	{
		return (ingredient_id);
	}

	int Ingredient::GetRecipeID() const	//Author : S.X.-B.1a
	{
		return (recipe_id);
	}

	float Ingredient::GetAmt() const	//Author : S.X.-B.1a
	{
		return (amt);
	}

	string Ingredient::GetUnits() const	//Author : S.X.-B.1a
	{
		return (units);
	}

	string Ingredient::GetName() const	//Author : S.X.-B.1a
	{
		return (name);
	}

