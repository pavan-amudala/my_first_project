#include <iostream>
#include <memory>  // for std::unique_ptr

int main() {
    // ✅ smart pointer automatically deletes memory when it goes out of scope
    std::unique_ptr<int> ptr = std::make_unique<int>(10);

    std::cout << "Value: " << *ptr << std::endl;

    // No need to call delete — unique_ptr handles it automatically
    return 0;
}
