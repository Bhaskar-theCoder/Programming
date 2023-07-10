// Problem Link: https://leetcode.com/problems/maximize-the-confusion-of-an-exam/

// Concepts: Sliding Window

class Solution {
public:
    int maxConsecutiveAnswers(string answerKey, int k) {
        int i=0,j=0,maxi=0;
        unordered_map<char,int> mp;

        while(j<answerKey.length()){
            char ch=answerKey[j];
            mp[ch]++;
            maxi=max(maxi,mp[ch]);
            if(j-i+1>maxi+k){
                mp[answerKey[i]]--;
                i++;
            }
            j++;
        }
        return answerKey.length()-i;
    }
};