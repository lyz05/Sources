var i,n,m:longint;
begin
    randomize;
    n:=random(100)+1;
    m:=random(100)+1;
    writeln(n,' ',m);
    for i:=1 to m do writeln(random(n)+1,' ',random(n)+1);
end.