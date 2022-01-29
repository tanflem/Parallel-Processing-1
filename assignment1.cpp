// COP 4520 Spring 2022
// Programming Assignment 1
// Tanner Fleming

#include <bits/stdc++.h>
#include <thread>
#include <chrono>
using namespace std;

typedef struct primeValues
{
    int sum;
    int total;
} primeValues;

bitset<100000000> Primes;
void SieveOfEratosthenes(int n)
{
    Primes[0] = 1;
    for (int i = 3; i <= n; i += 2)
    {
        if (Primes[i / 2] == 0)
        {
            for (int j = 3 * i; j <= n; j += 2 * i)
                Primes[j / 2] = 1;
        }
    }
}

// Driver Code
int main()
{
    clock_t start, end;

    int n = 100000000;
    unsigned int finalSum = 2;
    int count = 1;
    float time = 0.0;

    start = clock();

    SieveOfEratosthenes(n);
    for (int i = 1; i <= n; i++)
    {
        if (i % 2 == 1 && Primes[i / 2] == 0)
        {
            finalSum += i;
            count++;
        }
    }

    end = clock();

    time = ((float)end - start) / CLOCKS_PER_SEC;

    return 0;
}