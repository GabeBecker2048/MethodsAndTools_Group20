#pragma once
#include <string>
#include <iostream>
#include <fstream>

#include "ShoppingCart.h"

using std::string;


class User {
    private:
        
        ShoppingCart cart;
        string name;
        string password;
        int cardNum;
        string address;
    
    public:
        
        User() : name(" "), password(" "), cardNum(0), address(" ") {}

        
        void login(string name, string password);
        void logout();
        
        string get_shipping_info();
        void set_shipping_info(string address);
        
        int get_payment_info();
        void set_payment_info(int cardNum);
        
        void create_account(string name, string password, int cardNum, string address);
        void delete_account();
        
        void checkout();
};






