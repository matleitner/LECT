from PIL import Image

def main(principal:str, marcadeagua:str):
    img_Principal = Image.open(principal)
    img_marcaDeAgua = Image.open(marcadeagua).convert("RGBA")



    im = marca_de_agua(img_Principal, img_marcaDeAgua)
    im.save("Imagens-suporte/ua-marca-de-agua-impersetivel-ex-7-19.jpg")


    img_A_Recuperar = Image.open("Imagens-suporte/ua-marca-de-agua-impersetivel-ex-7-19.jpg")
    
    recuperada = recuperar_marcaDeAgua(img_A_Recuperar, img_marcaDeAgua)
    recuperada.save("Imagens-suporte/ua-marca-de-agua-recuperada-ex-7-19.jpg")


def marca_de_agua(principal:Image, agua:Image):
    width, height = agua.size 

    largura, altura = principal.size
    start_x , start_y = int(largura/4), int(altura/3)

    for x in range(width):
        for y in range(height):
            #p1 é um pixel da imagem original
            #p2 é um pixel da marca de água
            p1 = principal.getpixel( (x+start_x, y+start_y) )
            p2 = agua.getpixel( (x,y) )
            if(p2[3] == 0):
                continue
            r = (p1[0] & 0b11111110) | (p2[0]>>7)
            g = (p1[1] & 0b11111110) | (p2[1]>>7)
            b = (p1[2] & 0b11111110) | (p2[2]>>7)
            principal.putpixel((x+start_x, y+start_y),(r,g,b))
    return principal;


def recuperar_marcaDeAgua(principal:Image, agua:Image):

    width, height = agua.size 

    largura, altura = principal.size
    start_x , start_y = int(largura/4), int(altura/3)
    marca = Image.new("RGB", (width, height))

    for x in range(largura):
        for y in range(altura):
            #p1 é um pixel da imagem original
            #p2 é um pixel da marca de água
            p1 = principal.getpixel( (x+start_x, y+start_y) )
            p2 = agua.getpixel( (x,y) )
            
            r = ((p2[0]) << 7) 
            g = ((p2[1]) << 7) 
            b = ((p2[2]) << 7) 
            marca.putpixel((x+start_x, y+start_y),(r,g,b))
    return marca;



main("Imagens-suporte/ua.jpg", "Imagens-suporte/ua-logo.png")