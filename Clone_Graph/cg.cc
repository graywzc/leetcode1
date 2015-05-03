/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */
class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        queue<UndirectedGraphNode*> qu;         
        unordered_map<UndirectedGraphNode*, UndirectedGraphNode*> visited;

        qu.push(node);
        UndirectedGraphNode *res = new UndirectedGraphNode(node->label); 
        visited[node] = res; 

        while(!qu.empty())
        {
            UndirectedGraphNode *cur = qu.front(); 
            qu.pop();
            UndirectedGraphNode *ncur = visited[cur];
            for(UndirectedGraphNode *nb: cur->neighbors)
            {
                if(visited.find(nb) == visited.end()) 
                {
                    UndirectedGraphNode *nnb = new UndirectedGraphNode(nb->label); 
                    qu.push(nb);
                    visited[nb] = nnb;
                }
                ncur->neighbors.push_back(visited[nb]);
            }
        }
        return res;
    }
};
