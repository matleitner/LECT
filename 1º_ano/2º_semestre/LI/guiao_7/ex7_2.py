from PIL import Image;


def main(fname):
    im = Image.open(fname)
    nomeDoFicheiro = fname.split(".")[0]
    width, height = im.size
    for s in [0.2, 8]:
        dimension = (int(width *s), int(height*s))
        new_im = im.resize( dimension, Image.NEAREST)
        new_im.save(nomeDoFicheiro+"-%.2f.jpg" % s)


main("Imagens-suporte/vasos.jpg")