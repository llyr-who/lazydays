/**
 * An early prototype of the computation graph.
 * As we are only interested in binary operations
 * (for use with solvant) we can simplify things
 * a lot.
 */
template <typename T>
class comp_graph {
private:
    using unq_ptr = std::unique_ptr;
    struct comp_node {
        unq_ptr<T> m_node;
        int m_operation;
        unq_ptr<comp_node> m_l;
        unq_ptr<comp_node> m_r;
    };
    unq_ptr<comp_node> m_head;

public:
    constexpr void add_item(int operation, unq_ptr<T> l, unq_ptr<T> r,
                            unq_ptr<T> result) {
        // create a node
        h_node = std::make_unique<comp_node>();
        l_node = std::make_unique<comp_node>();
        r_node = std::make_unique<comp_node>();
        h_node->m_l = std::move(l);
        h_node->m_r = std::move(r);
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
