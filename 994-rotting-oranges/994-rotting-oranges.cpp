class Solution {
    
    /*
    doing bfs will give us minimum time took rotten all oranges
    but every time we store current max time 
    */
    
public:
    int orangesRotting(vector<vector<int>>& grid) {
       int n = grid.size() , m = grid[0].size() ; 
       int tm = 0 , fresh = 0 , count = 0 ;
       int vis[n][m];
        
        queue<pair<pair<int,int>,int>>q;
        for(int i = 0 ; i < n ; i++){
            for(int j = 0 ; j < m ; j++){
                if(grid[i][j]==2){
                    q.push({{i,j},0});
                    vis[i][j] = 2 ;
                }else{
                    vis[i][j] = 0 ;
                }
                
                if(grid[i][j]==1) fresh++;
            }
        }
        
        while(!q.empty()){
            int row = q.front().first.first;
            int col = q.front().first.second;
            int time = q.front().second;
            q.pop();
            
            tm = max(time,tm);
            int delrow[] = {0,0,-1,1};
            int delcol[] = {-1,1,0,0};
            
            for(int i = 0 ; i < 4 ; i++){
                int nrow = row+delrow[i];
                int ncol = col+delcol[i];
                
                if(nrow >= 0 && nrow < n && ncol >= 0 && ncol < m && vis[nrow][ncol]!=2 && grid[nrow][ncol]==1){
                    q.push({{nrow,ncol},time+1});
                    vis[nrow][ncol] = 2 ;
                    count++;
                }
            }
            
        }
        
        if(count != fresh) return -1;
        
        return tm;
        
    }
};