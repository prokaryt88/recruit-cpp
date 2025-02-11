#include <iostream>
#include <iomanip>
#include <vector>
#include <string>
#include <cstring>

/*
Exercise: Basic Statistics Calculator

Implement a Statistics calculator that can process a series of integers and compute basic statistics.

Requirements:
1. Complete the Stats class implementation below
2. The class should store the following statistics:
   - sum: The sum of all numbers
   - max: The maximum value
   - avg: The average (mean) value as a double
3. The program should handle standard input correctly in normal mode

Notes:
- Handle empty input appropriately
- Consider edge cases like negative numbers
- The calculate() method should process the input vector and update all statistics
*/

class Stats {
    public:
        Stats() = default;
        Stats(const std::vector<int>& data) {
            calculate(data);
        }

        void calculate(const std::vector<int>& data);

        int sum{0};
        int max{0};
        double avg{0.0};
};

void
Stats::calculate(const std::vector<int>& data) {
    // TODO: Implement this method
    // It should process the input vector and update sum, max, and avg
    sum = 0;
    max = INT_MIN;
    for( auto & it : data){
        sum += it;
        max = (it > max) ? it : max;
    }
    avg  = static_cast<double>(sum) / static_cast<double>(data.size());

}

int main(int argc, char** argv) {
    std::vector<int> data;
    // Read integers from stdin into data until EOF or invalid input
    std::copy(std::istream_iterator<int>(std::cin),
        std::istream_iterator<int>(),
        std::back_inserter(data)
    );
    
    // Exit with appropriate message if input is invalid
    Stats s(data);
    
    std::cout << "Count: " << data.size() << std::endl;
    std::cout << "Sum:   " << s.sum << std::endl;
    std::cout << "Max:   " << s.max << std::endl;
    std::cout << "Avg:   " << std::fixed << std::setprecision(6)
              << s.avg << std::endl;
    
    return 0;
}
