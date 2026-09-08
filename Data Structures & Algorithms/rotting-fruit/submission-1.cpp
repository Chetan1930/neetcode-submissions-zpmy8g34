class Solution {
public:
    int orangesRotting(vector<vector<int>>& grid) {
        int minute=0;
        queue<pair<int,int>>q;
        int n=grid.size();
        int m= grid[0].size();

        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(grid[i][j]==2)q.push({i,j});
            }
        }

        if(q.empty())return -1;


        while(!q.empty()){
            int num=q.size();

            int possibleMove=0;
            for(int i=0;i<num;i++){
                pair<int,int> temp = q.front();
                q.pop();
                int r=temp.first;
                int c=temp.second;
                // now move in all 4 direction and 
                if(r>0){
                    if(grid[r-1][c]==1){
                        grid[r-1][c]=2;
                        q.push({r-1,c});
                        possibleMove=1;
                    }
                }
                if(r<n-1){
                    if(grid[r+1][c]==1){
                        grid[r+1][c]=2;
                        q.push({r+1,c});
                        possibleMove=1;
                    }
                }
                if(c>0){
                    if(grid[r][c-1]==1){
                        grid[r][c-1]=2;
                        q.push({r,c-1});
                        possibleMove=1;
                    }
                }
                if(c<m-1){
                    if(grid[r][c+1]==1){
                        grid[r][c+1]=2;
                        q.push({r,c+1});
                        possibleMove=1;
                    }
                }
                grid[r][c]=0;
            }
            minute+=possibleMove;
        }
        
        for(auto &i:grid){
            for(auto &j:i){
                if(j==1)return -1;
            }
            cout<<endl;
        }

        if(minute==0)return -1;
        return minute;
    }
};
