class Solution {
public:
    int minTimeToReach(vector<vector<int>>& a) {
        int n = a.size(), m = a[0].size();
        priority_queue<pair<int, pair<int, int>>> pq;
        pq.push({0, {0, 0}});
        vector<vector<int>> dist(n, vector<int>(m, INT_MAX));
        dist[0][0] = 0;

        int dir[4][2] = {{0, 1}, {1, 0}, {0, -1}, {-1, 0}};
        
        while (!pq.empty()) {
            int currentTime = pq.top().first;
            int x = pq.top().second.first;
            int y = pq.top().second.second;
            pq.pop();
            
            for (auto& d : dir) {
                int newX = x + d[0], newY = y + d[1];

                if (newX >= 0 && newY >= 0 && newX < n && newY < m) {
                    int newTime = max(currentTime + 1, a[newX][newY] + 1);

                    if (newTime < dist[newX][newY]) {
                        dist[newX][newY] = newTime;
                        pq.push({newTime, {newX, newY}});
                    }
                }
            }
        }
        
        return dist[n-1][m-1];
    }
};
