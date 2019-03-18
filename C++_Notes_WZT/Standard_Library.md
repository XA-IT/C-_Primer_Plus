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

| 文件模式 |           说明           |
| :------: | :----------------------: |
|    in    |       以读方式打开       |
|   out    |            写            |
|   app    | 每次操作前均定位到文件尾 |
|   ate    |  打开文件后立即定位到尾  |
|  trunc   |         截断文件         |
|  binary  |       二进制方式IO       |

  - ofstream默认为out模式, 若仅以out方式打开会截断文件, 为保留文件内容应指定app模式: 
  - `ofstream app2("file1", ofstream::out | ofstream::app);`
  - 每次open均会设置文件模式

#### string流
特有操作: 
```cpp
sstream strm;
sstream strm(s);
strm.str();     //返回strm中保存的string的拷贝
strm.str(s);    //将s拷贝到strm中
```
---
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

#### **顺序容器**操作
- 添加元素
  - `c.push_back(t); c.emplace_back(args);` `c.push_front(t);`
  - `slist.insert(iter, "hello!");` //将hello插入到iter所指位置之前 `slist.insert(iter, 10, "hi!"); //插入10个hi` `slist.insert(iter, iter2begin, 2end);`
    - insert将返回指向新加入元素的iter, 在旧版本中其他Insert版本将返回void
    - C++11: 接收元素个数或范围的insert也将返回指向第一个新加入元素的iter
  - `c.emplace_back(argv); //以argv为参数调用元素的构造函数, 而非拷贝元素`
- 访问元素
  - `c.front(); ` 与 `c.back();`
  - `c.at(0);` 代替 `c[0];`, 会提示下标越界问题
- 删除元素
  - `c.pop_back();` `c.pop_front();`, 返回void, 若c为空则行为未定义
  - `c.erase(p);` `c.erase(b,e);` 删除b到e之前的元素, 返回删除元素的下一个位置
- 改变容器大小 `ilist.resize(10, -1);` //若ilist元素少于10个则以-1补全
- 注意对容器的操作可能会使迭代器**失效**
  - 对于容器中元素的增删都会影响, 当删除元素时, c.end()总是会失效, 


#### vector 与 string的高效增长
- 其分配的内存空间将大于当前需求的:
  - `c.shrink_to_fit()`将capacity()缩小至size();
  - `c.capacity()` and `c.reserve(n)`显示c的容量与申请预留n个元素的空间
- 其原则是只有**迫不得已**才会重新分配新的内存空间

#### string 的其他操作
- string的其他构造方法
  - `string s(cp, n)` //以cp的前n个字符构造s, 
  - `string s(s2, pos2)` //以s2中pos2开始的字符构造, 
  - `string s(s2, pos2, len2)` //pos2开始的len2个字符
  - 注意: const char* 向 string转换或构造时, 若无计数值限制则需遇到'\0'才会停止
- 改变string内容的其他方法, assign, insert, erase; append, replace;
- string中的搜索
- 比较--s.compare函数
- 数值转换
  - `string s = to_string(i);` //将整数i转换
  - `double d = stod(s);` //转换为double

#### 容器适配器
- stack, queue, priority_queue

---
### Cpt.10 泛型算法
#### 概述
- 借助迭代器进行操作, 输入前两个参数往往是两个迭代器表示范围, 不依赖于容器类型, 但其具体的算法可能与容器中元素类型的操作相关, 如比较==, <等
- 对迭代器的操作分类
  - **只读算法**, 只读取输入范围内的元素, 有find, count, accumulate, equal等
    - `accumulate(b, e, val)`: 对范围内元素进行累加求和, 初始值为val, val需支持+运算, 如string可初始化为`string("")`, 避免被认为是char*
    - `equal(b1, e1, b2)`: 检查第一个序列的每一个元素是否与第二个相等, 注意第二个序列的大小必须大于等于第一个
  - **写入/修改元素**的算法, 首先需要注意容器的大小往往不能由算法改变, 因此要检查容量, 有fill, fill_n(二者均只写入或修改, 不负责申请空间), copy, replace, replace_copy等
    - back_inserter, 插入迭代器, `auto it = back_inserter(vec); *it = 43;` 对迭代器的赋值将会push_back一个对应值的元素: `fill_n(back_inserter(vec), 10, 0);`
    - `replace_copy(ilist.cbegin(), ilist.cend(), back_inserter(ivec), 0, 42);`
  - **重排元素**的算法, sort, unique等
    - `unique(b, e)`: 返回最后一个不重复元素之后的迭代器
    - erase等

