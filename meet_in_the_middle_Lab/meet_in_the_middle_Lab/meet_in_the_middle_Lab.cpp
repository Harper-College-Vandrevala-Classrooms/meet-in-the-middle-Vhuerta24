#include <iostream>
#include <fstream>
#include <sstream>
#include <vector>
#include <string>
#include <unordered_map>
#include <algorithm>

using namespace std;

// Function to calculate the median
double calculateMedian(const vector<int>& numbers) {
    int n = numbers.size();
    if (n % 2 == 1) {
        return numbers[n / 2]; // If odd, return middle element
    }
    else {
        return (numbers[(n / 2) - 1] + numbers[n / 2]) / 2.0; // If even, average the two middle elements
    }
}

// Function to calculate the mode (2 extra credit for portfolio 2) 
vector<int> calculateMode(const vector<int>& numbers) {
    unordered_map<int, int> frequencyMap;
    int maxFrequency = 0;

    // Counting the frequency of each number
    for (int num : numbers) {
        frequencyMap[num]++;
        maxFrequency = max(maxFrequency, frequencyMap[num]);
    }

    // Collecting numbers with the highest frequency (the mode)
    vector<int> mode;
    for (const auto& entry : frequencyMap) {
        if (entry.second == maxFrequency) {
            mode.push_back(entry.first);
        }
    }
    return mode;
}

// Function to read CSV file
vector<int> readCSV(const string& filename) {
    ifstream file(filename);
    vector<int> numbers;
    string line, number;

    if (file.is_open()) {
       
        getline(file, line);
        stringstream ss(line);

        
        while (getline(ss, number, ',')) {
            numbers.push_back(stoi(number));
        }

        file.close();
    }
    else {
        cerr << "Sorry, unable to open file.\n";
    }

    return numbers;
}

int main() {
    string filename;
    cout << "Enter the filename: ";
    cin >> filename;

    vector<int> numbers = readCSV(filename);

    if (numbers.empty()) {
        cout << "No data found in file or unable to read file.\n";
        return 1;
    }

    // Calculating the median
    double median = calculateMedian(numbers);
    cout << "The median is: " << median << endl;

    // Calculating the mode
    vector<int> mode = calculateMode(numbers);
    cout << "The mode is: ";
    if (mode.size() == 1) {
        cout << mode[0] << endl;  //  one mode
    }
    else {
        for (int m : mode) {
            cout << m << " ";  //  multiple modes
        }
        cout << endl;
    }

    return 0;
}
