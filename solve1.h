// 位运算 + 常见的算法
// Created by Ycq on 2022/5/28.
// 用于做题的

#ifndef CLIONTEST_SOLVE1_H
#define CLIONTEST_SOLVE1_H

#include <bits/stdc++.h>
using namespace std;


class Solution
{
private:
    int p_a = 0;
public:

    //计算无符号数二进制表示中1的个数
    int getone(unsigned int a)
    {
        int res = 0;
        while (a != 0)
        {
            res++;
            a = a & (a - 1); // 每次消除二进制表示的最后一个1
        }
        return res;
    }

    //判断该数是个否是2的指数
    bool isPoweroftwo(int a)
    {//判断该数是个否是2的指数，如果是的话，二进制表示最高位为1，经过a & (a - 1)操作后就为0了
        if (a <= 0) return false;
        return (a & (a - 1)) == 0;
    }

    //在数组中查找只出现一次的元素
    int findone(vector<int>& nums)
    {//相同的数的异或为0，一个数与0的异或为本身
        int res = 0;
        for (auto n : nums)
            res ^= n;
        return res;
    }

    /*!
     * 判断奇偶性
     * @param num
     * @return true:奇数，false:偶数
     */
    bool odd_even(int num){
        return num & 1;
    }

    /*!
     * 判断闰年
     * @param year
     * @return ture:闰年
     */
    bool isleap_year(int year){
        return (year % 4 == 0 && year % 100 != 0) || (year % 400 == 0);
    }

    struct node
    {
      node(int a) : val(a){}
      node(){}
      int val;
      node *next;
    };

    /*!
     * 多个指针指向一个位置的使用
     */
    void print_point()
    {

      node* n1 = new node(5);
      node* n2 = new node();
      n2->next = n1;

      delete n1;
      printf("n1:%d, n2:%d\n", n1, n2->next);
      n1 = NULL;
      printf("n1:%d, n2:%d\n", n1, n2->next);
      printf("n1:%d\n", n2->next->val);
      n2->next = NULL;
      //printf("n1:%d\n", n2->next->val);
      printf("n1:%d, n2:%d\n", n1, n2->next);

      int* p = new int(5);
      int* p1 = p;
      int* p2 = p;
      printf("p:%d, p1:%d, p2:%d\n", &p, &p1, &p2);

      //p = NULL; //自己的指向置空，其他的指向还是指向以前的位置
      delete p; //只是释放了指向的空间，自己本身的指向没变
      printf("p:%d, p1:%d, p2:%d\n", p, p1, p2);
      cout << *p1 <<endl;
    }


};

#endif //CLIONTEST_SOLVE1_H
