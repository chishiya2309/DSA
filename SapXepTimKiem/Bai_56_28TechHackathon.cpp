/*
28Tech định tổ chức một kỳ thi Hackathon, kỳ thi này sẽ gồm N cuộc thi nhỏ diễn ra lần lượt. Mỗi cuộc thi sẽ chứa 1 số problem cụ thể, Hackathon sẽ diễn ra trong H giờ liên tiếp. Mỗi giờ bạn có thể quyết định mình sẽ giải được K problem.

Nếu cuộc thi nào mà bạn đã giải hết các problem của cuộc thi đó thì bạn không thể dành thời gian thừa để làm các problem trong các cuộc thi khác.

Nhiệm vụ của bạn là xác định giá trị nhỏ nhất của K để đảm bảo được mình sẽ hoàn thành tất cả problem trong các cuộc thi kịp thời gian.

Đầu vào
Dòng 1 là N và H

Dòng 2 là N số tương ứng với số problem trong các cuộc thi nhỏ của Hackathon

Giới hạn
1<=N<=2.10^5

N<=H<=10^9

Các problem trong các cuộc thi là số nguyên dương không vượt quá 10^6

Đầu ra
In ra giá trị nhỏ nhất của K tìm được

Ví dụ :
Input 01
Copy
5 8
5 5 4 2 2
Output 01
Copy
3
Giải thích test :
Các cuộc thi mất lần lượt 2, 2, 2, 1, 1 giờ để hoàn thành
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int n, h;
vector<int> problem;

bool check(int n, int h, vector<int>problem, ll k)
{
    int time = 0;
    for(int i = 0; i < n; i++)
    {
        if(problem[i] % k == 0)
        {
            time += problem[i] / k;
        }else
        {
            time += problem[i] / k + 1;
        }
        if(time > h)
        {
            return false;
        }
    }
    return time <= h;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n >> h;
    problem.resize(n);
    for(int i = 0; i < n; i++)
    {
        cin >> problem[i];
    }

    ll left = 0, right = 1e18;
    ll res = -1;

    while(left <= right)
    {
        ll mid = (left + right) / 2;
        if(check(n, h, problem, mid))
        {
            res = mid;
            right = mid - 1;
        }else 
        {
            left = mid + 1;
        }
    }

    cout << res;

    return 0;
}