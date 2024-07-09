#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QFileDialog>
#include <QMainWindow>
// #include "../maze/maze.hpp"
#include "../eller/eller_algorithm.hpp"
#include "../file_handling/file_handling.hpp"
#include "../waveAlgorithm/waveAlgorythm.hpp"

QT_BEGIN_NAMESPACE
namespace Ui {
class MainWindow;
}
QT_END_NAMESPACE

class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow(QWidget *parent = nullptr);
  ~MainWindow();

 private slots:
  void on_selectFile_clicked();

  void on_exportFile_clicked();

  void on_generateMaze_clicked();

  void on_searchWayButton_clicked();

  void on_rowsSpinBox_valueChanged(int arg1);

  void on_colsSpinBox_valueChanged(int arg1);

 private:
  Ui::MainWindow *ui;
};
#endif  // MAINWINDOW_H
