class Solution {
public:
    vector<int> pse(vector<int>&v){
        stack<int>st;
        int n=v.size();
        vector<int>res(n,-1);

        for(int i=0;i<n;i++){

            while(!st.empty() && v[st.top()]>v[i]){
                st.pop();

            }
            if(!st.empty())res[i]=st.top();
            st.push(i);

        }

        return res;
    }

     vector<int> nse(vector<int>&v){
        stack<int>st;
        int n=v.size();
        vector<int>res(n,n);

        for(int i=n-1;i>=0;i--){

            while(!st.empty() && v[st.top()]>=v[i]){
                st.pop();
            }
            if(!st.empty())res[i]=st.top();
            st.push(i);

        }

        return res;
    }
    int largestRectangleArea(vector<int>& heights) {
        int maxArea=0;

        vector<int>p1 = pse(heights);
        vector<int>n1 = nse(heights);


        for(auto &i:p1)cout<<i<<" ";
        cout<<endl;
        for(auto &i:n1)cout<<i<<" ";
        cout<<endl;

        for(int i=0;i<heights.size();i++){
            maxArea = max(maxArea, ((n1[i]-p1[i]-1) * heights[i]));
        }


        return maxArea;


    }
};
