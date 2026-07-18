class Solution {
public:
    int carFleet(int target, vector<int>& position, vector<int>& speed) {
        stack<int>st;
        
        vector<pair<int,int>>pos;

        for(int i=0;i<speed.size();i++){
            pos.push_back({position[i],speed[i]});
        }

        sort(pos.begin(),pos.end());

        for(int i=0;i<pos.size();i++){

            int temp = target - pos[i].first;
            temp = temp/pos[i].second;


            while(!st.empty() && st.top()<=temp){
                st.pop();
            }
            st.push(temp);
        }

        return st.size();
    }
};
