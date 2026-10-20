class Solution {
public:

    int solve(vector<int>& coins, int amount,int i){
        if(i<0)return 10000000;
        if(amount==0)return 0;

        if(amount - coins[i] >=0) {
            return min(solve(coins,amount,i-1), 1 + solve(coins,amount-coins[i],i));
        }
        else return solve(coins,amount,i-1);
    }
    int coinChange(vector<int>& coins, int amount) {
        int ans = solve(coins,amount,coins.size()-1);

        if(ans>=10000000)return -1;
        else return ans;
        
    }
};
