class Solution {
public:
    unordered_map<string,int>mp;

    int solve(int amount,vector<int>& coins,int i){
        if(i<0)return 0;
        if(amount==0) {
            return 1;
        }
        string temp = to_string(amount);
        temp+="-";
        temp +=to_string(i);

        if(mp.count(temp))return mp[temp];


        if(amount - coins[i] >=0){
            int take_it =  solve(amount-coins[i],coins,i);
            int dont_take = solve(amount,coins,i-1);

            return mp[temp] = take_it + dont_take;
        }

        else{
            // if we can't this this one , then try with smaller one or another one 

            return mp[temp] = solve(amount,coins,i-1);
        }
    }
    int change(int amount, vector<int>& coins) {
        
        return solve(amount,coins,coins.size()-1);

    }
};
