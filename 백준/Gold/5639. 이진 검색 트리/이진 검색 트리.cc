#include <bits/stdc++.h>

using namespace std;

struct TreeNode {
  int key;
  TreeNode *left;
  TreeNode *right;
  TreeNode(int key) {
    this->key = key;
    this->left = NULL;
    this->right = NULL;
  }
};

void generateTree(TreeNode *root, queue<int> &q, int left, int right) {
  if (q.empty())
    return;
  if (root->key > q.front() && q.front() > left) {
    root->left = new TreeNode(q.front());
    q.pop();
    generateTree(root->left, q, left, root->key);
  }
  if (q.empty())
    return;
  if (root->key < q.front() && q.front() < right) {
    root->right = new TreeNode(q.front());
    q.pop();
    generateTree(root->right, q, root->key, right);
  }
}

void postOrder(TreeNode *root) {
  if (!root)
    return;
  postOrder(root->left);
  postOrder(root->right);
  cout << root->key << "\n";
}

int main(int argc, char *argv[]) {
  queue<int> q;
  int temp;
  while (cin >> temp) {
    q.push(temp);
  }

  if (q.empty())
    return 0;

  TreeNode *root = new TreeNode(q.front());
  q.pop();

  TreeNode *p = root;
  generateTree(root, q, INT_MIN, INT_MAX);

  postOrder(root);

  return 0;
}