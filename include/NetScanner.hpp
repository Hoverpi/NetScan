#pragma once

#include "../include/IPAddress.hpp"
#include <iostream>
#include <boost/asio.hpp>
#include <string>
#include <vector>

using boost::asio::ip::address;
using boost::asio::ip::address_v4;
using boost::asio::ip::address_v6;
using boost::asio::ip::make_network_v4;
using boost::asio::ip::network_v4;
using boost::asio::ip::icmp;
using boost::asio::array;
using std::string;
using std::to_string;

using boost::system::system_error;
using std::cerr;
using std::endl;
using std::vector;

class NetScanner {
private:
    bool isAlive;
    vector<address_v4> ipsv4;
    vector<address_v6> ipsv6;

    bool isIPAlive(vector<string> &ip);

public:
    NetScanner(vector<string> &ips);
    NetScanner();

    void scan();
};