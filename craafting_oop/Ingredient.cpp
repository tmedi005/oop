#include "Ingredient.h"

using namespace std;
int main()
{
    return 0;
}


/**
 * Default to a Comsumable Item with an empty name
 */

Ingredient::Ingredient()
    :Item()
{
}

/**
 * Print the Ingredient Item
 */
void Ingredient::display( std::ostream &outs ) const {
    outs << this->name << "\n";
}

/**
 * Read Ingredient Item attributes from an input stream
 */
void Ingredient::read( std::istream& ins ) {
    ins >> this->name;
}

/**
 * Clone--i.e., copy--this Ingredient Item
 */
Item* Ingredient::clone() const {
    return new Ingredient(*this);
}
