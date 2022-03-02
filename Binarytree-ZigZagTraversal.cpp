vector <int> zigZagTraversal(Node* root)
    {
    	// Code here
    	vector<int>res;
    	
    	
    	bool order=false;
    	
    	 queue<Node*>q;
    	 q.push(root);
    	 
    	 
    	 while(!q.empty()){

           int size=q.size();
            stack<Node*>st;
          order=!order;
           while(size--){

            Node *curr=q.front();
                  q.pop();
                   
               if(!order){
                  st.push(curr);
                  }else{
                     res.push_back(curr->data);
                    }

                  if(curr->left){
                        q.push(curr->left);
                       } if(curr->right){
                                 q.push(curr->right);
                            }
                  
            }

           if(!order){
               while(!st.empty()){
                   Node *ele=st.top();
                          st.pop();
                    res.push_back(ele->data);
                  }
             }
   
        }
         return res;
    }
