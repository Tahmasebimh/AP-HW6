//
// Created by Hossein on 5/29/2020.
//

#include "../h/customer.h"

Customer::Customer(const std::string &name) {
    this->name = name;
}

Customer::~Customer() {

}

double Customer::getTotalAsset(void) const {
    return assetValue;
}

double Customer::getTotalChargedTax(void) const {
    return totalChargedTax;
}

void Customer::importNewGoods(std::shared_ptr<BasicGoods> shptrBg) {
    assets.push_back(shptrBg);
    totalChargedTax += shptrBg->getTaxPrice();
    assetValue += shptrBg->getEndPrice();
}

std::string Customer::printBasicInfo(void) const {
    return name + " >> No of assets: " + std::to_string(assets.size())
    + ", Total assets: " + std::to_string(assetValue) + ", Charged tax: " + std::to_string(totalChargedTax);
}
