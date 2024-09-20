#include "../include/IPAdress.hpp"

using boost::system::system_error;
using std::cerr;
using std::endl;

// Constructor
IPAddress::IPAddress(const string &ip, const unsigned short prefix) {
    setIPPrefix(ip, prefix);
}

// Motodo para validar una ip
bool IPAddress::validateIP() {
    try {
        // Verifica la versión y valida el prefijo
        whatVersion();
        if (!validatePrefix()) {
            cerr << "Error: Prefijo no válido para la versión de IP" << endl;
            return false;
        }
        return true;
    } catch (const system_error &e) {
        cerr << "Error: IP no válida: " << e.what() << endl;
        return false;
    }
}
// Determina si es IPv4 o IPv6
void IPAddress::whatVersion() {
    this->isIPv4 = ipAddress.is_v4();
}
// Valida que el prefijo sea correcto según la versión de la IP
bool IPAddress::validatePrefix() {
    if (this->isIPv4 && (this->prefix > 32 || this->prefix <= 0)) {
        cerr << "Error: Prefijo inválido para IPv4 (1-32)" << endl;
        return false;
    } else if (!this->isIPv4 && (this->prefix > 128 || this->prefix <= 0)) {
        cerr << "Error: Prefijo inválido para IPv6 (1-128)" << endl;
        return false;
    }
    return true;
}



// Setters para IP y Prefijo
void IPAddress::setIPPrefix(const string &ip, const unsigned short prefix) {
    if (!IPAddress::isValid(ip)) { // Corrección: llamada al método estático
        cerr << "Error: La IP proporcionada no es válida." << endl;
        return;
    }
    try {
        this->ipAddress = address::from_string(ip);
        this->prefix = prefix;
        // Evalúa que la IP y prefijo sean válidos
        this->isIPValid = validateIP();
        if (!this->isIPValid) {
            cerr << "Error: Configuración de IP y prefijo no válida." << endl;
        }
    } catch (const system_error &e) {
        cerr << "Error al establecer IP y prefijo: " << e.what() << endl;
    }
}
// Método estático para validar la IP
bool IPAddress::isValid(const string &ip) {
    try {
        address::from_string(ip);
        return true;
    } catch (const system_error &e) {
        cerr << "Error: " << e.what() << endl;
        return false;
    }
}
