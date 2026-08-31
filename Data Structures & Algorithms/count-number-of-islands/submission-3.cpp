class Solution {
public:
    void dfs(vector<vector<char>>& grid, int i, int j){
        int n=grid.size();
        int m=grid[0].size();
        if(i>=n || j>=m || i<0 || j<0)return ;
        if(grid[i][j]=='0')return ;

        grid[i][j]='0';

        // go left 
        dfs(grid,i,j-1);
        //go right 
         dfs(grid,i,j+1);
        // go up 
        dfs(grid,i-1,j);
        //go down 
         dfs(grid,i+1,j);

    }
    int numIslands(vector<vector<char>>& grid) {
        int n=grid.size();
        int m=grid[0].size();

        int ans=0;

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]=='1'){
                    ans++;
                    dfs(grid,i,j);
                }
            }
        }

        return ans;
    }
};
