#ifndef STDAFX_H
#define STDAFX_H

#if _MSC_VER > 1000
#pragma once
#endif // _MSC_VER > 1000


#include <assert.h>
#include <stdio.h>
#include <stdlib.h>

//#define _USE_MATH_DEFINES
#include <math.h>
//#undef  _USE_MATH_DEFINES

#include <memory.h>

//c++头文件
#include <algorithm>//STL 通用算法   
#include <bitset>//STL 位集容器   
#include <cctype>   
#include <cerrno>   
#include <clocale>   
#include <cmath>   
#include <complex>//复数类   
#include <cstdio>   
#include <cstdlib>   
#include <cstring>   
#include <ctime>   
#include <deque>//STL 双端队列容器   
#include <exception>//异常处理类   
#include <fstream>   
#include <functional>//STL 定义运算函数（代替运算符）   
#include <limits>   
#include <list>//STL 线性列表容器   
#include <map>//STL 映射容器   
#include <iomanip>   
#include <ios>//基本输入／输出支持   
#include <iosfwd>//输入／输出系统使用的前置声明   
#include <iostream>   
#include <istream>//基本输入流   
#include <ostream>//基本输出流   
#include <queue>//STL 队列容器   
#include <set>//STL 集合容器   
#include <sstream>//基于字符串的流   
#include <stack>//STL 堆栈容器　　　　   
#include <stdexcept>//标准异常类   
#include <streambuf>//底层输入／输出支持   
#include <string>//字符串类   
#include <utility>//STL 通用模板类   
#include <vector>//STL 动态数组容器   
#include <cwchar>   
#include <cwctype>

#include <memory>

using namespace std;

// Definition for a binary tree node.
struct TreeNode {
    int val;
    TreeNode *left;
    TreeNode *right;
    TreeNode(int x) : val(x), left(NULL), right(NULL) {}
};

 //Definition for singly-linked list.
 struct ListNode {
     int val;
     ListNode *next;
     ListNode(int x) : val(x), next(NULL) {}
 };
 #endif