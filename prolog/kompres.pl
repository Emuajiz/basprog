kompres([H], Bef, _, Jadi) :-
    \+ H = Bef, Bef = [],
    Jadi = [[H, 1]].

kompres([H], Bef, Count, Jadi) :-
    \+ H = Bef, \+ Bef = [],
    Jadi = [[Bef, Count],[H, 1]].

kompres([H], Bef, Count, Jadi) :-
    H = Bef,
    Tmp is Count + 1,
    Jadi = [[Bef, Tmp]].

kompres([H|T], Bef, Count, Jadi) :-
    \+ H = Bef, \+ Bef = [],
    kompres(T, H, 1, Tmp),
    Jadi = [[Bef, Count]| Tmp].

kompres([H|T], Bef, _, Jadi) :-
    \+ H = Bef, Bef = [],
    kompres(T, H, 1, Jadi).

kompres([H|T], Bef, Count, Jadi) :-
    H = Bef,
    Tmp is Count + 1,
    kompres(T, H, Tmp, Jadi).

program :- read(A), kompres(A, [], 1, List), write(List), nl.
:- program.