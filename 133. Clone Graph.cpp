/**
33. Clone Graph
Clone an undirected graph. Each node in the graph contains a label and a list of its neighbors.

OJ's undirected graph serialization:
Nodes are labeled uniquely.
We use # as a separator for each node, and , as a separator for node label and each neighbor of the node.
As an example, consider the serialized graph {0,1,2#1,2#2,2}.
The graph has a total of three nodes, and therefore contains three parts as separated by #.
  1. First node is labeled as 0. Connect node 0 to both nodes 1 and 2.
  2. Second node is labeled as 1. Connect node 1 to node 2.
  3. Third node is labeled as 2. Connect node 2 to node 2 (itself), thus forming a self-cycle.
Visually, the graph looks like the following:
       1
      / \
     /   \
    0 --- 2
         / \
         \_/
思路：递归深度优先遍历(DFS)
**/
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
        if(node==nullptr)
            return nullptr;
        if(m.find(node)!=m.end())
            return m[node];
        UndirectedGraphNode* copy = new UndirectedGraphNode(node->label);
        m[node]=copy;
        for(int i=0;i<(node->neighbors).size();i++){
            UndirectedGraphNode* neigh = cloneGraph((node->neighbors)[i]);
            (copy->neighbors).push_back(neigh);
        }
        return copy;
    }
private:
    unordered_map<UndirectedGraphNode*,UndirectedGraphNode*> m; //origin nodes map copy nodes
};

// 解法二：广度优先遍历
// 变量说明：
// 映射表m用来保存原图结点与克隆结点的对应关系。
// 映射表visited用来记录已经访问过的原图结点，防止循环访问。
// 队列q用于记录广度优先遍历的层次信息。

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
        // map from origin node to copy node
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        unordered_map<UndirectedGraphNode *, bool> visited;
        queue<UndirectedGraphNode*> q;
        q.push(node);
        while(!q.empty())
        {// BFS
            UndirectedGraphNode* front = q.front();
            q.pop();
            
            if(visited[front] == false)
            {
                visited[front] = true;
                
                UndirectedGraphNode* cur;
                if(m.find(front) == m.end())
                {
                    cur = new UndirectedGraphNode(front->label);
                    m[front] = cur;
                }
                else
                {
                    cur = m[front];
                }
                for(int i = 0; i < front->neighbors.size(); i ++)
                {
                    if(m.find(front->neighbors[i]) == m.end())
                    {
                        UndirectedGraphNode* nei = new UndirectedGraphNode(front->neighbors[i]->label);
                        m[front->neighbors[i]] = nei;
                        cur->neighbors.push_back(nei);
                            
                        q.push(front->neighbors[i]);
                    }
                    else
                    {
                        cur->neighbors.push_back(m[front->neighbors[i]]);
                    }
                }
            }
        }
        return m[node];
    }
};
//解法三：非递归深度优先遍历(DFS)
//深度优先遍历需要进行邻居计数。如果邻居已经全部访问，则该节点访问完成，可以出栈，否则就要继续处理下一个邻居。
 

/**
 * Definition for undirected graph.
 * struct UndirectedGraphNode {
 *     int label;
 *     vector<UndirectedGraphNode *> neighbors;
 *     UndirectedGraphNode(int x) : label(x) {};
 * };
 */

struct Node
{
    UndirectedGraphNode *node;
    int ind;    //next neighbor to visit
    Node(UndirectedGraphNode *n, int i): node(n), ind(i) {}
};

class Solution {
public:
    UndirectedGraphNode *cloneGraph(UndirectedGraphNode *node) {
        if(node == NULL)
            return NULL;
        // map from origin node to copy node
        unordered_map<UndirectedGraphNode *, UndirectedGraphNode *> m;
        unordered_map<UndirectedGraphNode *, bool> visited;
        stack<Node*> stk;
        Node* newnode = new Node(node, 0);
        stk.push(newnode);
        visited[newnode->node] = true;
        while(!stk.empty())
        {// DFS
            Node* top = stk.top();
            UndirectedGraphNode* topCopy;
            if(m.find(top->node) == m.end())
            {
                topCopy = new UndirectedGraphNode(top->node->label);
                m[top->node] = topCopy;
            }
            else
                topCopy = m[top->node];

            if(top->ind == top->node->neighbors.size())
                //finished copying its neighbors 
                    stk.pop();
            else
            {
                while(top->ind < top->node->neighbors.size())
                {
                    if(m.find(top->node->neighbors[top->ind]) == m.end())
                    {
                        UndirectedGraphNode* neiCopy = new UndirectedGraphNode(top->node->neighbors[top->ind]->label);
                        m[top->node->neighbors[top->ind]] = neiCopy;
                        topCopy->neighbors.push_back(neiCopy);
                        if(visited[top->node->neighbors[top->ind]] == false)
                        {
                            visited[top->node->neighbors[top->ind]] = true;
                            Node* topnei = new Node(top->node->neighbors[top->ind], 0);
                            stk.push(topnei);
                        }
                        top->ind ++;
                        break;
                    }
                    else
                    {
                        topCopy->neighbors.push_back(m[top->node->neighbors[top->ind]]);
                        top->ind ++;
                    }
                }
            }
        }
        return m[node];
    }
};
