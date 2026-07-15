class MinStack {
public:
    vector<pair<int,int>>st;
    int t=-1;

    MinStack() {
        
    }
    
    void push(int val) {
        if(t==-1){
            st.push_back({val,val});
            t++;
        }
        else{
            int temp=st[t].second;
            temp=min(temp,val);
            st.push_back({val,temp});
            t++;
        }
    }
    
    void pop() {
        if(t==-1) return ;
        st.pop_back();
        t--;
    }
    
    int top() {
        return st[t].first;
        
    }
    
    int getMin() {
        return st[t].second;
    }
};
