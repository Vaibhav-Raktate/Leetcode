class Solution {
public:

    bool isvowel(char ch){
        if(ch=='a'|| ch=='e'|| ch=='i'|| ch=='o'|| ch=='u') return true;
        return false;
    }

    int maxFreqSum(string s) {
        int n = s.length();
        unordered_map<char,int>freq;
        for(auto ch : s) freq[ch]++;
        int vowel=0, consonant=0;
        for(auto ch:freq){
            if(isvowel(ch.first)) vowel =max(vowel,ch.second);
            else consonant = max(consonant , ch.second);
        }
        return vowel+consonant;
    }
};
