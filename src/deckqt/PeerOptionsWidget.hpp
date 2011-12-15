#ifndef PEEROPTIONSWIDGET_HPP
#define PEEROPTIONSWIDGET_HPP

#include <QWidget>

namespace Ui {
class PeerOptionsWidget;
}

class PeerOptionsWidget : public QWidget
{
    Q_OBJECT
    
public:
    explicit PeerOptionsWidget(QWidget *parent = 0);
    ~PeerOptionsWidget();
    
private:
    Ui::PeerOptionsWidget *ui;
};

#endif // PEEROPTIONSWIDGET_HPP
