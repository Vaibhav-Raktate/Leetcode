class Solution {
    public int totalNumbers(int[] digits) {
        int n = digits.length;
        HashSet<Integer> hs = new HashSet<>();
        for(int i=0; i<n; i++){
            for(int j=0; j<n; j++){
                for(int k=0; k<n; k++){
                    if(i==j || j==k || k==i || digits[i]==0) continue;
                    int digit = digits[i]*100 + digits[j]*10 + digits[k];
                    if(digit%2 !=0) continue;
                    hs.add(digit);
                }
            }
        }
        return hs.size();
    }
}
