//
// Created by Hossein on 5/28/2020.
//

#ifndef HW6_FOOD_H
#define HW6_FOOD_H


#include <ctime>
#include "basicGoods.h"

template<typename Base, typename T>
inline bool instanceof(const T *) {
    return std::is_base_of<Base, T>::value;
}

enum class FOOD_MODE  {
    LIQUID, CREAM , SOLID
};


class Food: public BasicGoods
{
private:
    FOOD_MODE mode;
    double netWeight;
    std::time_t expirationTime;

public:

    Food(const std::string& name, double price, double Wei, FOOD_MODE md = FOOD_MODE::SOLID);
    //~Food();

    constexpr static double FOOD_TAX_SUBSIDE = 3; // subtract this!

    // getters
    double getEndPrice(void) const;
    double getTaxPrice(void) const override;
    double getWeight(void) const;
    std::time_t getRemainingExp(void) const;

    // setters
    void setExpiration(std::time_t t);
    void setFoodMode(FOOD_MODE md);

    void configFoodDimention(FOOD_MODE mode);

    bool operator==(const BasicGoods &in) const override;

    bool operator<(const BasicGoods &in) const override;
};



#endif //HW6_FOOD_H
