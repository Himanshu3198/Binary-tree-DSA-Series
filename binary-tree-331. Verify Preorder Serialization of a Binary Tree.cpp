// 331. Verify Preorder Serialization of a Binary Tree

class Solution {
public:
    bool isValidSerialization(string pre) {
        
        
        int vac=1;
        pre+=',';
        for(int i=0;i<pre.length();i++){
            
             if(pre[i]==','){
                 continue;
             } 
           
            
             vac--;
            
             if(vac<0){
                return false;
            }
            
           
          
            if(pre[i]!='#'){
                
               vac+=2;
                
                while(pre[i]!=','){   // This loop handle the case when digit >=10
                 
                     i++;
                    
                }
                
            }
        
        }
    
        return vac==0;
    }
};
