

#include <cstdlib>
#include <iostream>
#include <vector>

using std::vector;
using std::cin;
using std::cout;

long long MaxPairwiseProduct(const vector<int>& numbers) {
    long long result = 0;
    int n = numbers.size();

    for (int i = 0; i < n; i++) {
        for (int j = i + 1; j < n; ++j) {
            if (((long long) numbers[i]) * numbers[j] > result) {
                result = ((long long) (numbers[i])) * numbers[j];
            }
        }
    }

    return result;
}


long long MaxPairwiseProductFast(const vector<int>& numbers) {
    int n = numbers.size();

    int max_index1 = -1;
    for (int i = 0; i < n; ++i)
        if((max_index1 == -1) || (numbers[i] > numbers[max_index1]))
            max_index1 = i;

    int max_index2 = -1;
    for (int j = 0; j < n; ++j)
        // Original Code:
        // if((numbers[j] != numbers[max_index1]) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
        if ((j != max_index1) && ((max_index2 == -1) || (numbers[j] > numbers[max_index2])))
            max_index2 = j;

    cout << max_index1 << ' ' << max_index2 << "\n";

    return ((long long)(numbers[max_index1])) * numbers[max_index2];

}

int main() {

    // Stress Test:
    while (true) {
        //  'rand()' = Generate a large random number
            // a number between 0-9 and we add 2: random number between '2-11'

        // int n = rand() % 4 + 2;
        // Increased n:
        int n = rand() % 100 + 2;
        cout << n << "\n";
        vector<int> a;
        for (int i = 0; i < n; ++i) {
            // range of Array allowed: '0-99,999'
            
            // a.push_back(rand() % 10);
            // Increased range:
            a.push_back(rand() % 100000);
        }

        // Output the numbers in a single line seperated by ' ' spaces.
        for (int i = 0; i < n; ++i) {
            cout << a[i] << ' ';
        } 

        cout << "\n";
        long long res1 = MaxPairwiseProduct(a);
        long long res2 = MaxPairwiseProductFast(a);

        // Compare the results of the 2 algorithms
        if (res1 != res2) {
            cout << "Wrong answer: " << res1 << ' ' << res2 << "\n";
            break;
        } else {
            cout << "OK\n";
        }
    }

    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    return 0;

}