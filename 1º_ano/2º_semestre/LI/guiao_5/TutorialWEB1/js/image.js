function updatePhoto(event) {
    var reader = new FileReader();
    reader.onload = function(event) {
        // Create an image
        var img = new Image();
        img.onload = function() {
            // Show the image on the screen
            const canvas = document.getElementById("photo");
            // Using jQuery it is const canvas = $("#photo")[0];
            const ctx = canvas.getContext("2d");
            ctx.drawImage(img,0,0,img.width,img.height,0,0,530,400);
        }
        img.src = event.target.result;
    }


    // Get the file
    reader.readAsDataURL(event.target.files[0]);
    sendFile(event.target.files[0]);
    
    // Free image resources
    windowURL.revokeObjectURL(picURL);
    
}
function sendFile(file) {
    var data = new FormData();
    data.append("myFile", file);
    var xhr = new XMLHttpRequest();
    xhr.open("POST", "/upload");
    xhr.upload.addEventListener("progress", updateProgress, false);
    xhr.send(data);
}


function updateProgress(evt){
    if(evt.loaded == evt.total) alert("Okay");
}