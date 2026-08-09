class Solution {
public:

    double helper(double x, long long n) {

        if (n == 0)
            return 1;

        double temp = helper(x, n / 2);

        if (n % 2 == 0)
            return temp * temp;

        return x * temp * temp;
    }

    double myPow(double x, int n) {

        long long N = n;

        if (N < 0) {
            x = 1 / x;
            N = -N;
        }

        return helper(x, N);
    }
};