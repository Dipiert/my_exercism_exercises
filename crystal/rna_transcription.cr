class RnaComplement
  def self.of_dna(strand : String) : String
    return strand.tr("GCTA", "CGAU")
  end
end

