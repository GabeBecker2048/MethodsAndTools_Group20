#include <string>
#include <vector>

#include "inventory.h"
#include "item.h"

using std::string;
using std::vector;

Inventory::Inventory() {
	//something with the files
}

Inventory::~Inventory() {
	vector<Item> stock;
}

void Inventory::add_stock(Item item, int amount) {
	
	
	if(amount > 0) {
		
		// adds the amount to the stock
		for(int i=0; i < amount; i++) {
			stock.push_back(item);
		}
	}
	
	// errors out if amount is not positive
	else {
		return;
	}
}

void Inventory::remove_stock(Item item, int amount){


	if(amount > 0) {
		
		// counts the number of items in stock
		int in_stock=0;
		for(int i = 0; i < stock.size(); i++) {
			if (stock[i].get_name() == item.get_name())
				in_stock++;
		}
		
		// if the requested amount exceedes the current stock, error out
		if(amount > in_stock)
			return;
		
		// if the amount is less than or equal to the amount in stock...
		// removes that amount from the stock (from back of stock to front for easy indexing)
		for(int i = stock.size()-1; i > -1; i--){
			if(stock[i].get_name() == item.get_name() && amount > 0) {
				stock.erase(stock.begin()+i);
				amount--;
			}
		}
	}

	// errors out if amount is not positive
	else {
		return;
	}
}

vector<Item> Inventory::view_stock(){
	return stock;
}

vector<Item> Inventory::view_category(string category){
	
	vector<Item> in_category;
	
	// adds any items that are in the category to the "in_category" vector
	for(int i = 0; i < stock.size(); i++){
		if(stock[i].get_category() == category) 
			in_category.push_back(stock[i]);
	}

	
	return in_category;
}

void Inventory::update(){
	//???
}