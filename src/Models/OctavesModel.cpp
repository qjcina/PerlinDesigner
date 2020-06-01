#include "OctavesModel.h"

#include <QDebug>

OctavesModel::OctavesModel()
{
}

int OctavesModel::rowCount(const QModelIndex&) const
{
    return mOctaves.size();
}

QVariant OctavesModel::data(const QModelIndex& index, int role) const
{
    if (!isValidIndex(index.row()))
        return QVariant();

    const auto element = mOctaves[index.row()];

    switch (static_cast<OctavesModel::OctavesModelRoles>(role)) {
    case OctavesModelRoles::Algorihm:
        return element.getAlgorithm();
    case OctavesModelRoles::AlgorithmValid:
        return element.isAlgorithmValid();
    case OctavesModelRoles::Color:
        return element.getColorString();
    case OctavesModelRoles::ColorValid:
        return element.isColorValid();
    }

    return QVariant();
}

QHash<qint32, QByteArray> OctavesModel::roleNames() const
{
    QHash<qint32, QByteArray> roleNames;

    roleNames[static_cast<qint32>(OctavesModelRoles::Algorihm)] = "r_Algorithm";
    roleNames[static_cast<qint32>(OctavesModelRoles::AlgorithmValid)] = "r_AlgorithmValid";
    roleNames[static_cast<qint32>(OctavesModelRoles::Color)] = "r_Color";
    roleNames[static_cast<qint32>(OctavesModelRoles::ColorValid)] = "r_ColorValid";

    return roleNames;
}

void OctavesModel::addOctave()
{
    if (mOctaves.size() < MAX_OCTAVES) {
        const auto position = mOctaves.size();
        beginInsertRows(QModelIndex(), position, position);
        mOctaves.resize(position + 1);
        endInsertRows();
    }
}

void OctavesModel::removeOctave()
{
    if (mOctaves.size() > 0) {
        const auto position = mOctaves.size();
        beginRemoveRows(QModelIndex(), position, position);
        mOctaves.resize(mOctaves.size() - 1);
        endRemoveRows();
    }
}

void OctavesModel::setOctaveData(qint32 octaveIndex, const OctavesModel::OctavesModelRoles& role, const QString& value)
{
    if (!isValidIndex(octaveIndex))
        return;

    const auto modelIndex = this->index(octaveIndex);
    switch (role) {
    case OctavesModelRoles::Algorihm:
        mOctaves[octaveIndex].setAlgorithm(value);
        dataChanged(modelIndex, { OctavesModelRoles::Algorihm, OctavesModelRoles::AlgorithmValid });
        break;
    case OctavesModelRoles::Color:
        mOctaves[octaveIndex].setColor(value);
        dataChanged(modelIndex, { OctavesModelRoles::Color, OctavesModelRoles::ColorValid });
        break;
    default:
        // Role not assignable
        break;
    }
}

bool OctavesModel::isValidIndex(qint32 index) const
{
    return index >= 0 && index < static_cast<qint32>(mOctaves.size());
}

void OctavesModel::dataChanged(const QModelIndex& modelIndex, const std::initializer_list<OctavesModel::OctavesModelRoles>& modelRoles)
{
    if (!modelIndex.isValid() || modelRoles.size() <= 0)
        return;

    QVector<qint32> roles;
    std::transform(modelRoles.begin(), modelRoles.end(), std::back_inserter(roles), [](const OctavesModel::OctavesModelRoles& role) -> qint32 {
        return static_cast<qint32>(role);
    });
    emit QAbstractItemModel::dataChanged(modelIndex, modelIndex, roles);
}
