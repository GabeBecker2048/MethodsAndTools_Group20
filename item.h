
class Item {
private:
  string name;
  string category;
  double price;

public:
  Item(string x, string y, double z) {
    name = x;
    category = y;
    price = z;
  }

  string get_name() {
    return name;
  }

  string get_category() {
    return category;
  }

  void set_price(double p) {
    price = p;
  }

  double get_price() {
    return price;
  }
};
