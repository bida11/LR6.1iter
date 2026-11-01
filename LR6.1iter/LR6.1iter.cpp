#include <iomanip>

#include <iostream>

#include <random>

using namespace std;



bool isTarget(int value, int index)

{

    return value > 0 && index % 5 != 0;

}



void fillArrayRec(int* a, int n, int i, mt19937& generator)

{

    if (i == n) return;

    uniform_int_distribution<int> distribution(-20, 50);

    a[i] = distribution(generator);

    fillArrayRec(a, n, i + 1, generator);

}



void printArrayRec(const int* a, int n, int i)

{

    if (i == n) { cout << '\n'; return; }

    cout << setw(4) << a[i];

    printArrayRec(a, n, i + 1);

}



int countTargetRec(const int* a, int n, int i)

{

    if (i == n) return 0;

    return (isTarget(a[i], i) ? 1 : 0) + countTargetRec(a, n, i + 1);

}



long long sumTargetRec(const int* a, int n, int i)

{

    if (i == n) return 0;

    return (isTarget(a[i], i) ? a[i] : 0) + sumTargetRec(a, n, i + 1);

}



void zeroTargetRec(int* a, int n, int i)

{

    if (i == n) return;

    if (isTarget(a[i], i)) a[i] = 0;

    zeroTargetRec(a, n, i + 1);

}



#ifndef UNIT_TEST

int main()

{

    const int n = 20;

    int a[n]{};

    mt19937 generator(2026);

    fillArrayRec(a, n, 0, generator);

    cout << "Initial array:"; printArrayRec(a, n, 0);

    cout << "Count = " << countTargetRec(a, n, 0) << "\nSum = " << sumTargetRec(a, n, 0) << '\n';

    zeroTargetRec(a, n, 0);

    cout << "Modified array:"; printArrayRec(a, n, 0);

}

#endif