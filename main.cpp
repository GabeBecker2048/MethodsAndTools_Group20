#include <string>
#include <vector>
#include <iostream>

#include "inventory.h"
#include "item.h"
#include "User.h"
#include "ShoppingCart.h"

using std::string;
using std::cout;
using std::cin;
using std::endl;

int screen1();
User* screen11();
int screen12();
int screen2();
int screen21();
int screen211();
int screen22();
string screen23();
int screen24(User* user);
Item* screen25(Inventory* inventory);

int main() {
	
	bool run = true;
	Inventory* inventory = new Inventory;
	User* user = new User;
	while (run) {
		
		inventory->update();
		int choice = -1;
		while (choice == -1) 
		{
			
			// brings up the first screen
			choice = screen1();
			
			// exits program
			if (choice == 3)
				return 0;
			
			// creates account
			else if (choice == 2) 
			{
				
				int account_created = screen12();
				choice = -1;
				
			}

			// logs in
			else if (choice == 1) 
			{
				user = screen11();
			
				//if (user == NULL)
				//	choice = -1;
			}

		}
		
		choice = -1;
		while (choice == -1) 
		{
			
			// brings up the second screen
			choice = screen2();
			
			// exit program
			if (choice == 10)
				return 0;
			
			// add item to cart
			else if (choice == 9){
				Item* item_to_add = screen25(inventory);
				
				if(item_to_add != NULL)
				{	
					user.cart.add(&item_to_add);
					cout << "Item added!\n\n";
				}
				else
				{
					cout << "Error: item not found in stock\n\n";
				}
				
				choice = -1;
			}
			
			// delete account
			else if (choice == 8) {
				screen24(user);
			}
			
			// edit payment info
			else if (choice == 7) {
				int newPaymentInfo = screen22(); //test this
				user.set_payment_info(newPaymentInfo);
				choice = -1;
			}
			
			// edit shipping info
			else if (choice == 6) {
				string newShipping = screen23(); //test this
				user.set_shipping_info(newShipping);
				choice = -1;
			}
			
			// view order history
			else if (choice == 5) {
				
			}
			
			// view items by category
			else if (choice == 4) {
				
				vector<string> unique_category;
				vector<Item> unique_names;
				vector<int> unique_amounts;
				
				// gets unique names and amounts of each item
				for(int i=0 ; i < inventory->view_stock().size(); i++) {
					
					int size = unique_names.size();
					if (size > 0) {
						
						// checks for unique items and counts the amount
						bool in_unique_names = false;
						for(int j=0; j < size; j++) {
							if (inventory->view_stock()[i].get_name() == unique_names[j].get_name()) {
								in_unique_names = true;
								unique_amounts[j]++;
								break;
							}
						}
						
						// if the item is not in unique names, it is added
						if (!in_unique_names) {
							unique_names.push_back(inventory->view_stock()[i]);
							unique_amounts.push_back(1);
						}
						
					}
					
					// if there is nothing in unique names, it is automatically added
					else {
						unique_names.push_back(inventory->view_stock()[i]);
						unique_amounts.push_back(1);
					}
				}
				
				
				// finds all unique categorys
				for(int i=0; i < unique_names.size(); i++) {
					
					int size = unique_category.size();
					if (size > 0) {

						// tests if its already found 
						bool in_unique_category = false;
						for(int j=0; j < size; j++) {
							if (unique_names[i].get_category() == unique_category[j]) {
								in_unique_category = true;
								break;
							}
						}
						
						if (!in_unique_category)
							unique_category.push_back(unique_names[i].get_category());
					}
					
					// adds to unique_category if nothing is in it
					else {
						unique_category.push_back(unique_names[i].get_category());
					}
				}

				
				// searches through the categories
				for(int i=0; i<unique_category.size(); i++) {
					
					cout << "Category name: " << unique_category[i] << endl;
					cout << "--------------------\n";
					
					// gets the items in the category
					vector<Item> items_in_category = inventory->view_category(unique_category[i]);
					
					// loops through all items in the category
					for(int j=0; j < items_in_category.size(); j++) {
						
						if(j > 0) {
							if (items_in_category[j].get_name() != items_in_category[j-1].get_name()) {
							
								// gets item amount
								int amount = -1;
								for(int k=0; k < unique_names.size(); k++) {
									
									// displays item
									if (items_in_category[j].get_name() == unique_names[k].get_name()) {
										amount = unique_amounts[k];
										cout << "Item name: " << items_in_category[j].get_name() << "\n" << "Item amount: " << amount << "\n" << "Item price: " << items_in_category[j].get_price() << "\n\n";
										break;
									}
								}
							}
						}
						
						else {
							// gets item amount
							int amount = -1;
							for(int k=0; k < unique_names.size(); k++) {
								
								// displays item
								if (items_in_category[j].get_name() == unique_names[k].get_name()) {
									amount = unique_amounts[k];
									cout << "Item name: " << items_in_category[j].get_name() << "\n" << "Item amount: " << amount << "\n" << "Item price: " << items_in_category[j].get_price() << "\n\n";
									break;
								}
							}
						}
					}
					
					
					cout << endl;
				}
				
				choice = -1;
				
			}
			
			// view all items
			else if (choice == 3) {
				
				vector<Item> unique_names;
				vector<int> unique_amounts;
				for(int i=0 ; i < inventory->view_stock().size(); i++) {
					
					int size = unique_names.size();
					if (size > 0) {
						
						// checks for unique items and counts the amount
						bool in_unique_names = false;
						for(int j=0; j < size; j++) {
							if (inventory->view_stock()[i].get_name() == unique_names[j].get_name()) {
								in_unique_names = true;
								unique_amounts[j]++;
								break;
							}
							
						}
						
						// if the item is not in unique names, it is added
						if (!in_unique_names) {
							unique_names.push_back(inventory->view_stock()[i]);
							unique_amounts.push_back(1);
						}
						
					}
					
					// if there is nothing in unique names, it is automatically added
					else {
						unique_names.push_back(inventory->view_stock()[i]);
						unique_amounts.push_back(1);
					}
				}
				
				cout << "Item names\tCategory\tAmount\n";
				cout << "--------------------------------------\n";
				for(int i = 0; i < unique_names.size(); i++) {
					cout << unique_names[i].get_name() << "\t\t" << unique_names[i].get_category() << "\t" << unique_amounts[i] << "\n";
				}
				cout << endl;
				
				// loops back
				choice = -1;
			}

			// cart information
			else if (choice == 2) {
				int cart_choice = screen21();
			}
				
		}
	}
}

