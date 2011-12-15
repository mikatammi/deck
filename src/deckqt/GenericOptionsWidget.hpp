#ifndef GENERICOPTIONSWIDGET_HPP
#define GENERICOPTIONSWIDGET_HPP

#include <QWidget>

namespace Ui {
class GenericOptionsWidget;
}

class GenericOptionsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit GenericOptionsWidget(QWidget *parent = 0);
    ~GenericOptionsWidget();
    
private:
    Ui::GenericOptionsWidget *ui;
};

#endif // GENERICOPTIONSWIDGET_HPP
