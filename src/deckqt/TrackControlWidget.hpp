#ifndef TRACKCONTROLWIDGET_HPP
#define TRACKCONTROLWIDGET_HPP

#include <QToolBar>

namespace Ui {
class TrackControlWidget;
}

/// Track Controlling Widget.
/// Used for controlling tracks position and volume,
/// and switching to previous and next tracks. Also
/// stops, pauses and starts playing.
class TrackControlWidget : public QWidget
{
    Q_OBJECT
    
public:
    /// Constructor for track control widget.
    /// @param parent Parent widget.
    explicit TrackControlWidget(QWidget *parent = 0);

    ~TrackControlWidget();
    
private:
    Ui::TrackControlWidget *ui_;
};

#endif // TRACKCONTROLWIDGET_HPP
