//Author : S.X.-B.1a

#include "Recipe.h"
#include <iostream>

int Recipe :: getRecipeID() const
{
	return (recipe_id);
}

string Recipe :: getRecipeChefName() const
{
	return (chef_name);
}

Instructions Recipe :: getRecipeInstr() const
{
	return (instr);
}