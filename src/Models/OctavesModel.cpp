#include "OctavesModel.h"

OctavesModel::OctavesModel()
{
}

int OctavesModel::rowCount(const QModelIndex&) const
{
    return mOctaves.size();
}

QVariant OctavesModel::data(const QModelIndex& index, int role) const
{
    switch (role) {
    default:
        return 0;
    }
}

QHash<qint32, QByteArray> OctavesModel::roleNames() const
{
    QHash<qint32, QByteArray> roleNames;

    return roleNames;
}

void OctavesModel::addOctave()
{
}

void OctavesModel::removeOctave()
{
}
