ambil([A|_], 1, A).
ambil([_|T], K, C) :-
    Tmp is K - 1,
    ambil(T, Tmp, C).

program :- read(A), read(B), ambil(A,B,C), write(C), nl.
:- program.