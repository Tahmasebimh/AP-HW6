//
// Created by Hossein on 5/28/2020.
//

#include <iostream>
#include "../h/productID.h"

productID::productID(std::shared_ptr<std::string> &in, const std::string &ss) {
    confirmStatement = in;
    standardSerial = ss;
}

void productID::printStatement(void) const {
    std::cout << "Legal Confirmation Statement: ["
     << confirmStatement->data() << "] , producer country: " << countryName << std::endl;
}

std::ostream &operator<<(std::ostream &os, const productID &id) {
    os << "Legal Confirmation Statement: [" << id.confirmStatement->data()
    << "] , producer country: " << id.countryName << ", serial number: " << id.standardSerial;
    return os;
}
