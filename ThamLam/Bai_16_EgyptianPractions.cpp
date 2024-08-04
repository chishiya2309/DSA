/*
Một phân số đơn vị nếu tử số của phân số đó là 1. Mọi phân số nguyên dương đều có thể biểu diễn thành tổng các phân số đơn vị. Ví dụ 2/3 = 1/2 + 1/6. Cho phân số nguyên dương P/Q , hãy biểu diễn phân số nguyên dương thành tổng phân số đơn vị với số hạng tử là ít nhất.

Đầu vào
1 dòng duy nhất chứa 2 số P, Q

Giới hạn
1<=P,Q<=400

Đầu ra
Đưa ra đáp án trên 1 dòng

Ví dụ :
Input 01
5 6
Output 01
1/2 + 1/3
*/

#include <bits/stdc++.h>

using namespace std;
int gcd(int a, int b)
{
    if(b == 0)
    {
        return a;
    }else {
        return gcd(b, a % b);
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int p, q;
    cin >> p >> q;
    vector<pair<int, int>> result;
    while(p != 0)
    {
        //Ước số nguyên tố nhỏ nhất mà phân số đơn vị nhỏ hơn hoặc bằng P/Q
        int x = (q + p - 1) / p;    //ceil(Q/P)

        result.push_back({1, x});

        p = p * x - q;
        q = q * x;

        int g = gcd(p, q);
        p /= g;
        q /= g;
    }

    for(auto it = 0; it < result.size(); it++)
    {
        if(it != 0)
        {
            cout << " + ";
        }
        cout << result[it].first << "/" << result[it].second;
    }
    return 0;
}