#include <stdio.h>

typedef struct TreeNode {
	int data;
	struct TreeNode* left, * right;
}TreeNode;

TreeNode* create_node(int key) {
	TreeNode* p = (TreeNode*)malloc(sizeof(TreeNode));
	p->data = key;
	p->left = p->right = NULL;
	return p;
}
TreeNode* insert(TreeNode* node, int key) {
	if (!node) return create_node(key);

	if (key < node->data) node->left = insert(node->left, key);
	else node->right = insert(node->right, key);

	return node;
}

void postorder(TreeNode* root) {
	if (root) {
		postorder(root->left);
		postorder(root->right);
		printf("%d\n", root->data);
	}
}
int main() {
	int n;
	TreeNode* root = NULL;

	while (scanf("%d", &n) != EOF) root = insert(root, n);

	postorder(root);
}