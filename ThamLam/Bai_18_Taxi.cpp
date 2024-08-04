/*
Có N nhóm học sinh, mỗi nhóm học sinh có từ 1 tới 4 người. Các nhóm học sinh này dự định sẽ đi thăm quan vườn bách thú bằng những chiếc xe taxi, mỗi xe taxi trở được tối đa 4 người. Hãy tìm số lượng taxi tối thiểu để có thể trở hết N nhóm học sinh này, biết rằng những học sinh ở cùng 1 nhóm sẽ đi cùng 1 taxi

Đầu vào
Dòng đầu tiên chứa số nguyên dương N là số nhóm học sinh

Dòng thứ 2 gồm N số là số lượng của các nhóm học sinh

Giới hạn
1<=N<=10000

Số lượng học sinh của mỗi nhóm là 1 số dương không quá 4

Đầu ra
In ra số lượng xe taxi tối thiểu cần dùng

Ví dụ :
Input 01
6
2 1 3 1 2 2
Output 01
3
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int n;
    cin >> n;
    
    vector<int> cnt(5, 0);
    for(int i=0; i<n; i++)
    {
        int x;
        cin >> x;
        cnt[x]++;
    }
    //Số taxi tối thiểu
    int soTaxi = cnt[4]; // Cứ 4 học sinh là 1 xe

    soTaxi += cnt[3];//Ghép nhóm 3 học sinh với 1 học sinh
    cnt[1] = max(0, cnt[1] - cnt[3]);

    soTaxi += cnt[2] / 2;   //Ghép nhóm 2 học sinh với nhau
    if(cnt[2] % 2)
    {
        soTaxi += 1;
        cnt[1] = max(0, cnt[1] - 2);    //ghép 2 nhóm 1 học sinh nếu có
    }

    soTaxi += (cnt[1] + 3) / 4;
    cout << soTaxi;
    return 0;
}