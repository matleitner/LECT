from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    new_im = effect_gray(im)
    new_im.save(nomeFIcheiro+"-L-7-11.jpg")

def effect_gray(im :Image) -> Image:
    width, height = im.size
    new_im = Image.new("L", im.size)

    for x in range(width):
        for y in range(height):
            p = im.getpixel(( x, y ))
            l = int(p[0] + p[1] + p[2])
            new_im.putpixel( (x,y) , (l) )
    return new_im

main("Imagens-suporte/flor.jpg")

