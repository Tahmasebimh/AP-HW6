//
// Created by Hossein on 5/29/2020.
//

#ifndef HW6_CUSTOMER_H
#define HW6_CUSTOMER_H
#include <string>
#include <vector>
#include <memory>
#include  <queue>
#include <algorithm>
#include "basicGoods.h"

using sharedBG = std::shared_ptr<BasicGoods>;


class Customer
{
protected:
    std::string name;
    double totalChargedTax;
    std::deque< std::shared_ptr<BasicGoods> > assets;
    double assetValue;

public:
    explicit Customer(const std::string& name);
    virtual ~Customer();




    // simple functions
    using sharedBG = std::shared_ptr<BasicGoods>;
    std::string printBasicInfo(void) const;

    // getter
    double getTotalAsset(void) const;
    double getTotalChargedTax(void) const;


//     importers
    virtual void importNewGoods(std::shared_ptr<BasicGoods>);

    template<class Iterator>
    void importNewGoods(Iterator f, Iterator d) {
        for (Iterator it = f; it != d ; it++) {
            assets.push_back(*it);
        }
    };

    //template <class T>
    //	void findGoods( std::deque< sharedBG >& list, T comp);


    //template <typename T>
    //bool queueGoods(
    //	std::priority_queue< sharedBG, std::deque<sharedBG> , Shared_less<BasicGoods> >& Q);



    // operators
    //virtual bool operator==(const Customer& in) const = 0;
};



#endif //HW6_CUSTOMER_H
