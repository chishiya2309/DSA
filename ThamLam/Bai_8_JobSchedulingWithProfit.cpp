/*
Cho N công việc. Mỗi công việc được biểu diễn như một bộ 3 số nguyên dương , trong đó JobId là mã của việc, Deadline là thời gian kết thúc của việc, Profit là lợi nhuận đem lại nếu hoàn thành việc đó đúng thời gian. Thời gian để hoàn toàn mỗi công việc là 1 đơn vị thời gian. Hãy cho biết lợi nhuận lớn nhất có thể thực hiện các việc với giả thiết mỗi việc được thực hiện đơn lẻ.

Gợi ý :

B1. Sắp xếp công việc theo lợi nhuận giảm dần

B2. Đối với mỗi công việc => Lựa chọn mốc thời gian bắt đầu để thực hiện công việc, ví dụ nếu deadline là X thì mốc thời gian hợp lệ sẽ là 0,1...X-1, và lựa chọn mốc thời gian lớn nhất còn trống để thực hiện công việc này, sau đó đánh dấu mốc thời gian này đã được sử dụng.

Đầu vào
Dòng thứ 1 chứa số nguyên dương N

N dòng tiếp theo mô tả id, deadline, profit của N công việc

Giới hạn
1<=N<=10^5

1<=JobID<=N

1<=Deadline<=N

1<=Profit<=1000

Đầu ra
In ra lợi nhuận lớn nhất

Ví dụ :
Input 01
4
1 4 20
2 1 10
3 1 40
4 1 30
Output 01
60
*/

#include <bits/stdc++.h>

using namespace std;
bool used[100003];
bool cmp(pair<int, pair<int, int>> a, pair<int, pair<int, int>> b)
{
    return a.second.second > b.second.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, pair<int, int>>> job(n);
    for(int i = 0; i < n; i++)
    {
        cin >> job[i].first >> job[i].second.first >> job[i].second.second;
    }
    sort(job.begin(), job.end(), cmp);
    int profit = job[0].second.second;
    used[job[0].second.first - 1] = true;
    for(int i = 1; i < n; i++)
    {
        for(int j = job[i].second.first - 1; j >= 0; j--)
        {
            if(!used[j])
            {
                used[j] = true;
                profit += job[i].second.second;
                break;
            }
        }
    }
    cout << profit;
    return 0;
}