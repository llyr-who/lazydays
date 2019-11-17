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
        unq_ptr<comp_node> m_l;
        unq_ptr<comp_node> m_r;
    }
    unq_ptr<comp_node> head;
};
