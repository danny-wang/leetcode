/**
二叉搜索树与双向链表
题目描述
输入一棵二叉搜索树，将该二叉搜索树转换成一个排序的双向链表。要求不能创建任何新的结点，只能调整树中结点指针的指向。

思路：

    1：由于要求链表是有序的，可以借助二叉树中序遍历，因为中序遍历算法的特点就是从小到大访问结点。

    当遍历访问到根结点时，假设根结点的左侧已经处理好，只需将根结点与上次访问的最近结点（左子树中最大值结点）的指针连接好即可。

    进而更新当前链表的最后一个结点指针。

    2：由于中序遍历过程正好是转换成链表的过程，即可采用递归处理

    这样分为三步：

    1.转换左子树；

    2.链接根节点。设置根节点的左指针、尾结点的右指针。更新尾结点。

    3.转换右子树。

注意：这里传入的是一个指针的指针，原因是参数传递是值传递，如果直接传递一个指针，虽然会改变指针指向的值，但是指针本身并不会改变，

当函数运行结束，这个指针指向的元素不会变化。所以如果想要传递一个可以改变的指针，就将这个指针的地址传递给一个指向指针的指针P，这样，

在函数中修改这个P所指向的内容，在函数结束之后也会保留下来
**/
    /*
    struct TreeNode {
      int val;
      struct TreeNode *left;
      struct TreeNode *right;
      TreeNode(int x) :
          val(x), left(NULL), right(NULL) {
      }
    };
    */
    class Solution {
    public:
        TreeNode* Convert(TreeNode* pRootOfTree){
            TreeNode* pLastNodeInList = NULL;
            CovertNode(pRootOfTree, &pLastNodeInList);
            while (pLastNodeInList != NULL && pLastNodeInList->left != NULL) {
                pLastNodeInList = pLastNodeInList->left;
            }
            return pLastNodeInList;
        }
         
        void CovertNode(TreeNode* pRoot, TreeNode** pLastNodeInList) {
            if (pRoot == NULL)
                return;
            if (pRoot->left != NULL)
                CovertNode(pRoot->left, pLastNodeInList);
            pRoot->left = *pLastNodeInList;
            if (*pLastNodeInList != NULL)
                (*pLastNodeInList)->right = pRoot;
            *pLastNodeInList = pRoot;
            if (pRoot->right != NULL)
                CovertNode(pRoot->right, pLastNodeInList);
        }
    };

