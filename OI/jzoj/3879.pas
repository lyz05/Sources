var a,b:int64;
begin
	while not eof do begin
		readln(a,b);
		if a=1000000000 then begin
			if b=0 then writeln('no') else writeln('yes');
		end else 	
		if (abs(a)<=1000000000) or (a+b=1000000000) then writeln('no') 
			else writeln('yes');
	end;
end.
