class Hamming
  def self.compute(strand1 : String, strand2 : String) : Number
    if (strand1.size != strand2.size)
      raise ArgumentError.new
    end
    count = 0
    index = 0
    loop do
      if (strand1[index] != strand2[index])
        count += 1
      end
      index += 1
      break unless index < strand1.size
    end
    return count
  end
end

