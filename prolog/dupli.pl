duplicate([_,0],[]).
duplicate([H|T], Jadi) :-
    Tmp2 is T-1,
    duplicate([H,Tmp2], Tmp),
    append([H], Tmp, Jadi).

urai([],_,[]).
urai([H|T], B, List) :-
    duplicate([H,B], Jadi1), urai(T, B, Jadi2),
    append(Jadi1, Jadi2, List).


program :- read(A), read(B), urai(A, B, List), write(List), nl.
:- program.