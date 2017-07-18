#include <iomanip>

#include "Item.h"

/**
 *
 */
Item::Item()
    :name("Air"),
     uses(1)
{
}

/**
 *
 */
Item::Item( std::string name )
    :name("Air")
{
    this->uses = 1;
}

Item::Item( std::string name, int uses ) {
    this->name = name;
    this->uses = uses;
}

Item::~Item()
{
}


