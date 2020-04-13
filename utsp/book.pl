judul([book(_,Judul,_,_)],[Judul]).
judul([book(_,Judul,_,_)|T], X) :-
    judul(T,X1),
    X = [Judul,X1].

% judul(A, Judul) :- A = book(_,Judul,_,_).

program :- read(A), judul(A,X), write(X), nl.
