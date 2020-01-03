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

