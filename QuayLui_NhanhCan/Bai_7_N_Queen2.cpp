/*
Cho một bàn cờ 8 x 8, mỗi ô có một giá trị A[i][j], tương ứng với điểm số đạt được nếu như bạn đặt một quân cờ vào đó. Nhiệm vụ của bạn là đặt 8 quân hậu lên bàn cờ, sao cho không có 2 quân nào ăn nhau, và số điểm đạt được là lớn nhất.



Đầu vào
Gồm 8 dòng, mỗi dòng gồm 8 số tương ứng với các số trên bàn cờ.

Giới hạn
1<=A[i][j]<=100

Đầu ra
In ra số điểm đạt được lớn nhất.

Ví dụ :
Input 01
12 29 80 91 56 46 97 13 
54 88 27 84 85 9 32 77 
48 80 88 74 30 77 38 98 
6 82 20 95 7 86 12 43 
100 82 15 7 95 9 5 84 
51 40 65 98 86 38 30 63 
96 78 98 76 33 11 2 58 
33 51 35 68 62 87 67 39
Output 01
653
*/

#include <bits/stdc++.h>

using namespace std;
int a[9][9];
int sum = 0, max_sum = INT_MIN;
int cot[20], xuoi[20], nguoc[20], x[9];
void Try(int i)
{
    for(int j = 1; j <= 8; j++)
    {
        if(cot[j] == 0 && xuoi[i - j + 8] == 0 && nguoc[i + j - 1] == 0)
        {
            x[i] = j;
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 1;
            sum += a[i][x[i]];
            if(i == 8)
            {
                max_sum = max(max_sum, sum);
            }else {
                Try(i + 1);
            }
            cot[j] = xuoi[i - j + 8] = nguoc[i + j - 1] = 0;
            sum -= a[i][x[i]];
        }
    }
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    for(int i = 1; i <= 8; i++)
    {
        for(int j = 1; j <= 8; j++)
        {
            cin >> a[i][j];
        }
    }
    Try(1);
    cout << max_sum;
    return 0;
}