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

#include "cpp_primer_13_39_1.h"

void StrVec::push_back(const string & s) {
	chk_n_alloc();
	// 构造一个s在对象中, 递增first_free
	alloc.construct(first_free++, s);
}

pair<string*, string*> 
StrVec::alloc_n_copy(const string *b, const string *e) {
	auto data = alloc.allocate(e - b);		// 指向新分配内存的首地址
	// 在返回语句中进行拷贝填充
	return { data, uninitialized_copy(b, e, data) };
}

void StrVec::free() {
	if (elements) {
		// 销毁元素, 逆序
		for (auto p = first_free; p != elements; ) {
			alloc.destroy(--p);
		}
		alloc.deallocate(elements, cap - elements);
	}
}

StrVec::StrVec(const StrVec& s) {
	auto newdata = alloc_n_copy(s.begin(), s.end());
	elements = newdata.first;
	first_free = cap = newdata.second;
}

StrVec::~StrVec() {
	free();
}

StrVec& StrVec::operator=(const StrVec& rhs) {
	auto data = alloc_n_copy(rhs.begin(), rhs.end());
	free();
	elements = data.first;
	first_free = cap = data.second;
	return *this;
}

void StrVec::reallocate() {
	auto newcapacity = size() ? 2 * size() : 1;
	alloc_n_move(newcapacity);
}

void StrVec::alloc_n_move(size_t newcapacity) {
	// 分配新内存
	auto newdata = alloc.allocate(newcapacity);
	// 转移数据, 使用std::move(), 构造后的元素对象从elem指向的
	// string处接管内存的所有权
	auto dest = newdata;
	auto elem = elements;
	for (size_t i = 0; i < size(); ++i) {
		alloc.construct(dest++, std::move(*elem++));
	}
	free();
	// 更新数据成员
	elements = newdata;
	first_free = dest;
	cap = elements + newcapacity;
}

void StrVec::reserve(size_t count) {
	if (count < capacity()) return;
	alloc_n_move(count);
}

void StrVec::resize(int count, const string& s = "") {
	if (count > size()) {
		if (count > capacity()) reserve(count * 2);
		for (size_t i = size(); i < count; ++i) {
			alloc.construct(first_free++, s);
		}
	}
	else if (count < size()) {
		while (first_free != elements + count) {
			alloc.destroy(--first_free);
		}
		// 以下不是resize的目的..搞错了
		//alloc.deallocate(first_free, cap - first_free);
		//cap = first_free;
	}
}