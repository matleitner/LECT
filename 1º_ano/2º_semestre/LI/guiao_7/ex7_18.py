from PIL import Image

def main(principal:str, marcadeagua:str):
    img_Principal = Image.open(principal)
    img_marcaDeAgua = Image.open(marcadeagua)
    f = float(input("Insira um fator de transparência: ")) # 0.8
    
    im = marca_de_agua(img_Principal, img_marcaDeAgua, min(1,max(f,0)))
    im.save("Imagens-suporte/ua-marca-de-agua-ex-7-18.jpg")


def marca_de_agua(principal:Image, agua:Image, f:int):
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
            r = int(p1[0]*(1-f)+p2[0]*f)
            g = int(p1[1]*(1-f)+p2[1]*f)
            b = int(p1[2]*(1-f)+p2[2]*f)
            principal.putpixel((x+start_x, y+start_y),(r,g,b))
    return principal;




main("Imagens-suporte/ua.jpg", "Imagens-suporte/ua-logo.png")