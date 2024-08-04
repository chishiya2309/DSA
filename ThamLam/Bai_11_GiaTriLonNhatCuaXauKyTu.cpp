/*
Cho xâu S và số nguyên K, giá trị của xâu S là bình phương số lần xuất hiện các ký tự trong xâu.

Ví dụ : S = "abbba" sẽ có giá trị là 2^2 + 3^2 = 13. Nhiệm vụ của bạn là được phép xóa tối đa K ký tự từ xâu S, hãy tìm giá trị nhỏ nhất của xâu S sau khi thực hiện xóa.

Đầu vào
Dòng 1 chứa số nguyên K

Dòng 2 chứa xâu S

Giới hạn
1<=K<=100000

1<=len(S)<=100000

Đầu ra
In ra đáp án nhỏ nhất tìm được

Ví dụ :
Input 01
2
aabbb
Output 01
5
*/

#include <bits/stdc++.h>
#define ll long long
using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int k;
    cin >> k;
    string s;
    cin >> s;
    if(k >= s.size())
    {
        cout << 0;
        return 0;
    }
    map<char, int> char_count;
    for(char c: s)
    {
        char_count[c]++;
    }
    priority_queue<int> Q;
    for(auto it : char_count)
    {
        Q.push(it.second);
    }
    
        while(k--)
        {
            int tmp = Q.top();
            Q.pop();
            tmp--;
            Q.push(tmp);
        }
        ll sum = 0;
        while(!Q.empty())
        {
            int tmp = Q.top();
            Q.pop();
            sum += pow(tmp, 2);
        }
        cout << sum;
        return 0;
    }
    