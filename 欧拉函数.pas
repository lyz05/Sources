var     n,oula,i:longint;
begin
        readln(n);
        i:=2;
        oula:=n;
        while i*i<=n do begin
                if n mod i=0 then begin
                        oula:=oula div i*(i-1);
                        while n mod i=0 do n:=n div i;
                end else inc(i);
        end;
        if n<>1 then oula:=oula div n*(n-1);
        writeln(oula);
end.
