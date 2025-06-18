from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    im_Sepia = effect_Sepia(im)
    im_Sepia.save(nomeFIcheiro+"-sepia.jpg")
    im_Lomo = effect_lomo(im)
    im_Lomo.save(nomeFIcheiro+"-lomo.jpg")


def effect_Sepia(im:Image) -> Image:
    width, height = im.size
    for x in range(width):
        for y in range(height):
            R, G, B = im.getpixel( (x,y) )
            r = int( 0.189*R + 0.769*G + 0.393*B)
            g = int ( 0.168*R + 0.686*G + 0.349*B)

            b = int( 0.131*R + 0.534*G + 0.272*B)
            im.putpixel( (x,y), (r,g,b) )
    return im

def effect_lomo(im:Image) -> Image:
    width, height = im.size
    for x in range(width):
        for y in range(height):
            R, G, B = im.getpixel( (x,y) )
            r = int(0.131*R + 0.534*G + 0.272*B)
            g = int(0.168*R + 0.686*G + 0.349*B)

            b = int( 0.189*R + 0.769*G + 0.393*B)
            im.putpixel( (x,y), (r,g,b) )
    return im

main("Imagens-suporte/flor.jpg")