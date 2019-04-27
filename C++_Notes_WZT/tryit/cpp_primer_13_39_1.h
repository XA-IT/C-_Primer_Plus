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
    string* elements;		// ������ڴ���׵�ַ
    string* first_free;		// ���һ��Ԫ��֮��ĵ�ַ
    string* cap;			// �����ڴ��β���ַ
    static allocator<string> alloc;

	// ���StrVec�����Ƿ�������һ����Ԫ�صĿռ�, 
	// û����reallocate
    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
	// �����ڴ�, ������Ŀ��Ԫ��
    pair<string*, string*> alloc_n_copy(const string*, 
                                        const string*);
    void free();
    void reallocate();
	// ���·���ռ�Ϊn
	void alloc_n_move(size_t newcapacity);
};