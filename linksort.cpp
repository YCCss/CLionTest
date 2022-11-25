#include <iostream>
#include <vector>
#include <string>

using namespace std;

//将链表用冒泡排序

//链表的节点
struct Node
{
  char val;
  Node* next;
  Node(char ch) : val(ch), next(nullptr){}
};

class Solution
{
public:
  Solution(){}//无参构造函数

  Solution(string &s)
  {//有参构造函数
    build(s);
  }
  ~Solution()
  {//析构函数，释放动态分配的内存
    Node* cur = head->next;
    while (cur != nullptr)
    {
      Node *tp = cur->next;//保存下一个节点
      delete cur;//释放当前节点的空间
      cur = tp;
    }
    delete head;//释放头节点的空间
  }

  void set_str(string &str)
  {//当使用无参构造的时候，需要调用这个函数构建链表
    build(str);
  }

  Node* get_head()
  {//返回链表头节点
    return head;
  }

  void print_list()
  {  //打印链表
    cout << "Access by in:";
    Node* cur = head->next;
    while (cur->next != nullptr)
    {
      cout << cur->val << "->";
      cur = cur->next;
    }
    cout << cur->val << endl;
  }

  void bubble_sort()
  {//链表冒泡排序
    int ct, num;//ct为链表长度，num为第二趟排序的次数
    Node *pre = head, *p1, *p2;
    while(pre->next != nullptr)
    {//计算链表长度
      ct++;
      pre = pre->next;
    }

    for (int i{0}; i < ct - 1; i++)
    {
      num = ct - i - 1;

      p1 = head->next;//p1指向第一个节点
      p2 = p1->next;//p2指向第二个节点
      pre = head;//pre指向p1的前一个节点，即头结点

      while(num--)
      {
        if(cmp(p1->val, p2->val))
        {//前面的节点大，交换
          p1->next = p2->next;
          p2->next = p1;
          pre->next = p2;
        }
        pre = pre->next;
        p1 = pre->next;
        p2 = p1->next;
      }
    }
  }

  //从尾部添加节点
  void add(char val)
  {
    Node *new_n, *cur = head;
    new_n = new Node(val);
    while(cur->next != nullptr)
    {//获得最后一个节点
      cur = cur->next;
    }
    cur->next = new_n;
  }

private:
  Node *head = new Node(0);//头结点不包含数据

  //根据字符串创建链表
  void build(string &s)
  {
    Node* cur = head;
    for (int i=0; i < s.size(); i++)
    {
      Node *n = new Node(s[i]);
      cur->next = n;
      cur = cur->next;
    }
  }


  bool cmp(char a, char b)
  {//按照0-9，a-z,A-Z排序， a>b,返回true,需要交换
    //由于字符串的ascii码从小到大，是0-9,A-Z,a-z
    //因此a和b分别是A-Z和a-z，则需要反序判断
    if((a >= 'A' && a <= 'Z') && (b >= 'a' && b <= 'z'))
      return true;
    else if((a >= 'a' && a <= 'z') && (b >= 'A' && b <= 'Z'))
      return false;
    else if(a > b)
      return true;
    else
      return false;
  }

};

int main1241()
{
  string str;
  cout << "Please enter the string:";
  cin >> str;
  Solution s(str);//定义一个链表冒泡排序对象，传入一个string对象,并构建链表
  s.bubble_sort();//对链表排序
  s.print_list();//输出链表

  //获取链表的头结点，以至于在对象外访问排序的链表，比如打印或访问
  Node* head = s.get_head();
  cout << "Access by out:";
  Node* cur = head->next;
  while (cur->next != nullptr)
  {
    cout << cur->val << "->";
    cur = cur->next;
  }
  cout << cur->val << endl;


  return 0;
}
