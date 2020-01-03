var	i,j,k,m,n,p1,p2,p3,len,l,r:longint;
	s:ansistring;		//change
	ch:char;
begin
	readln(p1,p2,p3);
	readln(s);
	len:=length(s);
	for i:=1 to len do begin
		if s[i]='-' then begin
			if (i=len) or (i=1) or (s[i-1]>=s[i+1]) 
			or (s[i-1]='-') or (s[i+1]='-') or
		        (('0'<=s[i-1])and(s[i-1]<='9')and('a'<=s[i+1])and(s[i+1]<='z')) or
			(('a'<=s[i-1])and(s[i-1]<='z')and('0'<=s[i+1])and(s[i+1]<='9'))then begin
				write(s[i]);
				continue;
			end;
			if (ord(s[i-1])+1=ord(s[i+1])) then continue;
			if p3=1 then begin
				l:=ord(s[i-1])+1;
				r:=ord(s[i+1])-1;
			end else begin
				l:=ord(s[i+1])-1;
				r:=ord(s[i-1])+1;
			end;
			if (l<r) then begin
				for j:=l to r do begin
					ch:=chr(j);
					if p1=1 then ch:=lowercase(ch)
					else if p1=2 then ch:=upcase(ch)
					else ch:='*';
					for k:=1 to p2 do begin
						write(ch);
					end;
				end;
			end else begin
				for j:=l downto r do begin
					ch:=chr(j);
					if p1=1 then ch:=lowercase(ch)
					else if p1=2 then ch:=upcase(ch)
					else ch:='*';
					for k:=1 to p2 do begin
						write(ch);
					end;
				end;
			end;
		end else write(s[i]);
	end;
end.
