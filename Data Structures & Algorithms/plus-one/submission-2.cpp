class Solution {
public:
    vector<int> plusOne(vector<int>& digits) {
        int carry=0;
        int n=digits.size();
        int lastdigit=digits[n-1];
        lastdigit +=1;

        digits[n-1]=lastdigit%10;
        carry=lastdigit/10;

        for(int i=digits.size()-2;i>=0;i--){
            int temp=digits[i] + carry ; 
            digits[i] = temp %10 ;
            carry = temp/10;
        }

        if(carry)digits.insert(digits.begin(),carry);

        return digits;
    }
};
