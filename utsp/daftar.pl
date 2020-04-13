createlist(_, End, _, Pos, []) :-
    Pos > End, !.

createlist(Start, End, Inc, Pos,X) :-
    Pos < Start,
    Tmp is Pos+Inc,
    createlist(Start, End, Inc, Tmp, X)    .

createlist(Start, End, Inc, Pos, [Pos|X1]) :-
    \+ Pos > End,
    Tmp1 is Pos+Inc,
    createlist(Start, End, Inc, Tmp1, X1).

program :- read(Start), read(End), read(Inc), createlist(Start,End,Inc, Inc,X), write(X), nl.

% kalau awal nya lebih 