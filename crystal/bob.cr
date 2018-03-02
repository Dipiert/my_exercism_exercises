class Bob
  def self.hey(phrase : String) : String
    return "Fine. Be that way!" if (phrase.blank?)
    return "Whoa, chill out!" if (phrase == phrase.upcase && phrase.upcase.count("A-Z") > 0)
    return "Sure." if (phrase.ends_with?('?'))
    return "Whatever."
  end
end

