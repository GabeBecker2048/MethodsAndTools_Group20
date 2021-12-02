
#include "User.h"


int User::login(string name, string password)
{
    Json::Value user;
    
    // loads existing user data from user.json
    std::ifstream user_file("./data/Users.json");
    user_file >> user;
    user_file.close();
	
    for(int i = 0;i<user["username"].size();i++)//loops through the usernames
    {
        if(user["username"][i].asString() == name && user["password"][i].asString() == password)//if the username at that index matches and the password at that index ALSO matches, continue
        {
			address = user["address"][i].asString();
			cardNum = user["payment info"][i].asInt();
			
            cout << "Login successful!" << endl << endl;
            return 1;
        }
	}
	
	cout << "Username or password is incorrect." << endl << endl;
    return 0;
}


void User::set_name(string name_arg) {
	name = name_arg;
}

string User::get_name()
{
	return name;
}

void User::set_password(string password_arg){
	password = password_arg;
}

string User::get_password()
{
	return password;
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


int User::create_account(string name, string password, int cardNum, string address)
{
    Json::Value user;
    
    // loads existing user data from user.json
    std::ifstream user_file("./data/Users.json");
    user_file >> user;
    user_file.close();
    
    //loops through the usernames
    //if the username entered is the same as another username, dont move forward
    for(int i = 0;i<user["username"].size(); i++)
    {
        if(user["username"][i].asString() == name)
        {
            cout << "There is already a user with this name." << endl << endl;
            return 0;
        }
    }
    
    //adds various user info
    user["username"].append(name);
    user["password"].append(password);
    user["payment info"].append(cardNum);
    user["address"].append(address);
    
    //writes those values to the file
    std::ofstream outuserfile ("./data/Users.json");
    outuserfile << user;
    outuserfile.close();
	
	cout << "Account created\n\n";
	
	return 1;
        
}


int User::delete_account(string name, string password)
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
            return 1;
        }
        else
        {
            cout << "Username or password is incorrect." << endl;
            return 0;
        }
	}
	
	return 0;
}


void User::checkout()
{
    	
	
	Json::Value order;
	User user;
	
	int totalPrice;
	
	int rtime = rand() % 100;
	
	for(int i;i<cart.view().size();i++)
	{
		totalPrice += cart.view()[i].get_price();
	}
	
	order["username"].append(user.get_name());
	order["cost"].append(totalPrice);
	order["shipped to"].append(user.get_shipping_info());
	order["timestamp"].append(rtime);
	
	
	std::ofstream order_file("./data/PreviousOrders.json");
	order_file << order;
	order_file.close();
	
	cart.remove_all(); //calls the remove_all() function from the shoppingcart that removes everything
}

