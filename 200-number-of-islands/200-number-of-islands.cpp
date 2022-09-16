class Solution {
    private:
    void dfs(int row , int col , vector<vector<char>>&grid , vector<vector<int>>&vis){
        int n = grid.size();
        int m = grid[0].size();
        vis[row][col] = 1 ;
        int delrow[] = {0,0,-1,1};
        int delcol[] = {-1,1,0,0};
        for(int i = 0 ; i < 4 ; i++){
            if(row+delrow[i] >= 0  && row+delrow[i] < n && col+delcol[i] >= 0 && col+delcol[i] < m
              && !vis[row+delrow[i]][col+delcol[i]] && grid[row+delrow[i]][col+delcol[i]]=='1')
                dfs(row+delrow[i],col+delcol[i],grid,vis);
        }
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        int n = grid.size();
        int m = grid[0].size();
        vector<vector<int>>vis(n,vector<int>(m,0));
        int islands = 0 ;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]=='1' && !vis[i][j]){
                dfs(i,j,grid,vis); 
                    islands++;
                }
            }
        }
        return islands;
    }
};