#include <iostream>
#include <string>
#include <vector>

// https://github.com/okdshin/PicoSHA2
#include "vendor/picosha2.h"

#include "Manccoin.h"

int main(int argc, char **argv) {
    std::string welcomeMessage = "Welcome to mancCoin";
    std::vector<unsigned char> hash(32);

    // SHA256 hash the welcome message
    picosha2::hash256(welcomeMessage.begin(),
                      welcomeMessage.end(),
                      hash.begin(),
                      hash.end());

    std::cout << welcomeMessage << " SHA256: " << std::endl;
    std::cout << picosha2::bytes_to_hex_string(hash.begin(), hash.end())
              << std::endl;

    std::cout << "Starting Blockchain" << std::endl;

    return Manccoin().start();
}
