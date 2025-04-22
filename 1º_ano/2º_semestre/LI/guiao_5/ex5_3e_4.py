import cherrypy
class HelloWorld():
    @cherrypy.expose
    def index(self):
        #return "Hello World!"
        host = cherrypy.request.headers["Host"]
        return "You have successfully reached " + host 
    

cherrypy.quickstart(HelloWorld())
