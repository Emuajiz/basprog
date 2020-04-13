kucing(pusi).
kucing(mesi).
kucing(sansi).
kucing(tom).
kucing(dasi).
kucing(rasi).
kucing(nasi).

tikus(jerry).
tikus(bery).
tikus(tery).
tikus(carry).

% kelompok([], K, T, [K,T]).

% kelompok([H|T], K, T, X) :-
%     tikus(H), !,
%     kelompok(T, K, [H|T], X).

% kelompok([H|T], K, T, X) :-
%     kucing(H),
%     kelompok(T, [H|K], T, X).

% kelompok(A,Hasil) :-
%     kelompok(A,[],[],Hasil).

kelompokt([H|T],X) :-
    kucing(H),
    kelompokt(T,X).

kelompokt([],[]).

kelompokt([H|T], X) :-
    tikus(H),
    kelompokt(T,X1),
    X = [H|X1].

kelompok([H|T],X) :-
    tikus(H),
    kelompok(T,X).

kelompok([],[]).

kelompok([H|T], X) :-
    kucing(H),
    kelompok(T,X1),
    X = [H|X1].


program :- read(A), kelompok(A, Hasil), kelompokt(A, Hasil1), write([Hasil,Hasil1]), nl.
program :- read(A), kucing(A), write(1), nl.


% [pusi,jerry,mesi,tery].
% [pusi,mesi].