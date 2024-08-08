#pragma once
#include <cmath>
#include <memory>
#include <vector>

namespace s {
namespace Kit {

struct vec2 {
  int x, y;
};

/**
 * Binary Rect.  A rectangle that is recursively and evenly subdivided along
 * alternated axes.
 */
class BRect : public std::enable_shared_from_this<BRect> {
 public:
  /**
   * @param _x x position of the top left corner
   * @param _y y position of the top left corner
   * @param _w width
   * @param _h height
   * @param numLevels number of subdivions
   * @param vertical whether the first division is vertical
   * @param _id the {x, y} id of the current BRect in the current level
   */
  BRect(float _x, float _y, float _w, float _h, int numLevels,
        bool vertical = true, vec2 _id = {0, 0});

  /** @return All leaf nodes of the current `BRect`, i.e. nodes without `left`
   * and without `right` children. */
  auto getLeaves() -> std::vector<std::shared_ptr<BRect>>;

  /**
   * @return The number of end columns
   */
  inline constexpr int getNumCols() {
    int exp = (levels / 2) + (levels % 2);
    return pow(2, exp);
  };

  /**
   * @return The number of end rows
   */
  inline constexpr int getNumRows() { return pow(2, levels / 2); };

  float x, y, width, height;
  std::shared_ptr<BRect> left, right;

 private:
  vec2 id;
  int levels;
};

}  // namespace Kit
}  // namespace s