from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeDoFicheiro = fname.split(".")[0]
    im.save(nomeDoFicheiro+".png")
    im.save(nomeDoFicheiro+".bmp")
    im.save(nomeDoFicheiro+".tiff")


main("Imagens-suporte/flor.jpg")

#jpg < png < tiff = bmp