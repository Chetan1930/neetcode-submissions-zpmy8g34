class Solution {
public:
    unordered_map<string,int>mp;

    int findProfit(int day,vector<int>& prices,int n, bool buy){
        if(day>=n)return 0;

        string temp = to_string(day);
        temp  +="-";
        temp += to_string(buy);

        if(mp.count(temp))return mp[temp];

        int profit = 0;


        if(buy){
            int b_today = findProfit(day+1,prices,n,false) - prices[day];

            int not_buy = findProfit(day+1,prices,n,true);

            return max({profit,b_today,not_buy});
        }

        else{

            int sell_today = prices[day] + findProfit(day+2,prices,n,true);

            int not_sell = findProfit(day+1,prices,n,false);

            return max({profit,sell_today,not_sell});

        }
        

        return mp[temp] = profit;
    }

    

    int maxProfit(vector<int>& prices) {
        int n=prices.size();
        if(n == 1)return 0;

        return findProfit(0,prices,n,true);

    }
};
