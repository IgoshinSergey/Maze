#ifndef MAZEWIDGET_H
#define MAZEWIDGET_H

#include <QPaintEvent>
#include <QPainter>
#include <QWidget>
// #include <vector>
// #include "../maze/maze.hpp"
#include "../waveAlgorithm/waveAlgorythm.hpp"

class MazeWidget : public QWidget {
  Q_OBJECT
 public:
  explicit MazeWidget(QWidget *parent = nullptr);
  s21::Maze maze;
  std::vector<s21::Point> path;

 protected:
  void paintEvent(QPaintEvent *e) override;
 signals:
};

#endif  // MAZEWIDGET_H
