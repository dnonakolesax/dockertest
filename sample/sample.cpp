#include "sample.hpp"
#include <pqxx/pqxx>

bool tryDB () {
    pqxx::connection conn("dbname=testdocker user=habrpguser password=pgpwd4habr \
                   	hostaddr=172.19.0.2 port=5432");

    pqxx::work txn(conn);

    std::string sql = "SELECT * FROM testdocker.example";
    pqxx::result r = txn.exec(sql);

    txn.commit();

    // for (auto const &row: r) {
    //     for (auto const &field: row) 
    //         std::cout << field.c_str() << '\t';
    //     std::cout << '\n';
    // }

    conn.close();
    return true;
}