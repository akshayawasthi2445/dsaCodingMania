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
    
    int maxLevelSum(TreeNode* root) {
        int maxSum = INT_MIN, optimalLevel = 0,currLevel = 0;
        vector<TreeNode*> V{root};
        while(!V.empty()){
            int levelSum = 0;
            currLevel+=1;
            vector<TreeNode*> current;
            for(auto i : V){
                if(i->left){
                    current.push_back(i->left);
                }
                if(i->right){
                    current.push_back(i->right);
                }
                levelSum+=i->val;
            }
            if(levelSum>maxSum){
                maxSum = levelSum;
                optimalLevel = currLevel;
            }
            swap(current,V);
        }
        return optimalLevel;
    }
};