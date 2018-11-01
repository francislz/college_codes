#include <iostream>
#include <cstring>
#include <cmath>
#include "decimal.hpp"
using namespace std;

decimal::decimal(int LEFT, int RIGHT, int PRECISION){
    left = LEFT;
    right = RIGHT;
    precision = PRECISION;
}

decimal::decimal(){
    left = 0;
    right = 0;
    precision = 0;
}


int decimal::getSize(int n) const{
    int q = 0, cont = 0;
    do{
        q = n/10;
        n = q;
        ++cont;
    }while(q != 0);
    return cont;
}

/*string decimal::getValue() const{
    int cont = precision - getSize(right);

    string result = to_string(left) + ".";
    for (int i = 0; i < cont; ++i){
        result += '0';
    }
    result += to_string(right);
    return result;
}*/

decimal decimal::operator+(const decimal& dec){
    decimal result;
    int sizeR1 = result.getSize(dec.right);
    int sizeR2 = result.getSize(right);

    if(precision == dec.precision){
        int part1 = dec.left + left;
        int part2 = dec.right + right;
        int sum = result.getSize(part2);

        if((sizeR2 == sizeR1) and (sizeR1 == sum)){
            result.left = part1;
            result.right = part2;
            result.precision = precision;
        }
        else if((sizeR2 == sizeR1) and (sizeR1 != sum)){
            part2 = part2 - pow(10,sizeR1);
            part1 += 1;
            result.left = part1;
            result.right = part2;
            result.precision = precision;
        }
    }
    else if(precision > dec.precision){
        int pot = precision - dec.precision;
        int deci = dec.right * pow(10, pot);
        result.left = dec.left + left;
        result.right = deci + right;
        result.precision = precision;
    }
    else{
        int pot = dec.precision - precision;
        int deci = right * pow(10, pot);
        result.left = dec.left + left;
        result.right = deci + dec.right;
        result.precision = precision;
    }
    return result;
}

ostream& operator<<(ostream& os, const decimal& dec){
    int cont = dec.precision - dec.getSize(dec.right);

    string result = to_string(dec.left) + ".";
    for (int i = 0; i < cont; ++i){
        result += '0';
    }
    result += to_string(dec.right);
    os << result;
    return os;
}

void decimal::operation(type T){}