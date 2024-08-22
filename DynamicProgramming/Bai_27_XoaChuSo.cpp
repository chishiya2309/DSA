/*
Bạn được cung cấp một số nguyên n. Trên mỗi bước, bạn có thể trừ một trong các chữ số khỏi số. Cần thực hiện bao nhiêu bước để số đó bằng 0?

Đầu vào
Dòng duy nhất chứa số nguyên n

Giới hạn
1<=n<=10^6

Đầu ra
In ra số bước tối thiểu

Ví dụ :
Input 01
Copy
27
Output 01
Copy
5
Giải thích test :
Các bước thực hiện : 27→20→18→10→9→0
*/

#include <bits/stdc++.h>

using namespace std;

int f[1000003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    f[0] = 0;
    int n;
    cin >> n;
    for(int i = 1; i <= n; i++)
    {
        f[i] = 1000003;
        for(char x : to_string(i))
        {
            f[i] = min(f[i], f[i - (x - '0')] + 1);
        }
    }

    cout << f[n];

    return 0;
}