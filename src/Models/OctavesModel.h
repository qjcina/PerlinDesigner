#pragma once

#include "IOctavesModel.h"
#include "OctaveSettings/OctaveSettingsEntry.h"

#include <QAbstractListModel>

class OctavesModel : public IOctavesModel {
    Q_OBJECT

    static constexpr const qint32 MAX_OCTAVES = 128;

public:
    OctavesModel();

    int rowCount(const QModelIndex& parent) const override;
    QVariant data(const QModelIndex& index, int role) const override;
    QHash<int, QByteArray> roleNames() const override;

    Q_INVOKABLE void addOctave();
    Q_INVOKABLE void removeOctave(quint32 index);
    Q_INVOKABLE void clearOctaves();
    Q_INVOKABLE void setOctaveData(qint32 octaveIndex, const OctavesModelRoles& role, const QString& value);
    void updateAlgorithmValid() override;

    const std::vector<OctaveSettingsEntry>& getOctaves() const override;

private:
    bool isValidIndex(qint32 index) const;
    void dataChanged(const QModelIndex& modelIndex, const std::initializer_list<OctavesModelRoles>& modelRoles);

    std::vector<OctaveSettingsEntry> mOctaves;
};
