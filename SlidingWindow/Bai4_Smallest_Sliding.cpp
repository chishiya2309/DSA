/*
Cho xâu S chỉ gồm chữ cái in thường, nhiệm vụ của bạn là tìm chiều dài của xâu con liên tiếp nhỏ nhất có chứa đầy đủ các kí tự khác nhau của S.

Ví dụ S = abcaaaabcad thì xâu con bcad có độ dài nhỏ nhất và chứa đầy đủ các kí tự khác nhau của S.

Đầu vào
Dòng duy nhất chứa xâu S

Giới hạn
1<=len(S)<=10^6

Đầu ra
In ra độ dài xâu con nhỏ nhất tìm được

Ví dụ :
Input 01
28teeeeeechhhh
Output 01
11
*/

#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;
    int min_Length = s.size();
    map<char, int> char_count;
    for(char c : s)
    {
        char_count[c] = 0;
    }
    int distinct_char = char_count.size();
    int cnt = 0, start = 0;
    for(int right = 0; right < s.size(); right++)
    {
        if(++char_count[s[right]] == 1)
        {
            cnt++;
        }
        while(cnt == distinct_char)
        {
            min_Length = min(min_Length, right - start + 1);
            if(--char_count[s[start]] == 0)
            {
                cnt--;
            }
            start++;
        }
    }
    cout << min_Length;
    return 0;
}