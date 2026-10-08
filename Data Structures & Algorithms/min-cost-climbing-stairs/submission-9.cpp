class Solution {
public:
    int helper(vector<int>&dp, vector<int>& cost,int i){
        if(i>=cost.size()) return 0;
        if(dp[i]!=-1)return dp[i];
        return dp[i] = cost[i] + min(helper(dp,cost,i+1),helper(dp,cost,i+2));
    }
    int minCostClimbingStairs(vector<int>& cost) {
        vector<int>dp(cost.size(),-1);
        return min(helper(dp,cost,0),helper(dp,cost,1));

    }
};
