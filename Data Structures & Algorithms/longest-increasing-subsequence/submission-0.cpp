class Solution {
public:
    int lengthOfLIS(vector<int>& nums) {
        stack<int>s;
        int ans =0;
        int n=0;
        for(int &i:nums){
                while(!s.empty() && s.top()>=i){
                    s.pop();
                    n--;
                }
                s.push(i);  
                n++;         

            ans = max(ans,n);
        }

        return ans;
    }
};
