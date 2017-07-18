#include <iostream>
#include <fstream>
#include <string>
#include <cstdlib>
#include <vector>
#include <algorithm>

#include "Inventory.h"
#include "ItemStack.h"
#include "Item.h"

using namespace std;

/**
 * Trim leading and trailing whitespace from a string.
 * 
 * @param str string to prune
 * 
 * @pre str is nonempty
 */
void trim( string &str );

/**
 * Read file containing the list
 * of all items
 *
 * @return vector<ItemStack> collection of un-merged stacks of items
 */
vector<ItemStack> parseItemList( istream &inf );

/**
 * Create an empty Invetory object. Take the raw listing
 * of ItemStacks and add them to the Inventory object--while
 * merging ItemStacks containgin the same type of item.
 *
 * @param items collection of un-merged ItemStack entries
 * @param capacity size of the new Inventory
 *
 * @pre items is non-empty
 */
Inventory fillInventory( const vector<ItemStack> &items, int capacity );

/**
 * Generate a summary of the un-merged ItemStacks
 */
void printItems( const vector<ItemStack> &items );

/**
 * Generate a summary of Inventory utilization
 */
void printInventory( const Inventory &storage );

/**
 * Assignment 1: Item Inventory
 *
 * @param argv[1] Items filename
 * @param argv[2] Inventory capacity
 */
int main( int argc, char** argv ){        
    vector<ItemStack> item_list; // Listing of Items (as ItemStacks)
    Inventory storage;           // One Inventory
    int desired_size;            // Desired Inventory Capacity

    ifstream infile;  

    // Check Command Line Arguments
    if( argc != 3 ){
        cerr << "Usage: " << argv[0] << " item_file inventory_size" << "\n";
        return 1;
    }

    desired_size = atoi( argv[2] );

    if( desired_size < 1 ) {
        cerr << desired_size << " is not a valid capacity" << "\n";
        return 4;
    }

    // Open list_file
    infile.open( argv[1] );
    if( !infile ){
        cerr << "Error: " << argv[1] << " could not be opened" << "\n";
        return 2;
    }

    // Read listing of possible items
    item_list = parseItemList( infile );

    // Close and reset for the next file
    infile.close();
    infile.clear();

    printItems( item_list );

    storage = fillInventory( item_list, desired_size );    

    printInventory( storage );

    return 0;
}

/**
 *
 */
void trim( std::string &str ){
    if( str.empty() ){
        return;
    }

    int first_nonspace = str.find_first_not_of(" \t");
    int last_non_space = str.find_last_not_of(" \t");

    str = str.substr( 
        first_nonspace,
        last_non_space + 1
    );
}

/**
 *
 */
vector<ItemStack> parseItemList( istream &inf ){
    vector<ItemStack> items;

    int id;    // Temporary item id
    int count; // Temporary item count
    string n;  // Temporary item name

    while( inf >> id ){  
        inf >> ws;

        inf >> count;
        getline( inf, n );
        trim(n);

        inf >> ws;        

        items.push_back( 
            ItemStack(
                Item( id, n ),
                count
            )
        );
    }

    return items;
}

/**
 *
 */
Inventory fillInventory( const vector<ItemStack> &items, int capacity ) {
    Inventory inv( capacity ); // Collection of Inventory instances 

    cout << "Processing Log:" << "\n";

    for( ItemStack s : items ) {     
        if( !(inv.addItems(s)) ){
           cout << " Discarded " << s << "\n";
        }
        else{
            cout << " Stored "   << s << "\n";
        }    
    }

    cout << "\n";

    return inv;
}

/**
 * 
 */
void printItems( const vector<ItemStack> &items ){
    cout << "\n";
    cout << "Item Listing: " << "\n";

    for( ItemStack it : items ) {
        cout << " " << it << "\n";
    }   

    cout << "\n";
}

/**
 * 
 */
void printInventory( const Inventory &storage ){
    cout << "Inventory Summary:" << "\n";
    cout << storage << "\n"; 
}