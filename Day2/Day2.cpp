#include <iostream>
#include <fstream>
#include <vector>
#include <algorithm>

using namespace std;

int main() {

    int min, max, counter = 0, counter2 = 0;
    char c;
    string s;
    vector<int> iAoC;

    ifstream infile("inputDay2.txt");

    while (infile >> min >> max >> c >> s >> s){
        if (count(s.begin(), s.end(), c) >= min && count(s.begin(), s.end(), c) <= abs(max))
            counter++;
        if ((s.at(min-1) == c || s.at(abs(max)-1) == c) && !(s.at(min-1) == c && s.at(abs(max)-1) == c))
            counter2++;
    }
    cout << "Solution1: "<< counter << "\nSolution2: "<< counter2 << endl;

    return 0;
}
