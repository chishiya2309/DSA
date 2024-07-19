/*
Cho một xâu kí tự S chỉ bao gồm các kí tự , hãy in ra các hoán vị của các kí tự khác nhau trong S theo thứ tự từ điển tăng dần.
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    set<char> se(s.begin(), s.end());
    string tmp = "";
    for(char c : se)
    {
        tmp += c;
    }
    do
    {
        cout << tmp << endl;
    }while(next_permutation(tmp.begin(), tmp.end()));
    return 0;
}