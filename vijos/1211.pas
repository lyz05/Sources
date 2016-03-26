const	moon:array[1..12] of longint=(31,28,31,30,31,30,31,31,30,31,30,31);
var	i,j,k,m,n,a,b,c:longint;
function run(x:longint):boolean;
begin
	if (x mod 400=0) or (x mod 4=0) then exit(true) else exit(false);
end;
begin
	readln(a,b,c);
	for i:=1 to 10000 do begin
		inc(c);
		if (b=2) and (c>29) and run(a) then begin
			c:=1;
			inc(b);
		end;
		if (b=2) and run(a) and (c=29) then continue;
		if (c>moon[b])  then begin
			c:=1;
			inc(b);
		end;
		if b=13 then begin
			inc(a);
			b:=1;
		end;
	end;
	writeln(a,'-',b,'-',c);
end.
