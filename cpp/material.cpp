//
// Created by Hossein on 5/28/2020.
//

#include "../h/material.h"

Material::Material(const std::string &name, double price, double weight, MAT_TYPE mt)
    :  BasicGoods(name, GOODS_TYPE::CONSUMABLE, price){
    this->weigth = weight;
    matType = mt;
}

double Material::getWeight(void) const {
    return BasicGoods::getWeight() + weigth;
}

double Material::getTaxPrice(void) const {
    return basePrice * ((taxRate + MATERIAL_TAX)/100);
}

double Material::getEndPrice(void) const {
    return basePrice * (1 + ((taxRate + MATERIAL_TAX)/100));
}

bool Material::operator==(const BasicGoods &in) const {
    if(const auto * material = dynamic_cast<const Material*>(&in)){
        return BasicGoods::operator==(in) && (getWeight() == material->getWeight());
    }else{
        return false;
    }
}
