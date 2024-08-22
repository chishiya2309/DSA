/*
Lập bảng chân trị của mệnh đề !(p -> q) -> p
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

    cout << "p\tq\t!(p -> q) -> p" << endl;
    cout << "..................." << endl;

    for(int i = 1; i >= 0; i--)
    {
        p = i;
        for(int j = 1; j >= 0; j--)
        {
            q = j;

            bool res = implication(!implication(p, q), p);

            cout << p << "\t" << q << "\t" << res << endl;
        }
    }

    return 0;

}