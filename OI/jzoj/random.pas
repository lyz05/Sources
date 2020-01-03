var n,i,j,max,tmp:longint;
begin
	assign(output,'0.in');rewrite(output);
        randomize;
	n:=5;
	max:=10000;
	writeln(n*9);
        for j:=2 to 10 do begin
	for i:=1 to n do begin
             writeln(j,' ',i);
	end;
        end;
      {  for i:=1 to n do begin
                writeln(3,' ',i)
        end;}
	close(output);
end.
