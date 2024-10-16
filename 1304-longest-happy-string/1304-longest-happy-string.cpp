class Solution {
public:
    string longestDiverseString(int a, int b, int c) {
        priority_queue<pair<int, char>> pq;

        if (a > 0) pq.push({a, 'a'});
        if (b > 0) pq.push({b, 'b'});
        if (c > 0) pq.push({c, 'c'});

        string result = "";

       
        while (!pq.empty()) {
            auto first = pq.top();
            pq.pop();

            
            int n = result.size();
            if (n >= 2 && result[n - 1] == first.second && result[n - 2] == first.second) {
                
                if (pq.empty()) break;

                
                auto second = pq.top();
                pq.pop();
                result += second.second;
                second.first--;
                if (second.first > 0) pq.push(second);
                pq.push(first);
            } else {
                result += first.second;
                first.first--;
                if (first.first > 0) pq.push(first);
            }
        }

        return result;
    }
};