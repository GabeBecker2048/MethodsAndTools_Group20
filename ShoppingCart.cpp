//cpp for shopping cart
#include <string>
#include <vector>

#include "ShoppingCart.h"
#include "item.h"
#include "inventory.h"

using std::string;
using std::vector;
using namespace::std:

ShoppingCart::ShoppingCart()
{


}

ShoppingCart::~ShoppingCart()
{


}

void ShoppingCart::add(item)//adds item to cart
{
/// if(item.view_stock !=0)???
 incart.push_back(item)
}

void ShoppingCart::remove(item)//removes an instance of an item from cart
{
 for(int i;i<cart.size();i++)
 {
  if(item == (incart.begin()+i) )//erases one instance of an item in cart
  {
  incart.erase(incart.begin()+i);
  break
   }
  }
}

void ShoppingCart::remove_all()//clears all items from cart
{
 for(int i;i<cart.size();i++)
     {
         incart.erase(incart.begin()+i);
     }
}
void ShoppingCart::view()//prints a list of items in cart
{
 for(int i;i<cart.size();i++)
     {
         cout<<" "<<(incart.begin()+i);
     }
cout<<endl;
}
