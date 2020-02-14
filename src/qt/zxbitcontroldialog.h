// Copyright (c) 2017-2020 The BITCHAIN developers
// Distributed under the MIT/X11 software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef ZXBITCONTROLDIALOG_H
#define ZXBITCONTROLDIALOG_H

#include <QDialog>
#include <QTreeWidgetItem>
#include "zxbit/zerocoin.h"

class CZerocoinMint;
class WalletModel;

namespace Ui {
class ZXBITControlDialog;
}

class CZXBITControlWidgetItem : public QTreeWidgetItem
{
public:
    explicit CZXBITControlWidgetItem(QTreeWidget *parent, int type = Type) : QTreeWidgetItem(parent, type) {}
    explicit CZXBITControlWidgetItem(int type = Type) : QTreeWidgetItem(type) {}
    explicit CZXBITControlWidgetItem(QTreeWidgetItem *parent, int type = Type) : QTreeWidgetItem(parent, type) {}

    bool operator<(const QTreeWidgetItem &other) const;
};

class ZXBITControlDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ZXBITControlDialog(QWidget *parent);
    ~ZXBITControlDialog();

    void setModel(WalletModel* model);

    static std::set<std::string> setSelectedMints;
    static std::set<CMintMeta> setMints;
    static std::vector<CMintMeta> GetSelectedMints();

private:
    Ui::ZXBITControlDialog *ui;
    WalletModel* model;

    void updateList();
    void updateLabels();

    enum {
        COLUMN_CHECKBOX,
        COLUMN_DENOMINATION,
        COLUMN_PUBCOIN,
        COLUMN_VERSION,
        COLUMN_CONFIRMATIONS,
        COLUMN_ISSPENDABLE
    };
    friend class CZXBITControlWidgetItem;

private Q_SLOTS:
    void updateSelection(QTreeWidgetItem* item, int column);
    void ButtonAllClicked();
};

#endif // ZXBITCONTROLDIALOG_H
