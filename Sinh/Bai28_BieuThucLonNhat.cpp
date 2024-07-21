#include<bits/stdc++.h>

using namespace std;

long long calculate(vector<long long>& nums, vector<int>& signs) {
    long long result = nums[0];
    for (int i = 1; i < 4; i++) {
        if (signs[i-1] == 0) result += nums[i];
        else result -= nums[i];
    }
    return result;
}

int main() {
    vector<long long> nums(4);
    for (int i = 0; i < 4; i++) {
        cin >> nums[i];
    }

    vector<int> signs(3, 0);  // 0 represents '+', 1 represents '-'
    long long max_result = LLONG_MIN;

    do {
        long long current_result = calculate(nums, signs);
        max_result = max(max_result, current_result);
    } while (next_permutation(signs.begin(), signs.end()));

    cout << max_result << endl;

    return 0;
}