bandingkan(X,Y,1) :- X < Y, !.
bandingkan(X,Y,0) :- X =:= Y, !.
bandingkan(X,Y,-1) :- X > Y.

program :- read(A), read(B), bandingkan(A,B,J), write(J), nl.

?- program.