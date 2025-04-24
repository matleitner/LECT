function clock() {
    $.get("/clock",
        function(response){
            var text = "<h2>" + response.datep+"</h2><br><h2>"+response.time+"</h2>";
            $("#clock").html(text);
        });
}


$(document).ready(function() {
    $("#refresh_clock").on("click", clock)


});

