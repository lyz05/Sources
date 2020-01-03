var	i,j,n,m,x,ans:longint;
	flag:boolean;
begin
	for x:=2 to 999999 do begin
		flag:=true;
		for j:=2 to trunc(sqrt(x)) do
			if x mod j=0 then begin
				flag:=false;
				break;
			end;
		if flag then begin
			inc(ans);
			write(x,',');
			if ans=50 then exit;
		end;
	end;
end.
begin
	readln(n);
	write(n,'=');
	while n<>1 do begin
		for i:=2 to n do 
			if n mod i=0 then begin
				write(i,'*');
				n:=n div i;
				break;
			end;
	end;
	writeln;
end.
