#ifndef ITEM_H_INCLUDED
#define ITEM_H_INCLUDED

#include <iostream>
#include <string>



/**
 * Item represents an individual Item.
 * This includes items such as potions, building materials, and food.
 *
 * Only one of each item can exist--i.e., if two items have the same name,
 * they are the same type of item. 
 */
class Item{
    private:         
        int uses;        ///< Number of times this item can be used.

    protected:
        std::string name; ///< Short title--e.g., Torch

    public:
        /**
         * Default to name = Air and stackable = true
         */
        Item();

        /**
         * Create an Item with a specified name
         *
         * @pre 
         *  - all items that share a name are of the same type
         *  - differences in capitalization denote different items 
         */
        Item( std::string name );

        /**
         * Create an Item with a specified name and
         * number of uses
         *
         * @param uses number of times this item
         *     can be used before breaking
         *
         * @pre 
         *  - all items that share a name are of the same type
         *  - differences in capitalization denote different items
         */
        Item( std::string name, int uses );

        /**
         * Virtual Destructor
         */
        virtual ~Item();

        /**
         * Retrieve name
         */
        std::string getName() const;

        /**
         * Update name
         */
        void setName( std::string n );

        /**
         * Retrieve number of uses
         */
        int getUses() const;

        /**
         * Set the number of uses
         */
        void setUses( int u );

        /**
         * Can this item be used (Does at lesat one use remain)?
         */
        bool isUsable() const;

        /**
         * Check for logical equivalence--based on name
         */
        bool operator==( const Item &rhs ) const;

        /**
         * Check ordering--based on name
         */
        bool operator<( const Item &rhs ) const;

        /**
         * Print one Item
         */
        virtual void display( std::ostream &outs ) const = 0;

        /**
         * Read the item from an input stream
         */
        virtual void read( std::istream& ins ) = 0;

        /**
         * Copy this Item--i.e., duplicate this Item
         */
        virtual Item* clone() const = 0;
};

/**
 * Print one Item by invoking display--through dynamic binding
 */
inline
std::ostream& operator<<( std::ostream &outs, const Item &prt ) {
    prt.display( outs );

    return outs;
}

/**
 * 
 */
inline
std::string Item::getName() const {
    return this->name;
}

/**
 * 
 */
inline
void Item::setName( std::string n ) {
    this->name = n;
}


/**
 * Retrieve number of uses
 */
inline
int Item::getUses() const {
    return this->uses;
}

/**
 * Set the number of uses
 */
inline
void Item::setUses( int u ) {
    this->uses = u;
}



/**
 *
 */
inline
bool Item::isUsable() const {
    return this->uses > 0;
}

/**
 *
 */
inline
bool Item::operator==( const Item &rhs ) const {
    return this->name == rhs.name;
}

/**
 *
 */
inline
bool Item::operator<( const Item &rhs ) const {
    return this->name < rhs.name;
}

#endif