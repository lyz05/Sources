var i,j:longint;
    a,b,c,d,ans,n,k:qword;
begin
  readln(n,k);
  if n=1 then
  begin
    if k=1 then writeln(1) else writeln(-1);
    exit;
  end;
  if n=2 then
  begin
    if k<=3 then writeln(k) else writeln(-1);
    exit;
  end;
  a:=1;b:=n;ans:=0;
  for i:=1 to k do
  begin
    inc(ans,b-a+1);
    if ans>=k then begin
      writeln(b-(ans-k));
      exit;
    end;
    c:=a+a+1;
    d:=b+b-1;
    a:=c;
    b:=d;
  end;
  writeln(-1);
end.
