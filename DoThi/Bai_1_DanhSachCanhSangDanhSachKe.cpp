/*
Cho đồ thị vô hướng G = <V, E> gồm n đỉnh và m cạnh được biểu diễn dưới dạng danh sách cạnh. Hãy chuyển đổi đồ thị dưới dạng danh sách cạnh này sang danh sách kề tương ứng.

Đầu vào
Dòng đầu tiên là 2 số n và m, tương ứng với số lượng đỉnh và cạnh của đồ thị. Các đỉnh của đồ thị được đánh số từ 1 tới n.

m dòng tiếp theo mỗi dòng chứa đỉnh u, v tương ứng với một cạnh của đồ thị.

Giới hạn
1<=n<=1000

1<=m<=n*(n-1)/2

Đầu ra
In ra n dòng, trong đó dòng thứ i in ra danh sách kề của đỉnh i. Các đỉnh trong danh sách kề được liệt kê từ nhỏ tới lớn.

Ví dụ :
Input 01
Copy
5 4
2 5
4 1
4 2
4 3
Output 01
Copy
1 : 4 
2 : 4 5 
3 : 4 
4 : 1 2 3 
5 : 2
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

int n, m;
vector<int> ke[1003];

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
    for(int i = 1; i <= n; i++)
    {
        sort(ke[i].begin(), ke[i].end());
    }

    for(int i = 1; i <= n; i++)
    {
        cout << i << " : ";
        for(int j = 0; j < ke[i].size(); j++)
        {
            cout << ke[i][j] << " ";
        }
        cout << endl;
    }

    return 0;
}