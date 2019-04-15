## Part Ⅲ Tools for Class Designer
C++ Primer 5th edition

---

### Cpt.14 **重载运算与类型转换**
重载的运算符是具有特殊名字的函数, 其名字由关键字**operator**和其后要定义的运算符号组成.
#### 基本概念
- 不能对内置类型进行重载: `int operator+(int, int);` //错误!
- 直接调用运算符函数: `operator+(data1, data2);` 等价于 `data1 + data2;`
- 重载的运算符含义应该与内置类型一致
- 对于赋值/下标/调用等运算符可以设为成员函数, 但对于算数/相等性/关系/位运算等应该设为非成员函数:
  - `string u = "hi" + s;` //若为成员函数则错误, `const char* `类型没有成员函数`operator+`!
#### 输入和输出运算符
- 对输出运算符的重载
  - 输入为ostream的引用 以及 输入对象的常引用; 返回为os 的引用
  - 尽量减少格式化操作, 避免自行换行等操作
  - 运算符必须为非成员函数
- 对输入运算符的重载
  - 注意检查输入istream & is的错误: 
    - 在使用输入数据前进行判断: `if (is) { ... }`
  - 发生错误后及时将操作对象重置为空(调用默认构造函数)
#### 算术和关系运算符
- 非成员函数, 传入常量引用
- 如果定义了复合运算符, 更应在实现中调用之(如 += 实现 + ), 这样可以减小拷贝次数
- 如果定义了相等运算符(==), 则应定义不等运算(!=)
- 如果定义了关系运算符(<), 则对于两个!=的对象应该有一个 < 另一个
#### 赋值运算符
- 注意释放当前内存空间, 并创建新空间
- 一般需为成员函数, 返回运算符左侧的对象的引用: *this
#### 下标运算符operator[]
- 必须为成员函数, 返回访问元素的引用, 且应有普通和const两个版本
#### 递增和递减运算符++, --
- 应为成员函数, 返回对象的引用, 且应有前置和后置两个版本
- 前置: `StrBlobPtr& operator++ ();`
- 后置: `StrBlobPtr operator++ (int);`, 形参仅用于区分前置, 不参与运算
  - // 注意应先记录当前对象值, 自增后返回增加前的值
  - 后置应调用前置的版本
  - 若想显式地调用后置运算符, 需传入形参: `strblobp.operator++(0);`
#### 成员访问运算符
- 成员函数, 返回对应的引用(*)或地址(->)
- 箭头运算符必须实现成员访问的功能
  - `point->mem`等价于`point.operator()->mem;`
#### 函数调用运算符: 使对象可以作为函数进行调用
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
- **头文件**: `<functional>`
- 定义成模板的形式, 如`plus<string> strAdd;`实现对string的加法
    |         算术         |         关系         |        逻辑         |
    | :------------------: | :------------------: | :-----------------: |
    |     `plus<Type>`     |   `equla_to<Type>`   | `logical_and<Type>` |
    |    `minus<Type>`     | `not_equal_to<Type>` | `logical_or<Type>`  |
    |  `mulitplies<Type>`  |   `greater<Type>`    | `logical_not<Type>` |
    |   `以及divides, `    | `less, less_equal等` |
    | `modulus(%), negate` |
- 使用标注库函数对象: `sort(svec.begin(), svec.end(), greater<string>());`//降序排列
    - 甚至可以比较指针: 
    - `sort(nameTable.begin(), nameTable.end(), less<string*>());`//其中nameTable的元素为string*
- 可调用对象与function
- 可调用对象: 函数/函数指针/lambda表达式/bind创建对象/重载函数调用运算符的类
- 可能共享相同的**调用形式**: 如`int(int, int)`表示接受两个int返回一个int
    ```cpp
    int add(int i, int j) { return i + j; }
    auto mod = [] (int i, int j) { return i % j; }
    struct divide {
        int operator() (int i, int j) {
            return i / j;
        }
    }   //分别定义了加法/取模/除法
    ```
    - 对于相同调用形式的可调用对象, 可以定义一个**函数表**(function table)用于存储指向这些对象的"指针", 可以通过`map`实现:
    - `map<string, int(*) (int, int)> binops;` //这里只能直接存放函数指针add
- 标准库function类型
    - `function`的操作:
    - `function<T> f;` `function<T> f(obj);`// f存储可调用对象obj的副本
    - `f`//当f存储obj时为真, 为空时为假
    - `f(args)`// 调用f中的对象, 参数是args
    - `function<T>`的成员类型:
    - `result_type`, `argument_type`, `first_argument_type`, `second_argument_type`等
    - 创建具体的function类型: 
    - `function<int (int, int)> f2 = divide();`
    - 从而使`map`变为`map<string, function<int (int, int)>> binops;`
    - 对于重载过的函数不能直接放入function对象中, 因为无法通过名字来确定版本
        - 需要使用函数指针或lambda表达式来限定函数版本


---

### Cpt.15 **面向对象的程序设计**
#### OOP: 概述
- 继承
  - 派生类由基类通过继承得到, 基类定义在层次关系中的所有类共同拥有的成员
  - 对于需要派生类各自定义版本的函数需要被声明为**虚函数**
- 动态绑定(运行时绑定)
  - 实现类的多态, 使用基类的引用, 在运行时确定调用的函数版本
  - ..

#### 定义基类与派生类

##### 类型转换与继承
- 注意: 基类的指针或引用可以绑定在派生类上
- 静态类型与动态类型
  - 仅对于指针或引用, 会在运行时确定的为动态类型
- 不能从基类隐式转换为派生类