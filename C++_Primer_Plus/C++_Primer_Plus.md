# C++_Primer_Plus

## Conventions Used in This Book
1. Computer typeface:  
Code lines, commands, statements, variables, filenamws, and program output appear
2. **Bold computer typeface:**  
**Progeam input**
3. *Italic computer typeface:*  
Placeholders in stytax descriptions appear in an *italic computer typeface*
new terms.
4. Sidebar: 旁注  
A sidebar provides a deeper discussion or additional background to help illuminate a topic.
5. Tip: 提示  
Tips present short, helpful guides to particular programming situations.
6. Caution: 警告  
A caution alerts you to potential pitfalls.
7. Note: 注意  
The notes provide a catch-all category for comments that don’t fall into one of the other categories.

## Chapter 1: Getting Started with C++
generic programming: 泛型编程  
buzzwords: 花里胡哨的词语   
the necessary vocabulary of cultivated discourse: 必不可少的术语  
system prompt: 系统提示符  
branching statements: 分支语句  

1. Class is a specification describing such a new data form, and an object is a par- ticular data structure constructed according to that plan.
2. In general, a class defines what data is used to represent an object and the operations that can be per- formed on that data.
3. The process of going from a lower level of organization, such as classes, to a higher level, such as program design, is called bottom-up programming.
4.  OOP facilitates creating reusable code, and that can eventually save a lot of work. Information hiding safeguards data from improper access. Polymorphism lets you create multiple definitions for operators and functions, with the programming context determining which definition is used. Inheritance lets you derive new classes from old ones.
5. Programming steps

```flow
st=>start: Source code
op1=>operation1: COMPILER
op2=>operation2: object code
op3=>operation3: LINKER
op4=>operation4: startup code
op5=>operation5: library code
e=>end: executable code
st->op1->op2->op3->e
op4->op3
op5->op3
```

6. Compile typically means compile the code in the file that is currently open.
7. Build or Make typically means compile the code for all the source code files in the project.This is often an incremental process.That is, if the project has three files, and you change just one, and then just that one is recompiled.
8. Build All typically means compile all the source code files from scratch.
9. As described earlier, Link means combine the compiled source code with the necessary library code.
10.  Run or Execute means run the program.Typically, if you have not yet done the earlier steps, Run does them before trying to run a program.
11. Debug means run the program with the option of going through step-by-step.
12. A compiler may offer the option of Debug and Release versions.The former contains extra code that increases the program size, slows program execution, but enables detailed debugging features.


compiler|extension 
:--:|:--:
C++ |Implementation Source Code Extension(s)  
Unix |C, cc, cxx, c
GNU |C++ C, cc, cxx, cpp, c++
Digital Mars| cpp, cxx  
Borland C++| cpp  
Watcom |cpp
Microsoft Visual C++| cpp, cxx, cc
Freestyle CodeWarrior| cpp, cp, cc, cxx, c++

## Chapter 2: Setting out to C++
case sensitive: 大小写敏感  
directive: 编译指令  
1. Never omit the semicolon
2. `int main()`: function header  
`main()`: function name  
`return 0;` : terminates function(return statement)
3. If the com- piler reaches the end of main() without encountering a return statement, the effect will be the same as if you ended main() with this statement:
`return 0;`
This implicit return is provided only for main() and not for any other function.
4. Header File Naming Conventions

Kind of Header|Convention|Example|Comments
:--:|:--:|:--:|:--:
C++ old style| Ends in .h| iostream.h| Usable by C++ programs
C old style| Ends in .h |math.h| Usable by C and C++ programs
C++ new style| No extension| iostream| Usable by C++ programs, uses namespace std
Converted C |c prefix, no extension|cmath| Usable by C++ programs, might use non-C features, such as namespace std

