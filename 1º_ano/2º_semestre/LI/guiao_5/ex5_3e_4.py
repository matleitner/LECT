import cherrypy
class HelloWorld():
    @cherrypy.expose
    def index(self):
        host = cherrypy.request.headers["Host"]
        return "You have successfully reached " + host 
    

cherrypy.quickstart(HelloWorld())
