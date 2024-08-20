/*
Cho đồ thị vô hướng G = (V, E) được biểu diễn dưới dạng danh sách cạnh.

Có Q truy vấn, mỗi truy vấn yêu cầu trả lời câu hỏi giữa 2 đỉnh s và t có tồn tại đường đi tới nhau hay không ?

Đầu vào
Dòng đầu tiên là 2 số n, m, tương ứng với số lượng đỉnh, cạnh của đồ thị.

Các đỉnh của đồ thị được đánh số từ 1 tới n. m dòng tiếp theo mỗi dòng chứa đỉnh u, v (u != v) tương ứng với một cạnh của đồ thị.

Giới hạn
1<=s,t<=n<=1000

1<=m<=n*(n-1)/2

1<=Q<=10000

Đầu ra
Đối với mỗi truy vấn in ra 1 nếu có đường đi giữa s và t, ngược lại in ra -1.

Ví dụ :
Input 01
Copy
5 3
5 4
4 1
4 3
3
4 5
4 2
3 4
Output 01
Copy
1
-1
1
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m, q;
vector<int> ke[1003];
int tplt[1003];
bool visited[1003];

void dfs(int u, int index)
{
    visited[u] = 1;
    tplt[u] = index;
    for(int j : ke[u])
    {
        if(!visited[j])
        {
            dfs(j, index);
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    
    for(int i =0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        ke[y].push_back(x);
    }

    int index = -1;
    for(int i = 1; i <= n; i++)
    {
        if(!visited[i])
        {
            index++;
            dfs(i, index);
        }
    }

    cin >> q;
    while(q--)
    {
        int s, t;
        cin >> s >> t;
        if(tplt[s] == tplt[t])
        {
            cout << 1 << endl;
        }else 
        {
            cout << -1 << endl;
        }
    }

    return 0;
}