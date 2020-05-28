#include <iostream>
#include <array>
#include <chrono>
#include "h/food.h"
#include "h/appliance.h"
#include "h/productID.h"


class Base
{
public:
    Base(){
        std::cout << "Base Constructor Called\n";
    }
    virtual ~Base(){
        std::cout << "Base Destructor called\n";
    }
};
class Derived1: public Base
{
public:
    Derived1(){
        std::cout << "Derived constructor called\n";
    }
    ~Derived1(){
        std::cout << "Derived destructor called\n";
    }
};
int main() {
//    Base *b = new Derived1();
//    delete b;
//    std::chrono::milliseconds ms = std::chrono::duration_cast< std::chrono::milliseconds >(
//            std::chrono::system_clock::now().time_since_epoch()
//    );
//    std::cout << "time in milis : " << ms.count() << std::endl;
//    std::cout << "time in milis : "
//    << std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::hours(24 * 14)).count();
//    std::time_t time1;
//    std::time_t result = std::time(&time1);
//    std::cout << std::asctime(std::localtime(&result))
//              << result << " seconds since the Epoch\n";
//
//    result = result +
//            (std::chrono::duration_cast< std::chrono::milliseconds >(std::chrono::hours(24 * 14)).count() / 1000);
//    std::cout << std::asctime(std::localtime(&result))
//              << result << " seconds since the Epoch\n";


//    BasicGoods basicGoods("asghat5", GOODS_TYPE::CONSUMABLE, 100);
    std::shared_ptr<std::array<double, 3> > dimen;
    std::array<double , 3> arr{2, 0.5, 3};
    dimen = std::make_shared<std::array<double, 3>>(arr);
//    basicGoods.setAppearance(PACK_TYPE::UNKNOWN, dimen);
//    std::cout << "dimen : " << basicGoods.getVolume() << std::endl;
//
//
//    Food food("name ", 1000, 4000);
//    std::cout << "exp : " << food.getRemainingExp() << std::endl;
//
//
//    auto* f = new BasicGoods("name ", GOODS_TYPE ::CONSUMABLE, 4000);
//
//    if (Food* f1 = dynamic_cast<Food*>(f)){
//        std::cout << "cast succes " << std::endl;
//    }else{
//        std::cout << "cast failed " << std::endl;
//
//    }



    BasicGoods * bb = new Appliance("daf", 100, 20);
    std::cout << "price is : " << bb->getEndPrice() << std::endl;

    Appliance appliance("daf", 100, 20);
    appliance.getApproxDime() = dimen;

    std::cout << appliance.getApproxDime().get()[0][2] << std::endl;
    std::string s = "salalalalal";
    std::shared_ptr<std::string> ptr = std::make_shared<std::string>(s);
    auto* productId = new productID(ptr, "dsffds");
    std::cout << *productId << std::endl;
    return 0;
}
