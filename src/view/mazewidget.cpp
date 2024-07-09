#include "mazewidget.h"

MazeWidget::MazeWidget(QWidget *parent) : QWidget{parent} {}

void MazeWidget::paintEvent(QPaintEvent *event) {
  Q_UNUSED(event);
  QPainter painter(this);

  if (maze.cols && maze.rows) {
    int v = 500 / maze.rows;
    int h = 500 / maze.cols;

    QPen pen(Qt::green, 2);
    painter.setPen(pen);

    painter.drawLine(0, 0, h * maze.cols, 0);
    painter.drawLine(0, 0, 0, v * maze.rows);

    for (int i = 0; i < maze.rows; i++) {
      for (int j = 0; j < maze.cols; j++) {
        if (maze.vertical_walls[i][j]) {
          painter.drawLine(h * (j + 1), v * (i + 1), h * (j + 1), v * i);
        }
        if (maze.horizontal_walls[i][j]) {
          painter.drawLine(h * j, v * (i + 1), h * (j + 1), v * (i + 1));
        }
      }
    }
    if (!path.empty()) {
      int v = 500 / maze.rows;
      int h = 500 / maze.cols;

      QPen pen(Qt::red, 2);
      painter.setPen(pen);

      for (std::size_t i = 0; i < path.size() - 1; i++) {
        s21::Point p1 = path[i];
        s21::Point p2 = path[i + 1];
        int x1 = p1.x;
        int y1 = p1.y;
        int x2 = p2.x;
        int y2 = p2.y;
        painter.drawLine(h * (x1) + h / 2, v * (y1) + v / 2, h * (x2) + h / 2,
                         v * (y2) + v / 2);
      }
    }
  }
}
