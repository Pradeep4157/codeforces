
#include <bits/stdc++.h>
using namespace std;
/*
    i have all the cycles in the graph should i bf on which edges to remove to achieve bipartite condition in min edges




*/

// Function to check if a node is
// visited in the current path
bool visited(int node, const vector<int> &path)
{
    return find(path.begin(), path.end(), node) != path.end();
}

// Function to rotate a cycle such that
// it starts with the smallest node
vector<int> rotateToSmallest(vector<int> path)
{
    auto minIt = min_element(path.begin(), path.end());
    rotate(path.begin(), minIt, path.end());
    return path;
}

// Function to invert the cycle order
vector<int> invert(vector<int> path)
{
    reverse(path.begin(), path.end());
    return rotateToSmallest(path);
}

// Function to check if a cycle is new
bool isNew(const vector<int> &path,
           vector<vector<int>> &cycles)
{
    return find(cycles.begin(),
                cycles.end(), path) == cycles.end();
}

// Function to find new cycles in the graph
void findNewCycles(vector<int> path,
                   vector<vector<int>> &graph, vector<vector<int>> &cycles)
{
    int startNode = path[0];
    int nextNode;
    vector<int> sub;

    // Visit each edge and node of each edge
    for (auto &edge : graph)
    {
        int node1 = edge[0], node2 = edge[1];

        if (startNode == node1 || startNode == node2)
        {
            nextNode = (node1 == startNode) ? node2 : node1;

            if (!visited(nextNode, path))
            {
                // Neighbor node not on path yet
                sub = {nextNode};
                sub.insert(sub.end(), path.begin(), path.end());
                // Explore extended path
                findNewCycles(sub, graph, cycles);
            }
            else if (path.size() > 2 && nextNode == path.back())
            {
                // Cycle found
                vector<int> p = rotateToSmallest(path);
                vector<int> inv = invert(p);

                if (isNew(p, cycles) && isNew(inv, cycles))
                {
                    cycles.push_back(p);
                }
            }
        }
    }
}

// Main function to initiate cycle detection
vector<vector<int>> findCycles(vector<vector<int>> &graph)
{

    vector<vector<int>> cycles;

    for (auto &edge : graph)
    {
        for (int node : edge)
        {
            findNewCycles({node}, graph, cycles);
        }
    }

    return cycles;
}
vector<pair<int, int>> greedyEdgesToRemoveForBipartite(const vector<vector<int>> &cycles)
{
    map<pair<int, int>, int> edgeFreq;

    // Step 1: Count edge frequency across odd-length cycles
    for (const auto &cycle : cycles)
    {
        if (cycle.size() % 2 == 1)
        {
            for (int i = 0; i < cycle.size(); ++i)
            {
                int u = cycle[i];
                int v = cycle[(i + 1) % cycle.size()];
                if (u > v)
                    swap(u, v); // Normalize edge
                edgeFreq[{u, v}]++;
            }
        }
    }

    // Step 2: Sort edges by frequency (descending)
    vector<pair<pair<int, int>, int>> sortedEdges(edgeFreq.begin(), edgeFreq.end());
    sort(sortedEdges.begin(), sortedEdges.end(), [](auto &a, auto &b)
         { return a.second > b.second; });

    // Step 3: Greedily remove edges until all odd cycles are broken
    set<pair<int, int>> removed;
    for (auto &[edge, freq] : sortedEdges)
    {
        removed.insert(edge);

        // Check if all odd cycles are broken
        bool allBroken = true;
        for (const auto &cycle : cycles)
        {
            if (cycle.size() % 2 == 1)
            {
                bool intact = true;
                for (int i = 0; i < cycle.size(); ++i)
                {
                    int u = cycle[i];
                    int v = cycle[(i + 1) % cycle.size()];
                    if (u > v)
                        swap(u, v);
                    if (removed.count({u, v}))
                    {
                        intact = false;
                        break;
                    }
                }
                if (intact)
                {
                    allBroken = false;
                    break;
                }
            }
        }

        if (allBroken)
            break;
    }

    // Convert set to vector for output
    return removed.size();
}
int main()
{
    int n, m;
    cin >> n >> m;
    vector<vector<int>> adj;

    for (int i = 0; i < m; i++)
    {
        int u, v;
        cin >> u >> v;
        adj.push_back({u, v});
    }
    vector<vector<int>> cycles = findCycles(adj);
    set<pair<int, int>> temp;
    cout << greedyEdgesToRemoveForBipartite(cycles) << endl;

    return 0;
}