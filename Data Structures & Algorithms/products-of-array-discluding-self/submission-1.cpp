class Solution {
public:
    vector<int> productExceptSelf(vector<int>& nums) {
        vector<int>output;
        int totalzero=0;
        int totalpro=1;

        for(auto &i:nums){
            if(i==0){
                totalzero++;
            }
            else{
                totalpro*=i;

            }
        }

        //case 1: if no zero is there
        if(totalzero==0){
            for(auto &i:nums){
                output.push_back(totalpro/i);
            }
        }


        // case 2 : if only 1 zero is there

        else if(totalzero==1){
            for(auto &i:nums){
                if(i==0){
                    output.push_back(totalpro);
                }
                else{
                    output.push_back(0);
                }
            }
        }

        // case 3: if more than 1 zero is there

        else{
            for(auto &i:nums){
                output.push_back(0);
            }
        }

        return output;
    }
};