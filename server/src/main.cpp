#include <string>
#include <iostream>
#include <csignal>
#include "network.hpp"


int port_selection(int argc, char* argv[]){
    int port = 12345;

    if (argc >= 2){
        try {
            port = std::stoi(argv[1]);
        }
        catch(const std::invalid_argument& e){
            std::cerr << "[ERROR]: Port must be a number." << '\n';
            return -1;
        }
        
        if (port < 1024 || port > 65535){
            std::cerr << "[ERROR]: Port must be in the range 1024 - 65535." << '\n';
            return -1;
        } 
    }

    return port;
}


int main(int argc, char* argv[]){
    int port = port_selection(argc, argv);
    if (port == -1){
        return 1;
    }

    std::signal(SIGPIPE, SIG_IGN); // SIG_IGN ignores SIGPIPE signal
    // SIGINT handle

    std::cout << "Server starts on port " << port << '\n';

    int fd = init_server_socket(port);
    if (fd == -1){
        return 1;
    }

    // Data loading




}