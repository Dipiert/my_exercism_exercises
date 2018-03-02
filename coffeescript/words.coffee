module.exports = class Words
  constructor: (phrase) ->
    @words = []
    for word in phrase.split(" ")
      @words.push(word.replace(/\W/gi, '').toLowerCase())
  count: () -> 
    word_count = {}
    for word in @words
      if(word)
        word_count[word] = word_count[word] + 1 || 1
    return word_count

