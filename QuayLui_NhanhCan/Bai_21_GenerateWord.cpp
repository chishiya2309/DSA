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
char c[10][10];
bool mark[10][10];
string s;
bool found = false;
int dx[] = {-1, 0, 1, 0};
int dy[] = {0, 1, 0, -1};
void Try(int i, int j, int pos)
{
    mark[i][j] = true;
    if(found || pos == s.size())
    {
        found = true;
        return;
    }

    for(int k = 0; k < 4; k++)
    {
        int inext = i + dx[k], jnext = j + dy[k];
        if(inext >= 0 && inext < n && jnext >= 0 && jnext < m && c[inext][jnext] == s[pos] && !mark[inext][jnext])
        {
            Try(inext, jnext, pos + 1);
        }
    }
    mark[i][j] = false;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> m;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            cin >> c[i][j];
        }
    }
    cin >> s;
    for(int i = 0; i < n; i++)
    {
        for(int j = 0; j < m; j++)
        {
            if(c[i][j] == s[0])
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