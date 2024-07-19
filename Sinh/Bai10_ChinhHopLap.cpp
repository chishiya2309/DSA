/*
Cho 2 số nguyên dương N và K. Nhiệm vụ của bạn là sinh ra chỉnh hợp lặp chập K của N phần tử gồm các số tự nhiên từ 1 đến N.

Ví dụ N = 3, K = 2 bạn sẽ có các kết quả là : 11, 12, 13, 21, 22, 23, 31, 32, 33. Số chỉnh hợp lặp chập K của N sẽ là N^K.
*/

#include <bits/stdc++.h>

using namespace std;
int n, k, x[10];
bool final = false;
void khoitao()
{
    for(int i = 1; i <= k; i++)
    {
        x[i] = 1;
    }
}
void sinh()
{
    int i = k;
    while(i >= 1 && x[i] == n)
    {
        i--;
    }
    if(i == 0)
    {
        final = true;
    }else {
        x[i]++;
        for(int j = i + 1; j <= k; j++)
        {
            x[j] = 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k;
    khoitao();
    while(!final)
    {
        for(int i = 1; i <= k; i++)
        {
            cout << x[i];
        }
        cout << endl;
        sinh();
    }
    return 0;
}