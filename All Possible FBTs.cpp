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
    vector<TreeNode*> giveAllPossibleFBT(int n, map<int,vector<TreeNode*>>&store){
        if(store.find(n)!=store.end()){
            return store[n];
        }
        
        for(int i=1;i<n-1;i+=2){
            auto leftRoots = giveAllPossibleFBT(i,store);
            auto rightRoots = giveAllPossibleFBT(n-i-1,store);
            for(int i=0;i<leftRoots.size();i++){
                for(int j=0;j<rightRoots.size();j++){
                    TreeNode* new_node = new TreeNode(0);
                    new_node->left = leftRoots[i];
                    new_node->right = rightRoots[j];
                    store[n].push_back(new_node);
                }
            }
        }
        return store[n];
    }
    
    
    vector<TreeNode*> allPossibleFBT(int n) {
        map<int,vector<TreeNode*>> store;
        TreeNode* new_node = new TreeNode(0);
        store[1] = {new_node};
        return giveAllPossibleFBT(n,store);
    }
};