#include "rpc.h"

#include <iostream>

#include "rpc/server.h"
#include "rpc/client.h"

namespace network {

    static const std::string ManccoinRPCVersion = "1.0.0";

    static std::vector<std::string> functions = std::vector<std::string>();

    const int serverPort = 8080;
    rpc::server srv(serverPort);

    std::string version() {
        return ManccoinRPCVersion;
    }

    void bindRPCFunctions() {
        // Bind RPC functions to RPC server
        network::srv.bind(rpcinterface::version, version);
        network::srv.bind(rpcinterface::functions, []() {
            return network::functions;
        });
    }

    void start() {
        std::cout << "Starting RPC server on port " << serverPort << std::endl;
        network::srv.async_run();

        bindRPCFunctions();

        // Test connection
        rpc::client client("localhost", serverPort);
        std::string version = client.call(rpcinterface::version).as<std::string>();
        std::cout << "Manccoin RPC version: " << version << std::endl;
    }

}
