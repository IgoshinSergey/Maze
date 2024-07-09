/**
 * @file file_handling.hpp
 * @brief Заголовочный файл, в котором объявлены классы для экспорта и импорта
 * лабиринтов в файлы
 */

#ifndef A1_MAZE_CPP_1_SRC_FILE_HANDLING_HPP_
#define A1_MAZE_CPP_1_SRC_FILE_HANDLING_HPP_

#include <fstream>
#include <string>

#include "../maze/maze.hpp"

namespace s21 {

/**
 * @class ExportFile
 * @brief Класс для экспорта лабиринта в файл
 */
class ExportFile {
 private:
  /**
   * @brief Лабиринт
   */
  Maze& maze;

 public:
  /**
   * @brief Метод для экспорта лабиринта
   * @param filename Файл в который созраняем лабиринт
   */
  void exportFile(std::string filename);

  /**
   * @brief Параметризированный конструктор
   * @param maze Лабиринт
   */
  ExportFile(Maze& maze);
};

/**
 * @class ImportFile
 * @brief Класс для импорта лабиринта из файла
 */
class ImportFile {
 private:
  /**
   * @brief Лабиринт
   */
  Maze& maze;

  /**
   * @brief Метод для очистки и ресайза лабиринта
   */
  void clearAndResizeMaze();

 public:
  /**
   * @brief Метод для импорта из файла
   * @param filename Имя файла
   */
  void importFile(std::string filename);

  /**
   * @brief Параметрищированный конструктор
   * @param maze Лабиринт
   */
  ImportFile(Maze& maze);
};
}  // namespace s21

#endif  // A1_MAZE_CPP_1_SRC_FILE_HANDLING_HPP_
