class Solution {
public:
    int solve(int amount,vector<int>& coins,int i){
        if(i<0)return 0;
        if(amount==0) {
            return 1;
        }

        if(amount - coins[i] >=0){
            int take_it =  solve(amount-coins[i],coins,i);
            int dont_take = solve(amount,coins,i-1);

            return take_it + dont_take;
        }

        else{
            // if we can't this this one , then try with smaller one or another one 

            return solve(amount,coins,i-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        
        return solve(amount,coins,coins.size()-1);

    }
};
