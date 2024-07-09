#include "eller_algorithm.hpp"

#include <iostream>

/************************************************************
 * @file eller_algorithm.cpp
 * @brief Реализация алгоритма Эллера
 ************************************************************/

s21::EllerAlgorithm::EllerAlgorithm(Maze& maze)
    : cols(maze.cols),
      rows(maze.rows),
      horizontal{maze.horizontal_walls},
      vertical{maze.vertical_walls} {}

void s21::EllerAlgorithm::resizeVectors(int rows, int cols) {
  this->cols = cols;
  this->rows = rows;
  vertical.resize(rows);
  horizontal.resize(rows);

  for (int i = 0; i < rows; i++) {
    vertical[i].clear();
    horizontal[i].clear();
    vertical[i].resize(cols);
    horizontal[i].resize(cols);
  }
}

bool randomBool() {
  static std::random_device rd;
  static std::mt19937 gen(rd());
  static std::uniform_int_distribution<> dis(0, 1);
  return dis(gen) == 1;
}

void s21::EllerAlgorithm::fillEmptyValue() {
  for (int i = 0; i < cols; i++) field_of_sets.push_back(0);
}

void s21::EllerAlgorithm::assignUniqueValues() {
  for (int i = 0; i < cols; i++) {
    if (field_of_sets[i] == 0) {
      field_of_sets[i] = counter;
      counter++;
    }
  }
}

void s21::EllerAlgorithm::mergeTwoSets(int ind, int value) {
  int set = field_of_sets[ind + 1];
  for (int i = 0; i < cols; i++) {
    if (field_of_sets[i] == set) field_of_sets[i] = value;
  }
}
void s21::EllerAlgorithm::createTheRightBorders(int rows) {
  for (int i = 0; i < cols - 1; i++) {
    bool choise = randomBool();
    if (choise || field_of_sets[i] == field_of_sets[i + 1])
      vertical[rows][i] = true;
    else
      mergeTwoSets(i, field_of_sets[i]);
  }
  vertical[rows][cols - 1] = true;
}

int s21::EllerAlgorithm::countOfUniqueSets(int value) {
  int cnt = 0;
  for (int i = 0; i < cols; i++) {
    if (field_of_sets[i] == value) cnt++;
  }
  return cnt;
}

void s21::EllerAlgorithm::createBorderAtTheBottom(int rows) {
  for (int i = 0; i < cols; i++) {
    bool choise = randomBool();
    if (countOfUniqueSets(field_of_sets[i]) != 1 && choise) {
      horizontal[rows][i] = true;
    }
  }
}

int s21::EllerAlgorithm::BottomBorderCount(int value, int rows) {
  int cnt = 0;
  for (int i = 0; i < cols; i++) {
    if (field_of_sets[i] == value && horizontal[rows][i] == false) cnt++;
  }
  return cnt;
}
void s21::EllerAlgorithm::CheckBottomBorders(int rows) {
  for (int i = 0; i < cols; i++) {
    if (BottomBorderCount(field_of_sets[i], rows) == 0)
      horizontal[rows][i] = false;
  }
}

void s21::EllerAlgorithm::addingNewLine(int rows) {
  for (int i = 0; i < cols; i++) {
    if (horizontal[rows][i]) {
      field_of_sets[i] = 0;
    }
  }
}

void s21::EllerAlgorithm::addingEndLine() {
  assignUniqueValues();
  createTheRightBorders(rows - 1);

  for (int i = 0; i < cols - 1; i++) {
    if (field_of_sets[i] != field_of_sets[i + 1]) {
      vertical[rows - 1][i] = false;
      mergeTwoSets(i, field_of_sets[i]);
    }
    horizontal[rows - 1][i] = true;
  }
  horizontal[rows - 1][cols - 1] = true;
}

void s21::EllerAlgorithm::createMaze(int rows, int cols) {
  resizeVectors(rows, cols);
  fillEmptyValue();
  for (int i = 0; i < rows - 1; i++) {
    assignUniqueValues();
    createTheRightBorders(i);
    createBorderAtTheBottom(i);
    CheckBottomBorders(i);
    addingNewLine(i);
  }
  addingEndLine();
}