from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    width, height = im.size
    new_im = Image.new(im.mode, im.size)
    for x in range(width):
        for y in range(height):
            p = im.getpixel( (x,y) )
            r = 255 - p[0]
            g = 255 - p[1]
            b = 255 - p[2]
            new_im.putpixel((x,y), (r, g, b) )
    new_im.save(nomeFIcheiro+"-negativa.jpg")


main("Imagens-suporte/flor.jpg")