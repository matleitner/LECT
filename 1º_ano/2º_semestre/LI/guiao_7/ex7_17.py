import math
from PIL import Image

def effectVignette(im:Image) -> Image:
    YCbCr_im = im.convert("YCbCr")
    width, height = YCbCr_im.size
    centro_x , centro_y = width/2, height/2
    for x in range(width):
        for y in range (height):
            Y, Cb , Cr = YCbCr_im.getpixel((x,y))
            Y *= get_factor(centro_x,centro_y,x,y)
            YCbCr_im.putpixel((x,y),((min(255,max(0,int(Y)))),Cb,Cr)) 

    return YCbCr_im

def get_factor(x, y, xref, yref):
    distance = math.sqrt( pow(x-xref,2) + pow(y-yref,2))
    if ( xref + yref )== 0:
        return 0
        
    else:
        distance_to_edge = math.sqrt( pow(xref,2) + pow(yref,2))
        return 1-(distance/distance_to_edge)



def main(fname:str):
    im = Image.open(fname)
    NomeDoFicheiro = fname.split(".")[0]
    imagemVignette = effectVignette(im)
    imagemVignette.save(NomeDoFicheiro+"-effeito-vinheta-7-17.jpg")


main("Imagens-suporte/flor.jpg")