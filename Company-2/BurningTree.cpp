class Solution {
  public:
  
    void dfs(Node* root,int t,vector<Node*>& v,bool &f){
        if(root == NULL || f)
        return;
        
       // cout << root->data << "\n";
        
        v.push_back(root);
        if(root->data == t){
            f=true;
            return;
        }
        dfs(root->left,t,v,f);
        if(f)
        return;
        dfs(root->right,t,v,f);
        if(f)
        return;
        v.pop_back();
    }
    
    void dfs2(Node* root,int v,int &mm){
        if(root == NULL)
        return;
        
        mm = max(mm,v);
        dfs2(root->left,v+1,mm);
        dfs2(root->right,v+1,mm);
    }
    
    int dfs1(Node* root,int id,vector<Node*> &v,int & mm){
        
        if(root == v.back()){
            mm = max(mm,0);
            dfs2(root->left,1,mm);
            dfs2(root->right,1,mm);
            return 1;
        }
        int x;
        if(root->left == v[id+1]){
            x = dfs1(root->left,id+1,v,mm);
            dfs2(root->right,x+1,mm);
        }
        else{
            x = dfs1(root->right,id+1,v,mm);
            dfs2(root->left,x+1,mm);
        }
        mm = max(mm,x);
        return x+1;
    }
    
    int minTime(Node* root, int target) 
    {
        // Your code goes here
        if(root == NULL)
        return 0;
        
        vector<Node*> v;
        bool f = false;
        dfs(root,target,v,f);
        
        /*for(auto x : v){
            cout << x->data << " ";
        }*/
        int mm = 0;
        dfs1(root,0,v,mm);
        return mm;
    }
};
