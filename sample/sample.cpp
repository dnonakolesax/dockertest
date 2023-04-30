#include "sample.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <sstream>

bool tryDB () {
    try {
    //pqxx::connection conn("dbname=testdocker user=habrpguser password=pgpwd4habr \
    //                	host=postgres port=5432");
    // pqxx::connection conn("dbname=postgres user=habrpguser password=pgpwd4habr \
    //                 	host=172.19.0.2 port=5432");
                        
    // std::string sql = "CREATE DATABASE uzbek;";
    // pqxx::nontransaction query(conn, sql);

    // pqxx::result r = query.exec(sql);

    // std::cout << "uzbek" << std::endl;

    pqxx::connection conn2("dbname=uzbek user=habrpguser password=pgpwd4habr \
                    	host=172.19.0.2 port=5432");

    std::ifstream sqlfile("../drop/db.sql");

    std::stringstream buffer;

    buffer << sqlfile.rdbuf();

    std::string sql2 = buffer.str();

    pqxx::nontransaction txn(conn2);                   

    pqxx::result r2 = txn.exec(sql2);
    }
    catch (std::exception const &e) {
        std::cerr << e.what() << std::endl;
    }
    return true;
}

void connectDB () {
     pqxx::connection conn2("dbname=uzbek user=habrpguser password=pgpwd4habr \
                    	host=172.19.0.2 port=5432");

    pqxx::work txn(conn2);                   

    pqxx::result r = txn.exec("SELECT * FROM testdocker.example");

    for (auto row: r) {
        std::cout << "id = " << row[0].as<int>() << ", column1 = " << row[1].as<std::string>() << ", column2 = " << row[2].as<std::string>() << std::endl;
    }

    txn.commit();
}