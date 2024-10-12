#include <iostream>
using namespace std;

// 定义二叉树的节点结构
struct TreeNode {
    int val;            // 节点的值
    TreeNode* left;     // 左子节点
    TreeNode* right;    // 右子节点
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // 构造函数
};

// 中序遍历的递归实现
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // 先遍历左子树
    inOrderTraversal(root->left);

    // 访问当前节点的值
    cout << root->val << " ";

    // 再遍历右子树
    inOrderTraversal(root->right);
}

//计算二叉树的深度
int getDepth(TreeNode* root) {

    int Depth = 1;

    if (root == NULL) {
        return 0;
    }
    else {

        getDepth(root->left);
        getDepth(root->right);

        Depth++;
    }
    return Depth;

}

int getCNo(TreeNode* root) {
    if (root == NULL) {

        return 0;
    }else {

        return 1 + getCNo(root->left) + getCNo(root->right);
    }
}


int main() {
    // 创建一个简单的二叉树
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // 输出中序遍历结果
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // 计算二叉树的深度
    cout << "get-depth from the tree: ";
    cout << getDepth(root);
    cout << endl;

    // 输出二叉树的节点数
    cout << "count the nodes from the tree: ";
    cout << getCNo(root);
    cout << endl;

    return 0;
}
