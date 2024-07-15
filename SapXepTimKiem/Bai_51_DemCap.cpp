/*
Cho mảng A[] có N phần tử, mảng B[] có M phần tử. Gọi a là những phần tử thuộc mảng A[], b là những phần tử thuộc mảng B[], nhiệm vụ của bạn là hãy đếm số cặp (a, b) thỏa mãn a^b > b^a.

Ví dụ A = [3, 9, 7, 2] và B = [2, 5] thì có những cặp thỏa mãn là (3, 2), (3, 5), (2, 5)

Gợi ý : a^b > b^a nếu a < b, ví dụ a = 2, và b = 5 thì 2^5 = 32 > 5^2 = 25. Có 1 vài ngoại lại là cặp (a, b) = (3, 2) thì lại ngược lại và cặp (2, 4) thì bằng nhau cần loại bỏ khi đếm và chú ý khi a = 0, a = 1 là những trường hợp đặc biệt.

Vậy đối với mỗi phần tử trong mảng A[] bạn cần đếm xem trong mảng B[] có bao nhiêu phần tử lớn hơn nó.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

ll demLonHon(vector<int>& b, int x)
{
    return b.end() - upper_bound(b.begin(), b.end(), x);
}

ll demSoCap(vector<int>& a, vector<int>& b)
{
    ll cnt = 0;
    ll countB[5] = {0};
    for(int num : b)
    {
        if(num < 5)
        {
            countB[num]++;
        }
    }

    for(int num : a)
    {
        if(num == 0)
        {
            continue;
        }
        if(num == 1)
        {
            cnt += countB[0];
            continue;
        }

        cnt += demLonHon(b, num);
        cnt += countB[0] + countB[1];
        if(num == 2)
        {
            cnt -= (countB[3] + countB[4]);
        }

        if(num == 3)
        {
            cnt += countB[2];
        }
    }
    return cnt;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, m;
    cin >> n >> m;
    vector<int> a(n), b(m);
    for(int i = 0; i < n; i++)
    {
        cin >> a[i];
    }
    for(int i = 0; i < m; i++)
    {
        cin >> b[i];
    }
    sort(b.begin(), b.end());
    cout << demSoCap(a, b);
    return 0;
}