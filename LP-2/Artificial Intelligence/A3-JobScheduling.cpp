#include<iostream>
#include <vector>
#include <algorithm>
using namespace std;

struct Job {
    int start;
    int end;
    int profit;
    int index; 
};

bool compareJobs(const Job& a, const Job& b) {
    return a.end < b.end;
}

pair<int, vector<int>> findMaxProfit(vector<Job>& jobs) {
    sort(jobs.begin(), jobs.end(), compareJobs);
    
    int n = jobs.size();
    vector<int> dp(n); // dp[i] stores the maximum profit until job i
    vector<int> selectedJobs(n, -1); // Stores the index of the selected job for each position
    
    dp[0] = jobs[0].profit;
    selectedJobs[0] = 0;
    
    for (int i = 1; i < n; ++i) {
        int latestNonConflict = -1;
        for (int j = i - 1; j >= 0; --j) {
            if (jobs[j].end <= jobs[i].start) {
                latestNonConflict = j;
                break;
            }
        }
        
        int include = jobs[i].profit;
        if (latestNonConflict != -1) {
            include += dp[latestNonConflict];
        }
        
        int exclude = dp[i - 1];
        
        if (include > exclude) {
            dp[i] = include;
            selectedJobs[i] = i;
        } else {
            dp[i] = exclude;
            selectedJobs[i] = selectedJobs[i - 1];
        }
    }
    
    vector<int> selectedOrder;
    int j = n - 1;
    while (j >= 0) {
        if (selectedJobs[j] == j) {
            selectedOrder.push_back(jobs[j].index);
            j--;
        } else 
            j--;
    }
    
    reverse(selectedOrder.begin(), selectedOrder.end());
    
    return make_pair(dp[n - 1], selectedOrder);
}

int main() {
    vector<Job> jobs = {
        {1, 4, 5, 0},
        {3, 5, 20, 1},
        {6, 7, 10, 2},
        {8, 9, 15, 3},
        {2, 6, 25, 4}
    };
    
    pair<int, vector<int>> result = findMaxProfit(jobs);
    cout << "Maximum profit: " << result.first << endl;
    cout << "Order of selected jobs: ";
    for (int index : result.second) {
        cout << index << " ";
    }
    cout << endl;
    
    return 0;
}
