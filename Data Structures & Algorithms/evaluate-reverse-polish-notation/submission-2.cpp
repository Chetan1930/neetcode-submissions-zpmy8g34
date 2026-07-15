class Solution {
public:
    int evalRPN(vector<string>& tokens) {
        
        int res=0;
        stack<string>st;

        for(auto &i:tokens){

            if(i=="+" || i=="-" || i=="*" || i=="/" ){    
                int second=stoi(st.top());
                st.pop();
                int first=stoi(st.top());
                st.pop();
                if(i=="+")res=first+second;
                else if(i=="-")res = first - second;
                else if(i=="*")res = first * second;
                else res=first/second;

                string ans= to_string(res);
                st.push(ans);
                
            }
            else{
                st.push(i);
            }
        }

        return stoi(st.top());
    }
};
