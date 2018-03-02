-module(collatz_conjecture).

-export([steps/1, test_version/0]).

steps(N) ->
case (N =< 0) of
    true -> {error, "Only positive numbers are allowed"};
    false -> steps(N, 0)
end.

steps(N, Count) when N == 1 -> Count;
steps(N, Count) -> 
case (N rem 2) of
    0 -> steps(N div 2, Count + 1);
    1 -> steps(N * 3 + 1, Count + 1)
end.

test_version() -> 2.

