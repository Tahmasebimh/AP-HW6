//
// Created by Hossein on 5/19/2020.
//

#include <cstring>
#include <utility>
#include "../h/basicGoods.h"

BasicGoods::BasicGoods(const std::string &bName, GOODS_TYPE gTyp, double price) {
    taxRate = INITIAL_TAX_RATE;
    packing = PACK_TYPE::UNKNOWN;
    weight = 0.1;
    brandName = const_cast<char *>(bName.c_str());
}

BasicGoods::~BasicGoods() {

}

double BasicGoods::getEndPrice(void) const {
    return basePrice * (1 + (taxRate / 100));
}

double BasicGoods::getTaxPrice(void) const {
    return basePrice * (taxRate / 100);
}

std::string BasicGoods::getBrandName(void) {
    return brandName;
}

double BasicGoods::getWeight(void) const {
    return weight;
}

double BasicGoods::getVolume(void) const {
//    return (approxDim->at(0) * approxDim->at(1) * approxDim->at(2));
    return approxDim.get()[0][0] * approxDim.get()[0][1] * approxDim.get()[0][2];
}

std::string BasicGoods::getOriginCountry(void) const {
    return originCountry;
}

void BasicGoods::setOriginCountry(const std::string &cnt) {
    originCountry[cnt.size() + 1];
    std::strcpy(originCountry, cnt.c_str());
}

void BasicGoods::setAppearance(PACK_TYPE pck, std::shared_ptr<std::array<double, 3> > dimen) {
    packing = pck;
    approxDim = std::move(dimen);
}

bool BasicGoods::operator==(const BasicGoods &in) const {
    return (basePrice == in.basePrice) && (goodsType == in.goodsType) && (brandName == in.brandName);
}

bool BasicGoods::operator<(const BasicGoods &in) const {
    return basePrice < in.basePrice;
}

void BasicGoods::setNewPrice(double price) {
    basePrice = price;
}
