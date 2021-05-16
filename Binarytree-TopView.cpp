// Binary tree Top View in cpp


    vector<int> topView(Node *root)
    {
        //Your code here
        
           queue<pair<Node*,int>>q;
           
           map<int,int>mp;
           
           q.push({root,0});
           
           while(!q.empty()){
               
               Node *temp=q.front().first;
               
               int h=q.front().second;
               
               q.pop();
                 
               if(!mp[h]){
                   
                   mp[h]=temp->data;
               }
               
               
               if(temp->left!=NULL){
                   
                   q.push({temp->left,h-1});
               }
               
               if(temp->right!=NULL){
                   
                   q.push({temp->right,h+1});
               }
           }
           
           vector<int>res;
           
           
           
        //   for(auto it:mp){
               
        //       cout<<it.first<<" "<<it.second<<"\n";
        //   }
           
           
           for(auto it:mp){
               
               res.push_back(it.second);
           }
           
           return res;
           
           
    }
