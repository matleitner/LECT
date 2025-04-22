import requests


address = "Universidade de Aveiro, 3810-193 Aveiro, Portugal"
servurl = f"https://nominatim.openstreetmap.org/search.php?format=json&q={address}"

headers = {
    'User-Agent': 'MyGeocodingApp/1.0 (contact@example.com)'
}

r = requests.get(servurl, headers=headers)

if r.status_code == 200:
    data = r.json()
    if data:
        first_result = data[0]
        print(f"Coordenadas: Latitude = {first_result['lat']}, Longitude = {first_result['lon']}")
    else:
        print("Endereço não encontrado.")
else:
    print(f"Erro {r.status_code}: {r.text}")