putar(LL,0,FL,X) :-
    append(LL,FL, X).

putar([H|T], Count, FL, X) :-
    append(FL, [H], TFL),
    TC is Count - 1,
    putar(T, TC, TFL, X).

program :- read(A), read(B), putar(A,B,[],X), write(X), nl.