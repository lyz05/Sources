const qm=100000000;
var i,j,k,a,b,ans:longint;
    s:string;//change
begin
  readln(s);
  j:=1;a:=0;b:=0;
  for i:=1 to length(s) do
  begin
    a:=a+ord(s[i])*j mod qm;
    j:=j*2;
    b:=2*b+ord(s[length(s)-i+1])*1;
    if a=b then write(i,' ');
  end;
end.
