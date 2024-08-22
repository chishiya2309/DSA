/*
Lập bảng chân trị của mệnh đề (p ^ q) V r -> p ^ (q V r)
*/

#include<bits/stdc++.h>
using namespace std;

bool implication(bool p, bool q)
{
    return !p || q;
}

signed main()
{
    bool p, q, r;

    cout << "p\tq\tr\t(p ^ q) V r -> p ^ (q V r)" << endl;
    cout << "..................................." << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;
            for(int k = 1; k >= 0; k--)
            {
                r = k;

                bool r1 = (p && q) || r;
                bool r2 = p && (q || r);

                bool res = implication(r1, r2);

                cout << p << "\t" << q << "\t" << r << "\t" << res << endl;
            }
        }
    }

    return 0;

}