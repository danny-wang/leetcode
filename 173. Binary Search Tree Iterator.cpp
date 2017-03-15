/**
173. Binary Search Tree Iterator
Implement an iterator over a binary search tree (BST). Your iterator will be initialized with the root node of a BST.
Calling next() will return the next smallest number in the BST.
Note: next() and hasNext() should run in average O(1) time and uses O(h) memory, where h is the height of the tree.

思路1：
刚开始想到首先对这个二叉搜索树进行中根遍历，将其存储在一个vector中，因为二叉搜索树的性质，中根遍历一定是排好序的，
之后只需要从vector[0]开始一个一个往后读就行，但是这种思路的空间复杂度是O(n)，不满足题目要求。

思路2：
为了能够让空间复杂度降低到O(h)，发现只需要一直遍历左子树，最后一个叶节点就是最小元素，保存这条路径到stack中，
每次取出top位置的元素，之后判断这个节点A是否有右子树，如果有就压入栈中，在判断A的右子树是否有左子树，
因为左子树一定比它的根节点小，所以把它的左子树在压入,不断循环，直到没有左子树为止。

代码：
**/

/**
 * Definition for binary tree
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class BSTIterator {
public:
    BSTIterator(TreeNode *root) {
        if(root==nullptr)
            return;
        TreeNode* temp=root;
        while(temp){  //将所有左子树压入，栈顶的一定是最小元素
            result.push(temp);
            temp=temp->left;
        }
    }

    /** @return whether we have a next smallest number */
    bool hasNext() {
        if(result.empty())
            return false;
        else
            return true;
    }

    /** @return the next smallest number */
    int next() {
        TreeNode* temp=result.top();
        result.pop();
        if(temp->right){//如果最小元素有右子树，压入它的右子树和从右子树开始的所有左子树。
            result.push(temp->right);
            TreeNode* temp_right_left=temp->right->left;
            while(temp_right_left){
                result.push(temp_right_left);
                temp_right_left=temp_right_left->left;
            }
        }       
        return temp->val;
    }
private:
    stack<TreeNode*> result;    
};

/**
 * Your BSTIterator will be called like this:
 * BSTIterator i = BSTIterator(root);
 * while (i.hasNext()) cout << i.next();
 */
