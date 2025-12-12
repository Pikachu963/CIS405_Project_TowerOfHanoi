#include <iostream>
#include <chrono>

using namespace std;
using namespace std::chrono;

int totalMoves = 0;

void towerOfHanoi(int n, char sourceRod, char auxiliaryRod, char destinationRod) {
    if (n <= 0) {
        cout << "No disks - no moves occurred." << endl;
        return;
    }
    if (n == 1) {
        cout << "Moved Disk " << n << " from " << sourceRod << " to " << destinationRod << endl;
        totalMoves++;
        return;
    }

    towerOfHanoi(n - 1, sourceRod, destinationRod, auxiliaryRod);

    cout << "Moved Disk " << n << " from " << sourceRod << " to " << destinationRod << endl;
    totalMoves++;

    towerOfHanoi(n - 1, auxiliaryRod, sourceRod, destinationRod);
}

int main() {
    int num = 0;
    char source = 'A';
    char aux = 'C';
    char dest = 'B';

    cout << "Initial State: " << endl;
    if (num > 0) {
        for (int i = num; i >= 1; --i) {
            cout << "  Disk " << i << " is on Rod " << source << endl;
        }
        cout << "All other rods (" << dest << " and " << aux << ") are empty." << endl;
        cout << "Starting the sequence of moves:" << endl << endl;
    }

    auto start = high_resolution_clock::now();

    towerOfHanoi(num, source, aux, dest);

    auto stop = high_resolution_clock::now();

    auto duration = duration_cast<chrono::microseconds>(stop - start);

    cout << "\nExecution Summary:" << endl;
    cout << "Number of Disks: " << num << endl;
    cout << "Total moves made: " << totalMoves << endl;
    cout << "Time taken by the towerOfHanoi function call: " << duration.count() << " microseconds" << endl;

    return 0;
}
    