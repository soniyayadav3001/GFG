class Solution {
  public:
    vector<int> maxOfSubarrays(vector<int>& arr, int k) {
        vector<int> result;
        deque<int> dq;  // Stores indices of useful elements in decreasing order
        
        for (int i = 0; i < arr.size(); i++) {
            // Remove elements that are out of the current window
            while (!dq.empty() && dq.front() <= i - k) {
                dq.pop_front();
            }
            
            // Remove smaller elements as they are not needed
            while (!dq.empty() && arr[dq.back()] <= arr[i]) {
                dq.pop_back();
            }
            
            // Add current element index
            dq.push_back(i);
            
            // Store the maximum element of the window
            if (i >= k - 1) {
                result.push_back(arr[dq.front()]);
            }
        }
        
        return result;
    }
};
