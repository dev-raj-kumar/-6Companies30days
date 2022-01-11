/**
 * Definition for a binary tree node.
 * struct TreeNode {
 *     int val;
 *     TreeNode *left;
 *     TreeNode *right;
 *     TreeNode(int x) : val(x), left(NULL), right(NULL) {}
 * };
 */
class Codec {
public:

    // Encodes a tree to a single string.
    string serialize(TreeNode* root) {
        string s = "";
        if(root == NULL)
            return s;
        queue<TreeNode*> q;
        q.push(root);
        while(!q.empty()){
            int n = q.size();
            while(n > 0){
                n--;
                TreeNode* nd = q.front();
                q.pop();
                if(nd == NULL){
                    s += "N ";
                    continue;
                }
                s += to_string(nd->val);
                s += " ";
                q.push(nd->left);
                q.push(nd->right);
            }
        }
        return s;
    }

    // Decodes your encoded data to tree.
    TreeNode* deserialize(string s) {
        TreeNode* root = NULL;
        //cout << s << "\n";
        
        int i;int n = s.length();
        if(n == 0)
            return root;
        
        vector<int> v;
        for(i=0;i<n;i++){
            
            string a = "";
            int j =i;
            while(j<n && s[j] != ' '){
                a += s[j];
                j++;
            }
            if(a == "N")
                v.push_back(1e5);
            else
                v.push_back(stoi(a));
            i=j;
            
            
        }
        /*for(auto x : v){
            cout << x << " ";
        }*/
        
        
        queue<TreeNode*> q;
        root = new TreeNode(v[0]);
        q.push(root);
        i=1;
        
        while(!q.empty()){
            int n = q.size();
            while(n > 0){
                n--;
                TreeNode* nd = q.front();
                q.pop();
                if(nd == NULL){
                    i++;
                    continue;
                }
                TreeNode* l = NULL;
                TreeNode* r = NULL;
                
                if(v[2*i -1] != 1e5){
                    l = new TreeNode(v[2*i -1]);
                    q.push(l);
                }
                if(v[2*i] != 1e5){
                    r = new TreeNode(v[2*i]);
                    q.push(r);
                }
                nd->left = l;
                nd->right = r;
                i++;
            }
        }
        
        
        
        return root;
    }
};


