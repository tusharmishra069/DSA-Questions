class Solution {
public:
    int maximumSwap(int num) {
        string numStr = to_string(num);
    int n = numStr.size();
    vector<int> lastIndex(10, -1);

    for (int i = 0; i < n; i++) {
        lastIndex[numStr[i] - '0'] = i;
    }
    for (int i = 0; i < n; i++) {
        
        for (int d = 9; d > numStr[i] - '0'; d--) {
        
            if (lastIndex[d] > i) {
                swap(numStr[i], numStr[lastIndex[d]]);

                return stoi(numStr);
            }
        }
    }

    return num;
    }
};