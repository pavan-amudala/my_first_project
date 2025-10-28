//generate a code with memory leak

#include <iostream>     
#include <cstdlib>
using namespace std;
void createMemoryLeak() {
    // Allocate memory on the heap
    int* leakArray = new int[10];
    
    // Intentionally forget to free the allocated memory
    // This will cause a memory leak
}
int main() {
    for (int i = 0; i < 10; ++i) {
        createMemoryLeak();
    }
    
    cout << "Memory leak created by allocating memory without freeing it." << endl;
    return 0;
}