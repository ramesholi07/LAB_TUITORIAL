#include <iostream>
using namespace std;

class design2
{
    int code;
    float value;

public:
    design2() : code(0), value(0) {}
    // design2(design1 d)
    // {
    //     code=d.get_code();
    //     value=d.get_qty()*d.get_price();
    // }

    void put_data()
    {
        cout << "design2 detail :: " << endl;
        cout << "code:" << code << endl
             << "value:" << value << endl;
    }
    friend class design1;
};
class design1
{
    int code;
    int qty;
    float price;

public:
    design1() : code(0), qty(0), price(0) {}
    design1(int a, int b, float c) : code(a), qty(b), price(c) {}
    void put_data()
    {
        cout << "design1 detail:: " << endl;
        cout << "code: " << code << endl
             << "qty: " << qty << endl
             << "price: " << price << endl;
    }
    operator float()
    {
        return qty * price;
    }

    operator design2()
    {
        design2 temp;
        temp.code = code;
        temp.value = qty * price;
        return temp;
    }

    int get_code() { return code; }
    int get_qty() { return qty; }
    float get_price() { return price; }
};

int main()
{
    design1 d1(20, 2, 100);
    design2 s1;
    float total_value;
    total_value = d1;
    d1.put_data();
    cout << "stock price: " << endl
         << total_value << endl;
    s1 = d1;
    s1.put_data();
    return 0;
}
