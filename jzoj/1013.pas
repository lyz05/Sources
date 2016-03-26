var g,l,i,j,k,x,y,z:longint;
function gcd(x,y:longint):longint;
begin
	if x mod y=0 then exit(y) else exit(gcd(y,x mod y));
end;
begin
	readln(g,l);
	x:=l div g;
	for i:=trunc(sqrt(x)) downto 1 do begin
		if (x mod i=0) and (gcd(i,x div i)=1) then begin
			writeln(g*(x div i-i));
			halt;
		end;
	end;
end.
