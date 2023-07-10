// Problem Link: https://leetcode.com/problems/longest-increasing-subsequence/

// Concepts: Dynamic Programming,Binary Search

// Method 1: Dynamic Programming (Time Complexity: O(N^2))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        vector<int> dp(nums.size(),1);
        int ans=1;
        for(int i=0;i<nums.size();i++){
            for(int j=0;j<i;j++){
                if(nums[i]>nums[j]){
                    dp[i]=max(dp[i],dp[j]+1);
                    ans=max(ans,dp[i]);
                }
            }
        }
        return ans;
    }
};

// Method 2: Binary Search (Time Complexity: O(N*log(N)))
class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        if(nums.size()==1)  return 1;
        vector<int> vals;
        vals.push_back(nums[0]);
        for(int i=1;i<nums.size();i++){
            if(nums[i]>vals[vals.size()-1])
                vals.push_back(nums[i]);
            else{
                int idx = lower_bound(vals.begin(),vals.end(),nums[i])-vals.begin();
                vals[idx]=nums[i];
            }
        }
        return vals.size();
    }
};