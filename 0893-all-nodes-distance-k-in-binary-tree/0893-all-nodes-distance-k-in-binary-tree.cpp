class Solution {
public:
    vector<int> distanceK(TreeNode* root, TreeNode* target, int k) {
        vector<int> nodes;
        unordered_map<int, TreeNode*> parent;
        queue<TreeNode*> q;
        q.push(root);
		// 전체 노드를 탐색하며 부모 관계를 잇는다.
        while(!q.empty()){
            int size = q.size();
            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();
                //왼쪽에 값이 있는 경우, 현재 노드의 왼쪽의 부모를 현재 노드로 하고, 큐에 넣는다.
                if(curr -> left){
                    parent[curr->left->val] = curr;
                    q.push(curr->left); 
                }
				//오른쪽에 값이 있는 경우, 현재 노드의 오른쪽의 부모를 현재 노드로 하고, 큐에 넣는다.
                if(curr -> right){
                    parent[curr->right->val] = curr;
                    q.push(curr->right); 
                }
            }
        }
		//k만큼 떨어져있는 노드들 찾기. 이 while문이 끝나면 큐에는 k만큼 떨어져있는 노드들만 남음.
        unordered_map<int, int> visited;
        q.push(target);
        while(k-- && !q.empty()){
            int size = q.size();

            for(int i = 0; i < size; i++){
                auto curr = q.front();
                q.pop();

                visited[curr -> val] = 1;

                if(curr -> left && !visited[curr->left->val]){
                    q.push(curr -> left);
                }

                if(curr -> right && !visited[curr->right->val]){
                    q.push(curr -> right);
                }

                if(parent[curr->val] && !visited[parent[curr->val] -> val]){
                    q.push(parent[curr->val]);
                }

            }
        }
		//노드들 출력하기
        while(!q.empty()){
            nodes.push_back(q.front()->val);
            q.pop();
        }
        return nodes;
    }
};