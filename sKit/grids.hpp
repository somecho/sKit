#pragma once

#include <glm/vec2.hpp>
#include <vector>

namespace s {
namespace Kit {

/**
 * @throw std::runtime_error If either `numCols` or `numRows` are less than 2.
 */
auto gridFillDiagonal(int numCols, int numRows) -> std::vector<glm::ivec2>;

/// @brief Unit int vector North
constexpr glm::ivec2 N(0, -1);
/// @brief Unit int vector East
constexpr glm::ivec2 E(1, 0);
/// @brief Unit int vector South
constexpr glm::ivec2 S(0, 1);
/// @brief Unit int vector West
constexpr glm::ivec2 W(-1, 0);
/// @brief Unit int vector North-East
constexpr glm::ivec2 NE(1, -1);
/// @brief Unit int vector South-West
constexpr glm::ivec2 SW(-1, 1);

}  // namespace Kit
}  // namespace s