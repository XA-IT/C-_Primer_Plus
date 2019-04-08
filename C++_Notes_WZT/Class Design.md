## Part Ⅲ Tools for Class Designer
C++ Primer 5th edition

---

### Cpt.14 **重载运算与类型转换**
重载的运算符是具有特殊名字的函数, 其名字由关键字**operator**和其后要定义的运算符号组成.
- 基本概念
  - 不能对内置类型进行重载: `int operator+(int, int);` //错误!
  - 直接调用运算符函数: `operator+(data1, data2);` 等价于 `data1 + data2;`
  - 重载的运算符含义应该与内置类型一致
  - 对于赋值/下标/调用等运算符可以设为成员函数, 但对于算数/相等性/关系/位运算等应该设为非成员函数:
    - `string u = "hi" + s;` //若为成员函数则错误, `const char* `类型没有成员函数`operator+`!
- 输入和输出运算符
  - 对输出运算符的重载
    - 输入为ostream的引用 以及 输入对象的常引用; 返回为os 的引用
    - 尽量减少格式化操作, 避免自行换行等操作
    - 运算符必须为非成员函数
  - 对输入运算符的重载
    - 注意检查输入istream & is的错误: 
      - 在使用输入数据前进行判断: `if (is) { ... }`
    - 发生错误后及时将操作对象重置为空(调用默认构造函数)
- 算术和关系运算符
  - 非成员函数, 传入常量引用
  - 如果定义了复合运算符, 更应在实现中调用之(如 += 实现 + ), 这样可以减小拷贝次数
  - 如果定义了相等运算符(==), 则应定义不等运算(!=)
  - 如果定义了关系运算符(<), 则对于两个!=的对象应该有一个 < 另一个
- 赋值运算符
  - 注意释放当前内存空间, 并创建新空间
  - 一般需为成员函数, 返回运算符左侧的对象的引用: *this
- 下标运算符operator[]
  - 必须为成员函数, 返回访问元素的引用, 且应有普通和const两个版本
- 递增和递减运算符++, --
  - 应为成员函数, 返回对象的引用, 且应有前置和后置两个版本
  - 前置: `StrBlobPtr& operator++ ();`
  - 后置: `StrBlobPtr operator++ (int);`, 形参仅用于区分前置, 不参与运算
    - // 注意应先记录当前对象值, 自增后返回增加前的值
    - 后置应调用前置的版本
    - 若想显式地调用后置运算符, 需传入形参: `strblobp.operator++(0);`
- 成员访问运算符
  - 成员函数, 返回对应的引用(*)或地址(->)
  - 箭头运算符必须实现成员访问的功能
    - `point->mem`等价于`point.operator()->mem;`
- 函数调用运算符: 使对象可以作为函数进行调用
  - 必须为成员函数, 定义了函数调用运算符的对象为 函数对象
    - 常用作泛型算法的实参: 
      ```cpp
      class PrintString {
      public:
          PrintString(ostream &os = cerr, char c = ' '): os(o), sep(c) { }
          void operator() (const string &s) const { os << s << sep; }
      private:
          ostream &os;
          char sep;
      }      
      for_each(vs.begin(), vs.end(), PrintString(cerr, '\n'));  
      ```
  - lambda是函数对象(未命名类的未命名对象)
    - 其值捕获相当于在类中以对应数量的数据成员进行初始化, 但该合成类将不具有默认构造函数等
  - 标准库定义的函数对象
    - 头文件: `<functional>`
    - 定义成模板的形式, 如`plus<string> strAdd;`实现对string的加法
      |        算术        |         关系         |        逻辑         |
      | :----------------: | :------------------: | :-----------------: |
      |    `plus<Type>`    |   `equla_to<Type>`   | `logical_and<Type>` |
      |   `minus<Type>`    | `not_equal_to<Type>` | `logical_or<Type>`  |
      | `mulitplies<Type>` |   `greater<Type>`    | `logical_not<Type>` |
      |`以及divides, `     |`less, less_equal等`|
      |`modulus(%), negate`| 
    - 使用标注库函数对象: `sort(svec.begin(), svec.end(), greater<string>());`//降序排列
      - 甚至可以比较指针: 
      - `sort(nameTable.begin(), nameTable.end(), less<string*>());`//其中nameTable的元素为string*