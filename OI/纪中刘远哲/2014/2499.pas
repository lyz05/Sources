var s:ansistring;
    x,y,i,j,t,ans,ans1:longint;
procedure solve(n:longint);
var i:longint;
begin
  for i:=1 to n do
  begin
    case s[i] of
      'E':inc(x);
      'S':dec(y);
      'W':dec(x);
      'N':inc(y);
    end;
  end;
end;
begin
  readln(s);
  readln(t);
  x:=0;y:=0;
  solve(length(s));

  ans1:=t div length(s);
  ans:=t mod length(s);
  x:=x*ans1;y:=y*ans1;
  solve(ans);
  writeln(x,' ',y);
end.
