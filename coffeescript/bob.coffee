module.exports = class Bob
  hey: (s) ->
    s = s.trim()
    return switch
      when (s.length == 0) then "Fine. Be that way!"
      when (s.match(/[a-z]/i) && s.toUpperCase() == s) then "Whoa, chill out!"
      when (s.endsWith('?')) then "Sure."
      else "Whatever."

