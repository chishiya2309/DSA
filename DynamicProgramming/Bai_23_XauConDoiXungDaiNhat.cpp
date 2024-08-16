/*
Cho xâu S chỉ bao gồm các ký tự viết thường và dài không quá 1000 ký tự.

Hãy tìm xâu con đối xứng dài nhất của S.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=1000

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
bcccbebge
Output 01
5
*/

#include <bits/stdc++.h>

using namespace std;

string s;
int n;
bool dp[1003][1003];

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> s;
    n = s.size();

    for(int i = 1; i <= n; i++)
    {
        dp[i][i] = 1;
    }

    int ans = 1;
    //Duyet do dai xau
    for(int length = 2; length <= n; length++)
    {
        //Duyet vi tri bat dau
        for(int i = 1; i + length - 1 <= n; i++)
        {
            //Vi tri ket thuc
            int j = i + length - 1;
            if(length == 2)
            {
                dp[i][j] = (s[i - 1] == s[j - 1]);
            }else 
            {
                dp[i][j] = (s[i - 1] == s[j - 1]) && dp[i + 1][j - 1];
            }

            if(dp[i][j])
            {
                ans = length;
            }
        }
    }

    cout << ans;

    return 0;
}