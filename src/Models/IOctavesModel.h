#pragma once

#include <QAbstractListModel>
#include <vector>

class OctaveSettingsEntry;

class IOctavesModel : public QAbstractListModel {
public:
    virtual const std::vector<OctaveSettingsEntry>& getOctaves() const = 0;
};
