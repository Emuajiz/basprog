judul([book(_,Judul,_,_)],[Judul]).
judul([book(_,Judul,_,_)|T], X) :-
    judul(T,X1),
    append([Judul], X1, X).

program :- read(A), judul(A,X), write(X), nl.

?- program.