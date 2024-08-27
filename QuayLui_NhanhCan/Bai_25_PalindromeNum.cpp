/*
Cho một số nguyên dương N có không quá 16 chữ số, bạn được phép tách các chữ số của N thành các số nhỏ hơn và phải đảm bảo các số tách được đều là số thuận nghịch, bạn cũng ko được phép đảo thứ tự các chữ số của N. Hãy in ra mọi cách tách như vậy.

Đầu vào
• Dòng duy nhất chứa N

Giới hạn
• 1<=N<=10^16

Đầu ra
In ra các cách tách N thành các số nhỏ thuận nghịch nhỏ hơn

Ví dụ :
Input 01
Copy
282882
Output 01
Copy
2 8 2 8 8 2 
2 8 2 88 2 
2 8 2882 
2 828 8 2 
282 8 8 2 
282 88 2
*/

#include <bits/stdc++.h>
#define endl '\n'
using namespace std;

string n;

bool isPalindrome(string tmp)
{
    string res = tmp;
    reverse(res.begin(), res.end());
    return res == tmp;
}

void Try(vector<string> v, int index)
{
    if(v.size() && index == n.size())
    {
        for(string num : v)
        {
            cout << num << " ";
        }
        cout << endl;
    }

    for(int length = 1; length + index - 1 < n.size(); length++)
    {
        string tmp = n.substr(index, length);
        if(isPalindrome(tmp))
        {
            v.push_back(tmp);
            Try(v, index + length);
            v.pop_back();
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    cin >> n;

    vector<string> v;
    Try(v, 0);

    return 0;
}