import cherrypy
import psutil
class Node():
    @cherrypy.expose
    def index(self):
        return "Eu sou o indice do Node (Node.index)"

    @cherrypy.expose
    def page(self):
        return "Eu sou um método do Node (Node.page)"
    


class Root():
    def __init__(self):
        self.node = Node()

    @cherrypy.expose
    def index(self):
        pcinfo = psutil.cpu_freq()
        return "Eu sou o indice do Root (Root.index)"
    

    @cherrypy.expose
    def page(self):
        return "Eu sou um método do Root (Root.page)"



if __name__ == "__main__":
    cherrypy.quickstart(Root(), "/")