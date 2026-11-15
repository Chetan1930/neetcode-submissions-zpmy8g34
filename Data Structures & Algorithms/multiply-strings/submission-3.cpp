class Solution {
public:
    string rev(string &s,int n){
        string ans="";
        
        for(int i=0;i<n;i++){
            ans = s[i]+ans;
        }

        return ans;
    }
    string add(string num1, string num2) {
        int i = num1.size() - 1, j = num2.size() - 1, carry = 0;
        num1=rev(num1,num1.size());
        num2=rev(num2,num2.size());
        string res;

        while (i >= 0 || j >= 0 || carry) {
            int n1 = (i >= 0) ? num1[i] - '0' : 0;
            int n2 = (j >= 0) ? num2[j] - '0' : 0;
            int total = n1 + n2 + carry;
            res.push_back((total % 10) + '0');
            carry = total / 10;
            i--;
            j--;
        }
        return res;
    }

    string multiply(string num1, string num2) {
        if(num1=="0" || num2=="0")return "0";
        int n1=num1.size(),n2=num2.size();
        if(n1==0 || n2==0)return "0";

        string s1 = rev(num1,n1);
        string s2 = rev(num2,n2);
        string ans="";
        for(int i=0;i<n1;i++){
            int carry=0;
            string prod ="";
            for(int k=0;k<i;k++)prod+="0";

            for(int j=0;j<n2;j++){
                int t1 = s1[i] - '0';
                int t2 = s2[j] - '0';
                int temp = t1*t2;
                temp+=carry;
                carry = temp/10;
                prod = prod + to_string(temp%10 ) ;
            }
            if(carry)prod +=to_string(carry);
            ans = add(ans,prod);
            
        }

        ans = rev(ans,ans.size());
        return ans;
    }
};
