import os
import cherrypy
PATH = os.path.abspath(os.path.dirname(__file__))
conf = {
    "/css": {
        "tools.staticdir.on": True,
        "tools.staticdir.dir": os.path.join(PATH, "static", "css")
    },
    "/js": {
        "tools.staticdir.on": True,
        "tools.staticdir.dir": os.path.join(PATH, "static", "js")
    },
    "/imagens": {
        "tools.staticdir.on": True,
        "tools.staticdir.dir": os.path.join(PATH, "static", "imagens")
    },
    "/static":{
        "tools.staticdir.on": True,
        "tools.staticdir.dir": os.path.join(PATH, "static",)
    }


}


class Root():
    @cherrypy.expose
    def index(self):
        return open("static/index.html")

cherrypy.quickstart(Root(), "/", config=conf)