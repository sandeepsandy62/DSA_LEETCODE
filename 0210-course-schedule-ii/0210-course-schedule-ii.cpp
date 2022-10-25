class Solution {
    private :
    
    bool dfs(int source , stack<int>&st , vector<bool>&visited ,vector<int>adj[],vector<bool>&onStack){
        visited[source] = true;
        onStack[source] = true;
        for(int neighbour: adj[source]) {
        if(visited[neighbour] && onStack[neighbour]) {
            return true;
        } else if(!visited[neighbour] && dfs(neighbour,st,visited,adj,onStack)) {
            return true;
        }
    }
    onStack[source] = false;
    st.push(source);
    return false;
        
    }
    
    void topoSort(vector<int>adj[] , int V , vector<int>&ans){
        stack<int>st;
        vector<bool>visited(V,false);
        vector<bool>onStack(V,false);
        
        for(int u = 0 ; u < V ; u++){
            if(!visited[u])
                if(dfs(u,st,visited,adj,onStack)){
                    ans.clear();
                    while(!st.empty()) st.pop();
                    break;
                }
        }
        
        while(!st.empty()){
            ans.push_back(st.top());
            st.pop();
        }
        
    }
public:
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        /*
        idea is to return the topo sort of the courses 
        */
        
        vector<int>adj[numCourses];
        for(int i = 0 ; i < prerequisites.size() ; i++){
            adj[prerequisites[i][1]].push_back(prerequisites[i][0]);
        }
        
        vector<int>ans;
        topoSort(adj,numCourses,ans);
        return ans;
    }
};