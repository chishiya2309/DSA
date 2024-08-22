/*
Lập bảng chân trị (p -> q) ^ r
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

    cout << "p\tq\tr\t(p -> q) ^ r" << endl;
    cout << "-----------------------------" << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;
            for(int k = 1; k >= 0; k--)
            {
                r = k;

                bool result = implication(p, q) && r;

                cout << p << "\t" << q << "\t" << r << "\t" << result << endl;
            }
        }
        
    }

    return 0;

}