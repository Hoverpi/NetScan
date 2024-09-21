#pragma once

#include <iostream>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::address;
using std::string;
using std::to_string;

using boost::system::system_error;
using std::cerr;
using std::endl;

class IPAddress {
protected:
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
    virtual ~IPAddress() = default;

    // Setters para IP y Prefijo
    void setIPPrefix(const string &ip, const unsigned short prefix);

    // Getters para IP y Prefijo
    string getIP() const;
    unsigned short getPrefix() const;

    // Método estático para validar la IP
    static bool isValid(const string &ip) const;
};

#endif 