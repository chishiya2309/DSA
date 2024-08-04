/*
Cho N công việc với thời gian bắt đầu và kết thúc, tại mỗi thời điểm bạn chỉ thể thực hiện 1 công việc. Bạn hãy tìm ra số lượng công việc lớn nhất mà bạn có thể thực hiện mà các công việc không bị trùng lặp thời gian, biết rằng 2 công việc không trùng lặp thời gian nếu thời gian bắt đầu của công việc hiện tại lớn hơn thời gian kết thúc của công việc trước đó thực hiện.

Đầu vào
Dòng thứ nhất là số nguyên N

N dòng tiếp theo mỗi dòng là thời gian bắt đầu, kết thúc của một công việc.

Giới hạn
1<=N<=10^6

Thời gian bắt đầu và kết thúc là số nguyên 32bit, thời gian kết thúc của 1 công việc luôn lớn hơn hoặc bằng thời gian bắt đầu của nó.

Đầu ra
In ra số công việc tối đa có thể thực hiện

Ví dụ :
Input 01
4
1 10
2 3
4 5
4 9
Output 01
2
*/

#include <bits/stdc++.h>

using namespace std;
bool cmp(pair<int, int> a, pair<int, int> b)
{
    return a.second < b.second;
}
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    vector<pair<int, int>> time(n);
    for(int i=0; i<n; i++)
    {
        cin >> time[i].first >> time[i].second;
    }
    sort(time.begin(), time.end(), cmp);
    int dem = 1, end = time[0].second;
    for(int i = 1; i < n; i++)
    {
        if(time[i].first > end)
        {
            dem++;
            end = time[i].second;
        }
    }
    cout << dem;
    return 0;
}