#ifndef PLAYLISTWIDGET_H
#define PLAYLISTWIDGET_H

#include <QWidget>

namespace Ui {
class PlayListWidget;
}

class PlayListWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PlayListWidget(QWidget *parent = 0);
    ~PlayListWidget();
    
private:
    Ui::PlayListWidget *ui;
};

#endif // PLAYLISTWIDGET_H
