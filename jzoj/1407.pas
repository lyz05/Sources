var	q,i,j,k,m,n:longint;
	a,f:array[1..100000] of longint;
procedure dfs(x,y,z:longint);
var i,t:longint;
begin
	if x>y then exit;
	t:=y+1;
	for i:=x to y do begin
		if a[i]+i>=y+1 then begin
			f[i]:=z;
			t:=i;
                        break;
		end;
	end;
	if t=y+1 then exit;
	dfs(1,t-1,z+1);
	for i:=t+1 to y do begin
	    if a[i]+i>=y+1 then f[i]:=z else f[i]:=z+1;
	end;
end;
begin
	readln(n,m);
	for i:=1 to n do read(a[i]);
	dfs(1,n,1);
	for i:=1 to m do begin
		read(q);
		write(f[q],' ');
	end;
	writeln;
end.
