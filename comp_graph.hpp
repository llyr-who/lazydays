#include <memory>
/**
 * An early prototype of the computation graph.
 * As we are only interested in binary operations
 * (for use with solvant) we can simplify things
 * a lot.
 */
template <typename T>
class comp_graph {
private:
    // clang-format off
    struct comp_node {
        std::unique_ptr<T>          m_node;          // e.g T = matrix<float>
        int                         m_operation;     // +,-,...
        std::unique_ptr<comp_node>  m_l;             // 
        std::unique_ptr<comp_node>  m_r;
    };
    // clang-format on
    std::unique_ptr<comp_node> m_head;

public:
    constexpr void add_item(int operation, std::unique_ptr<T> l,
                            std::unique_ptr<T> r, std::unique_ptr<T> result) {
        // create (new) head
        h_node = std::make_unique<comp_node>();
        // 
        l_node = std::make_unique<comp_node>();
        l_node->m_node = std::move(l);
        r_node = std::make_unique<comp_node>();
        r_node->m_node = std::move(r);

        h_node->m_l = std::move(l_node);
        h_node->m_r = std::move(r_node);

        h_node->m_node = std::move(result);
        h_node->m_operation = operation;
        if (!m_head) {
            // if the head is null
            m_head = std::move(h_node);
        } else {
            // yes, else what?
            // this assumes that l or r
            // are m_head - this would involve some search right?
            // the search carried out by the graph factory object?
        }
    }
};