The contents of the iostream file to be sent along with the contents of your file to the compiler. In essence, the contents of the iostream file replace the `#include <iostream>` line in the program.  
5. The namespace facility lets a vendor package its wares in a unit called a namespace so that you can use the name of a namespace to indicate which vendor’s product you want.  
`Microflop::wanda("go dancing?"); // use Microflop namespace version`   
`Piscine::wanda("a fish named Desire"); // use Piscine namespace version`  
6. bitwise left-shift operator: 左换位符  
7. Overloading： The important point here is not the exact function of these operators but that the same symbol can have more than one meaning, with the compiler determining the proper meaning from the context.  
8. Starting a new line  
`cout << "\n"; // start a new line`   
`cout << endl; // start a new line`  
The newline character is one example of special keystroke combinations termed “escape sequences”(转义字符)
9. carriage return: 回车  
parentheses and commas：括号和逗号  
10. Use a declaration statement to indicate the type of storage and to provide a label for the location. This statement provides two kinds of information: the type of memory storage needed and a label to attach to that storage.  
11. The C++ style for declaring variables is to declare a variable as close to its first use as possible.
12. For output, the << operator inserts characters into the output stream. For input, cin uses the >> operator to extract characters from the input stream.Typically, you provide a variable to the right of the operator to receive the extracted information. (The symbols << and >> were chosen to visually suggest the direc- tion in which information flows.)
13. A class is a data type the user defines. To define a class, you describe what sort of infor- mation it can represent and what sort of actions you can perform with that data. The class describes all the properties of a data type, including actions that can be per- formed with it, and an object is an entity created according to that description.
14. argument: 参数  
In short, an argument is information sent to the func- tion, and the return value is a value sent back from the function.
15. If you get such a complaint on a Unix implementation, for example, it may require that you use the -lm option (for library math) at the end of the com- mand line:
`CC sqrt.C -lm`
Some versions of the Gnu compiler under Linux behave similarly:
`g++ sqrt.C –lm`
16. Function Form
```
type functionname(argumentlist) 
{
    statements  
}
```
17. Keywords are the vocabulary of a computer language. This chapter has used four C++ key- words: int, void, return, and double. Because these keywords are special to C++, you can’t use them for other purposes.
18. you can place the following above the function definitions in a file, making all the contents of the std namespace available to every function in the file:
`using namespace std;`
19. You can place the following in a specific function definition, making all the con- tents of the std namespace available to that specific function:
`using namespace std;`
20. Instead of using
`using namespace std;`
you can place using declarations like the following in a specific function definition and make a particular element, such as cout, available to that function:
`using std::cout;`
21. You can omit the using directives and declarations entirely and use the std:: prefix whenever you use elements from the std namespace:
`std::cout << "I’m using cout and endl from the std namespace" << std::endl;`

### Chapter Review
You can find the answers to the chapter review at the end of each chapter in Appendix J, “Answers to Chapter Review.”
1. What are the modules of C++ programs called?
2. What does the following preprocessor directive do?
#include <iostream>
3. What does the following statement do?
using namespace std;
4. What statement would you use to print the phrase “Hello, world” and then start a new line?
5. What statement would you use to create an integer variable with the name cheeses?
6. What statement would you use to assign the value 32 to the variable cheeses?
7. What statement would you use to read a value from keyboard input into the vari-
able cheeses?
8. What statement would you use to print “We have X varieties of cheese,” where the
current value of the cheeses variable replaces X?
9. What do the following function prototypes tell you about the functions?
int froop(double t); void rattle(int n); int prune(void);
10. When do you not have to use the keyword return when you define a function?
11. Suppose your main() function has the following line:
cout << “Please enter your PIN: “;
And suppose the compiler complains that cout is an unknown identifier.What is
the likely cause of this complaint, and what are three ways to fix the problem?

### Answers to Chapter Review for Chapter 2
1. They are called functions.
2. It causes the contents of the iostream file to be substituted for this directive before final compilation.
3. It makes definitions made in the std namespace available to a program.
4. cout << "Hello, world\n";
or
cout << "Hello, world" << endl;
5. int cheeses;
6. cheeses = 32;
7. cin >> cheeses;
8. cout << "We have " << cheeses << " varieties of cheese\n";
9. The function froop() expects to be called with one argument, which will be type double, and that the function will return a type int value. For instance, it could be used as follows:
int gval = froop(3.14159);
The function rattle() has no return value and expects an int argument. For instance, it could be used as follows:
rattle(37);
                                        1336 Appendix J Answers to Chapter Reviews
The function prune() returns an int and expects to be used without an argument. For instance, it could be used as follows:
int residue = prune();
10. You don’t have to use return in a function when the function has the return type void. However, you can use it if you don’t give a return value:
return;

