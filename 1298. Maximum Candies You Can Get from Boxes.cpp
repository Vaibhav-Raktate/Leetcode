class Solution {
public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys,
                   vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {
        
        int n = status.size();
        vector<bool> hasKey(n, false);       // whether we have a key to open the box
        vector<bool> hasBox(n, false);       // whether we have the box
        vector<bool> visited(n, false);      // whether the box has been opened and processed
        queue<int> q;
        
        for (int box : initialBoxes) {
            hasBox[box] = true;
            if (status[box] == 1) q.push(box);
        }
        
        int totalCandies = 0;
        
        while (!q.empty()) {
            int box = q.front();
            q.pop();
            if (visited[box]) continue;
            
            visited[box] = true;
            totalCandies += candies[box];
            
            // process keys found in this box
            for (int key : keys[box]) {
                hasKey[key] = true;
                if (hasBox[key] && !visited[key]) {
                    q.push(key);
                }
            }
            
            // process boxes found inside this box
            for (int newBox : containedBoxes[box]) {
                hasBox[newBox] = true;
                if (status[newBox] == 1 || hasKey[newBox]) {
                    q.push(newBox);
                }
            }
        }
        
        return totalCandies;
    }
};
