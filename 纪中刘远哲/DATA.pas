var i,j,K,n:longint;
begin
	randomize;
	n:=random(100);
	WRITELN(N);
	for i:=1 to n do begin
		j:=random(4)+1;
		K:=RANDOM(N);
		case j of
	       		1:write('I ',K);
			2:write('D');
			3:WRITE('L');
			4:WRITE('R');
			5:WRITE('Q ',K);
		end;
                WRITELN;
	end;
end.
