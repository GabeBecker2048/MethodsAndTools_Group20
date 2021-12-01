#include "User.h"


void User::login(string name, string password)
{
    
}


void User::logout()
{
    
}


string User::get_shipping_info()
{
    return address;
}


void User::set_shipping_info(string address)
{
    this->address = address;
}


int User::get_payment_info()
{
    return cardNum;
}


void User::set_payment_info(int cardNum)
{
    this->cardNum = cardNum;
}


void User::create_account(string name, string password, int cardNum, string address)
{
    
}


void User::delete_account()
{
    
}


void User::checkout()
{
    cart.remove_all();
}

