#include <iostream>
#include <vector>
#include <fstream>
#include <sstream>
#include <string>

int main() {
//input reader and parser
    std::ifstream file("input.txt");
    if (!file) {
        std::cerr << "Error opening file\n";
        return 1;
    }
    // Vectors needed 
    std::vector<std::vector<int>> alloc;
    std::vector<std::vector<int>> max;
    std::vector<int> avail;

    for (int i = 0; i < 3; i++) {
        std::string line;
        std::getline(file, line);

        bool insideBraces = false;
        std::string number;

        std::vector<std::vector<int>> result;
        std::vector<int> currentVec;

        for (char c : line) {
            if (c == '{') {
                insideBraces = true;
                currentVec.clear();
                number.clear();
            }
            else if (isdigit(c) || c == '-') {
                number += c;
            }
            else if (c == ',' || c == ' ' || c == '}') {
                if (!number.empty()) {
                    currentVec.push_back(std::stoi(number));
                    number.clear();
                }
                if (c == '}') {
                    insideBraces = false;
                    result.push_back(currentVec);
                }
            }
        }

        if (i == 0) {
            alloc = result;
        }
        else if (i == 1) {
            max = result;
        }
        else {
            avail = currentVec;
        }
    }
/////////////////////////////////////////////////////////////////////////////////////////////
//Bankers algiorithm
    int numP = 5;
    int numR = 3;

    std::vector<int> f(numP, 0);
    std::vector<int> ans(numP);
    int ind = 0;

    std::vector<std::vector<int>> need(numP, std::vector<int>(numR));

    // Calculate Need matrix
    for (int i = 0; i < numP; i++) {
        for (int j = 0; j < numR; j++) {
            need[i][j] = max[i][j] - alloc[i][j];
        }
    }

    // Banker's Algorithm
    for (int k = 0; k < numP; k++) {
        for (int i = 0; i < numP; i++) {
            if (f[i] == 0) {
                bool flag = false;

                for (int j = 0; j < numR; j++) {
                    if (need[i][j] > avail[j]) {
                        flag = true;
                        break;
                    }
                }

                if (!flag) {
                    ans[ind++] = i;
                    for (int y = 0; y < numR; y++) {
                        avail[y] += alloc[i][y];
                    }
                    f[i] = 1;
                }
            }
        }
    }

    // Output Safe Sequence
    std::cout << "The safe sequence:\n";
    for (int i = 0; i < numP - 1; i++) {
        std::cout << "P" << ans[i] << " -> ";
    }
    std::cout << "P" << ans[numP - 1] << std::endl;

    return 0;
}
