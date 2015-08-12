var	i,n,len:longint;
	s:ansistring;
function work:boolean;
var	i,j:longint;
begin
	for i:=1 to len do begin
		work:=true;
		for j:=1 to (len div 2) do begin
			if s[i+j-1]<>s[i+len-j] then begin
				work:=false;
				break;
			end;
		end;
		if work then break;
		work:=true;
		for j:=1 to ((len-1) div 2) do begin
			if s[i+j-1]<>s[i+(len-1)-j] then begin
				work:=false;
				break;
			end;			
		end;
		if work then break;
	end;
	exit(work);
end;
begin
	assign(input,'necklace.in');reset(input);
	assign(output,'necklace.out');rewrite(output);

	readln(n);
	for i:=1 to n do begin
		readln(s);
		len:=length(s);
		s:=s+s;
		if work then writeln('YES') else writeln('NO');
	end;
	
	close(input);close(output);
end.
