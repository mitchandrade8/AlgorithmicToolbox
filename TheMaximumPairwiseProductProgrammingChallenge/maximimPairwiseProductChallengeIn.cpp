
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;


long long MaxPairwiseProduct(const vector<int>& numbers) {

    // Initialize result
    long long result = 0;
    int n = numbers.size();

    // Nested Loop
        // Will Loop through all elements in a given array
            // Then compare to see if the element is the biggest thus far
    for (int i = 0; i < n; ++i) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long)numbers[i]) * numbers[j] > result) {
                result = ((long long)numbers[i]) * numbers[j];
            }
        }
    }

    return result;
}


long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    // Find the first maximal element in array 
    int max_index1 = -1;
    for (int i = 0; i < n; i++)
        if ((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
        max_index1 = i;

    // Find the second maximal element in array, must ignore the first maximal element
    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
        if ((numbers[j] != numbers[max_index1] && ((max_index2 == -1) || numbers[j] > numbers[max_index2])))
        max_index2 - j;

    return ((long long) (numbers[max_index1])) * numbers[max_index2];
}


int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    long long result = MaxPairwiseProductFast(numbers);
    cout << result << "\n";
    return 0;
}