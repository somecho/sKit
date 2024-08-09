#include <format>
#include <iostream>
#include <sKit/grids.hpp>
#include <stdexcept>

auto s::Kit::gridFillDiagonal(int numCols,
                              int numRows) -> std::vector<glm::ivec2> {
  if (numCols < 2) {
    throw std::runtime_error(
        std::format("{}: Grids must have atleast 2 columns!", __func__));
  }
  if (numRows < 2) {
    throw std::runtime_error(
        std::format("{}: Grids must have atleast 2 rows!", __func__));
  }

  std::vector<glm::ivec2> path = {{0, 0}, {1, 0}, {0, 1}};

  glm::ivec2 pos(0, 1);
  glm::ivec2 dir = SW;
  glm::ivec2 prevDir = SW;
  const glm::ivec2 start(0, 0);
  const glm::ivec2 end(numCols - 1, numRows - 1);
  const glm::ivec2 bottomLeft(start.x, end.y);
  const glm::ivec2 topRight(end.x, start.y);
  bool atPathEnd = false;
  while (!atPathEnd) {
    if (pos == end) {
      atPathEnd = true;
      break;
    }
    if (pos == bottomLeft) {
      dir = prevDir == SW ? E : NE;
      pos += dir;
      path.push_back(pos);
      prevDir = dir;
      continue;
    }
    if (pos == topRight) {
      dir = prevDir == NE ? S : SW;
      pos += dir;
      path.push_back(pos);
      prevDir = dir;
      continue;
    }
    glm::ivec2 nextPos = pos + dir;
    bool outOfBounds = nextPos.x < 0 || nextPos.x >= numCols || nextPos.y < 0 ||
                       nextPos.y >= numRows;
    if (outOfBounds) {
      dir = prevDir == SW ? S : pos.y == 0 ? E : S;
      if (prevDir == SW) {
        if (pos.x == 0) {
          dir = S;
        } else {
          dir = E;
        }
      } else if (prevDir == NE) {
        if (pos.y == 0) {
          dir = E;
        } else {
          dir = S;
        }
      }

      pos += dir;
      path.push_back(pos);
      prevDir = dir;
      continue;
    }
    if (prevDir == S) {
      dir = pos.x == 0 ? NE : SW;
      pos += dir;
      path.push_back(pos);
      prevDir = dir;
      continue;
    }
    if (prevDir == E) {
      dir = pos.y == 0 ? SW : NE;
      pos += dir;
      path.push_back(pos);
      prevDir = dir;
      continue;
    }
    pos += dir;
    path.push_back(pos);
    prevDir = dir;
  }

  return path;
}