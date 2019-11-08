#include <functional>
#include <iostream>
#include <mutex>
#include <optional>
#include <string>

template <typename F>
class comp_store {
private:
    F m_computation;

public:
    comp_store(F function) : m_computation(function) {}
    void print() {
        std::cout << m_computation << std::endl;
    }
};

int sum(int a, int b) { 
    std::cout << "asd" << std::endl;    
    return a + b;
}

int main(int argc, char *argv[]) {
    int a, b;
    a = 4;
    b = 5;
    
    // in c++17 we can use automatic template
    // deduction for types (make sure -std=c++17
    // is supported)
    comp_store comp(sum(a,b));

    // in the above call, sum(a,b) is actually
    // called and the result 9 is stored in
    // computation

    // what is actually stored?
    comp.print();
}

