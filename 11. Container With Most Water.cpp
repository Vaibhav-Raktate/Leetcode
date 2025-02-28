class Solution {
    public:
        int maxArea(vector<int>& height) {
            int n=height.size();
            int area=0;
            int maxarea=0;
            int height1=0;
            int width=0;
            int left=0,right=n-1;
            while(left<right){
                width=right-left;
                height1=min(height[left],height[right]);
                area=width*height1;
                maxarea=max(area,maxarea);
                if(height[left]<height[right]){
                    left++;
                }
                else{
                    right--;
                }
            }
            // int area=0;
            // int maxarea=0;
            // int height1=0;
            // int width=0;
            // int n=height.size();
            // for(int i=0;i<n;i++){
            //     for (int j=i+1;j<n;j++){
            //         width=j-i;
            //         height1=min(height[i],height[j]);
                    // area=width*height1;
                    // maxarea=max(area,maxarea);
            //     }
            // }
             return maxarea;
        }
    };