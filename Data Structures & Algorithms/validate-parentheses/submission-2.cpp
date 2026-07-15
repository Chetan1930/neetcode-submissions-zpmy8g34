class Solution {
public:
    bool isValid(string st) {
        stack<char>s;

        for(char &i:st){

            if(i==']' || i=='}' || i==')'){

                if(!s.empty()){
                    char temp=s.top();
                    s.pop();
                    if(i==']' && temp=='[')continue;
                    else if(i=='}' && temp=='{')continue;
                    else if(i==')' && temp=='(')continue;
                    // else return false;
                }
                else return false;
            }

            else s.push(i);
            
        }


        return s.empty();


    
    }
};
