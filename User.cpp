
#include "User.h"


int User::login(string name, string password)
{
    Json::Value user;
    
    // loads existing user data from user.json
    std::ifstream user_file("./data/User.json");
    user_file >> user;
    user_file.close();
    
    
    for(int i = 0;i<user["username"].size();i++)//loops through the usernames
    {
        if(user["username"][i] == name && user["password"][i] == password)//if the username at that index matches and the password at that index ALSO matches, continue
        {
            cout << "Login successful!" << endl;
            return 1;
        }
        else
        {
            cout << "Username or password is incorrect." << endl;
            return 0;
        }
	}
}


int User::logout()
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
    
    // loads existing user data from user.json
    std::ifstream user_file("./data/User.json");
    user_file >> user;
    user_file.close();
    
    //loops through the usernames
    //if the username entered is the same as another username, dont move forward
    for(int i = 0;i<user["username"].size(); i++)
    {
        if(user["username"][i] == name)
        {
            cout << "There is already a user with this name." << endl;
            return;
        }
    }
    
    //adds various user info
    user["username"].append(name);
    user["password"].append(password);
    user["paymentinfo"].append(cardNum);
    user["address"].append(address);
    
    //writes those values to the file
    std::ofstream outuserfile ("./data/User.json");
    outuserfile << user;
    outuserfile.close();
        
}


void User::delete_account(string name, string password)
{
    Json::Value user;
    
    // loads existing user data from user.json
    std::ifstream user_file("./data/User.json");
    user_file >> user;
    user_file.close();
    
    
    for(int i = 0;i<user["username"].size();i++)//loops through the usernames
    {
        if(user["username"][i].asString() == name && user["password"][i].asString() == password)//if the username at that index matches and the password at that index ALSO matches, continue
        {
			Json::ArrayIndex index = Json::ArrayIndex(i);
			Json::Value *returned;
            user["username"].removeIndex(i, returned);
            user["password"].removeIndex(i, returned);
            return;
        }
        else
        {
            cout << "Username or password is incorrect." << endl;
            return;
        }
	}
}


void User::checkout()
{
    cart.remove_all(); //calls the remove_all() function from the shoppingcart that removes everything
}

