#ifndef TRACKCONTROLWIDGET_HPP
#define TRACKCONTROLWIDGET_HPP

#include <QWidget>

namespace Ui {
class TrackControlWidget;
}

class TrackControlWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit TrackControlWidget(QWidget *parent = 0);
    ~TrackControlWidget();
    
private:
    Ui::TrackControlWidget *ui;
};

#endif // TRACKCONTROLWIDGET_HPP