#### 定制操作
- 向算法传递函数
  - 传递一个**谓词(predicate)**, 是一个表达式, 其返回结果是一个bool, STL中的谓词有一元和二元两类
    - `sort(b, e, func);` //func为谓词, 即一个函数, 用于比较, 
    - `stable_sort(b, e, func);` //保持相等元素的原始顺序
    - `partition(b, e, predicate)`, //使得满足pre的在前, 为false的在后, 返回最后一个为true之后的元素位置

- **lambda表达式** (C++ 11)
  - 为了传递更多的谓词, 使用lambda表达式; 对于可以使用 **调用运算符(就是括号())** 的对象称为**可调用对象**, 典型例子: 函数与函数指针, 以及重载函数调用运算符的类, 以及**lambda expression**
    - 表示一个可调用的代码单元, 无名称的内联函数, 可能定义在函数内部
  - 典型形式: `[capture list] (parameter list) -> return type { function body } `
    - 捕获列表是lambda所在函数定义的局部变量列表, 通常为空; 其他与普通函数类似, 但必须使用尾置返回类型
    - 捕获列表可为空但不可缺省, 函数体亦不可缺省, 其他可以忽略, 返回值在函数体仅有一条return语句时自动推断, 否则**默认为void**: `auto f = [] { return 42; };`
    - 向lambda传递参数时不能有默认参数
    - 调用`find_if(b, e, lmd)`, 返回第一个使lmd为true的迭代器或e的拷贝, lmd为一元谓词
    - 调用`for_each(b, e, lmd)`, 对于输入序列的每一个元素都调用lmd
  - 捕获与返回: 捕获列表的参数的值传递(即拷贝)是在lambda创建时就已完成的, 而非在调用时, 与函数不同; 引用传递需要注意引用的存在必须久于lambda, 如果可能, 尽量避免使用, 尽量减少捕获的数据量
    - **隐式捕获**, 由编译器推断需要的变量: `[&]` 或 `[=]`, 可以与显式捕获混用, 但隐式必须在最前, 且用&则不能引用传递, 用=不能值传递
    - *可变*lambda, 对于被捕获并拷贝的值可以通过mutable来改变, 对于引用传值需保证引用的对象非const: 
      - `auto f = [v1] () mutable { return ++v1; } ;`
    - 调用`transform(b1, e1, b2, ldm);`, 将输入序列依次执行lambda并写入b2表示为起点的迭代器
    - **返回**类型, 当超过一条return语句时, 默认为void, 若想指定需尾置返回类型: 
      - `transform(vi.begin(), vi.end(), vi.begin(), [] (int i) -> int  { if (i < 0) return -i; return i; });`
  - 参数绑定: (C++ 11:)当函数参数多于谓词限制时考虑使用bind函数解决:
    - `auto newCallable = bind(callable, arg_list);`
    - >to be continue..

#### 迭代器再探
- 额外的迭代器: 插入迭代器, 流迭代器, 反向迭代器, 移动迭代器
- 插入迭代器: `back_inserter`, `front_inserter`, 和`inserter`
  - 注意每种迭代器都需要容器支持; `inserter(c, b)` 表示容器c的目标位置为b, 调用it将使元素被插入到b之前
  - 插入迭代器执行`*it`, `++it`等操作不会做任何事, 只会返回it本身
- iostream 迭代器
  - 将流作为特定的元素序列来处理
  - istream_iterator: 
    - `istream_iterator<int> in_it(cin), eof;`
    - `vector<int> vec(in_it, eof);`  //eof为空, 表示尾后位置
    - 使用流迭代器时允许懒惰求值, 仅在第一次解引用迭代器前进行读值
  - ostream_iterator:
    - 


---
### Cpt.11 **关联容器**
associative-container: 主要包含map和set两种

| 按关键字有序保存元素的 |                说明                |
| :--------------------: | :--------------------------------: |
|          map           |              关联数组              |
|          set           |      关键字即值，只保存关键字      |
|        multimap        | key可重复出现，相同key**相邻**存储 |
|        multiset        |                同上                |
|                        |
|        无序集合        |                说明                |
|     unordered_map      |        用哈希函数组织的map         |
|     unordered_set      |                同上                |
|   unordered_multimap   |
|   unordered_multiset   |

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