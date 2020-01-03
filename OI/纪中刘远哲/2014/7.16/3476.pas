const max=100000;
var n,i,j,l,r,ans,tmp,k,zz:longint;
    p:boolean;
    a:array[1..18] of longint;
    jl:array[1..max] of longint;
begin
  readln(n,l,r);
  for i:=1 to n do read(a[i]);

  ans:=0;
  for i:=1 to n do
  begin
    j:=l div a[i];
    repeat
      tmp:=j*a[i];
      if (tmp>=l) and (tmp<=r) then begin
       inc(ans);
       p:=true;
       for k:= 1 to max do
         if (jl[k]=tmp) then
         begin
           p:=false;
           break;
         end else
          if jl[k]=0 then break;
       zz:=k;
       if p then
       begin
        for k:=1 to n do
          if (k<>i) and (tmp mod a[k]=0) then
          begin
            dec(ans);
            jl[zz]:=tmp;
          end;
       end;
      end;
      inc(j);
    until tmp>r;
  end;

  writeln((r-l+1)-ans);
end.
