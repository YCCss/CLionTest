// 判断素数和统计素数
// Created by Ycq on 2022/6/2.
//

#ifndef CLIONTEST_SOLVE2_H
#define CLIONTEST_SOLVE2_H

#include <bits/stdc++.h>
using namespace std;

class PrimeNumber
{
public:
    //素数判断1
    bool isPrime1(int num)
    {
        if (num <= 3) return num > 1;
        for (int i = 2; i < num; i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }
    //素数判断2
    bool isPrime2(int num)
    {
        if (num <= 3) return num > 1;
        int sq = (int)sqrt(num);
        for (int i = 2; i <= sq; i++)
        {
            if (num % i == 0) return false;
        }
        return true;
    }
    //素数判断3
    bool isPrime3(int num)
    {
        if (num <= 3) return num > 1;
        // 不在6的倍数两侧的一定不是质数
        if (num % 6 != 1 && num % 6 != 5) {
            return false;
        }
        int sq = (int)sqrt(num);
        for (int i = 5; i <= sq; i += 6) {
            //6的倍数的前后两个数可能是质数，也有可能是质数的倍数，下面是将其排除
            if (num % i == 0 || num % (i + 2) == 0) {
                return false;
            }
        }
        return true;
    }

    //统计素数1
    int countPrime1(int num)
    {
        int res = 0;
        for (int i = 2; i < num; i++)
        {
            res += isPrime2(i);
        }
        return res;
    }

    //统计素数2
    int countPrime2(int num)
    {
        int res = 0;
        for (int i = 2; i < num; i++)
        {
            res += isPrime3(i);
        }
        return res;
    }

    //统计素数3, 排除不是素数的数
    int countPrime3(int num)
    {
        vector<int> isP(num, 1);
        int res = 0;
        for (int i = 2; i < num; i++)
        {
            if (isP[i])
            {
                res += 1;
                if ((long long) i * i < num)
                {
                    for (int j = i * i; j < num; j += i)
                    {//将i的倍数的数置为false,表示不是素数
                        isP[j] = 0;
                    }
                }
            }
        }
        return res;
    }

    //统计素数4, 线性筛选
    int countPrime4(int n) {
        vector<int> primes;
        vector<int> isPrime(n, 1);
        for (int i = 2; i < n; ++i) {
            if (isPrime[i]) {
                //把素数存起来
                primes.push_back(i);
            }
            for (int j = 0; j < primes.size() && i * primes[j] < n; ++j) {
                isPrime[i * primes[j]] = 0;
                if (i % primes[j] == 0) {
                    break;
                }
            }
        }
        return primes.size();
    }

};



#endif //CLIONTEST_SOLVE2_H
