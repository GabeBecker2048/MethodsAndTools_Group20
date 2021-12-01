#include <string>

#ifndef ITEM_H
#define ITEM_H

using std::string;

class Item
{
private:

	string name, category;
	float price;
	
public:

	Item(string name, string category, float price): name(name), category(category), price(price) {}
	string get_name();
	string get_category();
};

#endif
	