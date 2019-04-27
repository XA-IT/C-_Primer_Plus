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
    size_t size() { return first_free - elements; }

    
private:
    string* elements;
    string* first_place;
    string* cap;    
    static allocator<string> alloc;

    void chk_n_alloc()
        { if (size() == capacity()) reallocate(); }
    pair<string*, string*> alloc_n_copy(const string*, 
                                        const string*);
    void free();
    void reallocate();
};