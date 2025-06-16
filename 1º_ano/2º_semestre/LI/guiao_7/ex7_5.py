from PIL import Image

def main(fname):
    im = Image.open(fname)
    nomeDoFicheiro = fname.split(".")[0]

    for i in [1, 10, 50, 90, 100]:
        im.save(nomeDoFicheiro +"test-%i.jpg" % i, quality = i)

main("Imagens-suporte/southpark.png")