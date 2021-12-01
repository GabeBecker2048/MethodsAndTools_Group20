//cpp for shopping cart
#include <string>
#include <vector>

#include "ShoppingCart.h"
#include "item.h"
#include "inventory.h"
#include "json/json.h"

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

 // creates the json dictionary
Json::Value stock_json;	
// loads data from file
std::ifstream stockfile ("./inventory.json");
stockfile >> stock_json;
stockfile.close();
	
for (int i = 0; i<stock_json["name"]; i++) 
{
	if (stock_json["names"][i] == item.get_name())// this code will run if the item is in stock. If the item exists, there is at least one
	{
		incart.push_back(item)
	}		
	} 
 
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
