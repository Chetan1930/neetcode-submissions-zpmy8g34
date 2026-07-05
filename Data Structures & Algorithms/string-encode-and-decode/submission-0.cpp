class Solution {
public:

    string encode(vector<string>& strs) {
        string encoded="";
        for(auto  &i:strs){
            encoded+=i;
            encoded+="-";
        }
        return encoded;
    }

    vector<string> decode(string s) {
        vector<string>decoded;

        string word="";
        for(auto &i:s){
            if(i=='-'){
                decoded.push_back(word);
                word="";
            }
            else word+=i;            
        }

        return decoded;
    }
};
