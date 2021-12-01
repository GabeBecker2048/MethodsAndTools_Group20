#include <string>
using std::string;

class Item {
private:
  string name;
  string category;
  double price;

public:
  Item(string x, string y, double z);

  string get_name();

  string get_category();

  void set_price(double p);

  double get_price();
};
