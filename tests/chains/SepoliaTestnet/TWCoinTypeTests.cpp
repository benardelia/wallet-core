// SPDX-License-Identifier: Apache-2.0
//
// Copyright © 2017 Trust Wallet.

#include "TestUtilities.h"
#include <TrustWalletCore/TWCoinTypeConfiguration.h>
#include <gtest/gtest.h>

TEST(TWSepoliaTestnetCoinType, TWCoinType) {
    const auto coin = TWCoinTypeSepoliaTestnet;
    const auto symbol = WRAPS(TWCoinTypeConfigurationGetSymbol(coin));
    const auto id = WRAPS(TWCoinTypeConfigurationGetID(coin));
    const auto name = WRAPS(TWCoinTypeConfigurationGetName(coin));
    const auto txId = WRAPS(TWStringCreateWithUTF8Bytes("0x6e7e3b4eae8705890128d7f71ff8ebdcd1347f7b495237e64f0c43e6fb58b1ef"));
    const auto txUrl = WRAPS(TWCoinTypeConfigurationGetTransactionURL(coin, txId.get()));
    const auto accId = WRAPS(TWStringCreateWithUTF8Bytes("0x2b6edb804fc94a0d548d8bca7dca547c66d2030a"));
    const auto accUrl = WRAPS(TWCoinTypeConfigurationGetAccountURL(coin, accId.get()));

    assertStringsEqual(id, "Sepolia");
    assertStringsEqual(name, "Sepolia-Testnet");
    assertStringsEqual(symbol, "ETH");
    ASSERT_EQ(TWCoinTypeConfigurationGetDecimals(coin), 18);
    ASSERT_EQ(TWCoinTypeBlockchain(coin), TWBlockchainEthereum);
    ASSERT_EQ(TWCoinTypeP2pkhPrefix(coin), 0);
    ASSERT_EQ(TWCoinTypeP2shPrefix(coin), 0);
    ASSERT_EQ(TWCoinTypeStaticPrefix(coin), 0);
    assertStringsEqual(txUrl, "https://sepolia.etherscan.io/tx/0x6e7e3b4eae8705890128d7f71ff8ebdcd1347f7b495237e64f0c43e6fb58b1ef");
    assertStringsEqual(accUrl, "https://sepolia.etherscan.io/address/0x2b6edb804fc94a0d548d8bca7dca547c66d2030a");
}
