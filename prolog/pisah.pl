% last(A, 0, [A]).
% last([H|T], C, X) :-
%     Tmp is C - 1, pisah(T, Tmp, Tmp2), append([[H]], Tmp2, X).

first(A,0,[],A).
first([H|T], C, X, Y) :-
    Tmp is C-1, first(T, Tmp, Tmp2, Y), append([H], Tmp2, X).

program :- read(A), read(B), first(A, B, Jadi1, Jadi2),write([Jadi1, Jadi2]), nl.
:- program.