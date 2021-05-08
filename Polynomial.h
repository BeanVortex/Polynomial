#ifndef POLYNOMIAL_H
#define POLYNOMIAL_H

#include <iostream>

typedef unsigned long long int Long;

using namespace std;

class Polynomial
{
    friend istream &operator>>(istream &, Polynomial &);
    friend ostream &operator<<(ostream &, const Polynomial &);
    friend ostream &operator<<(ostream &, const Polynomial *);
    friend Polynomial *operator*(const Polynomial &, const Polynomial &);
    friend Polynomial *operator+(const Polynomial &, const Polynomial &);
    friend Polynomial *operator-(const Polynomial &, const Polynomial &);
    friend bool operator==(Polynomial &, Polynomial &);
    friend bool operator<=(Polynomial &, Polynomial &);
    friend bool operator>=(Polynomial &, Polynomial &);

private:
    int size;
    int *ratio;
    int *pow;
    Long power(int, int);

public:
    Polynomial(){};
    Polynomial(int size, int *ratio, int *pow);
    ~Polynomial();
    void sortByPowDecrement();
    Polynomial &operator*=(const Polynomial &);
    Polynomial &operator+=(const Polynomial &);
    Polynomial &operator-=(const Polynomial &);
    Long calculate(int);
    Polynomial *deleteSentenceByPow(int pow);
    void setSize(int);
    void setRatio(int *);
    void setPow(int *);
    int getSize() { return size; };
    int *getRatio() { return ratio; };
    int *getPow() { return pow; };
};

#endif // !POLYNOMIAL_H
