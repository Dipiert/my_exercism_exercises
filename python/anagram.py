from collections import Counter

def detect_anagrams(word, candidates):
	anagrams = []
	dict_word = count_letters(word)
	candidates = remove_own_anagrams(word, remove_duplicates(candidates))
	for candidate in candidates:
		if (dict_word == count_letters(candidate)):
			anagrams.append(candidate)
	return anagrams

def remove_own_anagrams(word, candidates):
	_candidates = [candidate.lower() for candidate in candidates]
	_word = word.lower()
	for i in range(0, len(_candidates)):
		if (_word == _candidates[i]):
			candidates.remove(candidates[i])
	return candidates

def remove_duplicates(candidates):
	_candidates = [candidate.lower() for candidate in candidates]
	results = []
	is_new = True
	for i in range(0, len(_candidates)):
		for result in results:
			if result.lower() == _candidates[i]:
				is_new = False
		if is_new:
			results.append(candidates[i])
		is_new = True
	return results

def count_letters(word):
	return Counter(l for l in word.lower() if l.isalpha())

