// Copyright (c) 2020 The BITCHAIN developers
// Distributed under the MIT software license, see the accompanying
// file COPYING or http://www.opensource.org/licenses/mit-license.php.

#ifndef BITCHAIN_LEGACY_ZPOS_H
#define BITCHAIN_LEGACY_ZPOS_H

#include "stakeinput.h"
#include "main.h"
#include "kernel.h"
#include "txdb.h"

class CLegacyZXBITStake : public CStakeInput
{
private:
    uint32_t nChecksum;
    libzerocoin::CoinDenomination denom;
    uint256 hashSerial;

public:
    explicit CLegacyZXBITStake(const libzerocoin::CoinSpend& spend);
    bool IsZXBIT() const override { return true; }
    uint32_t GetChecksum() const { return nChecksum; }
    CBlockIndex* GetIndexFrom() override;
    CAmount GetValue() const override;
    CDataStream GetUniqueness() const override;
    bool CreateTxIn(CWallet* pwallet, CTxIn& txIn, uint256 hashTxOut = 0) override { return false; /* creation disabled */}
    bool CreateTxOuts(CWallet* pwallet, std::vector<CTxOut>& vout, CAmount nTotal) override { return false; /* creation disabled */}
    bool GetTxFrom(CTransaction& tx) const override { return false; /* not available */ }
};

#endif //BITCHAIN_LEGACY_ZPOS_H
