#include "Polynomial.h"

Polynomial::Polynomial(int s, int *r, int *p) : size(s)
{
    ratio = new int[size];
    pow = new int[size];
    for (int i = 0; i < size; i++)
    {
        ratio[i] = r[i];
        pow[i] = p[i];
    }
}

Polynomial::~Polynomial()
{
    delete ratio;
    delete pow;
}

void Polynomial::setSize(int size) { this->size = size; }

void Polynomial::setRatio(int *ratio)
{
    this->ratio = new int[size];
    for (int i = 0; i < size; i++)
    {
        this->ratio[i] = ratio[i];
    }
}

void Polynomial::setPow(int *pow)
{
    this->pow = new int[size];
    for (int i = 0; i < size; i++)
    {
        this->pow[i] = pow[i];
    }
}

istream &operator>>(istream &in, Polynomial &obj)
{
    cout << "Enter polynomial size -> ";
    in >> obj.size;
    obj.ratio = new int[obj.size];
    obj.pow = new int[obj.size];

    cout << "Enter ratios: " << endl
         << endl;
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Enter " << i << " index of ratios -> ";
        in >> obj.ratio[i];
    }

    cout << endl;

    cout << "Enter powers: " << endl
         << endl;
    for (int i = 0; i < obj.size; i++)
    {
        cout << "Enter " << i << " index of powers -> ";
        in >> obj.pow[i];
    }
    return in;
}

ostream &operator<<(ostream &out, const Polynomial &obj)
{
    out << endl
        << "Printing Polynomial: " << endl;

    for (int i = 0; i < obj.size; i++)
    {
        out << obj.ratio[i] << "x^" << obj.pow[i];
        if (i != obj.size - 1)
            out << " + ";
        else
            out << endl;
    }
    return out;
}

ostream &operator<<(ostream &out, const Polynomial *obj)
{
    out << endl
        << "Printing Polynomial: " << endl;

    for (int i = 0; i < obj->size; i++)
    {
        out << obj->ratio[i] << "x^" << obj->pow[i];
        if (i != obj->size - 1)
            out << " + ";
        else
            out << endl;
    }
    return out;
}

Polynomial *operator+(const Polynomial &obj1, const Polynomial &obj2)
{
    bool obj2IsBigger = false;
    int maxSize = obj1.size;
    int minSize = obj2.size;
    if (obj1.size < obj2.size)
    {
        obj2IsBigger = true;
        maxSize = obj2.size;
        minSize = obj1.size;
    }

    Polynomial *p = new Polynomial();
    p->setSize(maxSize);

    int *ratio = new int[maxSize];
    int *pow = new int[maxSize];

    for (int i = 0; i < maxSize; i++)
    {
        for (int j = 0; j < maxSize; j++)
        {
            if (obj2IsBigger)
            {
                if (obj2.pow[i] == obj1.pow[j])
                {
                    ratio[i] = obj2.ratio[i] + obj1.ratio[j];
                    pow[i] = obj2.pow[i];
                }
            }
            else
            {
                if (obj1.pow[i] == obj2.pow[j])
                {
                    ratio[i] = obj1.ratio[i] + obj2.ratio[j];
                    pow[i] = obj1.pow[i];
                }
            }
        }

        if (obj2IsBigger)
        {
            if (i == minSize)
            {
                ratio[i] = obj2.ratio[i];
                pow[i] = obj2.pow[i];
            }
        }
        else
        {
            if (i == minSize)
            {
                ratio[i] = obj1.ratio[i];
                pow[i] = obj1.pow[i];
            }
        }
    }
    p->setRatio(ratio);
    p->setPow(pow);

    return p;
}

Polynomial *operator-(const Polynomial &obj1, const Polynomial &obj2)
{
    bool obj2IsBigger = false;
    int sign = 1;
    int maxSize = obj1.size;
    int minSize = obj2.size;
    if (obj1.size < obj2.size)
    {
        sign *= -1;
        obj2IsBigger = true;
        maxSize = obj2.size;
        minSize = obj1.size;
    }

    Polynomial *p = new Polynomial();
    p->setSize(maxSize);

    int *ratio = new int[maxSize];
    int *pow = new int[maxSize];

    for (int i = 0; i < maxSize; i++)
    {
        for (int j = 0; j < maxSize; j++)
        {
            if (obj2IsBigger)
            {
                if (obj2.pow[i] == obj1.pow[j])
                {
                    ratio[i] = obj1.ratio[j] - obj2.ratio[i];
                    pow[i] = obj2.pow[i];
                }
            }
            else
            {
                if (obj1.pow[i] == obj2.pow[j])
                {
                    ratio[i] = obj1.ratio[i] - obj2.ratio[j];
                    pow[i] = obj1.pow[i];
                }
            }
        }

        if (obj2IsBigger)
        {
            if (i == minSize)
            {
                ratio[i] = sign * obj2.ratio[i];
                pow[i] = obj2.pow[i];
            }
        }
        else
        {
            if (i == minSize)
            {
                ratio[i] = sign * obj1.ratio[i];
                pow[i] = obj1.pow[i];
            }
        }
    }
    p->setRatio(ratio);
    p->setPow(pow);

    return p;
}

