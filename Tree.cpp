#include <iostream>
using namespace std;

// ����������Ľڵ�ṹ
struct TreeNode {
    int val;            // �ڵ��ֵ
    TreeNode* left;     // ���ӽڵ�
    TreeNode* right;    // ���ӽڵ�
    TreeNode(int x) : val(x), left(NULL), right(NULL) {} // ���캯��
};

// ��������ĵݹ�ʵ��
void inOrderTraversal(TreeNode* root) {
    if (root == NULL) {
        return;
    }

    // �ȱ���������
    inOrderTraversal(root->left);

    // ���ʵ�ǰ�ڵ��ֵ
    cout << root->val << " ";

    // �ٱ���������
    inOrderTraversal(root->right);
}

//��������������
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
    // ����һ���򵥵Ķ�����
    TreeNode* root = new TreeNode(1);
    root->left = new TreeNode(2);
    root->right = new TreeNode(3);
    root->left->left = new TreeNode(4);
    root->left->right = new TreeNode(5);

    // �������������
    cout << "In-order traversal: ";
    inOrderTraversal(root);
    cout << endl;

    // ��������������
    cout << "get-depth from the tree: ";
    cout << getDepth(root);
    cout << endl;

    // ����������Ľڵ���
    cout << "count the nodes from the tree: ";
    cout << getCNo(root);
    cout << endl;

    return 0;
}
