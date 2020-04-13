tera([A], A).
tera([_|T], L) :-
    tera(T, L).

program :- read(A), tera(A, Last), write(Last), nl.
:- program.