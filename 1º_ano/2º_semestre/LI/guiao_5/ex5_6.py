import cherrypy


class HTMLDocument():
    @cherrypy.expose
    def index(self):
        return open("documento.html","r", encoding="utf-8")
    


# este é o main badass, o html aparece se no url meter /html
class Root():
    def __init__(self):
       self.html = HTMLDocument()

    @cherrypy.expose
    def index(self):
        return "Eu sou o indice do Root (Root.index)"
    

    @cherrypy.expose
    def page(self):
        return "Eu sou um método do Root (Root.page)"
    


if __name__ == "__main__":
    cherrypy.quickstart(Root(), "/")