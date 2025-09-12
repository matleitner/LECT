# encoding=utf-8
#
# Example of a cherrypy application that serves images.
#
# Adrego da Rocha - Abril de 2023
#
# To run: python3 app.py

import os.path
import cherrypy
import json
import hashlib
import sqlite3 as sql
import time

# The absolute path to this file's base directory
baseDir = os.path.abspath(os.path.dirname(__file__))

# Dictionary with this application's static directories configuration
config = {
			"/":		{	"tools.staticdir.root": baseDir },
			"/html":	{	"tools.staticdir.on": True, "tools.staticdir.dir": "html" },
			"/js":		{	"tools.staticdir.on": True, "tools.staticdir.dir": "js" },
			"/css":		{	"tools.staticdir.on": True, "tools.staticdir.dir": "css" },
			"/images":	{	"tools.staticdir.on": True, "tools.staticdir.dir": "images" },
			"/uploads":	{	"tools.staticdir.on": True, "tools.staticdir.dir": "uploads" },          
}

class Root():
	@cherrypy.expose
	def index(self):
		return open("html/index.html")

	# UpLoad image
	@cherrypy.expose
	def upload(self, myFile):
		h = hashlib.sha256()

		filename = baseDir + "/uploads/" + myFile.filename
		fileout = open(filename, "wb")
		while True:
			data = myFile.file.read(8192)
			if not data: break
			fileout.write(data)
			h.update(data)
		fileout.close()

		# final path of the image and changing the filename
		ext = myFile.filename.split(".")[-1]
		path = baseDir + "/uploads/" + h.hexdigest() + "." + ext
		os.rename(filename, path)
		
		# nameImg and authorImg are input parameters of this method
		# obtain the date and time of loading
		datetime = time.strftime('date:%d-%m-%Y time:%H:%M:%S')

		# insert the file information in the images table
		# eventually initialize the votes tables

		db = sql.connect('database.db')
			#db.execute(query of type INSERT (nameImg, authorImg, path, datetime))
		db.commit()
		db.close()

	# List requested images
	@cherrypy.expose
	def list(self, id):
		db = sql.connect('database.db')
		if (id == "all"):
			...
			# result = db.execute(query of type SELECT for all images)
		else:
			...
			# result = db.execute(query of type SELECT for all images of the author id)
		rows = result.fetchall()
		db.close()

		# Generate result (list of dictionaries) from rows (list of tuples)
		result = []
		
		# eventually sort result by image name before return

		cherrypy.response.headers["Content-Type"] = "application/json"
		return json.dumps({"images": result}).encode("utf-8")

	# List comments
	@cherrypy.expose
	def comments(self, idimg):
		db = sql.connect('database.db')
		# result = db.execute(query of type SELECT for image of the id idimg)
		row = result.fetchone()
		
		# Generate output dictionary with image information
		imageinfo = dict()

		# result = db.execute(query of type SELECT for all comments of the id idimg)
		rows = result.fetchall()

		# Generate output dictionary with image comments list
		comments = []

		# result = db.execute(query of type SELECT for votes of the id idimg)
		row = result.fetchone()
		db.close()

		# Generate output dictionary with image votes
		imagevotes = dict()
		imagevotes["thumbs_up"] = 0
		imagevotes["thumbs_down"] = 0

		cherrypy.response.headers["Content-Type"] = "application/json"
		return json.dumps({"image": imageinfo, "comments": comments, "votes": imagevotes}).encode("utf-8")

	# UpLoad comment
	# Increment Up votes
	# Increment Down votes

cherrypy.quickstart(Root(), "/", config)
