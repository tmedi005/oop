#include <utility>
#include "Inventory.h"

// Allow the compiler to define the remaining
// comparison operators
using namespace std::rel_ops;

/**
 *
 */
Inventory::Inventory() {
    this->slots    = 10;
    this->occupied = 0;

    this->items = new ItemStack[ slots ];
}

/**
 *
 */
Inventory::Inventory( int n ) {
    this->slots    = n;
    this->occupied = 0;

    this->items = new ItemStack[ slots ];
}

/**
 *
 */
Inventory::Inventory( const Inventory &src ) {

    this->slots    = src.slots;
    this->occupied = 0;

    this->items = new ItemStack[ slots ];

    for( int i = 0; i < src.occupied; i++ ) {
        this->addItems( src.items[i] );
    }
}

/**
 *
 */
Inventory::~Inventory() {
    delete[] this->items;
}

/**
 *
 */
bool Inventory::addItems( ItemStack stack ) {
    // Add the first ItemStack
    if( occupied == 0 ){
        this->items[0] = stack;
        occupied++;

        return true;
    }

    // Search for a matching stack
    int loc = 0;

    while( (loc < occupied) && (items[loc] != stack) ) {
        loc++;
    }

    if( loc >= occupied && occupied != slots ){
        items[loc] = stack;

        occupied++;

        return true;
    }

    if( loc < occupied ){
        items[loc].addItems( stack.size() );

        return true;
    }

    return false;
}

/**
 *
 */
void Inventory::display( std::ostream &outs ) const{
    outs << " -Used " << occupied << " of " << slots << " slots" << "\n";

    for( int i = 0; i < occupied; i++ ) {
        outs << "  " << items[i] << "\n";
    }
}

/**
 *
 */
Inventory& Inventory::operator=( const Inventory &rhs ){
    if( this != &rhs ){
        delete[] this->items;

        this->slots    = rhs.slots;
        this->occupied = 0;

        this->items = new ItemStack[ slots ];

        for( int i = 0; i < rhs.occupied; i++ ) {
            this->addItems( rhs.items[i] );
        }
    }

    return *this;
}
