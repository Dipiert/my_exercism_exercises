import re

def hey(string):
    stripped = string.strip()
    if not stripped: return 'Fine. Be that way!'
    elif stripped.isupper(): return 'Whoa, chill out!'
    elif stripped.endswith('?'): return 'Sure.'
    return 'Whatever.'

