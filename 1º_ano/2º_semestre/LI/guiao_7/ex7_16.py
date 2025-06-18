from PIL import Image

def is_edge(im, x,y, diff, bw):
    #Obter o pixel
    p = im.getpixel( (x , y) )
    width, height = im.size
    if x < width-1 and y < height-1 and x > 0 and y > 0:
    #Vizinhos acima e abaixo
        for vx in range(-1,1):
            for vy in [-1, 1]:
                px = im.getpixel( (x + vx, y + vy) )
                if abs(p[0]- px[0]) > diff:
                    return (0,128,128)
    #Vizinhos da esquerda e direita
        for vx in [-1, 1]:
            px = im.getpixel( (x + vx, y) )
            if abs(p[0]- px[0]) > diff:
                return (0,128,128)
    if bw :
        return (255,128,128)
    else:
        return p

    
def main(fname):
    im = Image.open(fname).convert("YCbCr")
    nomeFIcheiro = fname.split(".")[0]
    width, height = im.size 
    for x in range(width):
        for y in range(height):
            im.putpixel((x,y), is_edge(im, x,y,100,1)) #diff no 100 costuma funcionar bem, pelo menos com a flor.
    im.save(nomeFIcheiro+"-bordas-7-16.jpg")


main("Imagens-suporte/flor.jpg")