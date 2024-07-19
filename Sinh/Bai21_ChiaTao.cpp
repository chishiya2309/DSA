/*
Có n quả táo với khối lượng đã biết. Nhiệm vụ của bạn là chia táo thành hai nhóm sao cho sự khác biệt giữa trọng lượng của 2 nhóm là nhỏ nhất.

Đầu vào
Dòng 1 là số nguyên dương N : số lượng quả táo.

Dòng thứ 2 là N số nguyên p1,p2,...,pn là trọng lượng tương ứng của các quả táo.

Giới hạn
1<=N<=20

1<=pi<=10^9

Đầu ra
In ra độ chênh lệch nhỏ nhất giữa 2 nhóm táo.

Ví dụ :
Input 01
5
3 2 7 4 1
Output 01
1
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n, x[21];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= n; i++)
    {
        x[i] = 0;
    }
}

void sinh()
{
    int i = n;
    while(i >= 1 && x[i] == 1)
    {
        x[i] = 0;
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i] = 1;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    vector<int> p(n + 1);
    for(int i = 1; i <= n; i++)
    {
        cin >> p[i];
    }
    khoitao();
    ll dif = 1e18;
    while(!final)
    {
        ll sum0 = 0, sum1 = 0;
        for(int i = 1; i <= n; i++)
        {
            if(x[i] == 0)
            {
                sum0 += p[i];
            }else {
                sum1 += p[i];
            }
        }
        dif = min(dif, abs(sum1 - sum0));
        sinh();
    }
    cout << dif;
    return 0;
}