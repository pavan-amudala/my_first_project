//write a singleton pattern example in c++
#include <iostream>
#include <mutex>
class Singleton {
private:
    static Singleton* instance;
    static std::mutex mutex_;

    // Private constructor to prevent instantiation
    Singleton() {
        std::cout << "Singleton Instance Created" << std::endl;
    }

    // Delete copy constructor and assignment operator
    Singleton(const Singleton&) = delete;
    Singleton& operator=(const Singleton&) = delete;
public:
    static Singleton* getInstance() {
        std::lock_guard<std::mutex> lock(mutex_);
        if (instance == nullptr) {
            instance = new Singleton();
        }
        return instance;
    }
    void showMessage() {
        std::cout << "Hello from Singleton!" << std::endl;
    }
};
Singleton* Singleton::instance = nullptr;
std::mutex Singleton::mutex_;
int main() {
    Singleton* singleton1 = Singleton::getInstance();
    singleton1->showMessage();

    Singleton* singleton2 = Singleton::getInstance();
    singleton2->showMessage();

    if (singleton1 == singleton2) {
        std::cout << "Both instances are the same." << std::endl;
    } else {
        std::cout << "Instances are different!" << std::endl;
    }

    return 0;
}
