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
//love babbar approach using tuple
//1)validity,sumtill root,minvalue,maximumvalue
    tuple<bool,int,int,int> solve(TreeNode* node, int& currMax){
        if(node==nullptr){
            return tuple(true,0,INT_MAX,INT_MIN);
        }
        if(node->left==nullptr && node->right==nullptr){
            currMax=max(currMax,node->val);
            return tuple(true,node->val,node->val,node->val);
        }
        auto [leftbool,leftSum,leftmin,leftmax] = solve(node->left,currMax);
        auto [rightbool,rightSum,rightmin,rightmax] = solve(node->right,currMax);
        bool leftCheck=(node->left==nullptr) || (leftbool && (node->val>leftmax));
        bool rightCheck=(node->right==nullptr) || (rightbool && (node->val<rightmin));
        int preVal = node->val;
        bool preBool=leftCheck && rightCheck;
        int preSum=leftSum+rightSum+preVal;
        int preMin= min({preVal,leftmin,rightmin});
        int preMax = max({preVal,leftmax,rightmax});
        if(preBool && (currMax < preSum)){
            currMax = preSum;
        }
        return tuple(preBool,preSum,preMin,preMax);
    }
    int maxSumBST(TreeNode* root) {
        int currMax=0;
        solve(root,currMax);
        return currMax;
    }
};