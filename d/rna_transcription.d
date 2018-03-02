module rna_transcription;
import std.string: tr;
import std.regex;

string dnaComplement(string nucleotide) {
    if (matchAll(nucleotide, "[^CGTA]"))
        throw new Exception("Input contain Invalid nucleotides");   
    return nucleotide.tr("CGTA", "GCAU");
}

unittest {
import std.exception : assertThrown;

const int allTestsEnabled = 1;

    assert(dnaComplement("C") == "G");

static if (allTestsEnabled) {
    assert(dnaComplement("G") == "C");
    assert(dnaComplement("T") == "A");
    assert(dnaComplement("A") == "U");
    assert(dnaComplement("ACGTGGTCTTAA") == "UGCACCAGAAUU");
    assertThrown(dnaComplement("U"));
    assertThrown(dnaComplement("XXX"));
    assertThrown(dnaComplement("ACGTXXXCTTAA"));
}

}

