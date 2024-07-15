/*
28Tech định tổ chức một kỳ thi Hackathon, kỳ thi này sẽ gồm N cuộc thi nhỏ diễn ra lần lượt. Mỗi cuộc thi sẽ chứa 1 số problem cụ thể, Hackathon sẽ diễn ra trong H giờ liên tiếp. Mỗi giờ bạn có thể quyết định mình sẽ giải được K problem.

Nếu cuộc thi nào mà bạn đã giải hết các problem của cuộc thi đó thì bạn không thể dành thời gian thừa để làm các problem trong các cuộc thi khác.

Nhiệm vụ của bạn là xác định giá trị nhỏ nhất của K để đảm bảo được mình sẽ hoàn thành tất cả problem trong các cuộc thi kịp thời gian.
*/
#include <bits/stdc++.h>
#define ll long long
using namespace std;

bool check(vector<int>& problems, int n, int h, ll k)
{
    ll res = 0;
    for(int i = 0; i < n; i++)
    {
        if(problems[i] % k == 0)
        {
            res += problems[i] / k;
        }else {
            res += problems[i] / k + 1;
        }
        if(res > h)
        {
            return false;
        }
    }
    return res <= h;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n, h;
    cin >> n >> h;
    vector<int> problems(n);
    for(int i = 0; i < n; i++)
    {
        cin >> problems[i];
    }
    ll left = 0, right = 1e18;
    ll res = -1;
    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(check(problems, n, h, mid))
        {
            res = mid;
            right = mid - 1;
        }else {
            left = mid + 1;
        }
    }
    cout << res;
    return 0;
}