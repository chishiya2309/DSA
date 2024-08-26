/*
Cho n thành phố đánh số từ 1 đến n và các tuyến đường giao thông hai chiều giữa chúng, mạng lưới giao thông này được cho bởi mảng C[1…n, 1…n] ở đây C[i][j] = C[j][i] là chi phí đi đoạn đường trực tiếp từ thành phố i đến thành phố j. Một người du lịch xuất phát từ thành phố 1, muốn đi thăm tất cả các thành phố còn lại mỗi thành phố đúng 1 lần và cuối cùng quay lại thành phố 1. Hãy chỉ ra chi phí ít nhất mà người đó phải bỏ ra.



Đầu vào
Dòng đầu tiên là số nguyên n – số thành phố

n dòng sau, mỗi dòng chứa n số nguyên thể hiện cho mảng 2 chiều C.

Giới hạn
1<=N<=15

0<=C[i][j]<=100

Đầu ra
In ra chi phí mà người đó phải bỏ ra

Ví dụ :
Input 01
Copy
4
0 85 26 81 
85 0 77 97 
26 77 0 26 
81 97 26 0
Output 01
Copy
234
*/

#include <bits/stdc++.h>

using namespace std;

int n;
int c[16][16];
bool visited[16];
int x[16];
int minCost = INT_MAX;
int minChiPhi = INT_MAX;
int sum = 0;

void nhap()
{
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        for(int j = 1; j <= n; j++)
        {
            cin >> c[i][j];
            if(c[i][j])
            {
                minCost = min(minCost, c[i][j]);
            }
        }
    }
}

void Try(int i)
{
    for(int j = 2; j <= n; j++)
    {
        if(!visited[j])
        {
            visited[j] = true;
            x[i] = j;
            sum += c[x[i - 1]][x[i]];
            if(i == n)
            {
                minChiPhi = min(minChiPhi, sum + c[x[i]][x[1]]);
            }else if(sum + (n - i + 1)*minCost < minChiPhi)
            {
                Try(i + 1);
            }
            visited[j] = false;
            sum -= c[x[i - 1]][x[i]];
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    nhap();

    x[1] = 1;
    visited[1] = true;
    Try(2);

    cout << minChiPhi;

    return 0;
}