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

    map<char, int> char_count;
    for(char c : s)
    {
        char_count[c] = 0;
    }

    int distinct_char = char_count.size();
    int dem = 0, left = 0, minLength = INT_MAX;
    for(int i = 0; i < s.size(); i++)
    {
        if(++char_count[s[i]] == 1)
        {
            dem++;
        }

        while(dem == distinct_char)
        {
            minLength = min(minLength, i - left + 1);
            if(--char_count[s[left]] == 0)
            {
                dem--;
            }
            left++;
        }
    }

    cout << minLength;

    return 0;
}