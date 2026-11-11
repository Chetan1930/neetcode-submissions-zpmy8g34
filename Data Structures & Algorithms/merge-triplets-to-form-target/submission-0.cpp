class Solution {
public:
    bool mergeTriplets(vector<vector<int>>& triplets, vector<int>& target) {
        
        unordered_set<int>s;

        for(auto &i:triplets){

            if(i[0]>target[0] || i[1]>target[1] || i[2]>target[2])continue;


            for(int j=0;j<i.size();j++){

                    if(i[j]==target[j]){
                        s.insert(i[j]);
                    }

            }

        }

        return s.size()==3;
    }
};
