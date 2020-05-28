//
// Created by Hossein on 5/28/2020.
//

#include <iostream>
#include "../h/appliance.h"

Appliance::Appliance(const std::string &name, double price, double Wei) : BasicGoods(name, GOODS_TYPE::OBJECT, price) {
    weight = Wei;
}

bool Appliance::operator==(const BasicGoods &in) const {
    if(const auto* appliance = dynamic_cast<const Appliance*>(&in)){
        return BasicGoods::operator==(in) && (appliance->weight == weight) && (energyGrade == appliance->energyGrade);
    }else{
        return false;
    }
}

double Appliance::getEndPrice(void) const {
    return basePrice * (1 + ((taxRate + ((energyGrade == ENERGY_COST::HIGH) ? APPLIANCE_EXTRA_TAX_HIGH : APPLIANCE_EXTRA_TAX_MEDIUM))/100));
}

double Appliance::getWeight(void) const {
    return BasicGoods::getWeight() + weight;
}

double Appliance::getTaxPrice(void) const {
    return BasicGoods::getTaxPrice() +((energyGrade == ENERGY_COST::HIGH) ? APPLIANCE_EXTRA_TAX_HIGH : APPLIANCE_EXTRA_TAX_MEDIUM);
}

void Appliance::setWeight(double w) {
    weight = w;
}

void Appliance::setEnergyGrade(ENERGY_COST ec) {
    energyGrade = ec;
}

std::shared_ptr<std::array<double, 3> >& Appliance::getApproxDime() {
    return this->approxDim;
}
