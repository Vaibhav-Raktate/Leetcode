class Solution {
public:
    int maximum69Number (int num) {
        int placevalue = 0;
        int placevaluesix = -1;

        int temp = num;
        while(temp > 0){
            int remain = temp%10;

            if (remain == 6){
                placevaluesix = placevalue;
            }
            temp = temp/10;
            placevalue++;
        }
        if(placevaluesix == -1) return num;

        return num + 3*pow(10,placevaluesix);
    }
};
