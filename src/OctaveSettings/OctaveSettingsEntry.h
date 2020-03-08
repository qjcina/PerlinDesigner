#pragma once

#include <QQuickItem>

class OctaveSettingsEntry : public QQuickItem {
    Q_OBJECT
    Q_PROPERTY(QString color READ getColorString WRITE setColor NOTIFY colorChanged)
    Q_PROPERTY(QString algorithm MEMBER mAlgorithm WRITE setAlgorithm NOTIFY algorithmChanged)
    Q_PROPERTY(bool isColorValid READ isColorValid NOTIFY colorChanged)
    Q_PROPERTY(bool isAlgorithmValid READ isAlgorithmValid NOTIFY colorChanged)

public:
    OctaveSettingsEntry();
    ~OctaveSettingsEntry();

    QString getColorString() const;
    const QColor& getColor() const;
    void setColor(const QString& colorString);

    void setAlgorithm(const QString& algorithm);

    bool isColorValid() const;
    bool isAlgorithmValid() const;

signals:
    void colorChanged();
    void algorithmChanged();

private:
    QColor mColor;
    QString mAlgorithm;
    bool mIsAlgorithmValid = true;
};
