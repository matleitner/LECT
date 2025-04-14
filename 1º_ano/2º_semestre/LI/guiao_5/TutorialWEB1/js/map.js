var latitude = 40.633258
var longitude = -8.659097

var map = new L.Map("myMap", {center: [latitude,longitude],zoom: 15});

var osmUrl="http://{s}.tile.openstreetmap.org/{z}/{x}/{y}.png";
var osmAttrib="Map data  OpenStreetMap contributors";
var osm = new L.TileLayer(osmUrl, {attribution: osmAttrib});

map.addLayer(osm);

map.on("click", showCoordinates);

function showCoordinates(e){
  var s = document.getElementById("coordinates");
  s.innerHTML = "Latitude, Longitude = "+e.latlng.lat+", "+e.latlng.lng;
}

var iconeUA = L.icon({ iconUrl: "../images/ua.png" });
L.marker([40.633258, -8.659097], {icon: iconeUA}).bindPopup("LABI@DETI").addTo(map);
