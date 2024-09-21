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
    }
}