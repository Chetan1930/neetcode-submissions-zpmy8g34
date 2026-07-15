class Solution {
public:
    bool isValid(string st) {
        stack<char>s;

        for(char &i:st){

            if(i==']' || i=='}' || i==')'){
                if(s.empty())return false;

                while(!s.empty()){
                    char temp=s.top();
                    s.pop();
                    if(i==']' && temp=='[')break;
                    else if(i=='}' && temp=='{')break;
                    else if(i==')' && temp=='(')break;
                    else return false;
                }
            }

            else s.push(i);
            
        }


        return s.empty();


    
    }
};
