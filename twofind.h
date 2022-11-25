//
// Created by Ycq on 2022/6/23.
//

#ifndef CLIONTEST_TWOFIND_H
#define CLIONTEST_TWOFIND_H



#include <bits/stdc++.h>
using namespace std;

struct Creature
{
    int legs;
    string name;
};

class M
{//实现一个函数，是实现二分查找，基本数据和复制数据
public:

    template <typename T>
    int twofind(vector<T>& nums, T target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid] > target) right = mid - 1;
            else if (nums[mid] < target) left = mid + 1;
            else return mid;
        }
        return -1;
    }

    int twofind(vector<Creature>& nums, Creature target)
    {
        int n = nums.size();
        int left = 0, right = n - 1;
        while (left <= right)
        {
            int mid = left + (right - left) / 2;
            if (nums[mid].legs > target.legs) right = mid - 1;
            else if (nums[mid].legs < target.legs) left = mid + 1;
            else return mid;
        }
        return -1;
    }
};


//int main()
//{//二分查找
//    M m;
//    vector<Creature> cre = {
//            {2, "Bcd"},
//            {4, "C"},
//            {8, "D"}
//    };
//    vector<int> nums = {1, 2, 3};
//    int a = m.twofind(cre, {8, "D"});
//    cout << a << endl;
//    int b = m.twofind(nums, 2);
//    cout << b << endl;
//    cout<<" 你好 "<<endl;
//
//}




#endif //CLIONTEST_TWOFIND_H
