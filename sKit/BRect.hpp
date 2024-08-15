#pragma once
#include <cmath>
#include <memory>
#include <optional>
#include <vector>

namespace s {
namespace Kit {

struct vec2 {
  int x, y;
};

/**
 * @brief Binary Rectangle. A rectangle that is recursively and evenly
 * subdivided along alternating axes.
 */
template <typename Derived>
class BRectBase : public std::enable_shared_from_this<Derived> {
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
  BRectBase(float _x, float _y, float _w, float _h, int numLevels,
            bool _vertical = true, vec2 _id = {0, 0})
      : x(_x),
        y(_y),
        width(_w),
        height(_h),
        levels(numLevels),
        vertical(_vertical),
        id(_id) {
    if (numLevels < 0) {
      throw std::runtime_error("numLevels must be a positive integer!");
    }

    if (numLevels == 0) {
      return;
    }

    float t = 0.5;
    if (vertical) {
      float x1 = x;
      float x2 = x + width * t;
      float w1 = width * t;
      float w2 = width - width * t;
      left = std::make_shared<Derived>(x1, y, w1, height, numLevels - 1,
                                       !vertical, vec2{id.x * 2, id.y});
      right = std::make_shared<Derived>(x2, y, w2, height, numLevels - 1,
                                        !vertical, vec2{id.x * 2 + 1, id.y});
    } else {
      float y1 = y;
      float y2 = y + height * t;
      float h1 = height * t;
      float h2 = height - height * t;
      left = std::make_shared<Derived>(x, y1, width, h1, numLevels - 1,
                                       !vertical, vec2{id.x, id.y * 2});
      right = std::make_shared<Derived>(x, y2, width, h2, numLevels - 1,
                                        !vertical, vec2{id.x, id.y * 2 + 1});
    }
  };

  /** @return All leaf nodes of the current `BRect`, i.e. nodes without `left`
   * and without `right` children. */
  auto getLeaves() -> std::vector<std::shared_ptr<Derived>> {
    std::vector<std::shared_ptr<Derived>> leaves;
    if (left) {  // then there MUST also be a right
      for (auto p : left->getLeaves()) {
        leaves.push_back(p);
      }
      for (auto p : right->getLeaves()) {
        leaves.push_back(p);
      }
    } else {
      leaves.push_back(
          std::static_pointer_cast<Derived>(this->shared_from_this()));
    }
    return leaves;
  };

  auto getLeafAt(int x, int y) -> std::optional<std::shared_ptr<Derived>> {
    for (auto leaf : getLeaves()) {
      if (leaf->id.x == x && leaf->id.y == y) {
        return leaf;
      }
    }
    return std::nullopt;
  };

  /**
   * @return The number of leaf columns
   */
  inline constexpr int getNumCols() {
    int exp = (levels / 2) + (levels % 2);
    return pow(2, exp);
  };

  /**
   * @return The number of leaf rows
   */
  inline constexpr int getNumRows() { return pow(2, levels / 2); };

  float x, y, width, height;
  std::shared_ptr<Derived> left, right;

 protected:
  vec2 id;
  int levels;
  bool vertical;
};

class BRect : public BRectBase<BRect> {
 public:
  using BRectBase<BRect>::BRectBase;
};

}  // namespace Kit
}  // namespace s