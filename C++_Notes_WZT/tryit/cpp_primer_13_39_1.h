#pragma once
#include "stdafx.h"

class StrVec {
public:
    StrVec(): elements(nullptr), first_free(nullptr),
              cap(nullptr) { }
    StrVec(const StrVec&);
    StrVec& operator= (const StrVec&);
    ~StrVec();

    void push_back(const string&);
    size_t size() const { return first_free - elements; }
	size_t capacity() const { return cap - elements; }
	string* begin() const { return elements; }
	string* end() const { return first_free; }
	void reserve(size_t);
	void resize(int, const string&);
private:
    string* elements;		// 分配的内存的首地址
    string* first_free;		// 最后一个元素之后的地址
    string* cap;			// 分配内存的尾后地址
    static allocator<string> alloc;

	// 检查StrVec对象是否有容纳一个新元素的空间, 
	// 没有则reallocate
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
	// 分配内存, 并拷贝目标元素
    pair<string*, string*> alloc_n_copy(const string*, 
                                        const string*);
    void free();
    void reallocate();
	// 重新分配空间为n
	void alloc_n_move(size_t newcapacity);
};