Polynomial *operator*(const Polynomial &obj1, const Polynomial &obj2)
{

    bool obj2IsBigger = false;
    if (obj1.size < obj2.size)
        obj2IsBigger = true;

    int size = obj1.size * obj2.size;
    int *pow = new int[size];
    int *ratio = new int[size];

    for (int i = 0, k = 0; i < size; i++)
    {
        for (int j = 0; j < size / 2; j++)
        {
            if (k != size)
            {
                if (obj2IsBigger)
                {
                    ratio[k] = obj2.ratio[i] * obj1.ratio[j];
                    pow[k] = obj2.pow[i] + obj1.pow[j];
                    if (j != (size / 2) - 1)
                        k++;
                }
                else
                {
                    ratio[k] = obj1.ratio[i] * obj2.ratio[j];
                    pow[k] = obj1.pow[i] + obj2.pow[j];
                    if (j != (size / 2) - 1)
                        k++;
                }
            }
        }
    }

    Polynomial *p = new Polynomial();
    p->setSize(size);
    p->setRatio(ratio);
    p->setPow(pow);
    return p;
}

Polynomial &Polynomial::operator*=(const Polynomial &obj)
{
    Polynomial *obj2 = *this * obj;
    *this = *obj2;
    return *this;
}

Polynomial &Polynomial::operator+=(const Polynomial &obj)
{
    Polynomial *obj2 = *this + obj;
    *this = *obj2;
    return *this;
}

Polynomial &Polynomial::operator-=(const Polynomial &obj)
{
    Polynomial *obj2 = *this - obj;
    *this = *obj2;
    return *this;
}

Polynomial *Polynomial::deleteSentenceByPow(int powNum)
{
    int size = this->size - 1;
    int *ratio = new int[size];
    int *pow = new int[size];

    for (int i = 0; i < this->size; i++)
    {

        if (powNum <= this->pow[i])
        {
            if (i + 1 == this->size)
                continue;

            pow[i] = this->pow[i + 1];
            ratio[i] = this->ratio[i + 1];
        }
        else
        {
            pow[i] = this->pow[i];
            ratio[i] = this->ratio[i];
        }
    }
    Polynomial *p = new Polynomial();
    p->setSize(size);
    p->setRatio(ratio);
    p->setPow(pow);
    return p;
}

Long Polynomial::power(int base, int power)
{
    Long baseCopy = base;
    for (int i = 0; i < power; i++)
    {
        baseCopy *= base;
    }
    return baseCopy;
}

Long Polynomial::calculate(int x)
{
    Long sum = 0;
    for (int i = 0; i < size; i++)
    {
        sum += power(x, pow[i]) * ratio[i];
    }
    return sum;
}

bool operator==(Polynomial &obj1, Polynomial &obj2)
{
    Long value1 = obj1.calculate(1);
    Long value2 = obj2.calculate(1);
    return value1 == value2;
}

bool operator<=(Polynomial &obj1, Polynomial &obj2)
{
    Long value1 = obj1.calculate(1);
    Long value2 = obj2.calculate(1);
    return value1 <= value2;
}

bool operator>=(Polynomial &obj1, Polynomial &obj2)
{
    Long value1 = obj1.calculate(1);
    Long value2 = obj2.calculate(1);
    return value1 >= value2;
}

void Polynomial::sortByPowDecrement()
{

    for (int i = 0; i < size; i++)
    {
        for (int j = 1; j < (size - i); j++)
        {
            if (pow[j - 1] > pow[j])
            {
                int temp = pow[j - 1];
                int temp2 = ratio[j - 1];
                pow[j - 1] = pow[j];
                ratio[j - 1] = ratio[j];
                pow[j] = temp;
                ratio[j] = temp2;
            }
        }
    }
}
