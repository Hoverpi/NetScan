#include "../include/SubnetCalc.hpp"

// Constructor
SubnetCalc::SubnetCalc(const string &ip, unsigned short prefix)
    : IPAddress(ip, prefix) {}

void calcSubnets(unsigned int dSubnets = 0, unsigned int dHosts) {
    if(!(isValid(ip))) {
        cerr << "Error: Ip no valida" << endl;
        return;
    }

    try {
        auto network = make_network_v4(ipAddress.to_string() + "/" + to_string(prefix));
        cout << "Network: " << network << endl;

        vector<network_v4> subnets;

        // Calcular basado en las subredes
        if(dSubnets > 0) {
            unsigned int bitsNeed = 0;
            while((1 << bitsNeed) < dSubnets) {
                bitsNeed++;
            }
            unsigned short newPrefix = prefix + bitsNeed;
            
            // Generarlos
            for(unsigned int i = 0; i < (1 << bitsNeed); ++i) {
                address_v4 subnetAddress = network.network().to_v4();
                subnetAddress = address_v4(subnetAddress.to_ulong() + (i << (32 - newPrefix)));
                subnets.push_back(make_network_v4(subnetAddress, newPrefix));
            }
        }

        // Calcular subredes basadas en la cantidad de hosts
        if (dHosts > 0) {
            unsigned int bitsNeed = 0;
            // Determinar cuántos bits se necesitan para los hosts
            while ((1 << bitsNeed) < (dHosts + 2)) {  // Se suman 2 para la IP de red y la de broadcast
                bitsNeed++;
            }

            // Nuevo prefijo para las subredes
            unsigned short newPrefix = 32 - bitsNeed;

            // Generar subredes
            unsigned int numSubnets = 1 << (newPrefix - prefix);
            for (unsigned int i = 0; i < numSubnets; ++i) {
                address_v4 subnetAddress = network.network().to_v4();
                subnetAddress = address_v4(subnetAddress.to_ulong() + (i << bitsNeed));
                subnets.push_back(make_network_v4(subnetAddress, newPrefix));
            }
        }

        // Imprimir las subredes calculadas
        for (const auto& subnet : subnets) {
            cout << "Subnet: " << subnet << endl;
        }

    } catch(system_error &e) {
        cerr << "Error: IP no válida o prefijo incorrecto: " << e.what() << endl;
    }
}