## Chapter 3: Dealing with Data
1. The essence of object-oriented programming (OOP) is designing and extending your own data types. Designing your own data types represents an effort to make a type match the data.
2. To store an item of information in a computer, the program must keep track of three funda- mental properties:
- Where the information is stored   
- What value is kept there   
- What kind of information is stored  
3. simple C++ naming rules:
- The only characters you can use in names are alphabetic characters, numeric digits, and the underscore (_) character.
- The first character in a name cannot be a numeric digit.
- Uppercase characters are considered distinct from lowercase characters.
- You can’t use a C++ keyword for a name.
- Names beginning with two underscore characters or with an underscore character followed by an uppercase letter are reserved for use by the implementation—that is, the compiler and the resources it uses. Names beginning with a single underscore character are reserved for use as global identifiers by the implementation.
- C++ places no limits on the length of a name, and all characters in a name are sig- nificant. However, some platforms might have their own length limits.
4. hyphen: 连字符号
- A short integer is at least 16 bits wide.
- An int integer is at least as big as short.
- A long integer is at least 32 bits wide and at least as big as int.
- A long long integer is at least 64 bits wide and at least as big as long.
5. Think of a bit as an electronic switch that you can set to either off or on. Off represents the value 0, and on represents the value 1. A byte usually means an 8-bit unit of memory.
6. int is 4 bytes. short is 2 bytes. long is 4 bytes. long long is 8 bytes.  
Maximum values:  
int: 2147483647  
short: 32767  
long: 2147483647  
long long: 9223372036854775807  
Minimum int value = -2147483648 Bits per byte = 8
7. Symbolic Constants from climits

**Symbolic Constant**|**Represents**
:--:|:--:
CHAR_BIT |Number of bits in a char
CHAR_MAX |Maximum char value
CHAR_MIN |Minimum char value
SCHAR_MAX |Maximum signed char value
SCHAR_MIN |Minimum signed char value
UCHAR_MAX |Maximum unsigned char value
SHRT_MAX |Maximum short value
SHRT_MIN |Minimum short value
USHRT_MAX |Maximum unsigned short value
INT_MAX |Maximum int value
INT_MIN |Minimum int value
UINT_MAX |Maximum unsigned int value
LONG_MAX |Maximum long value
LONG_MIN |Minimum long value
ULONG_MAX |Maximum unsigned long value
LLONG_MAX |Maximum long long value
LLONG_MIN |Minimum long long value
ULLONG_MAX |Maximum unsigned long long value
8.The initialization syntax shown previously comes from C; C++ has an initialization syntax that is not shared with C:  
`int owls = 101; // traditional C initialization, sets owls to 101 int` `wrens(432); // alternative C++ syntax, set wrens to 432`
9. There’s another format for initialization that’s used with arrays and structures but in C++98 can also be used with single-valued variables:  
`int hamburgers = {24}; // set hamburgers to 24`
10. Using a braced initializer for a single-valued variable hasn’t been particularly common, but the C++11 standard is extending it some ways. First, it can be used with or without the = sign:  
`int emus{7}; // set emus to 5`
`int rheas = {12}; // set rheas to 12`  
Second, the braces can be left empty, in which case the variable is initialized to 0:  
`int rocs = {}; // set rocs to 0`
`int psychics{}; // set psychics to 0`
11. use unsigned types only for quantities that are never negative.
```
unsigned short change; // unsigned short type
unsigned int rovert; // unsigned int type
unsigned quarterback; // also unsigned int
unsigned long gone; // unsigned long type
unsigned long long lang_lang; // unsigned long long type
```
     Note that unsigned by itself is short for unsigned int.
