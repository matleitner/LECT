from PIL import Image

def main(fname):
    im = Image.open(fname)
    print(im.mode)


main("Imagens-suporte/flor.jpg")
main("Imagens-suporte/vasos.jpg")
main("Imagens-suporte/ua-logo.png")