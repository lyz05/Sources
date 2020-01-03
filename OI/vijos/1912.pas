var	a,b,x,y,i,j,m,n,l:longint;
	k,t,min:real;
function gcd(x,y:longint):longint;
begin
	if x mod y=0 then exit(y);
	gcd:=gcd(y,x mod y);
end;
begin
	readln(a,b,l);
	t:=a/b;
	min:=maxlongint>>1;
	for i:=1 to l do 
		for j:=1 to l do 
			if gcd(i,j)=1 then begin
				k:=i/j-t;
				if (k>=0) and (k<min) then begin
					x:=i;
					y:=j;
					min:=k;
				end;
			end;
	writeln(x,' ',y);
end.
