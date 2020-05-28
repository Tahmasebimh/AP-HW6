//
// Created by Hossein on 5/28/2020.
//

#ifndef HW6_PRODUCTID_H
#define HW6_PRODUCTID_H


#include <string>
#include <memory>
#include <ostream>

class productID {
protected:
    std::string standardSerial;
    std::shared_ptr< std::string > confirmStatement;
    std::string countryName;

public:
    productID(std::shared_ptr< std::string >& in , const std::string& ss = "");

    void printStatement(void) const;

    friend std::ostream &operator<<(std::ostream &os, const productID &id);
};


#endif //HW6_PRODUCTID_H
