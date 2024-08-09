#define DOCTEST_CONFIG_IMPLEMENT_WITH_MAIN
#include <doctest/doctest.h>

#include <sKit/BRect.hpp>

TEST_SUITE("BRect") {
  s::Kit::BRect lv0(0, 0, 100, 100, 0);
  s::Kit::BRect lv1(0, 0, 100, 100, 1);
  s::Kit::BRect lv2(0, 0, 100, 100, 2);
  s::Kit::BRect lv3(0, 0, 100, 100, 3);
  s::Kit::BRect lv4(0, 0, 100, 100, 4);
  s::Kit::BRect lv5(0, 0, 100, 100, 5);
  s::Kit::BRect lv6(0, 0, 100, 100, 6);
  s::Kit::BRect lv7(0, 0, 100, 100, 7);

  TEST_CASE("Num Cols") {
    CHECK_EQ(lv0.getNumCols(), 1);
    CHECK_EQ(lv1.getNumCols(), 2);
    CHECK_EQ(lv2.getNumCols(), 2);
    CHECK_EQ(lv3.getNumCols(), 4);
    CHECK_EQ(lv4.getNumCols(), 4);
    CHECK_EQ(lv5.getNumCols(), 8);
    CHECK_EQ(lv6.getNumCols(), 8);
    CHECK_EQ(lv7.getNumCols(), 16);
  }

  TEST_CASE("Num Rows") {
    CHECK_EQ(lv0.getNumRows(), 1);
    CHECK_EQ(lv1.getNumRows(), 1);
    CHECK_EQ(lv2.getNumRows(), 2);
    CHECK_EQ(lv3.getNumRows(), 2);
    CHECK_EQ(lv4.getNumRows(), 4);
    CHECK_EQ(lv5.getNumRows(), 4);
    CHECK_EQ(lv6.getNumRows(), 8);
    CHECK_EQ(lv7.getNumRows(), 8);
  }

  TEST_CASE("Get leaf by id") {
    s::Kit::BRect r(0, 0, 100, 100, 1);
    SUBCASE("should pass") {
      CHECK_NE(r.getLeafAt(0, 0), std::nullopt);
      CHECK_NE(r.getLeafAt(1, 0), std::nullopt);
    }
    SUBCASE("should fail") { CHECK_EQ(r.getLeafAt(20, 20), std::nullopt); }
  }
}