//{ Driver Code Starts
#include<bits/stdc++.h>
using namespace std;

// } Driver Code Ends
class Solution 
{
    public:
    //Function to find out minimum steps Knight needs to reach target position.
    bool valid(int row , int col , int drow , int dcol , int N ){
        if(row+drow >= 0 && row+drow <= N && col+dcol >= 0 && col+dcol <= N){
            return true;
        }
        return false;
    }
	int minStepToReachTarget(vector<int>&KnightPos,vector<int>&TargetPos,int N)
	{
	    // Code here
	    vector<vector<int>>vis(N+1,vector<int>(N+1,0));
	    queue<pair<int,pair<int,int>>>q;
	    int r = KnightPos[0] , c = KnightPos[1] ;
	    q.push({0,{r,c}});
	    
	    int drow[] =  { -2, -1, 1, 2, -2, -1, 1, 2 };
	    int dcol[] = { -1, -2, -2, -1, 1, 2, 2, 1 };
	    
	    vis[r][c] = 1;
	    int steps ;
	    while(!q.empty()){
	        auto node = q.front();
	        q.pop();
	        
	        int row = node.second.first;
	        int col = node.second.second;
	        steps = node.first;
	        
	        if(row == TargetPos[0] && col == TargetPos[1]){
	            return steps;
	        }
	        
	        for(int i = 0 ; i < 8 ; i++){
	            if(valid(row,col,drow[i],dcol[i],N) && vis[row+drow[i]][col+dcol[i]]==0){
	                vis[row+drow[i]][col+dcol[i]] = 1 ;
	                q.push({steps+1,{row+drow[i],col+dcol[i]}});
	            }
	        }
	    }
	    return -1;
	}
};

//{ Driver Code Starts.
int main(){
	int tc;
	cin >> tc;
	while(tc--){
		vector<int>KnightPos(2);
		vector<int>TargetPos(2);
		int N;
		cin >> N;
		cin >> KnightPos[0] >> KnightPos[1];
		cin >> TargetPos[0] >> TargetPos[1];
		Solution obj;
		int ans = obj.minStepToReachTarget(KnightPos, TargetPos, N);
		cout << ans <<"\n";
	}
	return 0;
}
// } Driver Code Ends