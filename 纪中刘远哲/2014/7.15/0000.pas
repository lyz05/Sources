const c = 2009;
var
 n, p, s, i, j, t: integer;
begin
 read(n, p);
 s := 0;
 t := 1;
 for i := 1 to n do
 begin
 t := t * p mod c;
 for j := 1 to i do
 s := (s + t) mod c;
 end;
 writeln(s);
end.