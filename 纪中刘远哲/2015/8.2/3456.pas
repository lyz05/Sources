const	maxx=10	00;
var	k,m,n,ans,x:longint;
	i,j,tmp:qword;
function jc(x:longint):longint;
var	i:longint;
begin
	jc:=1;
	for i:=2 to x do jc:=jc*i;
end;
begin
	ans:=0;
	readln(n);
	x:=jc(n);
	i:=x;
	while i<=maxx do begin 
		j:=x;
		while j<=maxx do begin
			if (i*j) mod (i+j)=0 then begin
				tmp:=(i*j) div (i+j);
				if tmp=x then
					inc(ans);
			end;
			inc(j);
		end;
		inc(i);
	end;
	writeln(ans);
end.
