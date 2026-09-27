class Solution {
public:
    int climbStairs(int n) {
        if(n==1 || n==2)return n;
        int second = 1;
        int first = 2;

        for(int i=3;i<=n;i++){
            int temp = second + first;
            second = first;
            first = temp;

            if(i==n)return temp;
        }

        return -1;
        
    }
};
