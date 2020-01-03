const max=100000;
var n,b,i,j,k,ans,tmp,m:longint;
    a:array[1..max] of longint;
    l,r:array[-max..max] of longint;
begin
	readln(n,b);
	for i:=1 to n do begin
		read(a[i]);
		if a[i]=b then m:=i;
	end;

        l[0]:=1;
        r[0]:=1;
	tmp:=0;
	for i:=m-1 downto 1 do begin
		if a[i]<a[m] then inc(tmp) else dec(tmp);
		inc(l[tmp]);
	end;
	tmp:=0;
	for i:=m+1 to n do begin
		if a[i]<a[m] then inc(tmp) else dec(tmp);
		inc(r[tmp]);
	end;
	ans:=0;
	for i:=-n to n do inc(ans,l[i]*r[-i]);
	
	writeln(ans);
end.
