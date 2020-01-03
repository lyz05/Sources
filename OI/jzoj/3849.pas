var	i,j,m,n,len,leng:longint;
	s,s1:ansistring;
	h,h1:longint;
        p:boolean;
function pd(x:longint):boolean;
var	i,j:longint;
	tmp,tmp1:ansistring;
begin
	tmp:=copy(s,1,x);
	for i:=2 to len div x do begin
		tmp1:=copy(s,(i-1)*x+1,x);
		if tmp<>tmp1 then exit(false);
	end;
	if (len div x)<2 then exit(false) else exit(true);
end;
begin
	readln(m);
	for i:=1 to m do begin
		readln(s);
		leng:=length(s);
		p:=true;
		while p do begin
			p:=false;
			len:=length(s);
			for j:=trunc(sqrt(len)) downto 1 do
				if len mod j=0 then begin
					if pd(j) then begin
						s:=copy(s,1,j);
						p:=true;
						break;
					end;
                         if pd(len div j) then begin
						s:=copy(s,1,len div j);
						p:=true;
						break;
					end;
				end;
		end;
		writeln(leng div len);

	end;
end.
