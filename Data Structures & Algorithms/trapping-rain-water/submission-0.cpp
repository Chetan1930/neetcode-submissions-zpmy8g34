class Solution {
public:
    int trap(vector<int>& h) {
        int n=h.size();
        vector<int>left(n,0);
        vector<int>right(n,0);
        vector<int>res(n,0);

        int temp=0;
        for(int i=0;i<n;i++){
            temp=max(h[i],temp);
            left[i]=temp;
        }

        temp=0;
        for(int i=h.size()-1;i>=0;i--){
            temp=max(h[i],temp);
            right[i]=temp;
        }


        for(int i=0;i<n;i++){
            res[i]=min(left[i],right[i])-h[i];
        }


        return accumulate(res.begin(),res.end(),0);

    }
};
