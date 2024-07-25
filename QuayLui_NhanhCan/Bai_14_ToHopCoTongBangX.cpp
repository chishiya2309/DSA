/*
Cho mảng A[] gồm N số nguyên dương phân biệt và số X. Nhiệm vụ của bạn là tìm phép tổ hợp các số trong mảng A[] có tổng bằng X. Các số trong mảng A[] có thể được sử dụng nhiều lần. Mỗi tổ hợp các số của mảng A[] được in ra theo thứ tự không giảm các số.

Ví dụ với A[] = {2, 4, 6, 8}, X = 8 ta có các tổ hợp các số như sau: {2, 2, 2, 2}, {2, 2, 4}, {2, 6}, {4, 4}, {8}.

Đầu vào
Dòng thứ nhất là hai số N và X

Dòng tiếp theo đưa vào N số của mmảng A[]

Giới hạn
1<=N<=20

1<=X,A[i]<=100

Đầu ra
In ra số tổ hợp thỏa mãn sau đó in ra các tổ hợp thỏa mãn trên từng dòng. Xem output để rõ hơn cách in. Trong trường hợp không có tổ hợp thỏa mãn thì in ra -1.

Ví dụ :
Input 01
3 10
4 2 3
Output 01
5
{2 2 2 2 2}
{2 2 2 4}
{2 2 3 3}
{2 4 4}
{3 3 4}
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, s;
int a[21];
int x[21];
int cnt = 0;
vector<vector<int>> v;
void Try(int i, int index, int sum)
{
    for(int j = index; j <= n; j++)
    {
        x[i] = a[j];
        if(sum + x[i] == s)
        {
            cnt++;
            vector<int> tmp(x + 1, x + i + 1);
            v.push_back(tmp);
        }else if(sum + x[i] < s)
        {
            Try(i + 1, j, sum + x[i]);
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; i++)
    {
        cin >> a[i];
    }
    sort(a + 1, a + n + 1);
    Try(1, 1, 0);
    if(cnt)
    {
        cout << cnt << endl;
        for(int  i = 0; i < v.size(); i++)
        {
            cout << "{";
            for(int j = 0; j < v[i].size(); j++)
            {
                cout << v[i][j];
                if(j == v[i].size() - 1)
                {
                    cout << "}";
                }else {
                    cout << " ";
                }
            }
            cout << endl;
        }
    }else {
        cout << -1;
    }
    return 0;
}