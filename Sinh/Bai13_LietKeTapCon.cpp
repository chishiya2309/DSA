/*
Cho một tập gồm N phần tử được đánh số từ 1 đến N. Nhiệm vụ của bạn là liệt kê tất cả các tập con khác rỗng của N theo thứ tự từ điển tăng dần.

Đầu vào
Dòng duy nhất chứa số nguyên dương N.

Giới hạn
1<=N<=9

Đầu ra
In ra các tập con của N theo thứ tự từ điển tăng dần.

Ví dụ :
Input 01
4
Output 01
1 
1 2 
1 2 3 
1 2 3 4 
1 2 4 
1 3 
1 3 4 
1 4 
2 
2 3 
2 3 4 
2 4 
3 
3 4 
4
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n, x[10];
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
    khoitao();
    vector<vector<int>> v;
    while(!final)
    {
        vector<int> tmp;
        for(int i = 1; i <= n; i++)
        {
            if(x[i] == 1)
            {
                tmp.push_back(i);
            }
        }
        v.push_back(tmp);
        sinh();
    }
    sort(v.begin(), v.end());
    for(int i = 0; i < v.size(); i++)
    {
        for(int j = 0; j < v[i].size(); j++)
        {
            cout << v[i][j] << " ";
        }
        cout << endl;
    }
    return 0;
}