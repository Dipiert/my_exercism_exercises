import std.conv;

string convert(int num) {
    string result = "";
    if (!(num % 3)) result ~= "Pling";
    if (!(num % 5)) result ~= "Plang";    
    if (!(num % 7)) result ~= "Plong"; 
    return (!result.length)? to!string(num) : result;
}

unittest {
const int allTestsEnabled = 1;


    assert(convert(3) == "Pling");
static if (allTestsEnabled) {
    assert(convert(1) == "1");
    assert(convert(3) == "Pling");
    assert(convert(5) == "Plang");
    assert(convert(7) == "Plong");
    assert(convert(6) == "Pling");
    assert(convert(9) == "Pling");
    assert(convert(10) == "Plang");
    assert(convert(14) == "Plong");
    assert(convert(15) == "PlingPlang");
    assert(convert(21) == "PlingPlong");
    assert(convert(25) == "Plang");
    assert(convert(35) == "PlangPlong");
    assert(convert(49) == "Plong");
    assert(convert(52) == "52");
    assert(convert(105) == "PlingPlangPlong");
}

}

