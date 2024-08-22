/*
Lập bảng chân trị của mệnh đề q -> (p -> q)
*/

#include<bits/stdc++.h>
using namespace std;

bool implication(bool p, bool q)
{
    return !p || q;
}

signed main()
{
    bool p, q;

    cout << "p\tq\tq -> (p -> q)" << endl;
    cout << "..................." << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;

            bool res = implication(q, implication(p, q));

            cout << p << "\t" << q << "\t" << res << endl;
        }
    }

    return 0;

}