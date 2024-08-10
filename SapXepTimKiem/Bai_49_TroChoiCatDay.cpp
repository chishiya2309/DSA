/*
Có n sợi dây, bạn cần cắt k đoạn dây có cùng chiều dài từ chúng. Tìm chiều dài tối đa của các mảnh dây bạn có thể nhận được.

Đầu vào
Dòng đầu tiên chứa hai số nguyên n và k. N dòng tiếp theo mỗi dòng ghi một số, chiều dài của sợi dây là a[i].

Giới hạn
1≤n, k≤10000

1≤ai≤10^7

Đầu ra
In ra chiều dài của mảnh dây dài nhất mà bạn có thể cắt với 6 số sau dấu phẩy.

Ví dụ :
Input 01
Copy
4 11
802 743 457 539
Output 01
Copy
200.500000
*/

#include <bits/stdc++.h>

using namespace std;

bool check(int n, int k, vector<int>a, double Length)
{
    int demDoan = 0;
    for(int i = 0; i < n; i++)
    {
        demDoan += (int)(a[i] / Length);
        if(demDoan >= k)
        {
            return true;
        }
    }

    return demDoan >= k;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n, k;
    cin >> n >> k;

    vector<int> a(n);
    for(int &x : a)
    {
        cin >> x;
    }

    double left = 0, right = 1e18;
    double res = -1;

    for(int i = 0; i <= 90; i++)
    {
        double mid = (left + right) / 2;
        if(check(n, k, a, mid))
        {
            res = mid;
            left = mid;
        }else 
        {
            right = mid;
        }
    }

    cout << fixed << setprecision(6) << res;
    return 0;
}