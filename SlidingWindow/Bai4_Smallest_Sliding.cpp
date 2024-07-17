#include <bits/stdc++.h>

using namespace std;

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    string s;
    cin >> s;

    unordered_map<char, int> char_count;

    for(char c : s) {
        char_count[c] = 0;
    }
    int distinct_chars = char_count.size();

    int start = 0, min_length = s.length();
    int count = 0;

    for(int end = 0; end < s.length(); end++) {
        if(++char_count[s[end]] == 1)
        {
            count++;
        }

        while(count == distinct_chars)
        {
            min_length = min(min_length, end - start + 1);

            if(--char_count[s[start]] == 0)
            {
                count--;
            }
            start++;
        }
    }
    cout << min_length;
    return 0;
}