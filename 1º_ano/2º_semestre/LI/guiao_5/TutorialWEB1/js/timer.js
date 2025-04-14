function decreaseImage(element){
	var height = parseInt(element.style.height) - 10 ;
	element.style.height = height+"px";
	
	if(height > 0) setTimeout("decreaseImage("+element.id+")",10);
}

function resetImage(element){
	element.style.display = "block";
	element.style.height = "450px";
	element.style.width ="550px";
}
