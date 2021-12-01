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
    Json::Value user;
    
    for(int i = 0;i<user["username"].size(); i++)
    {
        if(user["username"][i] == name)
        {
            cout << "There is already a user with this name." << endl;
            return;
        }
    }
    
    user["username"].append(name);
    user["password"].append(password);
    user["paymentinfo"].append(cardNum);
    user["address"].append(address);
    
    std::ofstream outuserfile ("./user.json");
    outuserfile << user;
    outuserfile.close;
        
}


void User::delete_account()
{
    
}


void User::checkout()
{
    cart.remove_all();
}

