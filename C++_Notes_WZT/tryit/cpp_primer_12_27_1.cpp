// 简答的文本查询程序
// 按行输出所查询单词所在的行数, 每行只输出一次
// 需要预先将文本分割并记录所有单词的情况, 查询时直接输出
#include "stdafx.h"
class QueryResult;      // 需要预先声明
// 用于保存输入的文本, 制作索引
class TextQuery {
public:
    // using size_t = vector<string>::size_t;
    QueryResult query(const string& sought) const;
    TextQuery(ifstream & infile);
private:
    // 使用vector存储文本, map关联每个单词和它出现行号的set
    // 为了查询类可以访问文本内容, 需要一个shared_ptr
    //vector<string> text; // 在构造函数中分配动态内存
    shared_ptr<vector<string>> file;
    map<string, shared_ptr<set<size_t>> > wm;
};

// 用于查询用户输入的单词, 输出次数, 行号以及每行的文本
class QueryResult {
    //print函数需要访问数据成员, 但它并不是类的成员函数
friend std::ostream& print(std::ostream&, const QueryResult&);
public:
    QueryResult(string s, shared_ptr<set<size_t>> p, 
                shared_ptr<vector<string>> f): 
                sought(s), lines(p), file(f) {  }
private:
    string sought;
    shared_ptr<set<size_t>> lines;
    shared_ptr<vector<string>> file;
};

TextQuery::TextQuery(ifstream &infile): file(new vector<string>)
{
    string str;
    while (getline(infile, str)) {
        file->push_back(str);
        // n为行号
        int n = file->size() - 1;
        istringstream line(str);
        string word;
        while (line >> word) {
            // 找到word对应的shared_ptr, 没有则创建
            auto &lines = wm[word];
            if (!lines)
                lines.reset(new set<size_t>);
            lines->insert(n);    // 插入n
        }
    }
}

string make_plural(size_t ctr, const string &word, const string &ending)
{
    return (ctr > 1)? word + ending : word;
}

QueryResult TextQuery::query(const string & sought) const
{
    // 未找到s所在的set时返回一个空的set, 这个set的指针在此定义:
    static shared_ptr<set<size_t>> nodata(new set<size_t>);
    auto posi = wm.find(sought);
    if (posi == wm.end())
        return QueryResult(sought, nodata, file);
    else 
        return QueryResult(sought, posi->second, file);
}

ostream& print(ostream& os, const QueryResult &qr) 
{
    os << qr.sought << " occurs " << qr.lines->size() << " "
       << make_plural(qr.lines->size(), "time", "s") << endl;
    
    for (auto num : *qr.lines) {
        os << "\t(line " << num + 1 << ")"
           << *(qr.file->begin() + num) << endl;
    }
    return os;
}
// 使用TextQuery类的场景:
void runQueries(ifstream &infile)
{
    TextQuery tq(infile);

    // 与用户交互的部分:
    while (true) {
        cout << "enter word to look for, or q to quit: " << endl;
        string s;
        if (!(cin >> s) || s == "q") break;
        // 使用查询输出结果
        print(cout, tq.query(s)) << endl;
    }
}

int main() {
    ifstream ff("d:\\Programing\\CPP coding2\\WZT\\LC23 Merge k Sorted Lists.cpp");
    runQueries(ff);
    ff.close();
    return 0;
}