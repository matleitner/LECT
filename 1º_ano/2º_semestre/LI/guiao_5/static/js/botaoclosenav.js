
let expandido= true;

function toggleNav() {
    if(expandido){
        document.getElementById("menu").style.width = "200px";
        document.getElementById("main").style.marginLeft = "200px";
        document.getElementById("intro").style.marginLeft = "200px";
        document.getElementById("setinhamenu").innerHTML = "chevron_left";
        window.scrollTo({
            top: 0,
            behavior:'smooth' 
        })
        
    } else{
        document.getElementById("menu").style.width = "0";
        document.getElementById("main").style.marginLeft = "0";

        document.getElementById("intro").style.marginLeft = "";
        document.getElementById("setinhamenu").innerHTML = "chevron_right";
    }
    expandido = !expandido;
}

//

//
function alertar() {
    alert("Já se encontra nessa página")
}

  document.addEventListener("DOMContentLoaded", function() {
      const navButton = document.getElementById("navbutton");
      
      navButton.addEventListener("mouseover", function() {
          const elemento = document.getElementById("icon");
          elemento.innerHTML = "close"; 
        });
        navButton.addEventListener("mouseleave", function() {
            const elemento = document.getElementById("icon");
            elemento.innerHTML = "menu"; 
        });
    });
    // https://www.w3schools.com/howto/howto_css_searchbar.asp
function filterFunction() {
    var input, filter, a, i;
    input = document.getElementById("myInput");
    filter = input.value.toUpperCase();
    div = document.getElementById("searchbar");
    a = div.getElementsByTagName("a");
    for (i = 0; i < a.length; i++) {
        txtValue = a[i].textContent || a[i].innerText;
    if (txtValue.toUpperCase().indexOf(filter) > -1) {
    a[i].style.display = "";
    } else {
        a[i].style.display = "none";
    }
}
}

function scrollcima() {
    window.scrollTo({
        top: 0,
        behavior: 'smooth' 
    });
}


// ^pop up 
function abrir_ajuda() {
    document.getElementById("popup").style.display = "block";
}
function fechar_ajuda() {
    document.getElementById("popup").style.display = "none";
}