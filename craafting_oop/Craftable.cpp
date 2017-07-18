#include "Craftable.h"
#include "Ingredient.h"

/**
 * Default to a Comsumable Item with an empty name
 */
Craftable::Craftable() {
   ingredients      = nullptr;
   ingredient_count = 0;
}

/**
 * Copy Constructor
 */
Craftable::Craftable( const Craftable &src ){
    this->name             = src.name;
    this->ingredient_count = src.ingredient_count;

    this->setUses( src.getUses() );

    ingredients = new Item*[ingredient_count];

    for( int i = 0; i < ingredient_count; i++ ) {
        ingredients[i] = src.ingredients[i]->clone();
    }
}

/**
 * Destructor
 */
Craftable::~Craftable() {
    for( int i = 0; i < ingredient_count; i++ ) {
        delete ingredients[i];
    }

    delete[] ingredients;
}

/**
 * Print the Craftable Item
 */
void Craftable::display( std::ostream &outs ) const {
    outs << this->name      << " - "
         << this->getUses() << " Use(s) Left" << "\n";

    outs << " # Ingredients " << ingredient_count << "\n";

    for( int i = 0; i < ingredient_count; i++ ) {
        outs << "  -" << *ingredients[i];
    }
}

/**
 * Read Craftable Item attributes from an input stream
 */
void Craftable::read( std::istream& ins ) {
    int u; // temporary number of uses
           // (uses is private to Item)

    ins >> this->name
        >> u
        >> this->ingredient_count;

    ingredients = new Item*[ingredient_count];

    // Use Item::setUses to access uses attribute
    this->setUses(u);

    for( int i = 0; i < ingredient_count; i++ ) {
        ingredients[i] = new Ingredient();
        ingredients[i]->read(ins);
    }
}

/**
 * Clone--i.e., copy--this Craftable Item
 */
Item* Craftable::clone() const {
    return new Craftable(*this);
}

/**
 * Assignment Operator
 */
Craftable& Craftable::operator=( const Craftable &rhs ) {
    if( this != &rhs ) {
        // Delete old ingredient list
        for( int i = 0; i < ingredient_count; i++ ) {
            delete ingredients[i];
        }

        delete[] ingredients;

        // Copy
        this->name             = rhs.name;
        this->ingredient_count = rhs.ingredient_count;

        this->setUses( rhs.getUses() );

        ingredients = new Item*[ingredient_count];

        for( int i = 0; i < ingredient_count; i++ ) {
            ingredients[i] = rhs.ingredients[i]->clone();
        }
    }

    return *this;
}
