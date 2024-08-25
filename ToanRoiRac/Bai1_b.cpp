/*
Bảng chân trị của mệnh đề (p ^ q) -> (p v q)
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

    cout << "p\tq\t(p ^ q) -> (p v q)" << endl;
    cout << "--------------------------------" << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;
            bool p_or_q = p || q;
            bool p_and_q = p && q;

            bool res = implication(p_and_q, p_or_q);
            cout << p << "\t" << q << "\t" << res << endl;
        }
    }
}