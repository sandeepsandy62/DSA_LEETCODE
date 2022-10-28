/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode() : val(0), left(nullptr), right(nullptr) {}
 *     TreeNode(int x) : val(x), left(nullptr), right(nullptr) {}
 *     TreeNode(int x, TreeNode *left, TreeNode *right) : val(x), left(left), right(right) {}
 * };
 */
class Solution {
public:
    
    void dfs(TreeNode* node , int curMax , int &count){
        if(!node) return ;
        
        if(node->val >= curMax){
            count++;
            curMax = node->val;
        }
        dfs(node->left,curMax,count);
        dfs(node->right,curMax,count);
    }
    
    int goodNodes(TreeNode* root) {
        int count = 0 ;
        if(root!=NULL)
        dfs(root , root->val,count);
        return count;
    }
};