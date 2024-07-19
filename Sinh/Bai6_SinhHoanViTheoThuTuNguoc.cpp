/*
Cho N số nguyên tự nhiên từ 1 tới N. Bạn là hãy liệt kê tất cả các hoán vị của các số trên nhưng theo thứ tự ngược.
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i=0; i<n; i++)
    {
        a[i] = i + 1;
    }
    vector<string> v;
    do
    {
        string s = "";
        for(int i = 0; i < n; i++)
        {
            s += a[i] + '0';
        }
        v.push_back(s);
    }while(next_permutation(a.begin(), a.end()));
    sort(v.begin(), v.end(), greater<string>());
    for(int i = 0; i < v.size(); i++)
    {
        cout << v[i] << endl;
    }
    return 0;
}