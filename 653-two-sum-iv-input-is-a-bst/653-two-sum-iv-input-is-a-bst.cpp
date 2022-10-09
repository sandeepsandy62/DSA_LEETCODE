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
    
    /*
    5 - 0
    3 - 0
    6 - 0
    2 - 0
    4 - 0
    7 - 0
    
    incrementing value is usefull for searching complimented value of given target
    if the value is eg : 3 - 1
    then we will return true
    
    That's the Idea :)
    */
    
    unordered_map<int,int>mp = {} ;
    bool findTarget(TreeNode* root, int k) {
       if(!root) return false;
       if(mp[root->val]) return true;
       mp[k-root->val]++;
       return (findTarget(root->left,k)||findTarget(root->right,k));
    }
};