class Solution {
public:
    void dfs(vector<vector<int>>&grid , int r, int c,int &i){
        int n=grid.size();
        int m=grid[0].size();
        if(r>=n || c>=m || r<0 || c<0) return ;
        if(grid[r][c]==0)return ;
        grid[r][c] = 0;
        i++;
        

        dfs(grid,r+1,c,i);
        dfs(grid,r,c+1,i);
         dfs(grid,r,c-1,i);
         dfs(grid,r-1,c,i);

        
    }
    int maxAreaOfIsland(vector<vector<int>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]){
                    int temp=0;
                    dfs(grid,i,j,temp);
                    ans=max(ans,temp);
                }
            }
        }

        return ans;

    }
};
