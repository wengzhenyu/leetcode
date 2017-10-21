/**
ÌâÄ¿ÃèÊö

Given a binary tree, find its maximum depth.
The maximum depth is the number of nodes along the longest path from the root node down to the farthest leaf node.
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Solution {
public:
    int maxDepth(TreeNode *root) {
        int depth = 0;
        
        getMaxDepth(root, depth, 1);
        return depth;
    }
    
    void getMaxDepth(TreeNode *root, int &depth, int curDepth){
        if(!root){
            return;
        }
        
        if(!root->left && !root->right){
            depth = depth < curDepth ? curDepth: depth;
            return;
        }
        
        getMaxDepth(root->left, depth, curDepth + 1);
        getMaxDepth(root->right, depth, curDepth + 1);
        return;
    }
};