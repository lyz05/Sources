var	n,m,i,j:longint;
begin
	writeln((100*101) div 2);
	for n:=1 to 100 do 
		for m:=1 to n do writeln(n,' ',m,' 1000000007');
end.
var
	n, i, j:longint;
begin
	//assign(output,'a.in');rewrite(output);
	randomize;
	repeat
		n := random(1000);
	until n >= 3;
	writeln(n);
	for i := 1 to 3 do begin
		for j := 1 to n do begin
			write(random(5) + 1,' ');
		end;
		writeln;
	end;
	
	close(output);
end.

