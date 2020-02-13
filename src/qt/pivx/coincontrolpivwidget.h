// Copyright (c) 2019 The BITCHAIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef COINCONTROLXBITWIDGET_H
#define COINCONTROLXBITWIDGET_H

#include <QDialog>

namespace Ui {
class CoinControlXBITWidget;
}

class CoinControlXBITWidget : public QDialog
{
    Q_OBJECT

public:
    explicit CoinControlXBITWidget(QWidget *parent = nullptr);
    ~CoinControlXBITWidget();

private:
    Ui::CoinControlXBITWidget *ui;
};

#endif // COINCONTROLXBITWIDGET_H
