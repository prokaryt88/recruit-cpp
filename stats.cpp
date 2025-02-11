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
    if(data.empty()){
        return;
    }
    
    sum = 0;
    max = data.front();
    for( auto & it : data){
        sum += it;
        max = (it > max) ? it : max;
    }
    avg  = static_cast<double>(sum) / static_cast<double>(data.size());

}

class StatsTest : Stats {
    public:
        struct testCase{
            std::vector<int> data {};
            long realSum {0};
            long realMax {0};
            double realAvg {0};
        };        
        void runTest(const testCase& tC);
        int getResult(){ return this->ret; }

    private:        
        void vectorPrint(const std::vector<int>& data);
        int ret {0};
}; 

void
StatsTest::vectorPrint(const std::vector<int>& data){
    std::cout << '{';
    for(auto & it : data){
        std::cout << it;
        if(it != data.back()){
            std::cout << ", ";
        }
    }
    std::cout << '}' << std::endl;

    return;
};

void
StatsTest::runTest(const testCase& tC){
    std::cout << "Testing ";
    vectorPrint(tC.data);

    calculate(tC.data);

    if(tC.realSum != static_cast<long>(this->sum) || 
       tC.realMax != static_cast<long>(this->max) || 
       tC.realAvg != static_cast<long>(this->avg)
    ){
        this->ret = 1;
    }

    std::cout <<"Count: " << tC.data.size() << std::endl;
    std::cout << std::left << "Calculated Sum: " << std::setw(20) << this->sum 
              << "Correct Sum: " << std::setw(20) << tC.realSum << std::endl;
    std::cout << "Calculated Max: " << std::setw(20) << this->max 
              << "Correct Max: " << std::setw(20) << tC.realMax << std::endl;
    std::cout << std::left << "Calculated Avg: " << std::fixed << std::setprecision(6)
              << std::setw(20) << this->avg
              << "Correct Avg: " << std::fixed << std::setprecision(6)
              << std::setw(20) << tC.realAvg << std::endl;
    
    if (this->ret == 0){
        std::cout << "*** PASS ***\n" << std::endl;
    }
    else{
        std::cout << "*** FAIL ***\n" << std::endl;
    }
    
    return;
}

int main(int argc, char** argv) {
    // unit testing
    if(argc == 2){
        auto test = std::string(argv[1]);
        int ret = 0;

        if(test == "--test"){
            StatsTest::testCase emptyVector;
            emptyVector.data = std::vector<int>{};
            emptyVector.realSum = 0;
            emptyVector.realMax = 0;
            emptyVector.realAvg = 0.0;

            StatsTest::testCase intMax;
            intMax.data = std::vector<int>{2147483647, 1};
            intMax.realSum = 2147483648;
            intMax.realMax = 2147483647;
            intMax.realAvg = static_cast<double>(2147483648)/2.0;

            StatsTest::testCase intMin;
            intMin.data= std::vector<int>{-2147483648, -1};
            intMin.realSum = -2147483649;
            intMin.realMax = -1;
            intMin.realAvg = static_cast<double>(-2147483649)/2.0;

            std::vector<StatsTest::testCase> tests = {emptyVector, intMax, intMin};
            for(auto & it : tests){
                StatsTest sT;
                sT.runTest(it);
                if(sT.getResult() == 1){
                    ret = 1;
                }
            }
            
            return ret;
        }
    }
    else if(argc > 2){
        std::cout << "Too many arguments" << std::endl;
        return 1;
    }

    std::vector<int> data;
    // Read integers from stdin into data until EOF or invalid input
    int input;
    while(std::cin >> input){
        data.emplace_back(input);
    }

    // Exit with appropriate message if input is invalid
    if(data.empty()){
        std::cout << "No input data..." << std::endl;
        return 1;
    }

    Stats s(data);
    
    std::cout << "Count: " << data.size() << std::endl;
    std::cout << "Sum:   " << s.sum << std::endl;
    std::cout << "Max:   " << s.max << std::endl;
    std::cout << "Avg:   " << std::fixed << std::setprecision(6)
              << s.avg << std::endl;
    
    return 0;
}