// the login screen
int screen1() {
	
	int choice = -1;
	while (choice == -1) {
	
		// gives options
		cout << "Enter an option: \n";
		cout << "1 : login\n";
		cout << "2 : create account\n";
		cout << "3 : exit program\n";
		
		// gets response
		string response;
		std::getline(cin, response);
		cout << std::endl;

		
		// tries to convert response to int
		try {
			choice = std::stoi(response);
			
			// error out if invalid response
			if (choice < 1 or choice > 3) {
				cout << "Error: Response must be integer between 1 and 3\n\n";
				choice = -1;
			}
		}
		
		// error out if invalid response
		catch (std::invalid_argument){
			cout << "Error: Response must be integer between 1 and 3\n\n";
		}
	}
	
	return choice;
}

// the login prompt screen
User* screen11() {
	
	// prompts for username
	cout << "Enter your username: ";
	string username;
	std::getline(cin, username);
	
	// prompts for password
	cout << "Enter your password: ";
	string password;
	std::getline(cin, password);
	
	cout << endl;
	
	User* user = new User();
	
	// attempts to log the user in
	// int login_status = User().login(username, password);
	// if (login_status)
	return user;
	// else
	//return NULL
}

// the create account screen
int screen12() {
	
	// prompts for username
	cout << "Enter your username: ";
	string username;
	std::getline(cin, username);
	
	// prompts for password
	cout << "Enter your password: ";
	string password;
	std::getline(cin, password);
	
	// prompts for card number
	int cardNum = -1;
	while (cardNum == -1) {
		
		// prompts for card number
		cout << "Enter your credit card number (super secure): ";
		string cardNumStr;
		std::getline(cin, cardNumStr);
		
		// tries to convert cardNumStr to int
		try {
			cardNum = std::stoi(cardNumStr);
			
			// error out if invalid response
			if (cardNum < 0) {
				cout << "Error: Invalid card number\n\n";
				cardNum = -1;
			}
		}
		// error out if invalid response
		catch (std::invalid_argument){
			cout << "Error: Invalid card number\n\n";
		}
	}
	
	// prompts for address
	cout << "Enter your address (super secure): ";
	string address;
	std::getline(cin, address);
	
	cout << endl;
	
	// attempts to create account
	//return User().create_account(name, password, cardNum, address);
	return 1;
}

