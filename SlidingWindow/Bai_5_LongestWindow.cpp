/*
Cho xâu kí tự S, Tèo là một người khá kì quặc, anh ta chỉ thích những thứ không trùng lặp. Vì thế anh ta yêu cầu bạn tìm ra độ dài xâu con dài nhất mà các kí tự trong xâu con đó không có bất cứ một kí tự nào được lặp lại.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
• 1<=len(S)<=10^6

• S chỉ bao gồm chữ cái in thường

Đầu ra
In ra đáp án của bài toán

Ví dụ :
Input 01
dabacdadbbdd
Output 01
4
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    map<char, int> char_count;
    int left = 0, maxLength = INT_MIN;
    for(int i = 0; i < s.size(); i++) 
    {
        char_count[s[i]]++;
        while(char_count[s[i]] == 2)
        {
            char_count[s[left]]--;
            left++;
        }
        maxLength = max(maxLength, i - left + 1);
    }
    cout << maxLength;
    return 0;
}