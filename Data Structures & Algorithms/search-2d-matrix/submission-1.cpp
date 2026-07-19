class Solution {
public: 

    bool bins(vector<int>&v,int target){
        int s=0;
        int e=v.size()-1;

        while(s<=e){
            int mid= (e-s)/2 + s; 


            if(v[mid]==target)return true;
            else if(v[mid]<target)s=mid+1;
            else e=mid-1;
        }

        return false;
    }

    bool searchMatrix(vector<vector<int>>& matrix, int target) {
        
        int n=matrix.size();
        int m=matrix[0].size();

        int s=0,e=n-1;
        int mid =0;
        while(s<=e){
            mid= (e-s)/2 + s; 

            if(matrix[mid][0]==target)return true;
            else if((matrix[mid][m-1])<target)s=mid+1;
            else if(matrix[mid][0]>target)e=mid-1;
            else break;
        }

        return bins(matrix[mid],target);
    }
};
