import sqlite3 as sql;

def main():

    domain = input("Insira um nome para pesquisar por exemplo Leitner: ");
    db = sql.connect("database.db");
    result = db.execute("SELECT * FROM contacts WHERE firstname LIKE ? OR middlename LIKE ? OR lastname LIKE ?", (domain,domain, domain))

    while True:
        rows = result.fetchone();
        if not rows:
            break;
        print(rows)
    db.close()


main()