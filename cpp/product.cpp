//
// Created by Hossein on 5/28/2020.
//

#include "../h/product.h"

Product::Product(const std::string &brandName, double price,
        double matWei, shared_str confirmation)
        : Material(brandName, price, matWei)
        , Appliance(brandName, price, 0.3)
        , productID(confirmation)
        , BasicGoods(brandName, GOODS_TYPE::OBJECT, price){
    packing = PACK_TYPE ::CARTON;
    std::array<double , 3> arr{0.5, 0.8, 1.2 * (1 + matWei)};
    approxDim = std::make_shared<std::array<double, 3>>(arr);
}

double Product::getWeight(void) const {
    return Appliance::weight + Material::weigth + BasicGoods::weight;
}

void Product::setTaxRate(double newTax) {
    taxRate = newTax;
}

bool Product::operator==(const BasicGoods &in) const {
    return Appliance::operator==(in) && Material::operator==(in);
}

double Product::getTaxPrice(void) const {
    return basePrice * (taxRate + ((energyGrade == ENERGY_COST::HIGH) ? APPLIANCE_EXTRA_TAX_HIGH : APPLIANCE_EXTRA_TAX_MEDIUM))/100;
}

Product::~Product() {

}


double Product::getEndPrice(void) const {
    return basePrice * (1 + (taxRate + ((energyGrade == ENERGY_COST::HIGH) ? APPLIANCE_EXTRA_TAX_HIGH : APPLIANCE_EXTRA_TAX_MEDIUM))/100);
}




