import json
def main():
    data = [
        {"time": 1394984189, "name": "cpu", "value": 12},
        {"time": 1394984190, "name": "cpu", "value": 19},
        {"time": 1394984112, "name": "cpu", "value": 10},
        {"time": 1394984543, "name": "cpu", "value": 11},
        {"time": 1394984333, "name": "cpu", "value": 12}
        ]
    print(json.dumps(data, indent=4))
main()
