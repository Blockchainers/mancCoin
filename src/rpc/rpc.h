#ifndef RPC_H
#define RPC_H

#include <string>

#include "rpc/server.h"

namespace network {
    extern const int serverPort;
    extern rpc::server srv;

    void start();

    // RPC function names
    namespace rpcinterface {
        static const auto version = "version";
        static const auto functions = "functions";
    }
}

#endif
