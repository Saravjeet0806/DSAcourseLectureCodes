#include <iostream>
#include <unordered_map>
#include <map>
using namespace std;
int main()
{
    // creation
    unordered_map<string, int> m;
    // insert 1
    pair<string, int> p = make_pair("Sarav", 1);
    m.insert(p);
    // insert 2
    pair<string, int> pair2("jeet", 2);
    m.insert(pair2);
    // insert3
    m["Singh"] = 3;
    cout << m["Singh"] << endl;
    cout<<m.size()<<endl;
    return 0;
}