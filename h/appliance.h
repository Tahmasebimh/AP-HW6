//
// Created by Hossein on 5/28/2020.
//

#ifndef HW6_APPLIANCE_H
#define HW6_APPLIANCE_H


#include "basicGoods.h"

enum class ENERGY_COST{
    IRRELEVANT,
    LOW,
    MEDIUM,
    HIGH
};


class Appliance : public BasicGoods {
protected:
    double weight; // which is netWeight
    ENERGY_COST energyGrade;

    double getEndPrice(void) const override;


public:

    Appliance(const std::string& name, double price, double Wei);
    //~Appliance();

    constexpr static double APPLIANCE_EXTRA_TAX_HIGH = 17;
    constexpr static double APPLIANCE_EXTRA_TAX_MEDIUM = 7;

    bool operator==(const BasicGoods &in) const override;

    // getter and setters
    double getWeight(void) const ;
    double getTaxPrice(void) const;
    void setWeight(double w);
    void setEnergyGrade(ENERGY_COST ec);

    std::shared_ptr< std::array<double,3> > &getApproxDime();

};


#endif //HW6_APPLIANCE_H
