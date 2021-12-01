
#include "item.h"

using std::string;

string Item::get_name() {
  return name;
}

string Item::get_category() {
  return category;
}

void Item::set_price(double p) {
  this -> price = p;
}

double Item::get_price() {
  return price;
}

Item::Item(string x, string y, double z) {
  name = x;
  category = y;
  price = z;
}
