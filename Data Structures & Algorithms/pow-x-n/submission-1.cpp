class Solution {
public:

    double helper(double x, int n){
         if(n==0)return 1;
        if(n==1)return x;

        if(n%2)return x * myPow(x,n-1);

        else{
            double temp = myPow(x,n/2);
            return temp*temp;
        } 
    }
    double myPow(double x, int n) {
       if(n>=0) return helper(x,n);

       else return 1/helper(x,abs(n));
    }
};
