#include <string>
#include <vector>
#include <fstream>

#include "json/json.h"
#include "item.h"

#ifndef INVENTORY_H
#define INVENTORY_H

using std::string;
using std::vector;

class Inventory
{
private:

	vector<Item> stock;
	
public: 

	void add_stock(Item item, int amount);
	void remove_stock(Item item, int amount);
	vector<Item> view_stock();
	vector<Item> view_category(string category);
	void update();
	void save();
	
	Inventory();
	~Inventory();
	
};

#endif