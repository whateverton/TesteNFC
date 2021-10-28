#ifndef NFCCONTROL_H
#define NFCCONTROL_H

#include <QGuiApplication>

class NFCControl : public QObject
{
    Q_OBJECT
public slots:
    void enableRead()
    {
        qDebug() << "Trace - Enabled tag read";
    }

    QString readData()
    {
        // Read nfc tag and return the value
        return "test";
    }

    bool writeData(const QString &data)
    {
        // Get the value and write in the tag
        qDebug() << "Text value: " << data;
        return true;
    }

    void cancelOperation()
    {
        qDebug() << "Trace - Operation canceled";
    }

};

#endif // NFCCONTROL_H
