from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    f = float(input("Insira o fator: "))
    new_im = effect_intensity(im, f)
    new_im.save(nomeFIcheiro+"-YCbCr-7-14.jpg")


def effect_intensity(im:Image, f:float) -> Image:
    new_im = im.convert("YCbCr")
    width, height = im.size
    
    for x in range(width):
        for y in range(height):
            p = new_im.getpixel( (x,y) )
            
            py = p[0]
            pb = min( 255, int((p[1] -128)* f+128))
            pr = min( 255, int((p[2] -128)* f+128))
            new_im.putpixel( (x,y), ( py , pb , pr ))
    return new_im;

main("Imagens-suporte/flor.jpg")