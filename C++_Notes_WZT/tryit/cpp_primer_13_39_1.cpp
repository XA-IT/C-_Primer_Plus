// - 实现一个类似于`vector<string>`的类`StrVec`
//   - 主要数据成员: 
//     - elements, 分配的内存的首元素
//     - first_free
//     - cap, 指向分配内存末尾之后的位置
//     - 静态成员`alloc`: 一个`allocator<string>`
//   - 主要成员函数:
//     - `alloc_n_copy`: 分配内存并拷贝n个元素进去
//     - `free` 销毁构造的元素, 释放内存
//     - `chk_n_alloc`: 保证`StrVec`对象有至少一个新元素的空间, 否则reallocate分配新内存
//     - `reallocate`

#include "cpp primer 13_39_1.h"
class StrVec;

void StrVec::push_back()

StrVec::Strvec(const StrVec& ne) {

}