// Problem Link: https://leetcode.com/problems/minimum-size-subarray-sum/

// Concepts: Sliding Window

class Solution {
public:
    int minSubArrayLen(int target, vector<int>& nums) {
        int sum=0,i=0,j=0,ans=INT_MAX;
        while(i<nums.size()){
            if(sum>=target){
                ans=min(ans,j-i);
                sum-=nums[i];
                i++;
            }
            else{
                if(j>=nums.size())  break;
                sum+=nums[j]; 
                j++;
            }
        }
        if(ans==INT_MAX)    return 0;
        return ans;
    }
};