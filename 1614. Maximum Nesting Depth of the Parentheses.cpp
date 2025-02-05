class Solution {
public:
    int maxDepth(string s) {
        int depth=0;
        int max_depth=0;
        for(int i=0;i<s.size();i++){
            if(s[i]=='('){
                depth=depth+1;
            }
            else if(s[i]==')'){
                depth=depth-1;
            }
            max_depth=max(depth,max_depth);
        }
        return max_depth;
    }
};