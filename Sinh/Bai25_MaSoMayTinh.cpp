/*
Số lượng máy tính ở các phòng thực hành tăng lên nhanh chóng. Để gán mã cho các máy tính của trường đó người ta sử dụng mã gồm 2*N ký tự, trong đó: N ký tự đầu tiên là hoán vị của N chữ cái in hoa đầu tiên, tính từ A. N ký tự tiếp theo là các ký tự số bất kỳ từ 1 đến N (có thể trùng nhau). Người ta ước tính chỉ cần N = 5 là đủ để gán mã cho toàn bộ máy tính kể cả khi mở rộng quy mô các phòng thực hành. Hãy viết chương trình liệt kê các mã tạo được với giá trị N cho trước.

Đầu vào
Số nguyên dương N

Giới hạn
1 < N < 6

Đầu ra
Ghi ra lần lượt các mã khác nhau tạo được theo thứ tự từ điển, mỗi mã ghi trên một dòng

Ví dụ :
Input 01
Copy
2
Output 01
Copy
AB11
AB12
AB21
AB22
BA11
BA12
BA21
BA22
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;
int n;
vector<char> c;
vector<int> x;
bool final = false;

void khoitao()
{
    x.assign(n, 1);
}
void sinh()
{
    int i = n - 1;
    while(i >= 0 && x[i] == n)
    {
        i--;
    }
    if(i == -1)
    {
        final = true;
    }else {
        x[i]++;
        for(int j = i + 1; j < n; j++)
        {
            x[j] = 1;
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n;
    c.resize(n);
    x.resize(n);

    for(int i = 0; i < n; i++)
    {
        c[i] = 'A' + i;
    }
    do
    {
        khoitao();
        final = false;
        while(!final)
        {
            for(int i = 0; i < n; i++) {
                cout << c[i];
            }
            for(int i = 0; i < n; i++)
            {
                cout << x[i];
            }
            cout << endl;
            sinh();
        }
    } while (next_permutation(c.begin(), c.end()));
    
    return 0;
}