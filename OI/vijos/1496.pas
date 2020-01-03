const	inf:array[0..9] of integer=(6,2,5,5,4,5,6,3,7,6);
var	i,j,k,n,m,ans:longint;
function get(x:longint):longint;
begin
	if x=0 then exit(inf[0]);
	get:=0;
	while x<>0 do begin
		inc(get,inf[x mod 10]);
		x:=x div 10;	
	end;
end;
begin
	readln(n);
	dec(n,4);
	ans:=0;
	for i:=0 to 1000 do begin
		for j:=0 to 1000 do begin
			k:=get(i)+get(j)+get(i+j);
			if k=n then begin
				inc(ans);
			end;
		end;
	end;
	writeln(ans);
end.
