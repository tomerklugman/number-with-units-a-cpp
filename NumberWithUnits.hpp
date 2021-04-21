#include <iostream>
using namespace std;

namespace ariel
{

    class NumberWithUnits
    {
    private:
        double num;
        string type;

    public:
        NumberWithUnits();
        NumberWithUnits(double num, string type);
        static void read_units(ifstream &file);

        friend bool operator>(const NumberWithUnits &x, const NumberWithUnits &y);
        friend bool operator>=(const NumberWithUnits &x, const NumberWithUnits &y);
        friend bool operator<(const NumberWithUnits &x, const NumberWithUnits &y);
        friend bool operator<=(const NumberWithUnits &x, const NumberWithUnits &y);
        friend bool operator==(const NumberWithUnits &x, const NumberWithUnits &y);
        friend bool operator!=(const NumberWithUnits &x, const NumberWithUnits &y);

        friend ostream &operator<<(ostream &out, const NumberWithUnits &z);
        friend istream &operator>>(istream &in, const NumberWithUnits &z);
    };

    NumberWithUnits operator+(NumberWithUnits x, const NumberWithUnits &y);
    NumberWithUnits operator+(NumberWithUnits x);
    NumberWithUnits operator+=(NumberWithUnits x, const NumberWithUnits &y);
    NumberWithUnits operator-(const NumberWithUnits &x, const NumberWithUnits &y);
    NumberWithUnits operator-(NumberWithUnits x);
    NumberWithUnits operator-=(NumberWithUnits x, const NumberWithUnits &y);

    NumberWithUnits operator++(NumberWithUnits x);
    NumberWithUnits operator--(NumberWithUnits x);

    NumberWithUnits operator*(double x, NumberWithUnits y);

}
