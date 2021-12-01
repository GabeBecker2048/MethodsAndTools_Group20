//shopping cart h file
#include <string>
#include <vector>

#include "item.h"
#include "inventory.h"

#ifndef SHOPPINGCART_H
#define SHOPPINGCART_H

using std::string;
using std::vector;



Class ShoppingCart
{

private:

  vector<Item> incart;

public:
  void add ();
  void remove ();
  void remove_all():
  void view();

  ShoppingCart();
  ~ShoppingCart();

};


#endif
