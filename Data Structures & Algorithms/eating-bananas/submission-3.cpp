class Solution {
public:

    int valid(vector<int>&piles,int r){

        int res=0;
        for(int i=0;i<piles.size();i++){
            res+= piles[i]/r;
            if((piles[i]%r)!=0)res++;
        }

        return res;
    }
    

    int minEatingSpeed(vector<int>& piles, int h) {
        // int n=piles.size();
        int start=*min_element(piles.begin(),piles.end());
        int end=*max_element(piles.begin(),piles.end());

        int ans=0;
        while(start<=end){
            int mid = (end - start)/2 + start;

            int hr = valid(piles,mid);

            if(hr<=h){
                ans=max(ans,mid);
                end=mid-1;
            }
            else start=mid+1;

        }

        return ans;
    }
};
