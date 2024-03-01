def shift_char(c, kshift):
    if 65 <= ord(c) <= 90:
        c = chr((ord(c) - 65 + kshift) % 26 + 65)
        return c
    elif 97 <= ord(c) <= 122:
        c = chr((ord(c) - 97 + kshift) % 26 + 97)
        return c
    return c

def encrypt_vigenere(plaintext, keyword):
    ciphertext = ''
    n = 0

    for char in plaintext:
        if not char.isalpha():
            ciphertext += shift_char(char, 0)
        else:
            kshift = ord(keyword[n].lower()) - 97
            ciphertext += shift_char(char, kshift)
            n = (n + 1) % len(keyword)

    return ciphertext

def main():
    plaintext = input("Enter plaintext: ")
    keyword = input("Enter keyword: ")

    ciphertext = encrypt_vigenere(plaintext, keyword)
    print("Ciphertext:", ciphertext)

if __name__ == "__main__":
    main()
