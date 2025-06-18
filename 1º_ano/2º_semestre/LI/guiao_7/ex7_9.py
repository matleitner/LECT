from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeFIcheiro = fname.split(".")[0]
    width, height = im.size
    new_im = Image.new(im.mode, im.size)
    for x in range(width):
        for y in range(height):
            p = im.getpixel( (x,y) )
            r = p[1]
            g = p[0]
            b = p[2]
            new_im.putpixel((x,y), (r, g, b) )
    new_im.save(nomeFIcheiro+"-cor-Trocada.jpg")


main("Imagens-suporte/flor.jpg")