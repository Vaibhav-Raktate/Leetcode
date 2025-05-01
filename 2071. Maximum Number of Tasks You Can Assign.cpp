class Solution {
public:
    bool canDo(int k, vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        multiset<int> w(workers.end() - k, workers.end());
        int p = pills;

        for (int i = k - 1; i >= 0; i--) {
            auto it = w.lower_bound(tasks[i]);
            if (it != w.end()) {
                w.erase(it);
            } else {
                if (p == 0) return false;
                it = w.lower_bound(tasks[i] - strength);
                if (it == w.end()) return false;
                w.erase(it);
                p--;
            }
        }
        return true;
    }

    int maxTaskAssign(vector<int>& tasks, vector<int>& workers, int pills, int strength) {
        sort(tasks.begin(), tasks.end());
        sort(workers.begin(), workers.end());
        int low = 0, high = min(tasks.size(), workers.size()), ans = 0;

        while (low <= high) {
            int mid = (low + high) / 2;
            if (canDo(mid, tasks, workers, pills, strength)) {
                ans = mid;
                low = mid + 1;
            } else {
                high = mid - 1;
            }
        }
        return ans;
    }
};
