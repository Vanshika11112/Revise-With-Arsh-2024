class tree{
    public:
        int maxi;
        int mini;
        bool isBst;
        int sum;
};
tree solve(TreeNode* root, int &ans){
    if(root == NULL){
        return {INT_MIN, INT_MAX, true, 0};
    }
    tree left = solve(root->left, ans);
    tree right = solve(root->right, ans);
    tree currNode;

    currNode.sum = left.sum + right.sum + root->val;

    currNode.maxi = max(root->val, right.maxi);
    currNode.mini = min(root->val, left.mini);

    if(left.isBst && right.isBst && (root->val > left.maxi && root->val < right.mini)){
        currNode.isBst = true;
    }
    else{
        currNode.isBst = false;
    }
    if(currNode.isBst){
        ans = max(ans, currNode.sum);
    }
    return currNode;
}

class Solution {
public:
    int maxSumBST(TreeNode* root) {
        int maxSum = 0;
        tree temp = solve(root, maxSum);
        return maxSum;
    }
};