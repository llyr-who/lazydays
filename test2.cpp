
#include <functional>
#include <iostream>
#include <mutex>
#include <optional>
#include <string>

template <typename F>
class lazy_val {
private:
    F m_computation;
    mutable std::optional<decltype(m_computation())> m_value;

public:
    lazy_val(F function) : m_computation(function) {}

    operator decltype(m_computation())() const {
        if (!m_value) {
            m_value = std::invoke(m_computation);
        }

        return *m_value;
    }
};


int main(int argc, char *argv[]) {
    int number = 6;
    
    auto val = lazy_val ({
        std::cout << number << std::endl;
        return 10;
    })

    number = 100;

    std::cout << val << std::endl;
    
}

