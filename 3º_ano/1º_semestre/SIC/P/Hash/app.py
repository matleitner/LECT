import hashlib 
def tetnativa1():
    hash_str: str = ""
    num: int = 1
    objeto = hashlib.sha256()
    while (hash_str[:3] != "000"):
        mensagem = str(num).encode("utf-8")
        hash_str = hashlib.sha256(mensagem).hexdigest()
        if not hash_str.startswith("000"):
            num += 1
    
    print(num)
    print(hash_str)

def tentativa2():
    import hashlib

student_number = "20261234"
nonce = 0
target_prefix = "000"

while True:
    # 1. Create the sentence template combining the student number and the nonce
    sentence = f"My student number is {student_number} and this is attempt #{nonce}."
    
    # 2. Calculate the SHA-256 hash of the sentence (must encode to bytes)
    hash_bytes = hashlib.sha256(sentence.encode('utf-8')).digest()
    hash_hex = hash_bytes.hex()
    
    # 3. Check if it meets our target condition
    if hash_hex.startswith(target_prefix):
        print("Success! Found a matching sentence:")
        print(f"Sentence: {sentence}")
        print(f"SHA-256:  {hash_hex}")
        break
        
    nonce += 1

tentativa2()
