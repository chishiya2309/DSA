/*
Bảng chân trị của mệnh đề p -> (p -> p)
*/

#include<bits/stdc++.h>
#define endl '\n'
using namespace std;

bool implication(bool p, bool q)
{
    return !p || q;
}

signed main()
{
    bool p;

    cout << "p\tq\tp -> (p -> p)" << endl;
    cout << "--------------------------------" << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        bool res = implication(p, implication(p, p));
        cout << p << "\t" << res << endl;
    }
}