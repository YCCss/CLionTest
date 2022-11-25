//
// Created by Ycq on 2022/7/24.
// 一些函数的封装

#ifndef CLIONTEST_PACKAGE_H
#define CLIONTEST_PACKAGE_H

#include <bits/stdc++.h>
using namespace std;

class Package
{
public:
    /*!
     * 写入文件,成功返回1
     * @param path 文件路径
     * @param str 写入文件的内容
     * @return  true写入成功
     */
    bool write_file(string path, string str)
    {
        fstream out; //创建文件输入输出流
        out.open(path, ios::out|ios::app);
        if (out.is_open())
        {
            out << str;
            out.close();
            return 1;
        }
        else return 0;
    }

    /*!
     * 读文件,成功返回读取到的文件大小,否者返回-1；
     * 该函数只能一次性将文件数据读完；
     * @param path 文件路径
     * @param str 读取文件的内容（不知道能都多少）
     * @param mode true:一行一行的读，false:一个一个字节的读
     * @return
     */
    int read_file(string path, string& str, bool mode = true)
    {
        fstream in;
        in.open(path, ios::in);
        if (in.is_open())
        {
            if (mode)
            {
                string buf;
                while (getline(in, buf))
                {//按行读
                    str += buf + '\n'; //读的时候会将换行符号去掉，这我们把他加上
                }
            }
            else
            {
                char c;
                while ((c = in.get()) != EOF)
                {//按每个字符读， 默认会读取换行符号
                    str += c;
                }
            }
            return str.size();
        }
        else return -1;

    }

    /*!
     *打印函数，并换行，str是string的话可以拼接后输出
     * 一般情况下只能打印内置数据类型
     */
    template<typename T>
    void print(T str)
    {
        cout << str << endl;
        cout << "------------------------------ print finsh ------------------------------" << endl;
    }

    /*！
     * 递归多参数打印
     * rprint("123", "fsdfa", "fsdg");
     * https://blog.csdn.net/wangx_x/article/details/122374408
     */
    void print()
    {//递归终止函数，最后会调用这个函数, 使用上面的函数替代了
        ;
    }
    //展开函数，
    template <class T, class ...Args>
    void print(T head, Args... args) {
        cout << head << " ";
        print(args...);
    }

    /*!
     * 遍历打印类似vector<int>的数据结构（一维数组），其他的如map<int, int>,需要重写for_each中的第三个参数lambda函数
     * 该函数不能遍历int a[]这种数组，没有迭代器
     * @tparam T
     * @param v
     */
    template<typename T>
    void for_each_(T v)
    {//for_each()在algorithm库中
        for_each(v.begin(), v.end(), [](decltype(*v.begin()) n){cout << n << ' ';});
        cout << endl;
        cout << "------------------------------ print finsh ------------------------------" << endl;
    }

    /*!
     * 通过字符ch分割字符串
     * @param in 输出字符串
     * @param ch 按照分割的字符
     * @return 分割好的string数组
     */
    vector<string> split(string in, char ch)
    {
        vector<string> res;
        for (auto &c : in)
        {
            if (c == ch) c = ' ';
        }
        istringstream str(in);
        string out;
        while (str >> out)
        {
            res.emplace_back(out);
        }
        return res;
    }
    vector<string> split1(string in, char ch)
    {
      vector<string> res;
      istringstream str(in);
      string out;
      while (getline(str, out, ','))
      {
        res.emplace_back(out);
      }
      return res;
    }


    template <class T>
    T mmax(T n)
    {
        return n;
    }
    /*!
     * 求最大值，可以传可变参数
     * @tparam T
     * @tparam Arg
     * @param n
     * @param arg
     * @return
     */
    template <class T, class ...Arg>
    T mmax(T n, Arg... arg)
    {
        return max(n, mmax(arg...));
    }


    /*!
     * 控制台打印进度条
     */
    void _progress_bar()
    {
        char buff[100]={};
        char ret[5]={"/|-\\"};
        int i=0;
        while(i<100)
        {
            buff[i]='#';
            i++;
            //%-100s:字符串占位100，-表示左对齐；
            //注意“%”的打印需要转义；
            printf("[%-100s][%d%%][%c]\r",buff,i,ret[i%4]);
            //每flush一下，就将缓冲区的内容刷到屏幕上
            fflush(stdout);
            Sleep(10);
        }
    }
};






#endif //CLIONTEST_PACKAGE_H
