#include "rpc.h"

#include <iostream>

#include "rpc/server.h"
#include "rpc/client.h"

namespace network {

  static const std::string ManccoinRPCVersion = "1.0.0";

  static rpc::server srv(8080);

  std::string version() {
    return ManccoinRPCVersion;
  }

  void bindRPCFunctions() {
    // Bind RPC functions to RPC server
    srv.bind("version", version);
  }

  template <typename F> void bind(std::string const &name, F func) {
    srv.bind(name, func);
  }

  void start() {
    std::cout << "Starting RPC server" << std::endl;

    bindRPCFunctions();
    srv.async_run();

    // Test connection
    rpc::client client("localhost", 8080);
    std::string version = client.call("version").as<std::string>();
    std::cout << "Manccoin RPC version: " << version << std::endl;
  }

}
