class Solution {
public:
    int maxProfit(vector<int>& prices) {
        int maxp=0;

        int buy=prices[0];

        for(auto &i:prices){
            if(i<buy)buy=i;
            else{
                maxp=max(maxp,i-buy);
            }
        }


        return maxp;
    }
};
