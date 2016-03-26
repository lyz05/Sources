var x,y,min,l1,l,z,k,x1:int64;
    i,t:longint;
begin
    readln(t);
    for i:=1 to t do begin
        readln(x,y);
        z:=2;
        min:=1000000000000000000;
        k:=trunc(sqrt(y));
        while z<=k do begin
              if y mod z=0 then begin
                  l:=0;
                  while y mod z=0 do begin
                        y:=y div z;
                        l:=l+1;
                  end;
                  k:=trunc(sqrt(y));
                  x1:=x;
                  while x1>0 do begin
                      x1:=x1 div z;
                      l1:=l1+x1;
                  end;
                  if l1 div l<min then min:=l1 div l;
                  l1:=0;
              end else inc(z);
        end;
        if y>1 then begin
            while x>0 do begin
                x:=x div y;
                l1:=l1+x;
            end;
            if l1<min then min:=l1;
            l1:=0;
        end;
        writeln(min);
    end;
end.