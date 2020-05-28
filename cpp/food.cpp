//
// Created by Hossein on 5/28/2020.
//

#include <chrono>
#include <iostream>
#include "../h/food.h"

double Food::getEndPrice(void) const {
    return basePrice * (1 + ((taxRate - FOOD_TAX_SUBSIDE)/100));
}

double Food::getTaxPrice(void) const {
    return basePrice * ((taxRate - FOOD_TAX_SUBSIDE)/100);
}

Food::Food(const std::string &name, double price, double Wei, FOOD_MODE md)
    : BasicGoods(name, GOODS_TYPE::CONSUMABLE, price) {
    mode = md;
    BasicGoods::weight = Wei;
    expirationTime = time(nullptr);
    expirationTime += (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::hours(24 * 14)).count() / 1000);

    configFoodDimention(md);

}

void Food::configFoodDimention(FOOD_MODE mode) {
    std::array<double , 3> arr{};
    arr[0] = 0.3;
    arr[1] = 0.4;
    if (mode == FOOD_MODE::SOLID){
        packing = PACK_TYPE ::NYLON;
        arr[2] = 0.7 * netWeight;
    }else if(mode == FOOD_MODE::CREAM){
        packing = PACK_TYPE ::BARREL;
        arr[2] = 0.3 * netWeight;
    }else if(mode == FOOD_MODE::LIQUID){
        packing = PACK_TYPE ::CAN;
        arr[2] = 0.2 * netWeight;
    }
    setAppearance(packing, std::make_shared<std::array<double, 3>>(arr));
}

double Food::getWeight(void) const {
    return BasicGoods::getWeight() + netWeight;
}

std::time_t Food::getRemainingExp(void) const {
    return expirationTime - std::time(nullptr);
}

void Food::setExpiration(std::time_t t){
    if (t >= std::time(nullptr)){
        expirationTime = t;
    }
//    else{
//        throw "expire time must be later than now";
//    }
}

void Food::setFoodMode(FOOD_MODE md) {
    mode = md;
}

bool Food::operator==(const BasicGoods &in) const {
    if(const auto * food = dynamic_cast<const Food*>(&in)){
        return BasicGoods::operator==(in) && (mode == food->mode );
    }else{
        return false;
    }
}

bool Food::operator<(const BasicGoods &in) const {
    if(const Food* food = dynamic_cast<const Food*>(&in)){
        return expirationTime < food->expirationTime;
    }else{
        return BasicGoods::operator<(in);
    }
}

