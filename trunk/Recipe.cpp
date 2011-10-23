//Author : S.X.-B.1a  LC, B.1b

#include "Recipe.h"
#include <iostream>

int Recipe :: getRecipeID() const //S.X.-B.1a  LC, B.1b
{
	return (recipe_id);
}

string Recipe :: getRecipeChefName() const //S.X.-B.1a  LC, B.1b
{
	return (chef_name);
}

Instructions Recipe :: getRecipeInstr() const //S.X.-B.1a  LC, B.1b
{
	return (instr);
}
