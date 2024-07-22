/*
Ta có một bài toán như sau:

Cho một dãy số gồm n số nguyên dương ai (n≤106,  ai≤109). Với mỗi vị trí i, hãy in ra vị trí j gần nhất về phía bên trái thoả mãn ai < aj. Nếu như không có phần tử nào thoả mãn in ra -1.

Ví dụ:

Input	
7
2 1 3 2 8 5 7
Output
-1 1 -1 3 -1 5 5
*/

#include<bits/stdc++.h>
using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }
    stack<int> s;
    for(int i = 0; i < n; i++)
    {
        while(!s.empty() && a[s.top()] < a[i])
        {
            s.pop();
        }
        if(!s.empty())
        {
            cout << s.top() + 1 << " ";
        }else {
            cout << -1 << " ";
        }
        s.push(i);
    }
}