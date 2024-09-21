#pragma once

#include "../include/IPAddress.hpp"
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <vector>

using boost::asio::ip::address;
using boost::asio::ip::address_v4;
using boost::asio::ip::make_network_v4;
using boost::asio::ip::network_v4;
using std::string;
using std::to_string;

using boost::system::system_error;
using std::cerr;
using std::endl;
using std::vector;

class SubnetCalc: public IPAddress {
public:
    // Constructor
    SubnetCalc(const string &ip, const unsigned prefix);
    
    // 
    void calcSubnets(unsigned int dSubnets = 0, unsigned int dHosts = 0);

};