#ifndef RECIPE_H_
#define RECIPE_H_

#include <string>

// other types
#include "Instructions.h"				//uncomment once you have added the type definition
using namespace std;
 
struct Recipe {
public:
	// constructors
	Recipe (int id, string n, Instructions a)	//uncomment once you have added the type definition
	: recipe_id(id), chef_name(n), instr(a) {}

   // utility functions
	string display() const;
	int getRecipeID() const;		//S.X.-B.1a
	string getRecipeChefName() const;	//S.X.-B.1a
	Instructions getRecipeInstr() const;	//S.X.-B.1a
	
private:
   //constants
     
   // private data
	int recipe_id;
	string chef_name;
	Instructions instr;			//uncomment once you have added the type definition
};


#endif //RECIPE_H_
