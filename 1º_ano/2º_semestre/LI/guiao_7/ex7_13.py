from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    g = float(input("Insira o fator gamma: "))
    new_im = effect_intensity(im, g)
    new_im.save(nomeFIcheiro+"-YCbCr-7-13.jpg")


def effect_intensity(im:Image, g:float) -> Image:
    new_im = im.convert("YCbCr")
    width, height = im.size
    
    for x in range(width):
        for y in range(height):
            pixel = new_im.getpixel( (x,y) )
            f = 255/(255**g)
            py = min(255, max(0, int((pixel[0]**g) * f)) ) 
            new_im.putpixel( (x,y), ( py , pixel[1], pixel[2] ))
    return new_im;

main("Imagens-suporte/flor.jpg")