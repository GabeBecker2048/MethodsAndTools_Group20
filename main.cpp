#include <string>
#include <vector>
#include <iostream>

#include "inventory.h"
#include "item.h"

int main() {
	
	Inventory inventory;
	Item item1("Item1", "Category1", 10.99);
	Item item2("Item2", "Category2", 7.89);
	Item item3("Item3", "Category2", 4.49);
	
	inventory.add_stock(item1, 10);
	inventory.add_stock(item2, 3);
	inventory.add_stock(item3, 5);
	inventory.remove_stock(item1, 4);
	inventory.remove_stock(item2, 2);
	
	vector<Item>stock = inventory.view_stock();
	vector<Item>category1 = inventory.view_category("Category2");
	
	std::cout << stock.size() << std::endl;
	
	for(int i = 0; i < category1.size(); i++) {
		std::cout << category1[i].get_name() << std::endl;
	}
	
}