#SELECT contacts.*
#FROM contacts,companies
#WHERE contacts.company_id = companies.id
#AND companies.adress = "Aveiro";

import sqlite3 as sql;

def main():

    domain = input("Insira um nome para pesquisar por exemplo Leitner: ");
    db = sql.connect("database.db");
    result = db.execute("SELECT name, firstname FROM contacts,companies WHERE contacts.company_id = companies.id AND (firstname LIKE ? OR middlename LIKE ? OR lastname LIKE ?)", (domain,domain,domain))
    print("(empresa, nome da pessoa)")
    while True:
        rows = result.fetchone();
        if not rows:
            break;
        print(rows)
    db.close()


main()