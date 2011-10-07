/*
	The directives starting with # below ensures that this file is read by the compiler only once
	even if it is #included several times. It is call an "include guard"
*/
#ifndef CATEGORY_H_
#define CATEGORY_H_

#include <string>

using namespace std;

struct Category {
public:
	// constructors
	Category () {}
	Category (int catID, string catName) : cat_id(catID), cat_name(catName) {}	//S.X.-A.3

    // utility functions
	string display() const;

private:
   //constants
     
   // private data
	int cat_id;
	string cat_name;
};


#endif //CATEGORY_H_
