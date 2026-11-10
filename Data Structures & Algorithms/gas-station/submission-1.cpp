class Solution {
public:
    int canCompleteCircuit(vector<int>& gas, vector<int>& cost) {
        int total_gas = accumulate(gas.begin(),gas.end(),0);

        int cost_t= accumulate(cost.begin(),cost.end(),0);

        if(cost_t>total_gas)return -1;

        int result =0;
        int total=0;

        for(int i=0;i<gas.size();i++){
            total    +=gas[i] - cost[i];

            if(total<0){
                total =0;
                result = i+1;
            }
        }

        return result;
    }
};
