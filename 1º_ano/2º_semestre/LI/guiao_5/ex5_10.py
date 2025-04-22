import requests

url ="http://localhost:8080/actions/doLogin"

values = {"username": "Marty", "password":"LoL"}

r = requests.post(url, data =values)
print(r.status_code)
print(r.text)

