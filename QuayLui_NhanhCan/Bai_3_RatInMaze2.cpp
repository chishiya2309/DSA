/*
Cho một mê cung được mô tả dưới dạng một ma trận nhị phân có N hàng và N cột. Một con chuột bắt đầu tử ô (1, 1) và muốn di chuyển tới (N, N). Con chuột chỉ được di chuyển sang trái, sang phải, lên trên và xuống dưới và chỉ được di chuyển tới ô nào đó nếu ô đó có giá trị là 1. Bạn hãy in ra các cách đi hợp lệ của con chuột, trong đó nếu con chuột đi sang phải thì nước đi được mô tả là chữ R, và nếu con chuột đi xuống dưới thì nước đi được mô tả là chữ D, nếu đi sang trái thì nước đi được mô tả là chữ L, nếu đi lên trên thì nước đi được mô tả là chữ U. Nếu con chuột không thể đi xuống ô (N, N) thì in ra -1. Chú ý trên mỗi đường đi con chuột chỉ có thể đi qua 1 ô nào đó đúng 1 lần.



Đầu vào
Dòng thứ nhất đưa vào N

N dòng tiếp theo mỗi dòng gồm N số

Giới hạn
1<=N<=8

Dữ liệu đảm bảo ô (1, 1) là số 1.

Đầu ra
Đưa ra các đường đi hợp lệ theo thứ tự từ điển tăng dần trên từng dòng.

Ví dụ :
Input 01
Copy
4
1 1 1 1 
1 1 0 1 
1 1 1 1 
0 1 1 1
Output 01
Copy
DDRDRR
DDRDRURD
DDRRDR
DDRRRD
DDRUURRDDD
DDRUURRDDLDR
DRDDRR
DRDDRURD
DRDRDR
DRDRRD
DRURRDDD
DRURRDDLDR
DRURRDDLLDRR
RDDDRR
RDDDRURD
RDDRDR
RDDRRD
RDLDRDRR
RDLDRDRURD
RDLDRRDR
RDLDRRRD
RRRDDD
RRRDDLDR
RRRDDLLDRR
*/

#include <bits/stdc++.h>

using namespace std;
int n;
int a[9][9], mark[9][9];
int dx[] = {1, 0, 0, -1};
int dy[] = {0, -1, 1, 0};
string WORDS = "DLRU";
string s = "";
bool final = false;
void Try(int i, int j)
{
    if(i == n && j == n)
    {
        final = true;
        cout << s << endl;
        return;
    }
    for(int k = 0; k < 4; k++)
    {
        int inext = i + dx[k];
        int jnext = j + dy[k];
        if(inext >= 0 && inext <= n && jnext >= 0 && jnext <= n && a[inext][jnext] == 1 && mark[inext][jnext] == 0)
        {
            s += WORDS[k];
            mark[inext][jnext] = 1;
            Try(inext, jnext);
            s.pop_back();
            mark[inext][jnext] = 0;
        }
    }
}
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
    mark[1][1] = 1;
    Try(1, 1);
    return 0;
}