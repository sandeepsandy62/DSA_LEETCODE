class Solution {
    private : 
    
    bool topoCycleDetect(vector<int>adj[] , int V){
        
        vector<int>in_degree(V,0);
        
        for(int u = 0 ; u < V ; u++){
            for(int x : adj[u]){
                in_degree[x]++;
            }
        }
        
        queue<int>q;
        for(int i = 0 ; i < V ; i++){
            if(in_degree[i] == 0){
                q.push(i);
            }
        }
        
        int count = 0 ;
        while(!q.empty()){
            int u = q.front();
            q.pop();
            
            for(int x : adj[u]){
                if(--in_degree[x] == 0){
                    q.push(x);
                }
            }
            count++;
        }
        
        if(count!=V){
            return true;
        }
        
        return false;
    }
    
    
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        
        /*
        Idea is , this problem is similar to finding a cycle using topological sort
        if we find any cycle then return FALSE
        else return TRUE
        */
        
        vector<int>adj[numCourses];
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        if(topoCycleDetect(adj,numCourses)) return false;
        
        return true;
    }
};