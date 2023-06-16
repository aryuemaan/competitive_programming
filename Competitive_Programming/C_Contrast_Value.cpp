#include <iostream>
#include <vector>
#include <unordered_map>
using namespace std;

int minSizeOfB(vector<int>& a) {
    unordered_map<int, int> freq;
    int n = a.size();
    
    // Count the frequency of each element in array a
    for (int i = 0; i < n; i++) {
        freq[a[i]]++;
    }
    
    int numDistinctElements = freq.size();
    
    // If there are more than two distinct elements, the minimum size of b is 2
    if (numDistinctElements > 2) {
        return 2;
    }
    
    // If there are two distinct elements, check if they are equal
    if (numDistinctElements == 2) {
        auto it = freq.begin();
        int firstElement = it->first;
        int firstElementCount = it->second;
        it++;
        int secondElement = it->first;
        int secondElementCount = it->second;
        
        // If the two distinct elements have the same count, the minimum size of b is 1
        if (firstElementCount == secondElementCount) {
            return 1;
        }
    }
    
    // For all other cases, the minimum size of b is 2
    return 2;
}

int main() {
    int t;
    cin >> t;
    
    while (t--) {
        int n;
        cin >> n;
        
        vector<int> a(n);
        for (int i = 0; i < n; i++) {
            cin >> a[i];
        }
        
        int answer = minSizeOfB(a);
        cout << answer << endl;
    }
    
    return 0;
}
