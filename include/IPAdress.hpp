#ifndef IPADRESS_HPP
#define IPADRESS_HPP

#include <iostream>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::address;
using std::string;

class IPAddress {
private:
    address ipAddress;
    unsigned short prefix;
    bool isIPv4;
    bool isIPValid;

    bool validateIP();
    void whatVersion();
    bool validatePrefix();

public:
    // Constructor
    IPAddress(const string &ip, const unsigned short prefix);
    // Destructor por defecto
    ~IPAddress() = default;

    // Setters para IP y Prefijo
    void setIPPrefix(const string &ip, const unsigned short prefix);

    // Método estático para validar la IP
    static bool isValid(const string &ip);
};

#endif 