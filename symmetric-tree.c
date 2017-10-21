/**
Given a binary tree, check whether it is a mirror of itself (ie, symmetric around its center).
For example, this binary tree is symmetric:
    1
   / \
  2   2
 / \ / \
3  4 4  3

But the following is not:
    1
   / \
  2   2
   \   \
   3    3

Note: 
Bonus points if you could solve it both recursively and iteratively.
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
    bool isSymmetric(TreeNode *root) {
        bool result = true;
        if(!root){
            return true;
        }
        
        //exchangeChildVal(root->left);
        result = compare(root->left, root->right);
        //exchangeChildVal(root->left);
        return result;
    }
    /* 可以不用交换左子树的值，抽象出比较规则
     void exchangeChildVal(TreeNode *root){
         TreeNode *p = NULL;
         if(!root){
             return;
         }
         p = root->left;
         root->left = root->right;
         root->right = p;
         exchangeChildVal(root->left);
         exchangeChildVal(root->right);
         return;
     }
    */
    bool compare(TreeNode *p, TreeNode *q){
        if(!p && !q){
            return true;
        }
        
        if((!p && q || p && !q) || (p->val != q->val)){
            return false;
        }
        
        //if(compare(p->left, q->left) && compare(p->right, q->right)){
        if(compare(p->left, q->right) && compare(p->right, q->left)){
            return true;
        }else{
            return false;
        }
    }
};