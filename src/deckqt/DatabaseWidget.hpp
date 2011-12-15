#ifndef DATABASEWIDGET_HPP
#define DATABASEWIDGET_HPP

#include <QWidget>

namespace Ui {
class DatabaseWidget;
}

class DatabaseWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DatabaseWidget(QWidget *parent = 0);
    ~DatabaseWidget();
    
private:
    Ui::DatabaseWidget *ui;
};

#endif // DATABASEWIDGET_HPP
