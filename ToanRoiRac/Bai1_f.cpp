/*
Bảng chân trị của mệnh đề (p -> q) - > [(q -> r) -> (p -> r)]
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
    bool p, q, r;

    cout << "p\tq\tr\t(p -> q) - > [(q -> r) -> (p -> r)]" << endl;
    cout << "------------------------------------------------------------" << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;
            for(int k = 1; k >= 0; k--)
            {
                r = k;
                bool res = implication(implication(p, q), implication(implication(q, r), implication(p, r)));
                cout << p << "\t" << q << "\t" << r << "\t" << res << endl;
            }
        }
    }
}