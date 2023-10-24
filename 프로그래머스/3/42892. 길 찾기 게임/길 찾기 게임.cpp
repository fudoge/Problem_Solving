#include <iostream>
#include <vector>
#include <algorithm>

using namespace std;

struct Node
{
    int val;
    int x;
    int y;
    Node *left;
    Node *right;

    Node(int value, int x, int y) : val(value), x(x), y(y), left(nullptr), right(nullptr) {}
};

class Tree
{
private:
    Node *root;

public:
    Node *getRoot()
    {
        return root;
    }

    Tree() : root(nullptr) {}

    void insert(vector<int> n)
    {
        int x = n[0];
        int y = n[1];
        int v = n[2];

        if (root == nullptr)
        {
            root = new Node(v, x, y);
            return;
        }

        insertRecursive(root, n);
    }

    void insertRecursive(Node *curr, vector<int> n)
    {
        int x = n[0];
        int y = n[1];
        int v = n[2];

        if (x < curr->x)
        {
            if (curr->left == nullptr)
            {
                curr->left = new Node(v, x, y);
                return;
            }
            else
            {
                insertRecursive(curr->left, n);
            }
        }
        else
        {
            if (curr->right == nullptr)
            {
                curr->right = new Node(v, x, y);
                return;
            }
            else
            {
                insertRecursive(curr->right, n);
            }
        }
    }

    void preorder_traversal(Node *start, vector<int> &log)
    {
        if (start == nullptr)
            return;

        log.push_back(start->val);
        preorder_traversal(start->left, log);
        preorder_traversal(start->right, log);
    }

    void postorder_traversal(Node *start, vector<int> &log)
    {
        if (start == nullptr)
            return;

        postorder_traversal(start->left, log);
        postorder_traversal(start->right, log);
        log.push_back(start->val);
    }
};

vector<vector<int>> solution(vector<vector<int>> nodeinfo)
{
    for (int i = 0; i < nodeinfo.size(); i++)
    {
        nodeinfo[i].push_back(i + 1);
    }

    sort(nodeinfo.begin(), nodeinfo.end(), [](const auto &a, const auto &b)
         {
             if (a[1] == b[1])
             {
                 return a[0] < b[0];
             }
             return a[1] > b[1]; });

    Tree T;

    for (const auto &node : nodeinfo)
    {
        T.insert(node);
    }

    vector<int> preorder_log;
    vector<int> postorder_log;

    T.preorder_traversal(T.getRoot(), preorder_log);
    T.postorder_traversal(T.getRoot(), postorder_log);

    vector<vector<int>> answer;
    answer.push_back(preorder_log);
    answer.push_back(postorder_log);

    return answer;
}