class Solution {
public:
    // bool check(int num){
    //     while(num){
    //         if(num%10==0){
    //             return false;
    //         }
    //         num/=10;
    //     }
    //     return true;
    // }

    vector<int> getNoZeroIntegers(int n) {
        int a=n;
        int b=0;
        int placevalue = 1;

        while(n>1){
            int take = 1;

            if(n%10 == 1){
                take = 2;
            }

            a = a-take*placevalue;
            b = b+take*placevalue;

            n = (n-take)/10;
            placevalue *=10;
            
        }

        // for(int a=1;a<=n-1; a++){
        //     int b = n-a;

        //     if(check(a)&& check(b)){
        //         return{a,b};
        //     }
        // }
        // return {};
        return{a,b};
    }
};
