#pragma once

#include <QAbstractListModel>
#include <vector>

class OctaveSettingsEntry;

class IOctavesModel : public QAbstractListModel {
    Q_OBJECT
public:
    virtual const std::vector<OctaveSettingsEntry>& getOctaves() const = 0;
    virtual void updateAlgorithmValid() = 0;

    enum class OctavesModelRoles {
        Algorihm = Qt::UserRole,
        AlgorithmValid,
        Color,
        ColorValid
    };

    Q_ENUM(OctavesModelRoles)
};
