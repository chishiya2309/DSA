/*
Bạn được đưa cho một bản đồ của một tòa nhà và nhiệm vụ của bạn là đếm số lượng phòng của tòa nhà đó.

Kích thước của bản đồ là n × m hình vuông và mỗi hình vuông là sàn hoặc tường. Bạn có thể đi bộ sang trái, phải, lên và xuống qua các ô sàn.

Đầu vào
Dòng nhập đầu tiên có hai số nguyên n và m: chiều cao và chiều rộng của bản đồ.

Khi đó có n dòng gồm m ký tự mô tả bản đồ. Mỗi ký tự là một trong hai ký tự '.' hoặc '#' tương ứng với sàn nhà và tường.

Giới hạn
1≤n,m≤1000

Đầu ra
In ra số nguyên duy nhất là số phòng của tòa nhà

Ví dụ :
Input 01
Copy
6 6
..###.
...#..
#..#..
.##.#.
######
.#.##.
Output 01
Copy
7
*/

#include <bits/stdc++.h>

using namespace std;

int n, m;
char a[1003][1003];

int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};

void bfs(int i, int j)
{
    queue<pair<int, int>> q;
    q.push({i, j});
    while(!q.empty())
    {
        pair<int, int> t = q.front();
        q.pop();
        int x = t.first;
        int y = t.second;
        for(int k = 0; k < 4; k++)
        {
            int inext = x + dx[k];
            int jnext = y + dy[k];
            if(inext >= 1 && inext <= n && jnext >= 1 && jnext <= m && a[inext][jnext] == '.')
            {
                a[inext][jnext] = '#';
                q.push({inext, jnext});
            }
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> m;
    for(int i = 1; i <= n; i++) 
    {
        for(int j = 1; j <= m; j++)
        {
            cin >> a[i][j];
        }
    }

    int dem = 0;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= m; j++)
        {
            if(a[i][j] == '.')
            {
                dem++;
                bfs(i, j);
            }
        }
    }

    cout << dem;

    return 0;
}