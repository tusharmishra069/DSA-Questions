#include <vector>
#include <algorithm>

using namespace std;

class Solution {
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        const int MAX_DISTANCE = 1e9;  // Use a very large value instead of 10000
        vector<int> dist1 = getDistances(edges, node1);
        vector<int> dist2 = getDistances(edges, node2);

        int answer = -1;
        int minDistance = MAX_DISTANCE;

        for (int i = 0; i < edges.size(); ++i) {
            if (dist1[i] != -1 && dist2[i] != -1) {  // Node is reachable from both
                int maxDist = max(dist1[i], dist2[i]);
                if (maxDist < minDistance) {
                    minDistance = maxDist;
                    answer = i;
                }
            }
        }

        return answer;
    }

private:
    vector<int> getDistances(const vector<int>& edges, int start) {
        int n = edges.size();
        vector<int> dist(n, -1);
        int current = start;
        int steps = 0;

        while (current != -1 && dist[current] == -1) {
            dist[current] = steps++;
            current = edges[current];
        }

        return dist;
    }
};
