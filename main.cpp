// Copyright 2023 YOURMOM
#include <iostream>
#include "sample.hpp"
#include <pqxx/pqxx>

int main(int argc, char* argv[]) {\
    pqxx::connection conn("dbname=testdocker user=habrpguser password=pgpwd4habr \
                   	hostaddr=172.19.0.2 port=5432");
    std::cout << "Hello, world!" << std::endl;
  //  std::cout << evenOdd (11) << std::endl;
    return 0;
}
