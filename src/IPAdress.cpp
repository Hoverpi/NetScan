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

    bool validateIP() {
        try {
            address::from_string(this->ipAdress.toString());
            whatVersion();
            if(!(validatePrefix())) {
                cerr << "Error: Prefijo no valido par la version IP" << endl;
                return false;
            } 
            return true;
        } catch(const system_error &e) {
            cerr << "Error: IP no valida " << e.what() << endl;
            return false;
        }
    } 

    void whatVersion() {
        this->isIPv4 = ipAdress.is_v4(); 
    }

    bool validatePrefix() {
        if(this->isIPv4 && (this->prefix >= 32) && (this->prefix <= 0)) {
            cerr << "Error: Prefijo invalido para IPv4 (1-32)" << endl;
            return false;
        } else if(!(isIPv4() && (this->prefix >= 128) && (this->prefix <= 0))) {
            cerr << "Error: Prefijo invalido para IPv6 (1-128)" << endl;
            return false;
        }
        return true;
    }

public:
    // Constructor
    IPAdress(const string &ip, const short prefix) {
        setIPPrefix(ip, prefix);
    }
    // Destructor por default
    ~IPAdress() = default;

    // Setters para IP y Prefijo
    void setIPPrefix(const string &ip, const unsigned short prefix) {
        try (
            this->ipAdress = address::from_string(ip);
            // Evalua que sea un ip valida
            this->isValid = validateIP();

            this->prefix = prefix;
            // Evalua que sea un prefijo valido
            if(!(this->isValid)) {
                cerr << "Error: Configuracion de IP y prefijo no valida" << endl;
            }
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
};