// AOC_day_5.cpp : This file contains the 'main' function. Program execution begins and ends there.
//

#include <iostream>
#include <vector>
#include <string>
#include <fstream>
#include <sstream>
using namespace std;
vector<int> adj[1000];
vector<int> sorted;
vector<int> nodes;
bool visited[1000];
int sum;
void toposort(int x) {
    if (visited[x])
        return;
    visited[x] = 1;
    for (auto i : adj[x]) {
        if (find(nodes.begin(), nodes.end(), i) != nodes.end()) {
            toposort(i);
        }
    }
    sorted.push_back(x);
}
int main()
{
    ifstream cin("input.in");
    ofstream cout("output.out");
    int a, b;
    char bar;
    while (cin >> a >> bar >> b) {
        adj[a].push_back(b);
        if (b == -12)
            break;
    }
    string line;
    getline(cin, line);
    getline(cin, line);

    while (getline(cin, line)) {
        stringstream s(line);
        int x = 0;
        char comma;
        while (s >> x) {
            s >> comma;
            nodes.push_back(x);
        }
        for (auto i : nodes) {
            if (!visited[i]) {
                toposort(i);
            }
        }
        reverse(sorted.begin(), sorted.end());
        if (sorted != nodes) {
            sum += sorted[sorted.size() / 2];
        }
        for (auto i : nodes) {
            visited[i] = 0;
        }
        sorted.clear();
        nodes.clear();


    }
    cout << sum;

}

// Run program: Ctrl + F5 or Debug > Start Without Debugging menu
// Debug program: F5 or Debug > Start Debugging menu

// Tips for Getting Started: 
//   1. Use the Solution Explorer window to add/manage files
//   2. Use the Team Explorer window to connect to source control
//   3. Use the Output window to see build output and other messages
//   4. Use the Error List window to view errors
//   5. Go to Project > Add New Item to create new code files, or Project > Add Existing Item to add existing code files to the project
//   6. In the future, to open this project again, go to File > Open > Project and select the .sln file
