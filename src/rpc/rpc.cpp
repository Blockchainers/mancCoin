#include "rpc.h"

#include <iostream>

#include "rpc/server.h"

namespace network {

  static const std::string ManccoinVersion = "1.0.0";

  static rpc::server srv(8080);

  void start() {
    std::cout << "Starting RPC server" << std::endl;

    srv.bind("version", [](void) {
      return ManccoinVersion;
    });

    srv.async_run();
  }

}
