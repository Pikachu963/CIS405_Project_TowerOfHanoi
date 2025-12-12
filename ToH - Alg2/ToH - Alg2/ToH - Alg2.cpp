#include <iostream>
#include <stack>
#include <vector>
#include <algorithm>
#include <limits>
#include <chrono>
#include <cmath>
#include <numeric>
#include <iomanip>

using namespace std;

void performMove(stack<int>& fromRod, stack<int>& toRod, char fromName, char toName, int& totalMoveCount) {
    int disk = fromRod.top();
    fromRod.pop();
    toRod.push(disk);
    cout << "Moved disk " << disk << " from peg " << fromName << " to peg " << toName << "." << endl;
    totalMoveCount++;
}

void legalMove(stack<int>& pegA, stack<int>& pegB, char pegAName, char pegBName, int& totalMoveCount) {
    if (pegA.empty()) {
        performMove(pegB, pegA, pegBName, pegAName, totalMoveCount);
    }
    else if (pegB.empty()) {
        performMove(pegA, pegB, pegAName, pegBName, totalMoveCount);
    }
    else if (pegA.top() < pegB.top()) {
        performMove(pegA, pegB, pegAName, pegBName, totalMoveCount);
    }
    else {
        performMove(pegB, pegA, pegBName, pegAName, totalMoveCount);
    }
}

void towerOfHanoi(int n, int& totalMoveCount) {
    if (n <= 1) {
        if (n == 1) {
            cout << "Only one disk; a single move completes the puzzle." << endl;
            totalMoveCount++;
        }
        if (n == 0) {
            cout << "Zero disks, no moves necessary." << endl;
            totalMoveCount++;
        }
        return;
    }

    stack<int> source;
    stack<int> auxiliary;
    stack<int> destination;

    char sName = 'A';
    char aName = 'B';
    char dName = 'C';

    for (int i = n; i > 0; --i) {
        source.push(i);
    }

    cout << "\nInitial Disk Configuration:" << endl;
    for (int i = 1; i <= n; ++i) {
        cout << "Disk " << i << " starts on peg " << sName << "." << endl;
    }
    cout << endl;

    int totalMoves = static_cast<int>(pow(2, n)) - 1;
    cout << "\nStarting Tower of Hanoi for " << n << " disks. Total moves required: " << totalMoves << "." << endl;

    for (int i = 1; i <= totalMoves; ++i) {
        if (i % 3 == 1) {
            legalMove(source, destination, sName, dName, totalMoveCount);
        }
        else if (i % 3 == 2) {
            legalMove(source, auxiliary, sName, aName, totalMoveCount);
        }
        else {
            legalMove(auxiliary, destination, aName, dName, totalMoveCount);
        }
    }
    cout << "\nTower of Hanoi puzzle solved successfully." << endl;
}

int main() {
    int num = 3;
    int finalMoveTotal = 0;

    auto start = chrono::high_resolution_clock::now();

    towerOfHanoi(num, finalMoveTotal);

    auto end = chrono::high_resolution_clock::now();

    auto duration = chrono::duration_cast<chrono::microseconds>(end - start);

    cout << "Total moves executed and counted: " << finalMoveTotal << endl;
    cout << "\nRuntime of the towerOfHanoi function for " << num << " disks: " << duration.count() << " microseconds." << endl;

    return 0;
}
