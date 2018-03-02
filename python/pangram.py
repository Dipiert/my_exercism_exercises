def is_pangram(sentence):
    letters = set()
    sentence = sentence.lower()
    for char in sentence:
      if (char.isalpha()):
         letters.add(char)
    return len(letters) == 26

