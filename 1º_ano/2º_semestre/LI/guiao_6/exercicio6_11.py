import sqlite3 as sql;

def main():
    counter = 0;
    db = sql.connect("database.db");
    result = db.execute("SELECT lastname FROM contacts")

    while True:
        rows = result.fetchone();
        if not rows:
            break;
        counter+=1;
        print(rows)
    db.close()
    print(counter, "contactos")


main()