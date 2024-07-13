/*
28tech rất yêu thích con số 28 vì thế anh ta có bài toán sau và nhờ bạn tìm lời giải. Cho một xâu kí tự S chỉ bao gồm kí tự 2 và kí tự 8, bạn hãy tìm xâu con liên tiếp có độ dài lớn nhất mà trong đó chứa nhiều nhất X kí tự 2 và Y kí tự 8.
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
    int l = 0;
    int res = -1e9;
    for(int r = 0; r < s.size(); ++r)
    {
        if(s[r] == '2')
        {
            cnt2++;
        }else {
            cnt8++;
        }
        while(cnt2 > x || cnt8 > y)
        {
            if(s[l] == '2')
            {
                cnt2--;
                l++;
            }else {
                cnt8--;
                l++;
            }
        }
        res = max(res, r - l + 1);
    }
    cout << res;
    return 0;
}