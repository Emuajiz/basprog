as --> [].
as --> [a], as.

kalimat -->
    sesuatu,
    " adalah ",
    jenis_sesuatu,
    " yang berbeda dengan ",
    beda_sesuatu.
sesuatu --> "Prolog".
jenis_sesuatu --> "pemrograman logika".
beda_sesuatu --> "modular.".

tree(nil) --> [].
tree(node(Name, Left, Right)) -->
    tree(Left),
    [Name],
    tree(Right).