import re;

def word_count(phrase):
    result = {}
    phrase = re.sub('[\s+_,]', ' ', phrase.lower())
    words = re.sub('[^a-z0-9\s]', '', phrase).split()
    for word in range(0,len(words)):
       count = len(re.findall("\\b" + re.escape(words[word]) + "\\b", phrase))
       result[words[word]] = count;
    return result

