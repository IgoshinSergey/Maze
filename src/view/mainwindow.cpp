#include "mainwindow.h"

#include "ui_mainwindow.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent), ui(new Ui::MainWindow) {
  ui->setupUi(this);
}

MainWindow::~MainWindow() { delete ui; }

void MainWindow::on_selectFile_clicked() {
  QString fileName = QFileDialog::getOpenFileName(
      this, tr("Open Text File"), "../../", tr("Text Files (*.txt)"));
  ui->mazeWidget->path.clear();
  if (!fileName.isEmpty()) {
    s21::ImportFile import_maze{ui->mazeWidget->maze};
    import_maze.importFile(fileName.toStdString());
    ui->rowsSpinBox->setValue(ui->mazeWidget->maze.rows);
    ui->colsSpinBox->setValue(ui->mazeWidget->maze.cols);
    ui->mazeWidget->repaint();
  }
}

void MainWindow::on_exportFile_clicked() {
  s21::ExportFile export_maze{ui->mazeWidget->maze};
  export_maze.exportFile("maze.txt");
}

void MainWindow::on_generateMaze_clicked() {
  s21::EllerAlgorithm eller{ui->mazeWidget->maze};
  eller.createMaze(ui->rowsSpinBox->value(), ui->colsSpinBox->value());
  ui->mazeWidget->path.clear();
  ui->mazeWidget->repaint();
}

void MainWindow::on_searchWayButton_clicked() {
  s21::Point start{ui->x1->value(), ui->y1->value()};
  s21::Point end{ui->x2->value(), ui->y2->value()};
  s21::WaveAlgorythm wave{start, end, ui->mazeWidget->maze};
  wave.findEndPoint();
  ui->mazeWidget->path = wave.path();
  ui->mazeWidget->repaint();
}

void MainWindow::on_rowsSpinBox_valueChanged(int arg1) {
  ui->y1->setMaximum(arg1 - 1);
  ui->y2->setMaximum(arg1 - 1);
}

void MainWindow::on_colsSpinBox_valueChanged(int arg1) {
  ui->x1->setMaximum(arg1 - 1);
  ui->x2->setMaximum(arg1 - 1);
}
