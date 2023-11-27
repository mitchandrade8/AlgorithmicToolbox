
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

int MaxPairwiseProduct(const vector<int>& numbers) {

    // Initialize result
    int result = 0;
    int n = numbers.size();

    // Nested Loop
        // Will Loop through all elements in a given array
            // Then compare to see if the element is the biggest thus far
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (numbers[i] * numbers[j] > result) {
                result = numbers[i] * numbers[j];
            }
        }
    }

    return result;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    int result = MaxPairwiseProduct(numbers);
    cout << result << "\n";
    return 0;
}