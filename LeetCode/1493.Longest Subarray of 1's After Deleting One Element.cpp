// Problem Link: https://leetcode.com/problems/longest-subarray-of-1s-after-deleting-one-element/

class Solution {
public:
    int longestSubarray(vector<int>& nums) {
        
        int zero=0,i=0,j=0,ans=-1;
        while(j<nums.size()){
            if(nums[j]==0)  zero++;
            while(zero>1){
                if(nums[i]==0)  zero--;
                i++;
            }
            ans=max(ans,j-i+1);
            j++;
        }
        return ans-1;
    }
};