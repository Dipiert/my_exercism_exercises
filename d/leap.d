bool is_leap(int year) {
     return !(year % 4) && (year % 100) || !(year % 400);
}

unittest {
  assert(!is_leap(2015));
  assert(is_leap(2016));
  assert(!is_leap(2100));
  assert(is_leap(2000));
}

