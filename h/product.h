//
// Created by Hossein on 5/28/2020.
//

#ifndef HW6_PRODUCT_H
#define HW6_PRODUCT_H


#include <string>
#include <memory>
#include "appliance.h"
#include "material.h"
#include "productID.h"

using shared_str = std::shared_ptr<std::string>;

class Product : public Material, public Appliance, public productID {

private:
    double taxRate;
public:

    bool operator==(const BasicGoods &in) const override;

    [[nodiscard]] double getTaxPrice(void) const override;

    ~Product() override;

    [[nodiscard]] double getEndPrice(void) const override;


protected:


public:
    Product(const std::string& brandName, double price, double matWei, shared_str confirmation);
    //~Product();

    constexpr static double TYPICAL_TAX_RATE = 23;



    double getWeight(void) const override;
    void setTaxRate(double newTax);
};


#endif //HW6_PRODUCT_H
