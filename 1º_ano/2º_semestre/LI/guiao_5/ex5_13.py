import os
import cherrypy
PATH = os.path.abspath(os.path.dirname(__file__))
conf = {
"/static": {
"tools.staticdir.on": True,
"tools.staticdir.dir": os.path.join(PATH, "static"),
'tools.staticdir.content_types': {
            'css': 'text/css',
            'js': 'application/javascript',
            'html': 'text/html'
        }
},
'/': {
        'tools.staticfile.on': True,
        'tools.staticfile.filename': os.path.join(os.path.join(PATH, 'static'), 'index.html'),
        
    }
}
class Root():
    @cherrypy.expose
    def index():
        return 
    

cherrypy.quickstart(Root(), "/", config=conf)