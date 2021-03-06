#include "MainWindow.hpp"

#include <QtGui/QApplication>

int main(int argc, char* argv[])
{
    // Create application
    QApplication app(argc, argv);

    app.setApplicationName("Deck");

    // Create main window
    MainWindow mainWindow;
    mainWindow.show();

    // Execute application
    return app.exec();
}
