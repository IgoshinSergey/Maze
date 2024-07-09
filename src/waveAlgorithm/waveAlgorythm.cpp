#include "waveAlgorythm.hpp"

#include <queue>

/************************************************************
 * @file waveAlgorythm.cpp
 * @brief Реализация волнового алгоритма
 ************************************************************/

bool s21::Point::operator!=(const s21::Point& other) {
  return x != other.x || y != other.y;
}

s21::WaveAlgorythm::WaveAlgorythm(Point start, Point end, const Maze& maze)
    : start(start),
      end(end),
      field(maze.rows, std::vector<int>(maze.cols, 0)),
      maze(maze) {}

bool s21::WaveAlgorythm::findEndPoint() {
  Point cur_point = start;
  field[start.y][start.x] = 1;
  std::queue<Point> que;
  que.push(start);
  while (field[end.y][end.x] == 0) {
    cur_point = que.front();
    que.pop();
    if (!maze.vertical_walls[cur_point.y][cur_point.x] &&
        cur_point.x + 1 < maze.cols &&
        field[cur_point.y][cur_point.x + 1] == 0) {
      field[cur_point.y][cur_point.x + 1] = cur_point.step + 1;
      Point p{cur_point.x + 1, cur_point.y, cur_point.step + 1};
      que.push(p);
    }
    if (cur_point.x - 1 >= 0 &&
        !maze.vertical_walls[cur_point.y][cur_point.x - 1] &&
        field[cur_point.y][cur_point.x - 1] == 0) {
      field[cur_point.y][cur_point.x - 1] = cur_point.step + 1;
      Point p{cur_point.x - 1, cur_point.y, cur_point.step + 1};
      que.push(p);
    }
    if (cur_point.y + 1 < maze.rows &&
        !maze.horizontal_walls[cur_point.y][cur_point.x] &&
        field[cur_point.y + 1][cur_point.x] == 0) {
      field[cur_point.y + 1][cur_point.x] = cur_point.step + 1;
      Point p{cur_point.x, cur_point.y + 1, cur_point.step + 1};
      que.push(p);
    }
    if (cur_point.y - 1 >= 0 &&
        !maze.horizontal_walls[cur_point.y - 1][cur_point.x] &&
        field[cur_point.y - 1][cur_point.x] == 0) {
      field[cur_point.y - 1][cur_point.x] = 1 + cur_point.step;
      Point p{cur_point.x, cur_point.y - 1, 1 + cur_point.step};
      que.push(p);
    }
    end.step = cur_point.step + 1;
  }
  return true;
}

std::vector<s21::Point> s21::WaveAlgorythm::path() {
  Point cur_point = end;
  std::vector<Point> path;
  while (cur_point != start) {
    Point p{0, 0, 0};
    path.push_back(cur_point);
    if (cur_point.x - 1 >= 0 &&
        !maze.vertical_walls[cur_point.y][cur_point.x - 1] &&
        field[cur_point.y][cur_point.x - 1] == cur_point.step - 1) {
      p.x = cur_point.x - 1;
      p.y = cur_point.y;
    } else if (cur_point.x + 1 < maze.cols &&
               !maze.vertical_walls[cur_point.y][cur_point.x] &&
               field[cur_point.y][cur_point.x + 1] == cur_point.step - 1) {
      p.x = cur_point.x + 1;
      p.y = cur_point.y;
    } else if (cur_point.y - 1 >= 0 &&
               !maze.horizontal_walls[cur_point.y - 1][cur_point.x] &&
               field[cur_point.y - 1][cur_point.x] == cur_point.step - 1) {
      p.x = cur_point.x;
      p.y = cur_point.y - 1;
    } else if (cur_point.y + 1 < maze.rows &&
               !maze.horizontal_walls[cur_point.y][cur_point.x] &&
               field[cur_point.y + 1][cur_point.x] == cur_point.step - 1) {
      p.x = cur_point.x;
      p.y = cur_point.y + 1;
    }
    p.step = cur_point.step - 1;
    cur_point.x = p.x;
    cur_point.y = p.y;
    cur_point.step = p.step;
  }
  path.push_back(start);

  return path;
}