class Solution {
public:
    int leastInterval(vector<char>& tasks, int n) {
        vector<int>v(26,0);
        priority_queue<int>pq;
        
        for(auto &i:tasks){
            v[i-'A']++;
        }

        for(auto &i:v){
            if(i>0)pq.push(i);
        }

        int time=0;
        while(!pq.empty()){
            vector<int>temp;

            for(int i=0;i<n+1;i++){

                if(!pq.empty()){
                    int freq=pq.top();
                    pq.pop();
                    freq--;

                    temp.push_back(freq);
                }
            }

            for(int i=0;i<temp.size();i++){
                if(temp[i]>0)pq.push(temp[i]);
            }

            if(!pq.empty()){
                time+= (n+1);
            }
            else {
                time+=temp.size();
            }
        }


        return time;

        

    }
};
