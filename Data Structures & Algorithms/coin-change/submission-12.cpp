class Solution {
public:
    unordered_map<int,int>dp;

    int dfs(vector<int>& coins, int amount) {
        if (amount == 0) return 0;
        if(dp.count(amount))return dp[amount];
        int res = 1e9;
        for (int coin : coins) {
            if (amount - coin >= 0) {
                res = min(res,
                      1 + dfs(coins, amount - coin));
            }
        }
        dp[amount]=res;
        return res;
    }

    int coinChange(vector<int>& coins, int amount) {
        int minCoins = dfs(coins, amount);
        return (minCoins >= 1e9) ? -1 : minCoins;
    }
};