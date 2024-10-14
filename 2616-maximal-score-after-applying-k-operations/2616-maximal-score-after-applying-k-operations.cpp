class Solution {
public:
    long long maxKelements(vector<int>& nums, int k) {
    // Max-heap (using negative values to simulate max-heap in priority_queue)
    priority_queue<long long> maxHeap; // Use long long for large values
    
    // Insert all elements of nums into the heap (negate them to simulate max-heap)
    for (int num : nums) {
        maxHeap.push(num); // We don't negate here since we are simulating max-heap with priority_queue
    }

    long long score = 0; // Use long long to avoid overflow
    
    // Perform exactly k operations
    for (int i = 0; i < k; ++i) {
        // Get the largest element
        long long top = maxHeap.top();
        maxHeap.pop();
        
        // Add it to the score
        score += top;
        
        // Replace the element with ceil(top / 3.0)
        long long updatedVal = ceil(top / 3.0);
        
        // Push the updated value back into the heap
        maxHeap.push(updatedVal);
    }
    
    return score;
    }
};