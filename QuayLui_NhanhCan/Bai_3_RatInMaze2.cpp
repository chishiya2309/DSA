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
int n, a[9][9], mark[9][9] = {0};
string s = "";
vector<string> res;
int di[] = {1, 0, 0, -1};
int dj[] = {0, -1, 1, 0};
string moves = "DLRU";
void Try(int i, int j)
{
    if(i == n && j == n)
    {
        res.push_back(s);
        return;
    }
    for(int k = 0; k < 4; k++)
    {
        int newi = i + di[k];
        int newj = j + dj[k];

        if(newi >= 1 && newi <= n && newj >= 1 && newj <= n && a[newi][newj] == 1 && mark[newi][newj] == 0)
        {
            s += moves[k];
            mark[newi][newj] = 1;
            Try(newi, newj);
            s.pop_back();
            mark[newi][newj] = 0;
        }
    }
    
    
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    for(int i = 1; i <= n; i++) {
        for(int j = 1; j <= n; j++) {
            cin >> a[i][j];
        }
    }
    mark[1][1] = 1;
    Try(1, 1);
    if(res.size() == 0) {
        cout << -1;
    }else {
        sort(res.begin(), res.end());
        for(int i = 0; i < res.size(); i++) {
            cout << res[i] << endl;
        }
    }
    return 0;
}
