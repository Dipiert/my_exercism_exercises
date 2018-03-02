module Bob exposing (..)

import Regex

hey: String -> String
hey msg = 
    if (containsLetters msg) && (isUpperCase msg) then
        "Whoa, chill out!"
    else if (isAQuestion msg) then
        "Sure."
    else if (isSilence msg) then
        "Fine. Be that way!"
    else
        "Whatever."

isUpperCase: String -> Bool
isUpperCase string = String.toUpper string == string

isAQuestion: String -> Bool
isAQuestion = String.endsWith "?"

containsLetters: String -> Bool
containsLetters = Regex.contains(Regex.regex "[a-zA-Z]")

isSilence: String -> Bool
isSilence = Regex.contains(Regex.regex "^\\s*$")
