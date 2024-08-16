/*
Cho số nguyên dương N, nhiệm vụ của bạn là kiểm tra xem có thể viết N = a * b * c hay không, trong đó a, b, c là 3 số nguyên dương lớn hơn hoặc bằng 2 khác nhau.

Đầu vào
Dòng duy nhất chứa số nguyên dương N

Giới hạn
2<=N<=10^9

Đầu ra
In ra YES nếu có thể biểu diễn N dưới dạng tích của 3 số, ngược lại in ra NO

Ví dụ :
Input 01
Copy
24
Output 01
Copy
YES
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n)
{
    int soThuaSo = 0, soMu = 0;
    for(int i = 2; i <= sqrt(n); i++)
    {
        if(n % i == 0)
        {
            soThuaSo++;
            while(n % i == 0)
            {
                soMu++;
                n /= i;
            }
        }
    }
    if(n > 1)
    {
        soThuaSo++;
        soMu++;
    }

    return (
        soThuaSo >= 3
    ||  (soThuaSo == 2 && soMu >= 4)
    ||  (soThuaSo == 1 && soMu >= 6)
    );
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    if(check(n))
    {
        cout << "YES";
    }else 
    {
        cout << "NO";
    }

    return 0;
}