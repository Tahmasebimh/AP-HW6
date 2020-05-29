//
// Created by Hossein on 5/28/2020.
//

#ifndef HW6_MATERIAL_H
#define HW6_MATERIAL_H


#include "basicGoods.h"

enum class MAT_TYPE{
    NORMAL,
    FLAMABLE,
    HAZARDOUS
};

class Material : virtual public BasicGoods {
protected:
    double weigth;
    MAT_TYPE matType;

public:
    Material(const std::string& name, double price , double weight, MAT_TYPE mt = MAT_TYPE::NORMAL);
    //~Material();

    constexpr static double MATERIAL_TAX = 1.5;


    // getters
    double getWeight(void) const;
    double getTaxPrice(void) const;
    double getEndPrice(void) const;

    bool operator==(const BasicGoods &in) const override;

};


#endif //HW6_MATERIAL_H
