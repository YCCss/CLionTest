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
{//实现一个函数，是实现二分查找，基本数据和复杂数据
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


    //二分法：
    //参考：https://mp.weixin.qq.com/s?__biz=MzAxODQxMDM0Mw==&mid=2247485044&idx=1&sn=e6b95782141c17abe206bfe2323a4226&scene=21#wechat_redirect
    //普通二分法
    int binarySearch(vector<int> nums, int target) {
        int left = 0;
        int right = nums.size() - 1; // 注意

        while(left <= right) {
            int mid = left + (right - left) / 2;
            if(nums[mid] == target)
                return mid;
            else if (nums[mid] < target)
                left = mid + 1; // 注意
            else if (nums[mid] > target)
                right = mid - 1; // 注意
        }
        return -1;
    }

    //二分法左边界
    int left_bound(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        // 搜索区间为 [left, right]
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                // 搜索区间变为 [mid+1, right]
                left = mid + 1;
            } else if (nums[mid] > target) {
                // 搜索区间变为 [left, mid-1]
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 收缩右侧边界
                right = mid - 1;
            }
        }
        // 检查出界情况
        if (left >= nums.size() || nums[left] != target)
            return -1;
        return left;
    }

    //二分法右边界
    int right_bound(vector<int> nums, int target) {
        int left = 0, right = nums.size() - 1;
        while (left <= right) {
            int mid = left + (right - left) / 2;
            if (nums[mid] < target) {
                left = mid + 1;
            } else if (nums[mid] > target) {
                right = mid - 1;
            } else if (nums[mid] == target) {
                // 这里改成收缩左侧边界即可
                left = mid + 1;
            }
        }
        // 这里改为检查 right 越界的情况，见下图
        if (right < 0 || nums[right] != target)
            return -1;
        return right;
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
