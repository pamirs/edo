#include <iostream>
#include <vector>
#include "cppunit/TestAssert.h"
#include <string>
#include <chrono>


using std::vector;
using std::cin;
using std::cout;



int MaxPairwiseProduct(const vector<int>& numbers) {
  int n = numbers.size();

  int max1 = 0;
  int max2 = 0;

  for (int i = 0; i < n; ++i) {
      if (numbers[i] > max1){
        max1 = numbers[i];
      }else if (numbers[i] > max2){
        max2 = numbers[i];
      }
  }

return max1 * max2;
}

int main() {
    int n;
    cin >> n;
    vector<int> numbers(n);
    for (int i = 0; i < n; ++i) {
        cin >> numbers[i];
    }

    auto start = std::chrono::steady_clock::now();
    int result = MaxPairwiseProduct(numbers);
    auto end = std::chrono::steady_clock::now();
    auto diff = end - start;
    cout << result << "\n";
    std::cout << std::endl;
    std::cout << "Microseconds: " << std::chrono::duration <double,std::micro> (diff).count() << " us" << std::endl;
    return 0;
}
