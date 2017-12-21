#ifndef RPC_H
#define RPC_H

#include <string>
namespace network {
  void start();

  template <typename F> 
  void bind(std::string const &name, F func);
}

#endif
