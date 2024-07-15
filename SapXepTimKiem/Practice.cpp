#include<bits/stdc++.h>

using namespace std;

signed main()
{
    int n;
    cin >> n;
    vector<int> a(n);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
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