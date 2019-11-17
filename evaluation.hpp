#include <mutex>
#include <optional>
/**
 * This object is responsable for "evaluating" the computation graph
 * and storing the result. The template parameter is a graph, which 
 * takes the same type as the evaluation object.
 */
template <template<typename T> graph>
class evaluation {
    // clang-format off
private:
    graph                      m_graph;
    mutable std::optional<T>   m_value;
    mutable std::mutex         m_value_lock;
    // clang-format on
public:
    evalution() {};
    evalution(evalution &&other)
        : m_computation(std::move(other.m_computation)) {}

    operator T () const {
        std::lock_guard<std::mutex> lock(m_value_lock);

        if (!m_value) {
            // trigger graph
            // so long as our implementation
            // is callable we should be good to go!
            //m_value = std::invoke(m_graph);
        }

        return *m_value;
    }
};

