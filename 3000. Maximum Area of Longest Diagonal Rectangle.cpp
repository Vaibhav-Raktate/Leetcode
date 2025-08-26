class Solution {
public:
    int areaOfMaxDiagonal(vector<vector<int>>& dimensions) {
        int n = dimensions.size();
        int maxdiag = 0;
        int maxarea = 0;
        for(int i=0; i<n; i++){
            int l = dimensions[i][0];
            int w = dimensions[i][1];
            
            int diag =(l*l)+(w*w);
            int area = l*w; 

            if ( diag > maxdiag ){
                maxdiag = diag;
                maxarea = area;
            }else if(diag == maxdiag){
                maxarea = max(maxarea,area);
            }
        }
        return maxarea;
    }
};
