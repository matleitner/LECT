import json 
with open("pcStats.json", "r",encoding="utf-8") as file:
    data = json.load(file)
print(json.dumps(data, indent=4))