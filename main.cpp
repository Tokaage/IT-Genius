#include <iostream>
#include <fstream>
#include <string>
#include <vector>
#include <map>
using namespace std;
 
vector<string> get_words(const char *fileName) {
    ifstream in("text.txt");
    vector<string> dstu;
    if (in.is_open()) {
        char c = 0;
        while (in.get(c)) {
            string tu;
            while (('a' <= c && c <= 'z') || ('A' <= c && c <= 'Z')) {
                if ('A' <= c && c <= 'Z')
                    c = c - 'A' + 'a';
                tu.push_back(c); 
                in.get(c);
            }
            if (tu.size() > 0) {
                dstu.push_back(tu);
            }
        }
    }
    in.close();
    return dstu;
}
 
map<string, int> words_count(vector<string> dstu) {
    map<string, int> ds;
    for (string tu: dstu) {
        if (ds.size() == 0) {
            ds.insert({tu, 1});
        }
        else {               
            if (ds.contains(tu)) {
                ds[tu]++;
            } else {
                ds.insert({tu, 1});
            }
        }
    }
    return ds;
}
 
void word_count_to_file(map<string, int> ds) {
    ofstream out("Nikita.txt");
    for (const auto& [tu, soluong]: ds) {
        if (soluong > 1) {
            out << tu << " [" <<  soluong << "]" << endl;
        }
    }
    out.close();
}
 
int main()
{
    vector<string> dstu = get_words("text.txt");
 
    map<string, int> ds = words_count(dstu);
 
    word_count_to_file(ds);
 
    return 0;
}
