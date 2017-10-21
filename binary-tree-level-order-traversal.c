/**
ÌâÄ¿ÃèÊö

Given a binary tree, return the level order traversal of its nodes' values. (ie, from left to right, level by level).
For example:
Given binary tree{3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its level order traversal as:
[
  [3],
  [9,20],
  [15,7]
]

confused what"{1,#,2,3}"means? > read more on how binary tree is serialized on OJ.

OJ's Binary Tree Serialization:
The serialization of a binary tree follows a level order traversal, where '#' signifies a path terminator where no node exists below.
Here's an example:
   1
  / \
 2   3
    /
   4
    \
     5
The above binary tree is serialized as"{1,2,3,#,#,4,#,#,5}".
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
    vector<vector<int> > levelOrder(TreeNode *root) {
        vector<int>  valVector;
        vector<vector<int> > newVector;
        queue<TreeNode *> qTreeNode;
        TreeNode *p;
        int qSize = 0;
        
        if(!root){
            return newVector;
        }
        qTreeNode.push(root);
        
        while(1){
            if(qTreeNode.empty()){
                break;
            }
            
        	qSize = qTreeNode.size();
            valVector.clear();
            while(qSize--){
                p = qTreeNode.front();
                qTreeNode.pop();
                if(p->left){
                    qTreeNode.push(p->left);
                }
                if(p->right){
                    qTreeNode.push(p->right);
                }
                valVector.push_back(p->val);
            }
            newVector.push_back(valVector);
        }
        return newVector;
    }
};