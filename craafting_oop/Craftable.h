#ifndef CRAFTABLE_H_INCLUDED
#define CRAFTABLE_H_INCLUDED

#include "Item.h"

/**
 * This class represents one Craftable Item. This is an Item that can only
 * be created by the result of crafting
 *
 * Craftable Items may be created from Ingredients, other Craftable Items,
 * or a combination of both.
 */
class Craftable : public Item {
    private:
        /**
         * Array of Item Pointers These represent the
         * Ingredients used to create this Craftable Item
         */
        Item **ingredients;

        /**
         * Number of ingredients used--i.e., size of the
         * ingredients array
         */
         int ingredient_count;

    public:
        /**
         * Default to a Comsumable Item with an empty name
         */
        Craftable();

        /**
         * Copy Constructor
         */
        Craftable( const Craftable &src );

        /**
         * Destructor
         */
        ~Craftable();

        /**
         * Print the Craftable Item
         */
        virtual void display( std::ostream &outs ) const ;

        /**
         * Read Craftable Item attributes from an input stream
         */
        virtual void read( std::istream& ins );

        /**
         * Clone--i.e., copy--this Craftable Item
         */
        virtual Item* clone() const ;

        /**
         * Assignment Operator
         */
        Craftable& operator=( const Craftable &rhs );
};

#endif
