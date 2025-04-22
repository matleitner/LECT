import cherrypy;
import requests

class Root():
    @cherrypy.expose
    def index(self):
        return "Olá isto é a página inicial!"
    @cherrypy.expose
    def form(self):
        cherrypy.response.headers["Content-Type"]= "text/html"
        return open("formulario.html").read()
    def __init__(self):
        self.actions = Actions();

class Actions():

    @cherrypy.expose
    def doLogin(self, username =None, password=None):
        if (username  and password):
            
            return "Verificar as credenciais do utilizador " + username +"\nAcesso Concedido"
        
        else:
            return "Verificar as credenciais do utilizador " + username +"\nAcesso Negado"
    
    


if __name__ == "__main__":
    cherrypy.quickstart(Root(), "/")