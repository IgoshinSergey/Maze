#include "file_handling.hpp"

s21::ExportFile::ExportFile(s21::Maze &maze) : maze{maze} {}

void s21::ExportFile::exportFile(std::string filename) {
  std::ofstream file(filename);
  if (file) {
    file << maze.rows << " " << maze.cols << std::endl;
    for (int i = 0; i < maze.rows; i++) {
      for (int j = 0; j < maze.cols; j++) {
        file << maze.vertical_walls[i][j] << " ";
      }
      file << std::endl;
    }
    file << std::endl;
    for (int i = 0; i < maze.rows; i++) {
      for (int j = 0; j < maze.cols; j++) {
        file << maze.horizontal_walls[i][j] << " ";
      }
      file << std::endl;
    }
  }
}
