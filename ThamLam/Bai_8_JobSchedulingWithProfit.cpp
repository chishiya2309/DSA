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
struct Job
{
    int JobID, Deadline, Profit;
};

bool cmp(Job a, Job b)
{
    return a.Profit > b.Profit;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int n;
    cin >> n;

    vector<Job> Jobs(n);
    for(int i = 0; i < n; i++)
    {
        cin >> Jobs[i].JobID >> Jobs[i].Deadline >> Jobs[i].Profit;
    }
    sort(Jobs.begin(), Jobs.end(), cmp);

    set<int, greater<int>> Slots;
    for(int i = 1; i <= n; i++)
    {
        Slots.insert(i);
    }

    int chiPhi = 0;
    for(auto job : Jobs)
    {
        auto it = Slots.lower_bound(job.Deadline);
        if(it != Slots.end())
        {
            chiPhi += job.Profit;
            Slots.erase(it);
        }
    }

    cout << chiPhi;
    return 0;
}