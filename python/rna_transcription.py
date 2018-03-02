from string import maketrans 
import re

def to_rna(s):
    return '' if re.search('[^ACGT]', s) else s.translate(maketrans('GCTA','CGAU'))

