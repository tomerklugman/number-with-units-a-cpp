#include "NumberWithUnits.hpp"
using namespace std;

namespace ariel
{

    // CONSTRUCTORS

    NumberWithUnits::NumberWithUnits()
    {
        num = 0;
        type = "";
    }

    NumberWithUnits::NumberWithUnits(double num, string type)
    {
        this->num = num;
        this->type = std::move(type);
    }

    // FUNCTIONS

    void NumberWithUnits::read_units(std::ifstream &file)
    {
    }

    // OPERATORS
    NumberWithUnits operator+(NumberWithUnits x, const NumberWithUnits &y)
    {
        return x;
    }
    NumberWithUnits operator+(NumberWithUnits x)
    {
        return x;
    }
    NumberWithUnits operator++(NumberWithUnits x)
    {
        return x;
    }
    NumberWithUnits operator-(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return x;
    }
    NumberWithUnits operator--(NumberWithUnits x)
    {
        return x;
    }
    NumberWithUnits operator-=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return x;
    }
    NumberWithUnits operator-(NumberWithUnits x)
    {
        return x;
    }
    NumberWithUnits operator*(double x, NumberWithUnits y)
    {
        return y;
    }
    bool operator>(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;
    }
    bool operator>=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;
    }
    bool operator<(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return false;
    }
    bool operator<=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return false;
    }
    bool operator==(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;
    }
    bool operator!=(const NumberWithUnits &x, const NumberWithUnits &y)
    {
        return true;
    }
    NumberWithUnits operator+=(NumberWithUnits x, const NumberWithUnits &y)
    {
        return x;
    }

    // STREAMS
    ostream &operator<<(ostream &out, const NumberWithUnits &z)
    {
        return out;
    }
    istream &operator>>(istream &in, const NumberWithUnits &z)
    {
        return in;
    }
}