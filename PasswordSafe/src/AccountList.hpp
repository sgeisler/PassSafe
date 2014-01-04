/*
 * AccountList.hpp
 *
 *  Created on: 01.01.2014
 *      Author: Sebastian
 */

#ifndef ACCOUNTLIST_HPP_
#define ACCOUNTLIST_HPP_

#include <QObject>
#include <QCryptographicHash>
#include <QMetaType>
#include <QtSql/QtSql>
#include <bb/data/JsonDataAccess>
#include "Account.hpp"
#include <bb/system/SystemToast>
#include <QMap>
#include <bb/system/Clipboard>
#include <bb/system/SystemUiModality>

class AccountList : public QObject {
    Q_OBJECT


public:
    AccountList();

    Q_INVOKABLE void setPassword(QString pass);
    Q_INVOKABLE QString getAccountAt(int i);
    Q_INVOKABLE int getStartAt(int i);
    Q_INVOKABLE int getStopAt(int i);
    Q_INVOKABLE int getSize();
    Q_INVOKABLE QString getPasswordAt(int i, int start, int stop);
    Q_INVOKABLE QString getPasswordAt(int i);
    Q_INVOKABLE void addAccount(QString name, int start, int stop);
    Q_INVOKABLE void editAccount(int i, QString name, int start, int stop);
    Q_INVOKABLE void removeAccountAt(int i);
    Q_INVOKABLE void copyToClipboard(QString str);
    void loadAccounts();

public slots:
    void clearClip();

private:
    QString password;
    QList<Account> accounts;
    QString file;
};


#endif /* ACCOUNTLIST_HPP_ */
