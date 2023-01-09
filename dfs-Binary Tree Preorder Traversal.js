var solve=(root,res)=>{
    if(!root) return;
    res.push(root.val);
    solve(root.left,res);
    solve(root.right,res);
}
var preorderTraversal = function(root) {
     var res=[];
     solve(root,res);
     return res;
      
};
