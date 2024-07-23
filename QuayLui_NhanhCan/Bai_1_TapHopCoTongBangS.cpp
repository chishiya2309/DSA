/*
Xét tất cả các tập hợp các số nguyên dương có các phần tử khác nhau và không lớn hơn số n cho trước. Nhiệm vụ của bạn là hãy đếm xem có tất cả bao nhiêu tập hợp có số lượng phần tử bằng k và tổng của tất cả các phần tử trong tập hợp bằng s? Các tập hợp là hoán vị của nhau chỉ được tính là một.

Ví dụ với n = 9, k = 3, s = 23, {6, 8, 9} là tập hợp duy nhất thỏa mãn.

Đầu vào
1 dòng gồm 3 số nguyên n, k, s

Giới hạn
1 ≤ n ≤ 20

1 ≤ k ≤ 10

1 ≤ s ≤ 155

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
Copy
16 8 91
Output 01
Copy
28
*/

#include <bits/stdc++.h>

using namespace std;
int n, k, s;
int x[11];
int cnt = 0, sum = 0;
void Try(int i, int index) {
    for(int j = index; j <= n; j++)
    {
        x[i] = j;
        sum += x[i];
        if(i == k)
        {   
            if(sum == s)
            {
                cnt++;
            }
        }else if(sum < s)
        {
            Try(i + 1, j + 1);
        }
        sum -= x[i];
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cin >> n >> k >> s;
    Try(1, 1);
    cout << cnt;
    return 0;
}