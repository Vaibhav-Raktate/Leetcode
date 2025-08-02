class Solution {
public:
    int countSymmetricIntegers(int low, int high) {
        int count =0;
        for(int num = low; num<= high;num++){
            if(num>=10 && num <=99 && num%11 == 0){
                count ++;
            } else if(num >=1000 && num <=9999){
                int first = num/1000;
                int second = (num/100)%10;

                int third = (num/10)%10;
                int fourth = (num)%10;

                if(first+second == third+fourth){
                    count++;
                }
            }
        }
        return count;




        // int count = 0;
        // for(int i=low; i<=high;i++){
        //     string s = to_string(i);
        //     int l= s.length();

        //     if(l%2 != 0)  continue;

        //     int lsum = 0;
        //     int rsum = 0;

        //     for(int i=0; i<l/2;i++){
        //         lsum += s[i] - '0';
        //     }

        //     for(int i=l/2; i<l;i++){
        //         rsum += s[i] - '0';
        //     }

        //     if(lsum == rsum){
        //         count++ ;
        //     }
        // }
        // return count;
    }
};
