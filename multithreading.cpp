//write a simple multithreading simple example in c++
#include <iostream>
#include <thread>
#include <vector>
using namespace std;
void printNumbers(int start, int end) {
    for (int i = start; i <= end; ++i) {
        cout << i << " ";
    }
    cout << endl;
}
int main() {
    // Create threads
    thread t1(printNumbers, 1, 5);
    thread t2(printNumbers, 6, 10);
    
    // Wait for threads to finish
    t1.join();
    t2.join();
    
    cout << "Finished printing numbers from multiple threads." << endl;
    return 0;
} 