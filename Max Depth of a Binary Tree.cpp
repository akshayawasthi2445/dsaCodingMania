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
    void findMaxDepth(TreeNode* root,int currCount,int &maxCount){
        if(root==NULL){
            if(currCount>maxCount) maxCount = currCount;
            return;
        }
        findMaxDepth(root->left,currCount+1,maxCount);
        findMaxDepth(root->right,currCount+1,maxCount);
    }
    
    int maxDepth(TreeNode* root) {
        int maxCount = 0;
        findMaxDepth(root,0,maxCount);
        return maxCount;
    }
};