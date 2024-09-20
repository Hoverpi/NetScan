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
    bool isIPv4;
    bool isValid;  

    void validateIP() {
        try {
            address::from_string(this->ipAdress.toString());
            return true;   
        } catch(const system_error &e) {
            cerr << "Error: IP no valida " << e.what() << endl;
            return false;
        }
    } 

    void whatVersion() {
        this->isIPv4 = ipAdress.is_v4(); 
    }

public:
    IPAdress(const string &ip, const short prefix) {
        setIPPrefix(ip, prefix);
    }

    ~IPAdress() = default;

    // Setters para IP y Prefijo
    void setIPPrefix(const string &ip, const unsigned short prefix) {
        try (
            this->ipAdress = address::from_string(ip);
            // Evalua que sea un ip valida
            this->isValid = validateIP;

            this->prefix = prefix;
            // Evalua que sea un prefijo valido
            whatVersion();
        ) catch(const system_error &e) {
            cerr << "Error al establecer IP y prefijo: " << e.what() << endl;
        }
    }

    static bool isValid(const string &ip) {
        try {
            address::from_string(pi);
            return true;
        } catch(const system_error &e) {
            cerr << "Error: " << e.what() << endl;
            return false;
        }
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