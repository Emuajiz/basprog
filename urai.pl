duplicate([_,0],[]).
duplicate([H|T], Jadi) :-
    Tmp2 is T-1,
    duplicate([H,Tmp2], Tmp),
    append([H], Tmp, Jadi).

urai([A],[A]) :-
    atomic(A).

urai([A], B) :- 
    is_list(A),
    duplicate(A, Tmp),
    append([], Tmp, B).

urai([H|T], Jadi) :-
    is_list(H),
    duplicate(H, Tmp2),
    urai(T, Tmp),
    append(Tmp2, Tmp, Jadi).

urai([H|T], Jadi) :-
    atomic(H),
    urai(T, Tmp),
    Jadi = [H|Tmp].

program :- read(A), urai(A, List), write(List), nl.
:- program.