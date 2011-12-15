#ifndef PLAYLISTMODEL_HPP
#define PLAYLISTMODEL_HPP

#include <QAbstractItemModel>

class PlayListModel : public QAbstractItemModel
{
    Q_OBJECT
public:
    explicit PlayListModel(QObject *parent = 0);
    
signals:
    
public slots:
    
};

#endif // PLAYLISTMODEL_HPP
