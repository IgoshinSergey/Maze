/**
 * @file maze.hpp
 * @brief Заголовочный файл, в котором объявлены класс для описания лабиринта
 */

#ifndef A1_MAZE_CPP_1_SRC_MAZE_MAZE_HPP_
#define A1_MAZE_CPP_1_SRC_MAZE_MAZE_HPP_

#include <vector>

namespace s21 {

/**
 * @class Maze
 * @brief Класс для хранения информации о лабиринте
 */
class Maze {
 public:
  /**
   * @brief Конструктор по умолчанию
   */
  Maze();

  /**
   * @brief Rows - кол-во строк
   * @brief Cols - кол-во столбцов
   */
  int cols{0}, rows{0};

  /**
   * @brief Вертикальные стенки
   */
  std::vector<std::vector<bool>> vertical_walls{{}};

  /**
   * @brief Горизонтальные стенки
   */
  std::vector<std::vector<bool>> horizontal_walls{{}};
};

}  // namespace s21

#endif  // A1_MAZE_CPP_1_SRC_MAZE_MAZE_HPP_