// option screen 2
int screen2() {
	
	int choice = -1;
	while (choice == -1) {
		
		// gives options
		cout << "Enter an option: \n";
		cout << "1 : logout\n";
		cout << "2 : cart information\n";
		cout << "3 : view all items\n";
		cout << "4 : view items by category\n";
		cout << "5 : view order history\n";
		cout << "6 : edit shipping info\n";
		cout << "7 : edit payment info\n";
		cout << "8 : delete account\n";
		cout << "9 : Add item to cart\n";
		cout << "10: exit program\n";
		
		// gets response
		string response;
		std::getline(cin, response);
		cout << std::endl;

		
		// tries to convert response to int
		try {
			choice = std::stoi(response);
			
			// error out if invalid response
			if (choice < 1 or choice > 10) {
				cout << "Error: Response must be integer between 1 and 10\n\n";
				choice = -1;
			}
		}
		
		// error out if invalid response
		catch (std::invalid_argument){
			cout << "Error: Response must be integer between 1 and 10\n\n";
		}
	}
	
	return choice;
	
}

// cart information screen
int screen21() 
{
	int choice = -1;
	while (choice == -1) {
		// gives options
		cout << "Enter an option: \n";
		cout << "1 : go back\n";
		cout << "2 : view cart\n";
		cout << "3 : remove item from cart\n";
		cout << "4 : check out\n";
		
		// gets response
		string response;
		std::getline(cin, response);
		cout << std::endl;

		
		// tries to convert response to int
		try {
			choice = std::stoi(response);
			
			// error out if invalid response
			if (choice < 1 or choice > 4) {
				cout << "Error: Response must be integer between 1 and 4\n\n";
				choice = -1;
			}
		}
		
		// error out if invalid response
		catch (std::invalid_argument){
			cout << "Error: Response must be integer between 1 and 4\n\n";
		}
	}
	
	return choice;
}

int screen22()
{
	
	// prompts for card number
	int cardNum = -1;
	while (cardNum == -1) {
		
		// prompts for card number
		cout << "Enter your credit card number (super secure): ";
		string cardNumStr;
		std::getline(cin, cardNumStr);
		
		// tries to convert cardNumStr to int
		try {
			cardNum = std::stoi(cardNumStr);
			
			// error out if invalid response
			if (cardNum < 0) {
				cout << "Error: Invalid card number\n\n";
				cardNum = -1;
			}
		}
		// error out if invalid response
		catch (std::invalid_argument){
			cout << "Error: Invalid card number\n\n";
		}
	}
	
	return cardNum;
}

string screen23() {

	// prompts for address
	cout << "Enter your address (super secure): ";
	string address;
	std::getline(cin, address);
	
	cout << endl;
	
	return address;
}

int screen24(User* user) {
	
	// prompts for username
	cout << "Enter your username: ";
	string username;
	std::getline(cin, username);
	
	// prompts for password
	cout << "Enter your password: ";
	string password;
	std::getline(cin, password);
	
	// user->delete_account(username, password)
	
	return 1;
}

Item* screen25(Inventory* inventory) {
	
	// prompts for item stuff
	cout << "Enter name of item: ";
	string item_name;
	std::getline(cin, item_name);
	
	cout << endl;
	
	// gets the rest of the item from inventory
	vector<Item> stock = inventory->view_stock();
	for(int i = 0; i < stock.size(); i++) {
		if (stock[i].get_name() == item_name) {
			Item* item = &stock[i];
			return item;
		}
	}
	
	return NULL;
}
