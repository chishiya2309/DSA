/*
Cho ma trận kề A[][] của đồ thị vô hướng G = <V, E> chỉ bao gồm các số 0 hoặc 1.

Hãy chuyển đổi đồ thị này thành danh sách cạnh và danh sách kề tương ứng.

Đầu vào
Dòng đầu tiên là n tương ứng với số lượng đỉnh của đồ thị.

n dòng tiếp theo mỗi dòng gồm n số mô tả ma trận A

Giới hạn
1<=n<=1000

Đầu ra
Những dòng đầu tiên liệt kê danh sách cạnh theo thứ tự từ điển tăng dần, mỗi cạnh chỉ liệt kê một lần.

Sau đó cách ra 1 dòng và liệt kê danh sách kề, trong đó các đỉnh trong danh sách kề được in ra theo thứ tự tăng dần. Xem output mẫu để rõ hơn.

Ví dụ :
Input 01
Copy
5
0 1 1 1 0 
1 0 0 1 1 
1 0 0 1 1 
1 1 1 0 1 
0 1 1 1 0
Output 01
Copy
2 1
3 1
4 1
4 2
4 3
5 2
5 3
5 4

1 : 2 3 4 
2 : 1 4 5 
3 : 1 4 5 
4 : 1 2 3 5 
5 : 2 3 4
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n;
vector<int> ke[1003];
vector<pair<int, int>> res;
int a[1003][1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> a[i][j];
        }
    }

    for(int i = n; i >= 1; i--)
    {
        for(int j = n; j >= 1; j--)
        {
            if(a[i][j] != 0)
            {
                res.push_back({i, j});
                a[j][i] = 0;
                ke[i].push_back(j);
                ke[j].push_back(i);
            }
        }
    }

    sort(res.begin(), res.end());
    for(auto r : res)
    {
        cout << r.first << " " << r.second << endl;
    }

    cout << endl;
    for(int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
    }
    for(int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for(int j : ke[i])
        {
            cout << j << " ";
        }
        cout << endl;
    }

    return 0;
}