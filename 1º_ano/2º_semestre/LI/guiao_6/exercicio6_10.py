import sqlite3 as sql;
import sys;

def main():
    db = sql.connect("database.db")               #db = sql.connect(argv[1]) i no main(argv)
    result = db.execute("SELECT * FROM contacts") #^^ 1º argumento no terminal, vou usar o nome direto da database1  
    #rows = result.fetchall()
    #for row in rows:
    #    print(row)     
    
    #ou então um a um usando fetchon()

    #while True:
    #    row = result.fetchone()
    #    if not row:
    #        break
    #    print(row)

    # ou 
    for row in result:
        print(row)
    db.close()                

if __name__ == "__main__":
    main() #e aqui ficaria main(sys.argv)