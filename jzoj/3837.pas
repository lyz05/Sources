var i,j,t:longint;
    ans,m,n:qword;
procedure swap(var x,y:qword);
var t:qword;
begin
   t:=x;
   x:=y;
   y:=t;
end;
begin
	readln(t);
	for i:=1 to t do begin
                ans:=0;
		readln(n,m);
		if n>m then swap(n,m);
		if n=1 then writeln(m);
		if n=2 then begin
                  ans:=4*(m div 4);
                  if m mod 4>=3 then inc(ans,4) else inc(ans,2*(m mod 4));
                 // ans:=ans+2*(m mod 4);
                end;
		if n>=3 then ans:=(n*m+1) div 2;
		if ans<>0 then writeln(ans);
	end;
end.
