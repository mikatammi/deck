#ifndef PEEROPTIONSWIDGET_HPP
#define PEEROPTIONSWIDGET_HPP

#include <QWidget>
#include <QString>

namespace Ui {
class PeerOptionsWidget;
}

class PeerOptionsWidget : public QWidget
{
    Q_OBJECT
    
public:
    /// Constructor
    /// @param parent Parent widget
    explicit PeerOptionsWidget(QWidget *parent = 0);

    /// Destructor
    ~PeerOptionsWidget();

    /// Sets NodeName in widget
    /// @param nodename NodeName in string
    void setNodeName(QString nodename);

    /// Gets NodeName from widget
    /// @return NodeName in string
    QString getNodeName() const;
    
private:
    Ui::PeerOptionsWidget *ui_;
};

#endif // PEEROPTIONSWIDGET_HPP
