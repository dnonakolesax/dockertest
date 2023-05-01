#include "sample.hpp"
#include <iostream>
#include <pqxx/pqxx>
#include <fstream>
#include <sstream>
#include <json.hpp>

using json = nlohmann::json;

bool tryDB()
{
    try
    {
        pqxx::connection conn("dbname=postgres user=habrpguser password=pgpwd4habr \
                   	host=postgres port=5432");
        // pqxx::connection conn("dbname=postgres user=habrpguser password=pgpwd4habr \
     //               	host=172.19.0.2 port=5432");

        std::string sql = "CREATE DATABASE uzbek;";
        pqxx::nontransaction query(conn, sql);

        pqxx::result r = query.exec(sql);

        pqxx::connection conn2("dbname=uzbek user=habrpguser password=pgpwd4habr \
                    	host=postgres port=5432");

        std::ifstream sqlfile("../drop/db.sql");

        std::stringstream buffer;

        buffer << sqlfile.rdbuf();

        std::string sql2 = buffer.str();

        pqxx::nontransaction txn(conn2);

        pqxx::result r2 = txn.exec(sql2);
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
    return true;
}

void connectDB()
{
    try
    {
        std::ifstream f("../drop/config.json");

        json data = json::parse(f);

        std::string hostName = data["host"];

        std::string connConfig = "dbname=uzbek user=habrpguser password=pgpwd4habr host=" + hostName + " port=5432";

        pqxx::connection conn2(connConfig);

        pqxx::work txn(conn2);

        pqxx::result r = txn.exec("SELECT * FROM testdocker.example");


        txn.commit();
    }
    catch (std::exception const &e)
    {
        std::cerr << e.what() << std::endl;
    }
}