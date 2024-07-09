#include "maze_tests.hpp"

TEST(Generation, TEST_1) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(4, 4);
  EXPECT_EQ(maze.rows, 4);
  EXPECT_EQ(maze.cols, 4);
}

TEST(Generation, TEST_2) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(25, 10);
  EXPECT_EQ(maze.rows, 25);
  EXPECT_EQ(maze.cols, 10);
}

TEST(Generation, TEST_3) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(5, 10);
  EXPECT_EQ(maze.rows, 5);
  EXPECT_EQ(maze.cols, 10);
}

TEST(Generation, TEST_4) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(50, 50);
  EXPECT_EQ(maze.rows, 50);
  EXPECT_EQ(maze.cols, 50);
}

TEST(Generation, TEST_5) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(2, 2);
  EXPECT_EQ(maze.rows, 2);
  EXPECT_EQ(maze.cols, 2);
}

TEST(Generation, TEST_6) {
  s21::Maze maze;
  s21::EllerAlgorithm eller(maze);

  eller.createMaze(1, 1);
  EXPECT_EQ(maze.rows, 1);
  EXPECT_EQ(maze.cols, 1);
}
