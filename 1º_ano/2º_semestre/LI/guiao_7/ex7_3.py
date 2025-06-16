from PIL import Image


def main(fname):
    im = Image.open(fname)
    width, height = im.size
    nomeDoFicheiro = fname.split(".")[0]


    dimension = (int(width *0.5), int(height*0.5)) # e brincar com isto
    new_im = im.resize(dimension, Image.BICUBIC) # trocar BILINEAR para BICUBIC

    new_im.save(nomeDoFicheiro+"-bicubic.jpg" )



main("Imagens-suporte/ua.jpg")