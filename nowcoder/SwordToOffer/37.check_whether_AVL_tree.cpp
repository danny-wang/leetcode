/**
平衡二叉树

题目描述
输入一棵二叉树，判断该二叉树是否是平衡二叉树。
思路：为了每个节点只遍历一次，那么在遍历这个节点之前就已经遍历了它的左右子树，所以采用后续遍历的方式。
在遍历某个节点的左右子树之后，可以通过它的左右子树的深度判断它是否是平衡的，并更新当前节点的深度。
当最后遍历到根节点的时候，我们就判断了整棵二叉树是不是平衡的
**/

class Solution {
public:
    bool IsBalanced_Solution(TreeNode* pRoot) {
		int depth=0;
        return IsBalanced(pRoot,depth);
        
    }
    bool IsBalanced(TreeNode* root, int& depth ){
        if(root==nullptr){
            depth=0;
            return true;
        }
        int left,right;
        if(IsBalanced(root->left,left)&&IsBalanced(root->right,right)){
            int diff=left-right;
            if(diff<=1 &&diff>=-1){
                depth=1+ (left>right? left:right);
                return true;
            }
            else{
                return false;
            }
        }
        return false;
    }
};
