## Part Ⅱ Standard Library
C++ Primer 5th edition

---
### Cpt.8 **IO库**
读取与写入数据

#### IO类
- 主要的IO库的头文件
  - iostream: 数据(流)的读写; istream, wistream; ostream, wostream; iostream, wiostream; 等
  - fstream: 文件读写
  - sstream: 内存string的读写
- IO对象不能拷贝或赋值
  - **不能用于形参或返回值类型**
- IO类的条件状态
  - 见表8.2, 
  - 在调用流对象时可以快速检查其状态, 如`while(cin >> word) {}` 如果输入操作成功则为真
  - 查询流的状态: strm::iostate类; 典型函数: good(), bad();
  - 管理流的状态: 
    - strm.rdstate();   //读取状态
    - strm.setstate(iostate);
    - strm.clear();
  - 输出缓冲管理
    - `endl`; `ends`; `flush`; //刷新缓冲区, ends输出一个空字符, flush不输出任何额外字符
    - `cout << unitbuf; `//在接下来的操作中均立即刷新缓冲区
    - `cin >> ival;` //cin与cout关联, 因此该操作导致cout立即被刷新
      - 通过`cin.tie();`获取当前关联流对象的指针, 若有参数则关联新的流对象

#### 文件输入输出
- 通过`ifstream 和 ofstream`向一个给定文件读取或写入数据, `fstream`同时读写数据
  - `fstream fstrm(s, mode);` //创建一个fstream对象fstrm, 并打开名为s的文件, mode可选
  - `fstrm.open(s);`    //若未初始化对象可用open初始化, 但不可open已经打开的文件流, 需要先close(), 在调用流前可以测试是否正常: `if (fstrm) {}`
  - 在main函数中可以使用循环打开argv[]中的文件
- 文件模式 mode

文件模式 | 说明
:--:|:--:
in | 以读方式打开
out | 写
app | 每次操作前均定位到文件尾
ate | 打开文件后立即定位到尾
trunc | 截断文件
binary | 二进制方式IO

  - ofstream默认为out模式, 若仅以out方式打开会截断文件, 为保留文件内容应指定app模式: 
  - `ofstream app2("file1", ofstream::out | ofstream::app);`
  - 每次open均会设置文件模式

#### string流
特有操作: 
```
sstream strm;
sstream strm(s);
strm.str();     //返回strm中保存的string的拷贝
strm.str(s);    //将s拷贝到strm中
```
### Cpt.9 **顺序容器**
#### 顺序容器概述
- 主要的顺序容器类型: vector, deque, list(双向链表), string, C++11: forward_list(手写单向链表, 无size操作), array 
  - deque: 双端队列, 与vector访问速度相当, 可快速在首尾增删元素
- 容器库概览: 
  - 通用操作: 
    - 类型别名: iterator, size_type, difference_type, value_type, reference, 当不知道容器中元素类型时使用更方便
    - 构造函数: `C c(b, e); //将迭代器b和e指定的范围内的元素拷贝到c, 即左闭右开, array不支持`
    - 赋值与swap
    - 大小: `c.size();  c.max_size();  c.empty();`
    - 增删元素
    - 关系运算
    - 获取迭代器: `c.begin(); c.end();  c.cbegin();  c.cend(); //获取迭代器常量`, end指向容器的**尾后元素**
    - 反向容器的成员: `reverse_iterator`, `c.rbegin();`等
  - array: 具有固定大小, 必须指定容器大小, 可以对整个容器进行拷贝或赋值
- 容器的定义与初始化
  - `C c(b, e);//不适用于array` `c seq(n, t); //不适用于string, 以n个t元素初始化`
- 赋值与swap
  - `c1=c2; c={a, b, c...};` 
  - `swap(c1, c2); //不会进行拷贝赋值, 而是直接交换二者的内部数据结构`
  - `seq.assign(b, e);//以[b, e)中的元素替换seq, 不能指向seq中元素` 关联容器与array不适用, 除string外, assign相比于赋值可以使指向seq的迭代器引用与指针保持有效, 也可以实现从不同但兼容的容器中赋值
