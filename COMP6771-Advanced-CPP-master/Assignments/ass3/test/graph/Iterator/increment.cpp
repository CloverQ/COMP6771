// We don't own this macro; don't prefix it with `COMP6771_`.
#define CATCH_CONFIG_MAIN // NOLINT(readability-identifier-naming)
#include "catch2/catch.hpp"

#include "gdwg/graph.hpp"

TEST_CASE("increment_post") {
    using graph = gdwg::graph<int, int>;
    using value_type = gdwg::graph<int,int>::value_type;
    auto g = graph{1,2,3,4,5};
    g.insert_edge(1,2,3);
    g.insert_edge(1,2,7);
    g.insert_edge(1,2,4);
    g.insert_edge(1,2,6);
    auto it = g.begin();
    CHECK(*it == value_type{1,2,3});
    it = it++;
    CHECK(*it == value_type{1,2,4});
}

TEST_CASE("increment_pre") {
    using graph = gdwg::graph<int, int>;
    using value_type = gdwg::graph<int,int>::value_type;
    auto g = graph{1,2,3,4,5};
    g.insert_edge(1,2,3);
    g.insert_edge(1,2,7);
    g.insert_edge(1,2,4);
    g.insert_edge(1,2,6);
    auto it = g.begin();
    CHECK(*it == value_type{1,2,3});
    ++it;
    CHECK(*it == value_type{1,2,4});
}