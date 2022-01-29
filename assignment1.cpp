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
    int lastTen[10];
} primeValues;

bitset<100000000> Primes = {0};

void SieveOfEratosthenes(int l, int r)
{
    primeValues ret;

    // Going by 2 on odds only because even numbers are not prime
    for (int i = l; i <= r; i += 2)
    {
        bool flag = 1;
        for (int j = 2; j * j <= i; ++j)
        {
            if (i % j == 0)
            {
                flag = 0;
                break;
            }
        }

        if (flag)
        {
            Primes[i] = 1;
            ret.sum += i;
            ret.total++;
        }
    }
    // return ret;
}

int main()
{
    clock_t start, end;
    unsigned int finalSum = 2;
    int count = 1;
    float time = 0.0;
    int bigTen[9] = {0};

    start = clock();

    thread th1(SieveOfEratosthenes, 3, 50000000);
    thread th2(SieveOfEratosthenes, 50000001, 75000000);
    thread th3(SieveOfEratosthenes, 75000001, 82500000);
    thread th4(SieveOfEratosthenes, 82500001, 90000000);
    thread th5(SieveOfEratosthenes, 90000001, 95000000);
    thread th6(SieveOfEratosthenes, 95000001, 97500000);
    thread th7(SieveOfEratosthenes, 97500001, 98750000);
    thread th8(SieveOfEratosthenes, 98750000, 100000000);

    th1.join();
    th2.join();
    th3.join();
    th4.join();
    th5.join();
    th6.join();
    th7.join();
    th8.join();

    // While loop to find the 10 biggest primes
    int loopCount = 0;
    while (loopCount != 10)
    {
        int i = 99999999;
        if (Primes[i])
        {
            bigTen[count] = i;
            loopCount++;
        }
        i -= 2;
    }

    end = clock();

    time = ((float)end - start) / CLOCKS_PER_SEC;

    cout << "Execution Time: " << time << "secs"
         << "\nSum of all primes found: " << finalSum 
         << "\nNumber of primes found: " << count 
         << "\nThe 10 biggest primes" << bigTen;
    return 0;
}