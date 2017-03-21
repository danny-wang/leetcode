/**
从上往下打印二叉树 
题目描述
从上往下打印出二叉树的每个节点，同层节点从左至右打印。 
思路：二叉树的层次遍历
**/

/*
struct TreeNode {
	int val;
	struct TreeNode *left;
	struct TreeNode *right;
	TreeNode(int x) :
			val(x), left(NULL), right(NULL) {
	}
};*/
class Solution {
public:
    vector<int> PrintFromTopToBottom(TreeNode* root) {
	if(root==nullptr)
            return {};
        int length=1;
        queue<TreeNode*> helper;
        vector<int> result;
        helper.push(root);
        while(!helper.empty()){
            for(int i=0;i<length;i++){
                TreeNode* temp=helper.front();
                helper.pop();
                result.push_back(temp->val);
                if(temp->left)
                    helper.push(temp->left);
                if(temp->right)
                    helper.push(temp->right);
            }
            length=helper.size();
        }
        return result;
    }
};
