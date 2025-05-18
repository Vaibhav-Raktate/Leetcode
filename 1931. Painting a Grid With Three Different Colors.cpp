class Solution {
public:
    vector<string> columnstates;
    int M = 1e9+7;
    vector<vector<int>> t;
    void generatecolumnstates(string curr , char prevchar ,int l ,int m){
        if(l==m){
            columnstates.push_back(curr);
            return;
        }
        for(char ch : {'R','G','B'}){
            if(ch == prevchar)
            continue;

            generatecolumnstates(curr+ch , ch,l+1,m);
        }
    }

    int solve(int remaincols , int previdx ,int  m){
        if(remaincols == 0){
            return 1;
        }
        if(t[remaincols][previdx] != -1){
            return t[remaincols][previdx];
        }
        int ways =0;
        string prevstate = columnstates[previdx];

        for(int i =0; i<columnstates.size(); i++){
            if(i == previdx) continue;

            string currstate = columnstates[i];
            bool valid = true;

            for(int j = 0; j< m ;j++){
                if(prevstate[j] == currstate[j]){
                    valid = false;
                    break;
                }
            }

            if(valid){
                ways = (ways + solve(remaincols - 1, i, m)) % M;
            }
        }
        return t[remaincols][previdx] = ways;
    }

    int colorTheGrid(int m, int n) {
        generatecolumnstates("", '#',0 ,m);
        int totalstates = columnstates.size();
        t = vector<vector<int>>(n+1 , vector<int>(totalstates+1 , -1));

        int result = 0;
        for(int i= 0; i< columnstates.size();i++){
            result = (result+solve(n-1, i, m))%M;
        }
        return result;
    }
};
