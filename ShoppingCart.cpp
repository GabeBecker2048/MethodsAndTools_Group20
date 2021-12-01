//cpp for shopping cart

#include "ShoppingCart.h"


using std::string;
using std::vector;
using namespace::std;

ShoppingCart::ShoppingCart()
{


}

ShoppingCart::~ShoppingCart()
{


}

void ShoppingCart::add(Item item)//adds item to cart
{

 // creates the json dictionary
Json::Value stock_json;	
// loads data from file
std::ifstream stockfile ("./inventory.json");
stockfile >> stock_json;
stockfile.close();
	
for (int i = 0; i<stock_json["name"].size(); i++) 
{
	if (stock_json["names"][i] == item.get_name())// this code will run if the item is in stock. If the item exists, there is at least one
	{
		incart.push_back(item);
	}		
	} 
 
}

void ShoppingCart::remove(Item item)//removes an instance of an item from cart
{
 for(int i;i<incart.size();i++)
 {
  if(item.get_name() == incart[i].get_name() )//erases one instance of an item in cart
  {
  incart.erase(incart.begin()+i);
  break;
   }
  }
}

void ShoppingCart::remove_all()//clears all items from cart
{
 for(int i;i<incart.size();i++)
     {
         incart.erase(incart.begin()+i);
     }
}

vector<Item> ShoppingCart::view()//prints a list of items in cart
{
return incart;
}
