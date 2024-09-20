#include <iostream>
#include <boost/asio.hpp>
#include <string>

using boost::asio::ip::address;
using boost::system::system_error;
using std::string;
using std::cerr;
using std::endl;

class IPAdress {
private:
    address ipAdress;
    unsigned short prefix;
    bool IpVersion; // IPv4 = 0, IPv6 = 1
    bool isValid;  

    void isValid() {
        isValid(this->ipAdress, this->prefix);
    } 

    void isVersion() {
        isValidVersion(this->ipAdress, this->prefix) {
            bool flag;
            
        }
    }

public:
    IPAdress(const string &ip, const short prefix) {
        setIPPrefix(ip, prefix);
    }

    ~IPAdress() = default;

    // Setters
    void setIPPrefix(string &ip, const short prefix) {
        address oldIpAdress = this->ipAdress;
        using short oldprefix = this->prefix;

        this->ipAdress = ip;
        this->prefix = prefix;

        if(!(isValid() && isVersion())) {
            this->ipAdress;
        }
    }

    static bool isValid(string &ip, const short prefix) {

    }



    // Validate
    static bool isValidIP(string &ip) {
        try {
            address::from_string(ip);
            return true;   
        } catch(const system_error &e) {
            cerr << "Error: " << e.what() << endl;
            return false;
        }
    }
};