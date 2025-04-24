# encoding=utf-8
#
# Example of a cherrypy application that serves static content as well as dynamic content.
#
# Adrego da Rocha - Fevereiro de 2023
#
# To run: python3 app.py
import time
import os.path
import cherrypy
import json
from math import radians, cos, sin, asin, sqrt
import hashlib

# The absolute path to this file's base directory
baseDir = os.path.abspath(os.path.dirname(__file__))

# Dictionary with this application's static directories configuration
config = {
			"/":		{	"tools.staticdir.root": baseDir },

			"/html":	{	"tools.staticdir.on": True, "tools.staticdir.dir": "html" },

			"/js":		{	"tools.staticdir.on": True, "tools.staticdir.dir": "js" },

			"/css":		{	"tools.staticdir.on": True, "tools.staticdir.dir": "css" },

			"/images":	{	"tools.staticdir.on": True, "tools.staticdir.dir": "images" }, 
			"/uploads": { "tools.staticdir.on": True, "tools.staticdir.dir": "uploads" },


}


def distance(lat, lon):
	lat1 = 38.752667
	lon1 = -9.184711
	lon, lat, lon1, lat1 = map(radians, [lon, lat, lon1, lat1]) # Degrees -> Radians
	dlon = lon - lon1
	dlat = lat - lat1
	a = sin(dlat/2)**2 + cos(lat1) * cos(lat) * sin(dlon/2)**2 # Haversine formula
	c = 2 * asin(sqrt(a))
	km = 6367 * c # Earth Ray = 6367 km
	cherrypy.response.headers["Content-Type"] = "application/json"
	return json.dumps({"distance": km}).encode("utf-8")

class Root():
	@cherrypy.expose
	def index(self):
		return open(os.path.join(baseDir, "html", "index.html")).read()

	# Clock

	@cherrypy.expose
	def clock(self):
		cherrypy.response.headers["Content-Type"] = "application/json"
		return time.strftime('{"date":"%d-%m-%Y", "time":"%H:%M:%S"}').encode("utf-8")
	# Distance
	@cherrypy.expose
	def distance(self, lat, lon):
		return distance(float(lat), float(lon))

	# UpLoad
#	@cherrypy.expose
#	def upload(self, myFile):
#		upload_dir = os.path.join(baseDir, "uploads")
#		fileout = open(os.path.join(upload_dir, myFile.filename), "wb")
#		while True:
#			data = myFile.file.read(8192)
#			hash_name = hashlib.sha256(data).hexdigest()
#			if not data: break
#			fileout.write(data)
#		fileout.close()

	@cherrypy.expose
	def upload(self, myFile):
		upload_dir = os.path.join(baseDir, "uploads")
		data = myFile.file.read()

		hash_name = hashlib.sha256(data).hexdigest()

		_, ext = os.path.splitext(myFile.filename)

		new_filename = hash_name + ext
		file_path = os.path.join(upload_dir, new_filename)

		with open(file_path, "wb") as fileout:
			fileout.write(data)
		

cherrypy.quickstart(Root(), "/", config)
