//tests the shopping cart. Not part of final code.


#include <string>
#include <vector>
#include <iostream>

#include "ShoppingCart.h"
#include "inventory.h"
#include "item.h"

int main()

{
ShoppingCart ShoppingCart;

  Inventory inventory;//taken from inventory test.
	Item item1("Item1", "Category1", 10.99);
	Item item2("Item2", "Category2", 7.89);
	Item item3("Item3", "Category2", 4.49);
	
	inventory.add_stock(item1, 10);
	inventory.add_stock(item2, 3);
	inventory.add_stock(item3, 5);
	
  //test inventory
  //Item1:10
  //Item2:3
  //Item3:5
  
  ShoppingCart.add(item1);
  ShoppingCart.add(item1);
  ShoppingCart.add(item1);
    
  ShoppingCart.add(item2);
  
  ShoppingCart.add(item3);
  
  ShoppingCart.view();
  //supposed outcome
  //item1:3
  //item2:1
  //item3:1
  
  ShoppingCart.remove(item1);
  ShoppingCart.remove(item2);
  
  ShoppingCart.view();
  //supposed outcome
  //item1:2
  //item3:1 
  
  
  ShoppingCart.remove_all();
  ShoppingCart.view();
  //cart should be empty
  
  
	
	
}
