//shopping cart h file
#include <string>
#include <vector>
#include <fstream>

#include "item.h"
#include "json/json.h"

using std::string;
using std::vector;

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H


class ShoppingCart
{

private:

vector<Item> incart;

public:
void add(Item item);
void remove(Item item);
void remove_all();
vector<Item> view();

ShoppingCart();
~ShoppingCart();

};


#endif
