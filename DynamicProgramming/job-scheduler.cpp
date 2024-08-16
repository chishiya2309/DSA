struct Job {
    int start, end, profit;
}; 
bool cmp(Job a, Job b) {
    return a.end < b.end;
}
class Solution {
public:
    int find(Job jobs[], int l, int r, int x) {
        int res = -1;
        while (l <= r) {
            int mid = (l + r) / 2;
            if (jobs[mid].end <= x) {
                res = mid;
                l = mid + 1;
            } else {
                r = mid - 1;
            }
        }
        return res;
    }
    int jobScheduling(vector<int>& startTime, vector<int>& endTime,
                      vector<int>& profit) {
        int n = startTime.size();
        Job jobs[n];
        for (int i = 0; i < n; i++) {
            jobs[i].start = startTime[i];
            jobs[i].end = endTime[i];
            jobs[i].profit = profit[i];
        }
        sort(jobs, jobs+n, cmp);
        int F[50005] = {0};
        F[0] = jobs[0].profit;
        for (int i = 1; i < n; i++) {
            // lay no
            int t = find(jobs, 0, i - 1, jobs[i].start);
            if (t != -1) {
                F[i] = max(jobs[i].profit + F[t], F[i - 1]);
            } else {
                F[i] = max(jobs[i].profit, F[i - 1]);
            }
        }
        return F[n - 1];
    }
};
