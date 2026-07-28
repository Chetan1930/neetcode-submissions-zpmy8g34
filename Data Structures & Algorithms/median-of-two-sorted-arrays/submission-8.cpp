class Solution {
public:
    double findMedianSortedArrays(vector<int>& nums1, vector<int>& nums2) {
        vector<int>&A = nums1;
        vector<int>&B = nums2;

        if(A.size()>B.size()){
            swap(A,B);
        }

        int n=A.size(),m=B.size();
        int half = (n+m+1)/2;


        int l=0,r=A.size();

        while(l<=r){
            int i=(r-l)/2 + l;
            int j=half-i;

            double Aleft =INT_MIN;
            if(i>0){
                Aleft = A[i-1];
            }


            double Aright =INT_MAX;
            if(i<A.size()){
                Aright = A[i];
            }
            
            double Bleft =INT_MIN;
            if(j>0){
                Bleft = B[j-1];
            }

            double Bright =INT_MAX;
            if(j<B.size()){
               Bright = B[j];
            }


            if(Aleft <= Bright && Bleft<=Aright){
                if( (m+n) % 2){
                    return max(Aleft,Bleft);
                }
                else{
                    return (max(Aleft,Bleft) + min(Aright,Bright))/2.0;
                }

            }


            else if(Aleft > Bright ){
                r=i-1;
            }


            else l=i+1;
        }


        return -1.0;
    }
};
