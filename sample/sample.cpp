#include "sample.hpp"
#include <iostream>
#include <pqxx/pqxx>

bool tryDB () {
    try {
    pqxx::connection conn("dbname=testdocker user=habrpguser password=pgpwd4habr \
                    	host=postgres port=5432");

    pqxx::work txn(conn);

    std::string sql = "SELECT * FROM testdocker.example";
    pqxx::result r = txn.exec(sql);

    txn.commit();
    conn.close();

    std::cout << "uzbek" << std::endl;
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return true;
}