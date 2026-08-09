class Solution {
public:

    double helper(double x, int n){
         if(n==0)return 1;
        if(n==1)return x;

        if(n%2)return x * myPow(x,n-1);

        else return myPow(x,n/2)*myPow(x,n/2);
    }
    double myPow(double x, int n) {
       if(n>=0) return helper(x,n);

       else return 1/helper(x,abs(n));
    }
};
