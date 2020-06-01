#pragma once

#include <QAbstractListModel>

class PerlinOctave;

class OctavesModel : public QAbstractListModel {
public:
    OctavesModel();

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    enum class OctavesModelRoles {

    };

    Q_INVOKABLE void addOctave();
    Q_INVOKABLE void removeOctave();

private:
    std::vector<PerlinOctave> mOctaves;
};
