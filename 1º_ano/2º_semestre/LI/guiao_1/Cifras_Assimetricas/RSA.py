from Cryptodome.PublicKey import RSA

# keypair = RSA.generate(2048)
# fout = open("keypair.pem", "wb")
# kp = keypair.exportKey("PEM", "senha")
# fout.write(kp)
# fout.close()

# fin = open("keypair.pem", "rb")
# keypair = RSA.importKey(fin.read(), "senha")

# fin.close()
# print(keypair)

def generate_key_pair(file_name, encryption_key, key_size):

    key = RSA.generate(key_size)

    # Write the private key to a file
    private_key = key.exportKey("PEM", encryption_key )
    with open(file_name + "_privada.pem", 'wb') as f:
        f.write(private_key)

    # Write the public key to a file
    public_key = key.publickey().exportKey()
    with open(file_name + "_publica.pem", 'wb') as f:
        f.write(public_key)


if __name__ == '__main__':
    file_name = input('Nome do ficheiro para salvar as chaves: ')
    encryption_key = input('Insira uma chave : ')
    key_size = int(input('Insira o tamanho da chave (em bits): '))
    generate_key_pair(file_name, encryption_key, key_size)