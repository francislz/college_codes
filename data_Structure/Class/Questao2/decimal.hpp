#ifndef decimal_hpp
#define decimal_hpp
#include <iostream>
using namespace std;

enum type {sum, minus, mult, divide, print};

class decimal {
    private:
        int left;
        int right;
        int precision;
        type t;
    public:
        //string operator+(const decimal& dec1, const decimal& dec2);
        decimal(int left, int right, int precision);
        decimal();
        int getSize(int n) const;
        friend ostream& operator<<(ostream& os, const decimal& dec);
        decimal operator+(const decimal& dec);
        //string getValue() const;
        void operation(type t);
};

#endi
