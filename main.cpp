#include "Polynomial.h"

/*
    Navigate to ProjectFolder and run this
    g++ main.cpp Polynomial.cpp -o main && ./main
    Every feature is commented. so you can commented out to test
*/

int main()
{

    // Creating first polynomial ratios and powers for testing
    int size = 3;
    int *arr = new int[size];
    int *brr = new int[size];
    for (int i = 0; i < size; i++)
    {
        arr[i] = i + 2;
        brr[i] = i + 3;
    }

    // Creating second polynomial ratios and powers for testing
    int size2 = 3;
    int *arr2 = new int[size2];
    int *brr2 = new int[size2];

    for (int i = 0; i < size2; i++)
    {
        arr2[i] = i + 4;
        brr2[i] = i + 3;
    }

    // Creating by user input
    /* Polynomial p0;
    cin >> p0;
    cout << p0; */

    /* Polynomial p1(size, arr, brr);
    cout << p1; */

    /* Polynomial p2(size2, arr2, brr2);
    cout << p2; */

    /* Polynomial *p3 = p1 + p2;
    cout << p3; */

    /* p1 += p2;
    cout << p1; */

    /* Polynomial *p4 = p2 - p1;
    cout << p4; */

    /*  p1 -= p2;
    cout << p1; */

    /* Polynomial *p5 = p2 * p1;
    cout << *p5; */

    /* p2 *= p1;
    cout << p2; */

    /* Polynomial *p6 = p1.deleteSentenceByPow(4);
    cout << p6; */

    /* Long calculatedVal = p1.calculate(1);
    cout << endl
         << calculatedVal << endl; */

    /* bool b1 = p1 == p2;
    cout << endl
         << boolalpha << b1 << endl; */

    /* bool b2 = p1 >= p2;
    cout << endl
         << boolalpha << b2 << endl; */

    /* bool b3 = p1 <= p2;
    cout << endl
         << boolalpha << b3 << endl; */

    /*  Polynomial *p7 = p2 * p1;
     cout << p7;
     p7->sortByPowDecrement();
     cout << p7; */

    // Editing Polynomial is done by using setters

    return 0;
}