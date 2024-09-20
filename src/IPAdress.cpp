#include <boost/asio.hpp>

using boost::asio::ip::address;

class IP {
private:
    address ipAdress;
    bool IpVersion; // IPv4 = 0, IPv6 = 1
    address ipMask;
    bool isValid;   

public:
    
}