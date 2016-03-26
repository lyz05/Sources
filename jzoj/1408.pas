var i,j:longint;
    ans,n,tmp:qword;
    s,k:string;    //change
    a,b,ans:array[..10000] of longint;
procedure new;
begin
	a:=jf(a,a);a:=jf(a,1);
	b:=jf(b,b);b:=jf1(b,1);
	ans:=jf(ans,)
	
end;
procedure solve;
var i:longint;
begin
	while check do new;
	answer;
end;
begin
  readln(s);
  tmp:=pos(' ',s);
  val(copy(s,1,tmp-1),n);
  k:=copy(s,tmp+1,length(s)-tmp);
  
  if n=1 then
  begin
    if k='1' then writeln(1) else writeln(-1);
    exit;
  end;
  if n=2 then
  begin
    if k<='3' then writeln(k) else writeln(-1);
    exit;
  end;
  solve;
  {a:=1;b:=n;ans:=0;
  for i:=1 to k do
  begin
    inc(ans,b-a+1);
    if ans>=k then begin
      writeln(b-(ans-k));
      exit;
    end;
    a:=2*a+1;
    b:=2*b+1;
  end;}

  writeln(-1);
end.
