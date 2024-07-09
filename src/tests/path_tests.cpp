#include "maze_tests.hpp"

TEST(path_tests, test_1) {
  s21::Maze m{};

  s21::ImportFile import{m};
  import.importFile("tests/examples/maze_test_1.txt");

  s21::Point start{0, 0};
  s21::Point end{3, 3};
  s21::WaveAlgorythm wave{start, end, m};

  wave.findEndPoint();
  std::vector<s21::Point> path = wave.path();

  EXPECT_EQ(path[0].x, 3);
  EXPECT_EQ(path[0].y, 3);

  EXPECT_EQ(path[1].x, 2);
  EXPECT_EQ(path[1].y, 3);

  EXPECT_EQ(path[2].x, 2);
  EXPECT_EQ(path[2].y, 2);

  EXPECT_EQ(path[3].x, 3);
  EXPECT_EQ(path[3].y, 2);

  EXPECT_EQ(path[4].x, 3);
  EXPECT_EQ(path[4].y, 1);

  EXPECT_EQ(path[5].x, 3);
  EXPECT_EQ(path[5].y, 0);

  EXPECT_EQ(path[6].x, 2);
  EXPECT_EQ(path[6].y, 0);

  EXPECT_EQ(path[7].x, 1);
  EXPECT_EQ(path[7].y, 0);

  EXPECT_EQ(path[8].x, 0);
  EXPECT_EQ(path[8].y, 0);
}

TEST(path_tests, test_2) {
  s21::Maze m{};

  s21::ImportFile import{m};
  import.importFile("tests/examples/maze_test_2.txt");

  s21::Point start{0, 0};
  s21::Point end{0, 5};
  s21::WaveAlgorythm wave{start, end, m};

  wave.findEndPoint();
  std::vector<s21::Point> path = wave.path();

  EXPECT_EQ(path[0].x, 0);
  EXPECT_EQ(path[0].y, 5);

  EXPECT_EQ(path[1].x, 1);
  EXPECT_EQ(path[1].y, 5);

  EXPECT_EQ(path[2].x, 1);
  EXPECT_EQ(path[2].y, 4);

  EXPECT_EQ(path[3].x, 1);
  EXPECT_EQ(path[3].y, 3);

  EXPECT_EQ(path[4].x, 2);
  EXPECT_EQ(path[4].y, 3);

  EXPECT_EQ(path[5].x, 2);
  EXPECT_EQ(path[5].y, 2);

  EXPECT_EQ(path[6].x, 2);
  EXPECT_EQ(path[6].y, 1);

  EXPECT_EQ(path[7].x, 1);
  EXPECT_EQ(path[7].y, 1);

  EXPECT_EQ(path[8].x, 1);
  EXPECT_EQ(path[8].y, 0);

  EXPECT_EQ(path[9].x, 0);
  EXPECT_EQ(path[9].y, 0);
}

TEST(path_tests, test_3) {
  s21::Maze m{};

  s21::ImportFile import{m};
  import.importFile("tests/examples/maze_test_2.txt");

  s21::Point start{0, 0};
  s21::Point end{5, 5};
  s21::WaveAlgorythm wave{start, end, m};

  wave.findEndPoint();
  std::vector<s21::Point> path = wave.path();

  EXPECT_EQ(path[0].x, 5);
  EXPECT_EQ(path[0].y, 5);

  EXPECT_EQ(path[1].x, 4);
  EXPECT_EQ(path[1].y, 5);

  EXPECT_EQ(path[2].x, 4);
  EXPECT_EQ(path[2].y, 4);

  EXPECT_EQ(path[3].x, 3);
  EXPECT_EQ(path[3].y, 4);

  EXPECT_EQ(path[4].x, 2);
  EXPECT_EQ(path[4].y, 4);

  EXPECT_EQ(path[5].x, 2);
  EXPECT_EQ(path[5].y, 3);

  EXPECT_EQ(path[6].x, 2);
  EXPECT_EQ(path[6].y, 2);

  EXPECT_EQ(path[7].x, 2);
  EXPECT_EQ(path[7].y, 1);

  EXPECT_EQ(path[8].x, 1);
  EXPECT_EQ(path[8].y, 1);

  EXPECT_EQ(path[9].x, 1);
  EXPECT_EQ(path[9].y, 0);

  EXPECT_EQ(path[10].x, 0);
  EXPECT_EQ(path[10].y, 0);
}

TEST(path_tests, test_4) {
  s21::Maze m{};

  s21::ImportFile import{m};
  import.importFile("tests/examples/maze_test_2.txt");

  s21::Point start{0, 0};
  s21::Point end{5, 0};
  s21::WaveAlgorythm wave{start, end, m};

  wave.findEndPoint();
  std::vector<s21::Point> path = wave.path();

  EXPECT_EQ(path[0].x, 5);
  EXPECT_EQ(path[0].y, 0);

  EXPECT_EQ(path[1].x, 5);
  EXPECT_EQ(path[1].y, 1);

  EXPECT_EQ(path[2].x, 4);
  EXPECT_EQ(path[2].y, 1);

  EXPECT_EQ(path[3].x, 4);
  EXPECT_EQ(path[3].y, 2);

  EXPECT_EQ(path[4].x, 3);
  EXPECT_EQ(path[4].y, 2);

  EXPECT_EQ(path[5].x, 2);
  EXPECT_EQ(path[5].y, 2);

  EXPECT_EQ(path[6].x, 2);
  EXPECT_EQ(path[6].y, 1);

  EXPECT_EQ(path[7].x, 1);
  EXPECT_EQ(path[7].y, 1);

  EXPECT_EQ(path[8].x, 1);
  EXPECT_EQ(path[8].y, 0);

  EXPECT_EQ(path[9].x, 0);
  EXPECT_EQ(path[9].y, 0);
}
