#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <sKit/grids.hpp>

TEST_CASE("2x2 Grid should have correct points") {
  auto path = s::Kit::gridFillDiagonal(2, 2);
  std::vector<glm::ivec2> expected{{0, 0}, {1, 0}, {0, 1}, {1, 1}};
  for (std::size_t i = 0; i < path.size(); i++) {
    CHECK_EQ(path[i], expected[i]);
  }
}

TEST_SUITE("Sizes") {
  TEST_CASE("2x2 Grid should have 4 points") {
    auto path = s::Kit::gridFillDiagonal(2, 2);
    CHECK_EQ(path.size(), 4);
  }
  TEST_CASE("3x2 Grid should have 6 points") {
    auto path = s::Kit::gridFillDiagonal(3, 2);
    CHECK_EQ(path.size(), 6);
  }
  TEST_CASE("2x3 Grid should have 6 points") {
    auto path = s::Kit::gridFillDiagonal(2, 3);
    CHECK_EQ(path.size(), 6);
  }
  TEST_CASE("3x3 Grid should have 9 points") {
    INFO("3X3");
    auto path = s::Kit::gridFillDiagonal(3, 3);
    CHECK_EQ(path.size(), 9);
  }
  TEST_CASE("4x4 Grid should have 16 points") {
    auto path = s::Kit::gridFillDiagonal(4, 4);
    CHECK_EQ(path.size(), 16);
  }
  TEST_CASE("5x5 Grid should have 25 points") {
    auto path = s::Kit::gridFillDiagonal(5, 5);
    CHECK_EQ(path.size(), 25);
  }
}
