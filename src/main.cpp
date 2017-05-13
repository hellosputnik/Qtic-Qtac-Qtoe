#include <QApplication>

#include "mainwindow.h"

int main(int argc, char *argv[])
{
    QApplication app(argc, argv);
    MainWindow window;

    window.setFixedSize(300, 400);
    window.setWindowTitle("Qtic-Qtac-Qtoe");
    window.show();

    return app.exec();
}
