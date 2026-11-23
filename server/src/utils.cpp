#include <string>
#include <cstring>
#include <cerrno>
#include <iostream>
#include "utils.hpp"


void log_errno(const std::string &context){
    int err = errno;
    std::cerr << "[ERROR]: " << context << " (errno = " << err << "): " 
              << std::strerror(err) << '\n';
}