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

// python version

from collections import defaultdict
from typing import List
class Solution:
    def dfs(self,graph:defaultdict(list),colors: List[int],node:int)->int:

        same = True
        size = 1
        childs = graph[node]
        color = colors[node]

        for child in childs:

            child_size = self.dfs(graph,colors,child)

            if color != colors[child] or child_size == 0 :
                same = False
            else:
                size +=  child_size
        
        if same == False:
            return 0
        self.max_size = max(self.max_size,size)
        return size
        


    def maximumSubtreeSize(self, edges: List[List[int]], colors: List[int]) -> int:

        graph = defaultdict(list)
        for u,v in edges:
            graph[u].append(v)
        
        self.max_size = 0
        self.dfs(graph,colors,0)

        return self.max_size


        
        
