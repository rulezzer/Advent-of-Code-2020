#include <iostream>
#include <string>
#include <fstream>
#include <vector>
#include <random>
#include <iterator>

using namespace std;

template<typename Iter, typename RandomGenerator>
Iter select_randomly(Iter start, Iter end, RandomGenerator& g) {
    std::uniform_int_distribution<> dis(0, std::distance(start, end) - 1);
    std::advance(start, dis(g));
    return start;
}

template<typename Iter>
Iter select_randomly(Iter start, Iter end) {
    static std::random_device rd;
    static std::mt19937 gen(rd());
    return select_randomly(start, end, gen);
}


int main(){

    int a, b, c, sum = 0;
    vector<int> iAoC;

    ifstream infile("inputAdventOfCode.txt");

    while (infile >> a)
        iAoC.push_back(a);

    while (sum!=2020){
        a = *select_randomly(iAoC.begin(), iAoC.end());
        b = *select_randomly(iAoC.begin(), iAoC.end());
        c = *select_randomly(iAoC.begin(), iAoC.end());
        sum=a+b+c;
    }
    cout << a << " + " << b << " + " << c << " = " << sum << endl;
    cout << "Solution: " << a*b*c << endl;

    return 0;
}
