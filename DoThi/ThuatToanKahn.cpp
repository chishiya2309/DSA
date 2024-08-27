/*
1 kiểu sắp xếp topo dùng bfs, nếu duyệt hết được tất cả các đỉnh thì đồ thị không có chu trình, đỉnh nào có bán bậc vào bằng 0 thì đẩy vào hàng đợi
*/

#include<bits/stdc++.h>
using namespace std;

int n, m;
vector<int> ke[1003];
int bac[1003];

void Kahn()
{
    queue<int> q;
    for(int i = 1;i <= n; i++)
    {
        if(bac[i] == 0)
        {
            q.push(i);
        }
    }

    int dem = 0;

    while(!q.empty())
    {
        int u = q.front();
        q.pop();
        dem++;
        for(int j : ke[u])
        {
            bac[j]--;
            if(bac[j] == 0)
            {
                q.push(j);
            }
        }
    }
    if(dem == n)
    {
        cout << 0;
    }else 
    {
        cout << 1;
    }
}

signed main()
{
    cin >> n >> m;
    for(int i = 0; i < m; i++)
    {
        int x, y;
        cin >> x >> y;
        ke[x].push_back(y);
        bac[y]++;
    }

    Kahn();

    return 0;
    
}