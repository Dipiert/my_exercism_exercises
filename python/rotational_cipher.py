from string import ascii_letters 

def rotate(text, key):
    result = ''
    for letter in text: 
        letter_code = ord(letter)
        if (letter in ascii_letters):
            boundary = ord('z') if letter.islower() else ord('Z')
            letter_code += key % 26
            if (letter_code > boundary):
                letter_code -= 26
        result += chr(letter_code)
    return result

