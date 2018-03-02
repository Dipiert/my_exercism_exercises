def slices(series, length):
    result = []
    if not length or length > len(series):
        raise ValueError("Substring length can't be longest than string length")    
    for i in range(len(series) - length + 1):
        result.append([int(j) for j in list((series[i:i + length]))])
    return result

