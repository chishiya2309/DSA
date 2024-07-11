/*Có n sợi dây, bạn cần cắt k đoạn dây có cùng chiều dài từ chúng. Tìm chiều dài tối đa của các mảnh dây bạn có thể nhận được.*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;
bool check(int a[], int n, int k, double Length)
{
    ll cnt = 0;
    for(int i = 0; i < n; i++)
    {
        cnt += (int)(a[i] / Length);
        if(cnt >= k)
        {
            return true;
        }
    }
    return cnt >= k;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, k;
    cin >> n >> k;
    int a[n];
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    double left = 0, right = 1e18;
    double res = -1;
    for(int i = 0; i <= 90; i++)
    {
        double mid = (left + right) / 2;
        if(check(a, n, k, mid))
        {
            res = mid;
            left = mid + 1;
        }else {
            right = mid - 1;
        }
    }
    cout << fixed << setprecision(6) << res;
    return 0;
}