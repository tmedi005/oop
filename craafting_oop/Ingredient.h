#ifndef INGREDIENT_H_INCLUDED
#define INGREDIENT_H_INCLUDED

#include "Item.h"

/**
 * This class represents one Ingredient. This is an Item used in recipes to
 * craft other items. 
 *
 * It a base ingredient--i.e., it can not be crafted. Consider it to be a raw mnaterial
 *
 */
class Ingredient : public Item{
    private:        

    protected:

    public:
        /**
         * Default to a Comsumable Item with an empty name
         */
        Ingredient(); 

        /**
         * Print the Ingredient Item
         */
        virtual void display( std::ostream &outs ) const;

        /**
         * Read Ingredient Item attributes from an input stream
         */
        virtual void read( std::istream& ins );

        /**
         * Clone--i.e., copy--this Ingredient Item
         */
        virtual Item* clone() const;
};

#endif