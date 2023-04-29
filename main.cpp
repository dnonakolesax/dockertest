// Copyright 2023 YOURMOM
#include <iostream>
#include "sample.hpp"
#include <pqxx/pqxx>

int main(int argc, char* argv[]) {
    pqxx::connection conn("dbname=testdocker user=habrpguser password=pgpwd4habr \
                   	hostaddr=172.19.0.2 port=5432");
                    
    pqxx::work txn(conn);

    std::string sql = "SELECT * FROM testdocker.example";
    pqxx::result r = txn.exec(sql);

    txn.commit();

    for (auto const &row: r) {
        for (auto const &field: row) 
            std::cout << field.c_str() << '\t';
        std::cout << '\n';
    }

  //  std::cout << evenOdd (11) << std::endl;
    return 0;
}
