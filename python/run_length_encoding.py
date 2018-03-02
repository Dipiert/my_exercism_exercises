import re

def decode(input):
    return re.sub(r'(\d+)(\D)', lambda x: x.group(2) * int(x.group(1)), input)

def encode(string):
    result = ''
    matches = re.findall('(([a-zA-Z\s])\\2*)', string)
    for match in matches:
        result += concatenate_result(len(match[0]), match[1])
    return result

def concatenate_result(count, prev):
    if count <= 1:
        return prev
    else:
        return str(count) + prev

