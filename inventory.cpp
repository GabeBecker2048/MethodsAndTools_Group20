
#include "inventory.h"


using std::string;
using std::vector;

Inventory::Inventory() {
		
	//update();
	
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
	
	// creates the json dictionary
	Json::Value stock_json;
	
	// loads data from file
	std::ifstream stockfile("./data/Stock.json");
	stockfile >> stock_json;
	stockfile.close();
	
	
	// rebuilds the stock vector from stock.json
	stock.clear();
	for(int i = 0; i < stock_json["item name"].size(); i++) {
		
		string category = stock_json["categories"][i].asString();
		string name = stock_json["item name"][i].asString();
		int amount = stock_json["item amount"][i].asInt();
		float price = stock_json["price"][i].asFloat();
		
		add_stock(Item(name, category, price), amount);
	}
}

void Inventory::save() {
	
	// creates the json dictionary
	Json::Value stock_json;
	
	// loops though the stock
	for(int i = 0; i < stock.size(); i++) {
		
		// checks if the item is already in the stock_json
		bool found = false;
		for(int j = 0; j < stock_json["item name"].size(); j++) {
			
			// adds to amount if already found
			if (stock[i].get_name() == stock_json["item name"][j].asString()) {
				
				// increments the amount
				stock_json["item amount"][j] = stock_json["item amount"][j].asInt() + 1;
				
				found = true;
			}
		}
	
		// if the item is not already in the json dictionary, it is added
		if (!found) {
			stock_json["categories"].append(stock[i].get_category());
			stock_json["item name"].append(stock[i].get_name());
			stock_json["item amount"].append(1);
			stock_json["price"].append(stock[i].get_price());
		}
	}
	
	// creates the file and saves data to file
	std::ofstream stockfile("./data/Stock.json");
	stockfile << stock_json;
	stockfile.close();
	
	
}