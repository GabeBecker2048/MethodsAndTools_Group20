#pragma once
#include <string>
#include <iostream>
#include <fstream>
#include <time.h>
#include <stdlib.h>

#include "json/json.h"
#include "ShoppingCart.h"

using std::string;
using std::cout;
using std::endl;


class User {
    private:
        
        string name;
        string password;
        int cardNum;
        string address;
    
    public:
        
        User() : name(" "), password(" "), cardNum(0), address(" ") {}

		ShoppingCart cart;
        
        int login(string name, string password);
        int logout();
        
		void set_name(string name);
		void set_password(string password);
	
	string get_name();
	string get_password();
		
        string get_shipping_info();
        void set_shipping_info(string address);
        
        int get_payment_info();
        void set_payment_info(int cardNum);
        
        int create_account(string name, string password, int cardNum, string address);
        int delete_account(string name, string password);
        
        void checkout();
};






