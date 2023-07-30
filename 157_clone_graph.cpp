#include <bits/stdc++.h> 
/***************************************************************************

	Class for graph node is as follows:

	class graphNode
	{
		public:
    		int data;
    	vector<graphNode *> neighbours;
    	graphNode()
    	{
        	data = 0;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val)
    	{
        	data = val;
        	neighbours = vector<graphNode *>();
    	}

    	graphNode(int val, vector<graphNode *> neighbours)
    	{
        	data = val;
        	this->neighbours = neighbours;
    	}
	};

******************************************************************************/

graphNode *cloneGraph(graphNode *src)
{
    map<graphNode*, graphNode*> m;
    queue<graphNode*> q;
    q.push(src);
    graphNode *node;
    node = new graphNode();
    node->data = src->data;
    m[src] = node;
    while (!q.empty())
    {
        graphNode *u = q.front();
        q.pop();
        vector<graphNode *> v = u->neighbours;
        int n = v.size();
        for (int i = 0; i < n; i++)
        {
            if (m[v[i]] == NULL)
            {
                node = new graphNode();
                node->data = v[i]->data;
                m[v[i]] = node;
                q.push(v[i]);
            }
            m[u]->neighbours.push_back(m[v[i]]);
        }
    }
    return m[src];
}