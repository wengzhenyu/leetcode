/**
ÌâÄ¿ÃèÊö

Given a binary tree, return the zigzag level order traversal of its nodes' values. (ie, from left to right, then right to left for the next level and alternate between).
For example:
Given binary tree{3,9,20,#,#,15,7},
    3
   / \
  9  20
    /  \
   15   7

return its zigzag level order traversal as:
[
  [3],
  [20,9],
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
    vector<vector<int> > zigzagLevelOrder(TreeNode *root) {
        int count, ii, dir, tmp;
        TreeNode *p;
        queue<TreeNode *> q;
        vector<int> valVector;
        vector<vector<int> > newVector;
        
        if(!root){
            return newVector;
        }
        
        q.push(root);
        count = 1;
        tmp   = 0;
        dir   = 0;
        
        while(1){
            if(q.empty()){
                break;
            }
            
            valVector.clear();
            for(ii = 0; ii < count; ii++){
                p = q.front();
            	q.pop();
                if(0 == dir){
                    valVector.push_back(p->val);
                }else{
                    valVector.insert(valVector.begin(), p->val);
                }
                
                if(p->left){
                    q.push(p->left);
                    tmp++;
                }
                if(p->right){
                    q.push(p->right);
                    tmp++;
                }
            }
            
            newVector.push_back(valVector);
            count = tmp;
            tmp   = 0;
            dir   = ~dir;
        }
        return newVector;
    }
};