12. decimal: 十进制  
octal：八进制  
hex：十六进制  
13. uses hex and oct to display the decimal value 42 in three formats.
``` 
cout << "Monsieur cuts a striking figure!" << endl;
cout << "chest = " << chest << " (decimal for 42)" << endl; cout << hex; // manipulator for changing number base
cout << "waist = " << waist << " (hexadecimal for 42)" << endl; 
cout << oct; // manipulator for changing number base
Monsieur cuts a striking figure! chest = 42 (decimal for 42) 
waist = 2a (hexadecimal for 42) 
inseam = 52 (octal for 42)
```
14. The answer is that C++ stores integer constants as type int unless there is a reason to do oth- erwise. Two such reasons are if you use a special suffix to indicate a particular type or if a value is too large to be an int.
15. These are letters placed at the end of a numeric constant to indicate the type. An l or L suffix on an integer means the integer is a type long constant, a u or U suffix indicates an unsigned int constant, and ul (in any combination of orders and uppercase and lowercase) indicates a type unsigned long constant. (Because a lower- case l can look much like the digit 1, you should use the uppercase L for suffixes.) For example, on a system using a 16-bit int and a 32-bit long, the number 22022 is stored in 16 bits as an int, and the number 22022L is stored in 32 bits as a long. Similarly, 22022LU and 22022UL are unsigned long. C++11 provides the ll and LL suffixes for type long long, and ull, Ull, uLL, and ULL for unsigned long long.
16. A decimal integer without a suffix is represented by the smallest of the following types that can hold it:int, long, or long long. On a computer system using a 16-bit int and a 32-bit long, 20000 is represented as type int, 40000 is represented as long, and 3000000000 is represented as long long.A hexadecimal or octal integer without a suffix is represented by the smallest of the following types that can hold it:int,unsigned int,long,unsigned long,long long, or unsigned long long.The same computer system that represents 40000 as long represents the hexadecimal equivalent 0x9C40 as an unsigned int.That’s because hexa- decimal is frequently used to express memory addresses, which intrinsically are unsigned. So unsigned int is more appropriate than long for a 16-bit address.
17. C++ uses single quotation marks for a character and double quotation marks for a string.
18. the program introduces a cout feature, the cout.put() function, which displays a single character.
19. A member function belongs to a class and describes a method for manipulating class data. To use a class member function with an object such as cout, you use a period to combine the object name (cout) with the function name (put()). The period is called the membership operator.The notation cout.put() means to use the class member function put() with the class object cout.
20. C++ Escape Sequence Codes 转义序列编码

Character Name|ASCII Symbol|C++ Code|ASCII Decimal Code|ASCII Hex Code
:--:|:--:|:--:|:--:|:--:
Newline| NL (LF)| \n |10 |0xA
Horizontal tab| HT| \t |9| 0x9
Vertical tab| VT| \v |11| 0xB
Backspace |BS| \b |8 |0x8
Carriage return| CR| \r |13| 0xD
Alert| BEL| \a |7 |0x7
Backslash| \ | \\\ |92 |0x5C
Question mark| ?| \\? |63 |0x3F
Single quote| ’| \\' |39 |0x27
Double quote| ”| \\" |34| 0x22