- 容器大小操作
  - `c.size()` `c.empty()` `c.max_size() //返回大于等于该容器所容纳最大元素数的值`

- **顺序容器**操作
  - 添加元素
    - `c.push_back(t); c.emplace_back(args);` `c.push_front(t);`
    - `slist.insert(iter, "hello!"); //将hello插入到iter所指位置之前` `slist.insert(iter, 10, "hi!"); //插入10个hi` `slist.insert(iter, iter2begin, 2end);`
      - insert将返回指向新加入元素的iter, 在旧版本中其他Insert版本将返回void
      - C++11: 接收元素个数或范围的insert将返回指向第一个新加入元素的iter
    - `c.emplace_back(argv); //以argv为参数调用元素的构造函数, 而非拷贝元素`
  - 访问元素
    - 
---
### Cpt.11 **关联容器**
associative-container: 主要包含map和set两种

按关键字有序保存元素的 |说明  
:--:|:--:
map |关联数组
set |关键字即值，只保存关键字
multimap |key可重复出现，相同key**相邻**存储
multiset |同上
|
无序集合|说明
unordered_map|用哈希函数组织的map
unordered_set|同上
unordered_multimap|
unordered_multiset|  

#### 关联容器的使用
##### 概述
- 使用map： 
  - `map<string, size_t> word_count; string word; ++word_count[word];`
- 使用set
  - `set<string> exclude = {"the", "but", "and", "or"}; `
  - `if (exclude.find(word) == exclude.end()) ++word_count[word];`
##### 有序容器
- 比较关键字
  - 默认使用 < 来比较关键字的大小，可以自己定义，但操作须满足**严格弱序**（可看做小于等于）
  - 凡是定义了“行为正常”的<运算的类型均可作为有序容器的关键字
  - 比较类型可以通过函数指针来定义：
  - `bool compareISBN(const Sales_data &lhs, const Sales_data &rhs) { return lhs.isbn() < rhs.isbn();}`
  - `multiset<Sales_data, decltype(compareISBN) *> bookstore(compareISBN);//在<>中支出自定义操作的类型，对于函数指针其声明须加*，compareISBN为构造函数的参数。`
##### pair类型
- `pair<string, string> author{"James", "Joyce"};//初始化可省略`
- 成员为public类型，分别为first和second
- 基本操作：
  - 初始化：`pair<T1, T2> p = {v1, v2};` 等价于 `pair<T1, T2> p(v1, v2);`
  - p.first; p.second;
  - p1 relop p2;
  
##### 关联容器操作
- 在关联容器中额外有如下类型别名：
  - key_type
  - mapped_type 关键字关联的类型 `map<string, int>::mapped_type v5; //v5是一个int`
  - value_type 对于map而言其保存`pair<const key_type, mapped_type>`，对于set为key_type
- 使用迭代器访问
  - 返回一个value_type的引用，注意对于pair.first和set其迭代器均为const
- 插入元素
  - `set1.insert(vect1.begin(), vect1.end());`或`{}`
  - 返回一个pair，first为指向关键字元素的迭代器，second为bool型，失败（如已存在）则不执行插入并返回false
  - 向map中添加元素时须为pair类型
- 删除元素
  - `c.erase(key_type); `//从c中删除每个关键字为key_type的元素
  - 传递一个/两个迭代器元素，返回指向删除后的下一个元素的迭代器
- 在map中的下标操作：
  - `word_count["Anna"] = 1;`如果Anna不存在则**添加该关键字**并赋值为1，因此若map为const则不适用此方法
  - `c.at(k)`若k不在c中则抛出异常
  - 其返回值为mapped_type，因此可直接修改值的大小，但与迭代器返回的value_type并不相同
- 访问元素
  - 查找是否存在： find(v) //返回迭代器, count(v)//返回次数
  - `lower_bound(k)` `upper_bound(k)` `equal_range(k)/*返回一个迭代器pair，指向关键字符合k的元素的范围，不存在则均为c.end()`