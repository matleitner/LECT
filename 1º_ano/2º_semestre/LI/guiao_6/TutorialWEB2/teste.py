import time
from sqlite3 import sql
print(time.strftime('date:%d-%m-%Y time:%H:%M:%S'))

db = sql.connect("database.db")
db.execute("INSERT INTO images (names, author, path, datatime) VALUES (?, ?, ?, ?)",(nameImg,authorImg, path, datetime))
db.commit();

result = db.execute("SELECT * FROM images WHERE name = ?", (nameImg,))
lastid  = result.fetchone()[0]
db.execute("INSERT INTO votes (iding, ups, downs) VALUES (?, ?, ?)", (lastid, 0, 0))
db.commit()
db.close()