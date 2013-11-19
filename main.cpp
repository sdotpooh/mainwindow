// Group Members: Sean Vinas, Enmanuel Almanzar, Daniel Sodkiewicz
// Mosaic Tile Software Project
// CSC221 Section R: Software Design Lab
// Professor Wolberg
#include <QApplication>
#include "mainwindow.h"

int main(int argc, char **argv) {
	QApplication  app(argc, argv);
	MainWindow window;
	window.show();
	return app.exec();
}
