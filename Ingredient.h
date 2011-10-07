#ifndef INGREDIENT_H_
#define INGREDIENT_H_

#include <string>
using namespace std;


struct Ingredient {
public:
	// constructors
	Ingredient (int ing_id,int rec_id,float a,string u,string n); //add int ing_id,int rec_id,float a,string u,string n on the constructor M.O. A.1

   // utility functions
	string display() const;

private:
   //constants  

   // private data
	int ingredient_id;
	int recipe_id;
	float amt;
	string units;
	string name;
};


#endif //INGREDIENT_H_