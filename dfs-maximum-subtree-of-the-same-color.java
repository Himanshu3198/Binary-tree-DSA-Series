class Solution {
    int maxSize = 0;
    private int solve(Map<Integer,List<Integer>>graph,int[] colors,int node){

        boolean same = true;
        List<Integer>  childs = graph.getOrDefault(node,new ArrayList<>());
        int color = colors[node];
        int size = 1;

        for(int child:childs){
            int childSize = solve(graph,colors,child);
            if(color !=colors[child] || childSize == 0){
                same = false;
            }else{
                size+=childSize;
            }
            
        }
        if(same){
            maxSize = Math.max(size,maxSize);
            return size;
        }
        return 0;   
    }
    public int maximumSubtreeSize(int[][] edges, int[] colors) {
        
      
        Map<Integer,List<Integer>>graph = new HashMap<>();

        for(int i=0;i<edges.length;i++){

            int [] edge = edges[i];
            int u = edge[0];
            int v = edge[1];
            graph.putIfAbsent(u,new ArrayList<>());
            graph.get(u).add(v);
        }
        solve(graph,colors,0);
        return maxSize;

    }
}
