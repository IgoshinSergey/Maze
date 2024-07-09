#include "file_handling.hpp"

s21::ImportFile::ImportFile(s21::Maze &maze) : maze{maze} {}

void s21::ImportFile::importFile(std::string filename) {
  std::ifstream file(filename);
  if (file) {
    file >> maze.rows >> maze.cols;
    clearAndResizeMaze();
    for (int i = 0; i < maze.rows; ++i) {
      for (int j = 0; j < maze.cols; ++j) {
        bool var = 0;
        file >> var;
        maze.vertical_walls[i][j] = var;
      }
    }
    file >> std::ws;
    for (int i = 0; i < maze.rows; ++i) {
      for (int j = 0; j < maze.cols; ++j) {
        bool var = 0;
        file >> var;
        maze.horizontal_walls[i][j] = var;
      }
    }
  }
}

void s21::ImportFile::clearAndResizeMaze() {
  maze.horizontal_walls.resize(maze.rows);
  maze.vertical_walls.resize(maze.rows);

  for (int i = 0; i < maze.rows; i++) {
    maze.horizontal_walls[i].resize(maze.cols);
    maze.horizontal_walls[i].clear();

    maze.vertical_walls[i].resize(maze.cols);
    maze.vertical_walls[i].clear();
  }
}
