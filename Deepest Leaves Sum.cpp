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
    
    void calculateDeepestSum(TreeNode* root, int currLevel,int& maxLevel, int& deepestSum){
        if(root==NULL) return;
        
        if(currLevel>maxLevel){
            maxLevel = currLevel;
            deepestSum = root->val; //7
        }
        
        else if(currLevel == maxLevel){
            deepestSum+= root->val;
        }
        
        calculateDeepestSum(root->left,currLevel+1,maxLevel,deepestSum);
        calculateDeepestSum(root->right,currLevel+1,maxLevel,deepestSum);
    }
    
    int deepestLeavesSum(TreeNode* root) {
        int currLevel = 0;
        int maxLevel = -1;
        int deepestSum = 0;
        
        calculateDeepestSum(root,currLevel,maxLevel,deepestSum);
        
        return deepestSum;
    }
};