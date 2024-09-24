#include "../include/NetScanner.hpp"

NetScanner::NetScanner(vector<string> &ips) {

}
NetScanner::NetScanner() {
    ips = SubnetCalc::calcSubnets;
}

vool NetScanner::isIPAlive() {
    io_context io;
    resolver resolver(io);
    endpoint destination = *resolver.resolve(v4(), ip_address, "").begin();
    socket socket(io, icmp::v4());

    array<char, 8> send_buf = {{ 0x08, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00, 0x00 }};
    socket.send_to(buffer(send_buf), destination);

    // Recibir respuesta
    array<char, 1024> reply_buf;
    endpoint sender;
    socket.receive_from(buffer(reply_buf), sender);

    // Verifica si hay respuesta
    return reply_buf[0] == 0;  // El primer byte indica "echo reply" si es 0x00
}

void NetScanner::scan() {
    for(unsigned i = 0; i < ips.size(); ++i) {
        if(isIPAlive())
    }
}