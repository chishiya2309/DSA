/*
Một máy ATM hiện có n tờ tiền có giá trị a[1], a[2], …, a[n]. Hãy tìm cách trả ít tờ nhất với số tiền đúng bằng S (các tờ tiền có giá trị bất kỳ và có thể bằng nhau, mỗi tờ tiền chỉ được dùng một lần).

Đầu vào
Dòng 1 gồm 2 số nguyên n và S

Dòng thứ hai chứa n số nguyên a[1], a[2], …, a[n]

Giới hạn
1<=N<=30

1<=S<=10^9

1<=t[i]<=10^9

Đầu ra
In ra số tờ tiền ít nhất phải trả, nếu không thể tìm được ra kết quả thì in -1.

Ví dụ :
Input 01
Copy
6 30
10 4 10 5 8 8
Output 01
Copy
4
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
int n;
ll s, t[31], x[31];
ll sum  = 0;
int cnt = 0, min_ans = INT_MAX;
void Try(int i, int index)
{
    for(int j = index; j <= n; j++)
    {
        x[i] = t[j];
        sum += x[i];
        cnt++;
        if(sum == s)
        {
            min_ans = min(min_ans, cnt);
        }else if(sum < s)
        {
            Try(i + 1, j + 1);
        }
        sum -= x[i];
        cnt--;
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> s;
    for(int i = 1; i <= n; i++) {
        cin >> t[i];
    }
    Try(1, 1);
    cout << min_ans;
    return 0;
}