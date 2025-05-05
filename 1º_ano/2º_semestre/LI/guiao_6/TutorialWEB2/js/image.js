var id;

$(document).ready(
    function(){
        const params = new URLSearchParams(window.location.search);
        id = params.get("id");
        imagecomments ();
    });      

function imagecomments() {
	$.get("/comments",
		{ idimg : id },
		function(response){
			showimageandinfo(response);
		});
}

function showimageandinfo(response) {
	// response.image is the image information
	// response.comments is the image list comments
	// response.votes is the image votes
}

function newcomment() {
	// obtain the user and comment from image page
	var user = ""
	var comment = ""
	
	if (user == "" || comment == "") alert("Missing comment and/or username!");
	else {
		$.post("/newcomment",
			{ idimag: id, username: user, newcomment: comment },
			function() { imagecomments(); });
	}
}

function upvote() {
	$.post("/upvote",
		{ idimag: id },
		function(response)
		{
			// update thumbs_up and thumbs_down
		});
}

function downvote() {
	$.post("/downvote",
		{ idimag: id },
		function(response)
		{
			// update thumbs_up and thumbs_down	
		});
}