21. Note that you treat an escape sequence, such as \n, just as a regular character, such as Q. That is, you enclose it in single quotes to create a character constant and don’t use single quotes when including it as part of a string.
22. sing universal character names is similar to using escape sequences.A universal char- acter name begins either with \u or \U.The \u form is followed by 8 hexadecimal digits, and the \U form by 16 hexadecimal digits.
23. These distinctions are particularly important if you use char as a numeric type.The unsigned char type typically represents the range 0 to 255, and signed char typically represents the range –128 to 127.
```
char fodo; // may be signed, may be unsigned
unsigned char bar; // definitely unsigned
signed char snark; // definitely signed
```
24. The iostream header file provides parallel facilities in the form of wcin and wcout for handling wchar_t streams.
```
wchar_t bob = L'P'; // a wide-character constant
wcout << L"tall" << endl; // outputting a wide-character string
```
On a system with a 2-byte wchar_t, this code stores each character in a 2-byte unit of memory.
25. C++11 introduces the types char16_t, which is unsigned and 16 bits, and char32_t, which is unsigned and 32 bits. C++11 uses the u prefix for char16_t character and string constants, as in u'C' and u"be good". Similarly, it uses the U prefix for char32_t constants, as in U'R' and U"dirty rat".
26. The literals true and false can be converted to type int by promotion, with true converting to 1 and false to 0:
`int ans = true; // ans assigned 1`
`int promise = false; // promise assigned 0`
Also any numeric or pointer value can be converted implicitly (that is, without an explicit type cast) to a bool value. Any nonzero value converts to true, whereas a zero value converts to false:
`bool start = -100; // start assigned true `
`bool stop = 0; // stop assigned false`
27. The keyword const is termed a qualifier because it qualifies the meaning of a declaration. A common practice is to capitalize the first character in a name to help remind your- self that Months is a constant.
28. You can represent the second as 0.341245 (the same base value) and 100,000 (a bigger scaling factor).The scaling factor serves to move the decimal point, hence the term floating-point. C++ uses a similar method to represent floating-point numbers internally, except it’s based on binary numbers, so the scaling is by factors of 2 instead of by factors of 10.
29. The form d.dddE+n means move the decimal point n places to the right, and the form d.dddE-n means move the decimal point n places to the left. This moveable decimal point is the origin of the term “floating-point.”
30. Significant figures are the meaningful digits in a number. In effect, the C and C++ requirements for significant digits amount to float being at least 32 bits, double being at least 48 bits and certainly no smaller than float, and long double being at least as big as double.All three can be the same size.Typically, however, float is 32 bits, double is 64 bits, and long double is 80, 96, or 128 bits. Also the range in exponents for all three types is at least –37 to +37.
31. When you write a floating-point constant in a program, in which floating-point type does the program store it? By default, floating-point constants such as 8.24 and 2.4E8 are type double. If you want a constant to be type float, you use an f or F suffix. For type long double, you use an l or L suffix. (Because the lowercase l looks a lot like the digit 1, the uppercase L is a better choice.) Here are some samples:
`1.234f // a float constant `
`2.45E20F // a float constant`
`2.345324E28 // a double constant`
`2.2L // a long double constant`
32. C++ brings some order to its basic types by classifying them into families. Types signed char, short, int, and long are termed signed integer types. C++11 adds long long to that list. The unsigned versions are termed unsigned integer types. The bool, char, wchar_t, signed integer, and unsigned integer types together are termed integral types or integer types. C++11 adds char16_t and char32_t to that list. The float, double, and long double types are termed floating-point types. Integer and floating-point types are col- lectively termed arithmetic types.
33. C++’s five basic arithmetic operators:
- The + operator adds its operands. For example, 4 + 20 evaluates to 24.
- The - operator subtracts the second operand from the first. For example, 12 - 3 evaluates to 9.
- The * operator multiplies its operands. For example, 28 * 4 evaluates to 112.
- The / operator divides its first operand by the second. For example, 1000 / 5 eval- uates to 200. If both operands are integers, the result is the integer portion of the quotient. For example, 17 / 3 is 5, with the fractional part discarded.
- The % operator finds the modulus of its first operand with respect to the second. That is, it produces the remainder of dividing the first by the second. For example, 19 % 6 is 1 because 6 goes into 19 three times, with a remainder of 1. Both operands must be integer types; using the % operator with floating-point values causes a compile-time error. If one of the operands is negative, the sign of the result satisfies the following rule: (a/b)*b + a%b equals a.
34. When two operators have the same precedence, C++ looks at whether the operators have a left-to-right associativity or a right-to-left associativity.
35.  If both operands are integers, C++ performs integer division.That means any fractional part of the answer is discarded, mak- ing the result an integer. If one or both operands are floating-point values, the fractional part is kept, making the result floating-point.
36. Type Conversions:
- C++ converts values when you assign a value of one arithmetic type to a variable of another arithmetic type.
- C++ converts values when you combine mixed types in expressions. 
- C++ converts values when you pass arguments to functions.
37. Potential Numeric Conversion Problems

Conversion Type|potential Problems
:--:|:--:
Bigger floating-point type to smaller floating-point type, such as double to float|Loss of precision (significant figures); value might be out of range for target type, in which case result is undefined.
Floating-point type to integer type | Loss of fractional part; original value might be out of range for target type, in which case result is undefined.
Bigger integer type to smaller integer type, such as long to short|Original value might be out of range for target type; typically just the low-order bytes are copied.
38. The int type is generally chosen to be the computer’s
most natural type, which means the computer probably does calculations fastest for that type.
39. Here’s the C++11 version of the list, which the compiler goes through in order:
    1. If either operand is type long double, the other operand is converted to long double.
    2. Otherwise, if either operand is double, the other operand is converted to double.
    3. Otherwise, if either operand is float, the other operand is converted to float.
    4. Otherwise, the operands are integer types and the integral promotions are made.
    5. In that case, if both operands are signed or if both are unsigned, and one is of lower rank than the other, it is converted to the higher rank.
    6. Otherwise, one operand is signed and one is unsigned. If the unsigned operand is of higher rank than the signed operand, the latter is converted to the type of the unsigned operand.
    7. Otherwise, if the signed type can represent all values of the unsigned type, the unsigned operand is converted to the type of the signed type.
    8. Otherwise, both operands are converted to the unsigned version of the signed type.
40. This list introduces the concept of ranking the integer types. In brief, as you might expect, the basic ranking for signed integer types from high to low is long long, long, int, short, and signed char. Unsigned types have the same rank as the corresponding signed type.The three types char,signed char, and unsigned char all have the same rank.The bool type has the lowest rank.The wchar_t,char16_t, and char32_t have the same types as their underlying types.
