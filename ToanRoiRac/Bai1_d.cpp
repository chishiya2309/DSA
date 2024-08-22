/*
Bảng chân trị của mệnh đề p -> (p -> q)
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
    bool p, q;

    cout << "p\tq\tp -> (!q -> p)" << endl;
    cout << "--------------------------------" << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;

            bool res = implication(p, implication(p, q));
            cout << p << "\t" << q << "\t" << res << endl;
        }
    }
}