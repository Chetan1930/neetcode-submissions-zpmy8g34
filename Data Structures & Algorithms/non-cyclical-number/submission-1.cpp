class Solution {
public:
    int sq(int n){
        int ans=0;

        while(n>0){
            int temp = n%10;
            n=n/10;
            ans += temp*temp;
        }

        return ans;
    }

    bool solve(int n,unordered_map<int,int>&mp){
        if(n==1)return true;
        if(mp.count(n))return false;
        mp[n]++;
        int temp=sq(n);
        return solve(temp,mp);
    }
    bool isHappy(int n) {
        unordered_map<int,int>mp;

        return solve(n,mp);
    }
};
