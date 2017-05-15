/**
310. Minimum Height Trees

For a undirected graph with tree characteristics, we can choose any node as the root. The result graph is then a rooted tree. Among all possible rooted trees, those with minimum height are called minimum height trees (MHTs). Given such a graph, write a function to find all the MHTs and return a list of their root labels.
Format
The graph contains n nodes which are labeled from 0 to n - 1. You will be given the number n and a list of undirected edges (each edge is a pair of labels).
You can assume that no duplicate edges will appear in edges. Since all edges are undirected, [0, 1] is the same as [1, 0] and thus will not appear together in edges.
Example 1:
Given n = 4, edges = [[1, 0], [1, 2], [1, 3]]
        0
        |
        1
       / \
      2   3

return [1]
Example 2:
Given n = 6, edges = [[0, 3], [1, 3], [2, 3], [4, 3], [5, 4]]
     0  1  2
      \ | /
        3
        |
        4
        |
        5

return [3, 4]
Note:
(1) According to the definition of tree on Wikipedia: “a tree is an undirected graph in which any two vertices are connected by exactly one path. In other words, any connected graph without simple cycles is a tree.”
(2) The height of a rooted tree is the number of edges on the longest downward path between the root and a leaf.

思路1：暴力求解。对于所有节点进行深度优先遍历，求他们的最大深度，然后求所有节点的最小深度，深度是最小深度的即为解，
毫无疑问，这个方法会超时。
65 / 66 test cases passed.Status: 
Time Limit Exceeded
**/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        if(edges.empty()){
            for(int i=0;i<n;i++)
                result.push_back(i);
            return result;
        }
            
        int size=edges.size();
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<size;i++){
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        vector<int> height(n,0);
        
        vector<int> visited(n,0);
        for(int i=0;i<n;i++){
            int temp=0;
            dfs(graph,i,visited,0,temp);
            height[i]=temp;
            for(int i=0;i<n;i++)
                visited[i]=0;
        }
        int min=INT_MAX;
        for(int i=0;i<n;i++){
            if(height[i]<min)
                min=height[i];
        }
        for(int i=0;i<n;i++){
            if(height[i]==min)
                result.push_back(i);
        }
        return result;
    }
    void dfs(vector<vector<int>> &graph, int node,vector<int> &visited, int depth,int & max_depth){
        visited[node]=1;
        if(depth>max_depth)
            max_depth=depth;
        for(int i=0;i<graph[node].size();i++){
            if(visited[graph[node][i]]==0){
                dfs(graph,graph[node][i],visited,depth+1,max_depth);
            }
        }
        
    }
};
/**
思路2：类似于剥洋葱，一层一层的剥去。
所有入度（即相连边数）为 1 的节点即是叶子节点。找高度最小的节点，即找离所有叶子节点最远的节点，也即找最中心的节点。
找最中心的节点的思路很简单：
  ● 每次去掉当前图的所有叶子节点，重复此操作直到只剩下最后的根。
根据这个思路可以回答题目中的 [ hint : How many MHTs can a graph have at most? ]，只能有一个或者两个最小高度树树根
**/
class Solution {
public:
    vector<int> findMinHeightTrees(int n, vector<pair<int, int>>& edges) {
        vector<int> result;
        if(edges.empty()){
            for(int i=0;i<n;i++)
                result.push_back(i);
            return result;
        }
            
        int size=edges.size();
        vector<int> degree(n,0);
        vector<vector<int>> graph(n,vector<int>());
        for(int i=0;i<size;i++){
            degree[edges[i].first]++;
            degree[edges[i].second]++;
            graph[edges[i].first].push_back(edges[i].second);
            graph[edges[i].second].push_back(edges[i].first);
        }
        queue<int> temp;
        for(int i=0;i<n;i++){
            if(degree[i]==1)
                temp.push(i);
        }
        
        while(!temp.empty()){
            //cout<<"temp.size: "<<temp.size()<<endl;
            int length=temp.size();
            queue<int> backup(temp);
            for(int k=0;k<length;k++){
                int i=temp.front();
                temp.pop();
                //cout<<"i= "<<i<<endl;
                for(int j=0;j<graph[i].size();j++){
                    //cout<<"~~"<<graph[i][j]<<endl;
                    degree[graph[i][j]]--;
                    if(degree[graph[i][j]]==1)
                        temp.push(graph[i][j]);
                }
            }
            if(temp.empty()){
                //cout<<"~~~~~~~~~~~~~"<<endl;
                vector<int> result;
                int length=backup.size();
                for(int i=0;i<length;i++){
                    //cout<<i<<" "<<backup.front();
                    result.push_back(backup.front());
                    backup.pop();
                }
                return result;
            }
                
        }
        return {};
     
    }
    
};