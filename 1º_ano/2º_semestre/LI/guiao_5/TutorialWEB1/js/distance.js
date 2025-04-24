function distance(position){
    $.get("/distance",
            { lat: position.coords.latitude, lon: position.coords.longitude },
            function(response){
                var text="<h2> Benfica Stadium at "+response.distance+" km</h2>";
                $("#distance").html(text);
            });
}

function refresh(){
    navigator.geolocation.getCurrentPosition(distance);
}

$(document).ready(function() {
    $("#refresh_dist").on("click", refresh);
    });