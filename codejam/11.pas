var	i,j,k,m,n,t:longint;
	s1,s2,s:ansistring;
begin
	//assign(input,'11.in');reset(input);
	readln(T);
	for i:=1 to T do begin
		readln(s1);
		s2:=s1[1];
		for j:=2 to length(s1) do 
			if s1[j]>=s2[1] then s2:=s1[j]+s2 else s2:=s2+s1[j];
		writeln('Case #',i,': ',s2);
	end;
end.

