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
