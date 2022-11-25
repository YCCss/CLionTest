// 大堆根
// Created by Ycq on 2022/6/8.
//

#ifndef CLIONTEST_BIGHEAP_H
#define CLIONTEST_BIGHEAP_H

#include <vector>

using namespace std;

// 建立大堆根
// 参考：https://blog.csdn.net/dream_follower/article/details/105202811
// 数组以下标0开始，第i位置的左节点为2i+1,右节点为2i+2,父节点为(i-1)/2
class BigHeap
{
private:
    vector<int> vec;
public:
    BigHeap(){}
    BigHeap(vector<int> &v) : vec(v)
    {
        heapBuild(vec);
    }
    //返回大堆数组
    vector<int> get()
    {
        return vec;
    }
    //返回大堆顶
    int top()
    {
        return vec[0];
    }
    //删除堆顶
    void pop()
    {
        swap(vec[0], vec[vec.size() - 1]); //将堆顶元素交换到数组尾部
        vec.pop_back(); //删除尾部元素
        heapAdj(vec, 0, vec.size()); //调整大堆
    }
    //添加元素
    void push(int x)
    {
        vec.push_back(x);
        heapInsert(vec, vec.size() - 1);
    }
    //vec的大小
    int size()
    {
        return vec.size();
    }
    //判空
    bool empty()
    {
        return vec.empty();
    }

    //在大堆根后面index位置的元素进行调整
    void heapInsert(vector<int>& arr, int index)
    {//将index和他的根节点比较，大于的话就交换
        while(arr[index] > arr[(index-1)/2])
        {//index=0时会终止循环
            swap(arr[index], arr[(index-1)/2]);
            index = (index - 1) / 2;
        }
    }
    //调整index位置的元素，一般是第一个index=0
    void heapAdj(vector<int>& arr, int index, int heapSize)
    {//将index与他左/右节点最大的交换
        int left = 2 * index + 1; // index的左节点
        while(left < heapSize)
        {
            //寻找左右节点的最大值下标
            int large = left + 1 < heapSize && arr[left+1] > arr[left] ? left + 1 : left;
            //左右最大值和index比较
            large = arr[large] > arr[index] ? large : index;
            if (large == index)
            {
                break;
            }
            swap(arr[large], arr[index]);
            index = large;
            left = 2 * index + 1;
        }
    }
    //建大堆根
    void heapBuild(vector<int>& arr)
    {
        int n = arr.size();
        if (n < 2) return;
        for (int i = 0; i < n; i++)
        {//建大堆根
            heapInsert(arr, i);
        }
    }
    //堆排序, 不要给本对象的vec排序，由于使用的是引用传参，会改变vec，而使vec不满足大堆根的规则
    void heapSort(vector<int>& arr)
    {//其实就是依次把堆顶的元素放入数组尾部，每次heapSize减1（>0）,最后arr是升序
        int n = arr.size();
        heapBuild(arr);
        //将第一个（堆顶）元素和最后一个元素交换
        swap(arr[0], arr[--n]);
        while(n > 0)
        {
            heapAdj(arr, 0, n);
            swap(arr[0], arr[--n]);
        }
    }


    //递归方式建堆
    //参考：https://www.bilibili.com/video/BV1Eb41147dK?from=search&seid=3993837508839965022
    void heapify(vector<int>& nums, int n, int i)//对有一定顺序的堆，
    {//当前第i个结点取根左右的最大值（这个操作称heapfiy）
        int l = i * 2 + 1, r = i * 2 + 2;
        int max = i;
        if (l<n && nums[l]>nums[max])
            max = l;
        if (r<n && nums[r]>nums[max])
            max = r;
        if (max != i)
        {
            swap(nums[max], nums[i]);
            heapify(nums, n, max);
        }
    }
    void heapify_build(vector<int>& nums, int n)//建立大根堆，从树的倒数第二层第一个结点开始，
    {//对每个结点进行heapify操作，然后向上走
        int temp = (n - 2) / 2;
        for (int i = temp; i >= 0; i--)
            heapify(nums, n, i);
        for (int i = 0; i < nums.size(); i++)
            cout << nums[i] << " ";
        cout << endl;
    }
    void heapify_sort(vector<int>& nums, int n)//建立大根堆之后，每次交换最后一个结点和根节点（最大值），
    {//对交换后的根节点继续进行heapify（此时堆的最后一位是最大值，因此不用管他，n变为n-1）
        heapify_build(nums, n);
        for (int i = 0; i < n; i++)
        {
            swap(nums.front(), nums[n - i - 1]);
            heapify(nums, n - i - 1, 0);
        }
    }
};


#endif //CLIONTEST_BIGHEAP_H
