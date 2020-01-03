const 	maxn=100000;
var	i,j,k,m,n,ans,x:longint;
	a:array[1..maxn] of longint;
	last:array[-maxn..maxn] of longint;
begin
	readln(n);
	for i:=1 to n do begin
		read(x);
		if x=0 then x:=-1;
		a[i]:=a[i-1]+x;
	end;
	for i:=1 to n do 
		if (last[a[i]]<>0) or (a[i]=0) then begin
			if i-last[a[i]]>ans then ans:=i-last[a[i]];
		end else last[a[i]]:=i;
	writeln(ans);
end.
