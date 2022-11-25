//来自 https://gitee.com/-/ide/project/ycqycq/CPlusPlusThings/edit/master/-/tool/output/container.cpp
// Created by Ycq on 2022/10/24.
//打印容器的数据

/*!

 //用例
int main() {
  map<int, int> mp{
      {1, 1},
      {2, 4},
      {3, 9}};
  cout << mp << endl;
  vector<vector<int>> vv{
      {1, 1},
      {2, 4},
      {3, 9}};
  cout << vv << endl;

  pair<int, int> p{1, 2};
  cout << p << endl;

  set<int> s{1, 2, 3};
  cout << s << endl;

  vector<char> v{'a', 'b'};
  cout << v << endl;
  set<char *> vs{"a", "b"};
  cout << vs << endl;

  map<int, char *> mm{
      {1,   "23"},
      {2, "234hi"}
  };
  cout << mm << endl;

}
 */

#ifndef CLIONTEST_OUTPUT_CONTAINER_H
#define CLIONTEST_OUTPUT_CONTAINER_H


#include <ostream>      // std::ostream
#include <type_traits>  // std::false_type/true_type/decay_t/is_same_v
#include <utility>      // std::declval/pair

// 检测是否是pair
template<typename T>
struct is_pair : std::false_type {
};
template<typename T, typename U>
struct is_pair<std::pair<T, U>> : std::true_type {
};
template<typename T>
inline constexpr bool is_pair_v = is_pair<T>::value;

// 检测输出函数是否存在
template<typename T>
struct has_output_function {
  template<class U>
  static auto output(U *ptr)
  -> decltype(std::declval<std::ostream &>() << *ptr,
      std::true_type());

  template<class U>
  static std::false_type output(...);

  static constexpr bool value =
      decltype(output<T>(nullptr))::value;
};

template<typename T>
inline constexpr bool has_output_function_v =
    has_output_function<T>::value;


enum CHARS {
  ORD,        // 其他类型
  CHAR,       // char 类型
  STRING      // string 类型
};

template<typename T>
int ischarOrString(T &elem) {
  using std::decay_t;
  using std::is_same;
  using element_type = decay_t<decltype(elem)>;
  constexpr bool is_char_v = is_same<element_type, char>::value;

  constexpr bool is_string_v = is_same<element_type, char *>::value ||
                               is_same<element_type, const char *>::value ||
                               is_same<element_type, std::string>::value;
  if (is_char_v)
    return CHAR;
  else if (is_string_v)
    return STRING;
  else
    return ORD;
}

template<typename T>
void output(T &elem, int type, std::ostream &os) {
  switch (type) {
  case CHAR:
    os << '\'' << elem << '\'';
    break;
  case STRING:
    os << '\"' << elem << '\"';
    break;
  case ORD:
    os << elem;
    break;
  }
}

//是pair类型的会调用这个函数
template<typename T, typename Cont>
auto output_element(std::ostream &os, const T &element,
                    const Cont &)
-> typename std::enable_if<is_pair<typename Cont::value_type>::value, bool>::type {
  int ftype = ischarOrString(element.first);
  int stype = ischarOrString(element.second);

  output(element.first, ftype, os);
  os << " => ";
  output(element.second, stype, os);
  return true;
}

//是上一个函数的重载
template<typename T, typename Cont>
auto output_element(std::ostream &os, const T &element,
                    const Cont &)
-> typename std::enable_if<!is_pair<typename Cont::value_type>::value, bool>::type {
  int etype = ischarOrString(element);
  output(element, etype, os);
  return false;
}

template<typename T, typename U>
std::ostream &operator<<(std::ostream &os, const std::pair<T, U> &pr) {
  os << '(' << pr.first << ", " << pr.second << ')';
  return os;
}

//template<typename T, typename Cont>
//auto output_element(std::ostream& os, const T& element,
//                    const Cont&, const std::true_type)
//-> decltype(std::declval<typename Cont::key_type>(), os)
//{
//    os << element.first << " => " << element.second;
//    return os;
//}
//
//template <typename T, typename Cont>
//auto output_element(std::ostream& os, const T& element,
//                    const Cont&, ...)
//-> decltype(os)
//{
//    os << element;
//    return os;
//}



// 针对没有输出函数的容器处理
template<typename T,
    typename = std::enable_if_t<!has_output_function_v<T>>>
auto operator<<(std::ostream &os, const T &container)
-> decltype(container.begin(), container.end(), os) {
  os << "{ ";
  if (!container.empty()) {
    bool on_first_element = true;
    for (auto elem:container) {
      if (!on_first_element) {
        os << ", ";
      } else {
        on_first_element = false;
      }
      output_element(os, elem, container);
    }
  }
  os << " }";
  return os;
}

#endif // CLIONTEST_OUTPUT_CONTAINER_H
