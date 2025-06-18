from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    f = float( input("Insira um fator: "))
    new_im = effect_intensity(im, f)
    new_im.save(nomeFIcheiro+"-YCbCr-7-12.jpg")


def effect_intensity(im:Image, f:float) -> Image:
    new_im = im.convert("YCbCr")
    width, height = im.size
    
    for x in range(width):
        for y in range(height):
            pixel = new_im.getpixel( (x,y) )
            py = min(255, int(pixel[0] * f) ) 
            new_im.putpixel( (x,y), ( py , pixel[1], pixel[2] ))
    return new_im;

main("Imagens-suporte/flor.jpg")