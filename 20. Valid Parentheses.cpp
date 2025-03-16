class Solution {
    public:
        bool isValid(string s) {
            int n=s.size();
            stack<char> st;
            for(int i=0;i<n;i++){
                char ch = s[i];
                if(ch=='(' || ch=='{' || ch=='['){
                    st.push(ch);
                }
                else{
                    if(!st.empty()){
                        if(ch==')' && st.top()=='(' || ch=='}' && st.top()=='{' || ch==']' && st.top()=='['){
                            st.pop();
                        }
                        else{
                            return false;
                        }
                    }
                    else{
                        return false;
                    }
                }
            }
            if(st.empty()){
                return true;
            }
            else{
                return false;
            }
        }
    };