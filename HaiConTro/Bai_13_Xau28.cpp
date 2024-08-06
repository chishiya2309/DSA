/*
28tech rất yêu thích con số 28 vì thế anh ta có bài toán sau và nhờ bạn tìm lời giải. Cho một xâu kí tự S chỉ bao gồm kí tự 2 và kí tự 8, bạn hãy tìm xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 và Y kí tự 8.

Đầu vào
• Dòng 1 chứa xâu S

• Dòng 2 chứa 2 số X, Y

Giới hạn
• 2 <=len(S) <= 10^6

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
8228282888
3 3
Output 01
6
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int x, y;
    cin >> x >> y;

    int cnt2 = 0, cnt8 = 0;
    int left = 0;
    int maxLength = INT_MIN;
    for(int right = 0; right < s.size(); ++right) {
        if(s[right] == '2')
        {
            cnt2++;
        }else {
            cnt8++;
        }

        while(cnt2 > x || cnt8 > y)
        {
            if(s[left] == '2')
            {
                cnt2--;
                left++;
            }else {
                cnt8--;
                left++;
            }
        }

        maxLength = max(maxLength, right - left + 1);
    }
    cout << maxLength;
    return 0;
}