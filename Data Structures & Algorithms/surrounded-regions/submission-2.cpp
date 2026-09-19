class Solution {
public:
    int n,m;
    void dfs(vector<vector<char>>& board,int r,int c){
        if(r>=n || c>=m || r<0 || c<0)return ;
        if(board[r][c]=='S' || board[r][c]=='X')return ;
        board[r][c]='S';

        dfs(board,r-1,c);
        dfs(board,r+1,c);
        dfs(board,r,c+1);
        dfs(board,r,c-1);
    }
    void solve(vector<vector<char>>& board) {
        n=board.size();
        m=board[0].size();
       
       for(int i=0;i<n;i++){
        if(board[i][0]=='O')dfs(board,i,0);

        if(board[i][m-1]=='O')dfs(board,i,m-1);
       }

       for(int i=0;i<m;i++){
        if(board[0][i]=='O')dfs(board,0,i);

        if(board[n-1][i]=='O')dfs(board,n-1,i);
       }


        for(int i=0;i<n;i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O'){
                    board[i][j]='X';
                }
                else if( board[i][j] == 'S')board[i][j]='O';
            }
        }        
    }
};
