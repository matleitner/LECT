$(document).ready(
	function(){
		imageslist("all");
    });

function imageslist(id) {
	var author;
	if (id == "all") author = "all";
	else {
			author = $("#authorImg").val();
			if (author == "") author = "all";
	}
	$.get("/list",
		{ id : author },
		function(response){
			showimages(response);
		});
}

function showimages(response) {
	// response.images is the list of dictionaries with the images information
	$("#showimages").html("");
	for (let i = 0; i < response.images.length; i++) {
		// html code for print the image information
		// html code for showing the image and allow to click on it and invoke function showimagecomments
	}
}

function showimagecomments(id) {
	window.open("../html/image.html?id=" + id, '_blank');
}
