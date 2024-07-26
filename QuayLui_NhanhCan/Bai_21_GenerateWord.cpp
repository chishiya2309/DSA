/*
Cho một bảng HCN cỡ N hàng, M cột, mỗi ô trên HCN chứa 1 chữ cái in hoa hoặc chữ số. Một từ có thể được xây dựng từ các chữ cái của các ô liền kề theo thứ tự, trong đó các ô liền kề nằm cạnh nhau theo chiều ngang hoặc chiều dọc. Không được sử dụng cùng một ô chữ cái nhiều lần. Bạn hãy xác định xem có thể tạo thành từ S cho trước hay không ?

Đầu vào
• Dòng đầu tiên là N và M

• N dòng tiếp theo mô tả bảng HCN

• Dòng cuối cùng là từ S

Giới hạn
• 1<=N,M<=5

• 1<=len(S)<=25

Đầu ra
• In ra YES nếu có thể tạo được từ S, ngược lại in NO

Ví dụ :
Input 01
4 4
ACAC
28B5
1TE5
ABCH
28TECH
Output 01
YES
*/

#include <bits/stdc++.h>

using namespace std;
int n, m;
string s;
char a[10][10];
int mark[10][10];
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
bool found = 0;
void Try(int x, int y, int pos)
{
    mark[x][y] = 1;
    if(found || pos == s.size())
    {
        found = 1;
        return;
    }

    for(int k = 0; k < 4; k++)
    {
        int i = x + dx[k], j = y + dy[k];
        if(i >= 0 && i < n && j >= 0 && j < m && a[i][j] == s[pos] && mark[i][j] == 0)
        {
            Try(i, j, pos + 1);
        }
    }
    mark[x][y] = 0;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> a[i][j];
        }
    }
    cin >> s;
    for(int i = 0; i  < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(a[i][j] == s[0])
            {
                Try(i, j, 1);
            }
        }
    }
    if(found)
    {
        cout << "YES";
    }else {
        cout << "NO";
    }
    return 0;
}