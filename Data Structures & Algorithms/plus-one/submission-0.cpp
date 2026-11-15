class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        
        int number = 0;
        for(auto &i:digits){
            number=number*10;
            number+=i;
        }
        number+=1;

        vector<int>res;

        while(number>0){
            int temp=number%10;
            number/=10;
            res.push_back(temp);;
        }


        reverse(res.begin(),res.end());

        return res;

    }
};
