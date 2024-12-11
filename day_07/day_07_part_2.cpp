#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
unsigned long long target;
unsigned long long sum;
bool add;
unsigned long long evaluateExpression( vector<unsigned long long>& numbers, const vector<char>& operators) {
    unsigned long long result = numbers[0];
    for (int i = 0; i < operators.size(); ++i) {
        if (operators[i] == '+') {
            result += numbers[i + 1];
        }
        else if (operators[i] == '*') {
            result *= numbers[i + 1];
        }
        else {
            result = stoll(to_string(result) + to_string(numbers[i + 1]));
        }
    }
    if (result == target&&add==1){
        sum += result;
        add = 0;
    }
    return result;
}

void generateCombinations( vector<unsigned long long>& numbers, vector<char>& operators, int index) {
    static const char availableOperators[] = { '+', '*', '|'};
    if (index == numbers.size() - 1) {
        cout << numbers[0];
        for (int i = 0; i < operators.size(); ++i) {
            cout << " " << operators[i] << " " << numbers[i + 1];
        }
        cout << " = " << evaluateExpression(numbers, operators) << endl;
        return;
    }
    for (char op : availableOperators) {
        if (add == 0)
            break;
        operators[index] = op;
        generateCombinations(numbers, operators, index + 1);
    }
}

int main() {
    
    ifstream cin("input.in");
    ofstream cout("output.out");
    string line;
    while (getline(cin, line)) {
        add = 1;
        stringstream s(line);
        vector<unsigned long long> numbers;
        long long x;
        char colon;
        s >> target;
        s >> colon;
        while (s >> x) {
            numbers.push_back(x);
        }
        vector<char> operators(numbers.size() - 1);

        generateCombinations(numbers, operators, 0);
        
    }
    cout << sum;
   

    
}
