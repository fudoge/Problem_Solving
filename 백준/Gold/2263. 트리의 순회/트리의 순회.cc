#include <bits/stdc++.h>

using namespace std;

int n;
int inorder[100001], postorder[100001];
unordered_map<int, int> inorderIdx;

struct TreeNode {
  int val;
  TreeNode *left;
  TreeNode *right;

  TreeNode(int val) {
    this->val = val;
    this->left = nullptr;
    this->right = nullptr;
  }
};

void preOrder(TreeNode *root) {
  cout << root->val << " ";
  if (root->left)
    preOrder(root->left);
  if (root->right)
    preOrder(root->right);
}

TreeNode *buildTree(int inStart, int inEnd, int postStart, int postEnd) {
  if (inStart > inEnd || postStart > postEnd)
    return nullptr;

  int rootVal = postorder[postEnd];
  auto root = new TreeNode(rootVal);

  int rootIdx = inorderIdx[rootVal];

  int leftSize = rootIdx - inStart;

  root->left =
      buildTree(inStart, rootIdx - 1, postStart, postStart + leftSize - 1);
  root->right =
      buildTree(rootIdx + 1, inEnd, postStart + leftSize, postEnd - 1);

  return root;
}

int main(int argc, char *argv[]) {
  ios_base::sync_with_stdio(0);
  cin.tie(0);

  cin >> n;

  for (int i = 0; i < n; ++i) {
    cin >> inorder[i];
    inorderIdx[inorder[i]] = i;
  }
  for (int i = 0; i < n; ++i) {
    cin >> postorder[i];
  }

  auto root = buildTree(0, n - 1, 0, n - 1);

  preOrder(root);
  cout << "\n";

  return 0;
}