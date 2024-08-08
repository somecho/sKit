#include <sKit/BRect.hpp>
#include <stdexcept>

s::Kit::BRect::BRect(float _x, float _y, float _w, float _h, int numLevels,
                     bool vertical, vec2 _id)
    : x(_x), y(_y), width(_w), height(_h), levels(numLevels), id(_id) {
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
    left = std::make_shared<BRect>(x1, y, w1, height, numLevels - 1, !vertical,
                                   vec2{id.x * 2, id.y});
    right = std::make_shared<BRect>(x2, y, w2, height, numLevels - 1, !vertical,
                                    vec2{id.x * 2 + 1, id.y});
  } else {
    float y1 = y;
    float y2 = y + height * t;
    float h1 = height * t;
    float h2 = height - height * t;
    left = std::make_shared<BRect>(x, y1, width, h1, numLevels - 1, !vertical,
                                   vec2{id.x, id.y * 2});
    right = std::make_shared<BRect>(x, y2, width, h2, numLevels - 1, !vertical,
                                    vec2{id.x, id.y * 2 + 1});
  }
}

auto s::Kit::BRect::getLeaves() -> std::vector<std::shared_ptr<BRect>> {
  std::vector<std::shared_ptr<BRect>> leaves;
  if (left) {  // then there MUST also be a right
    for (auto p : left->getLeaves()) {
      leaves.push_back(p);
    }
    for (auto p : right->getLeaves()) {
      leaves.push_back(p);
    }
  } else {
    leaves.push_back(shared_from_this());
  }
  return leaves;
}