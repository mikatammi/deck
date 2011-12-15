#ifndef DATABASEOPTIONSWIDGET_HPP
#define DATABASEOPTIONSWIDGET_HPP

#include <QWidget>

namespace Ui {
class DatabaseOptionsWidget;
}

class DatabaseOptionsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit DatabaseOptionsWidget(QWidget *parent = 0);
    ~DatabaseOptionsWidget();
    
private:
    Ui::DatabaseOptionsWidget *ui;
};

#endif // DATABASEOPTIONSWIDGET_HPP
