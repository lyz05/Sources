var	i,j,k,m,n:longint;
	s:array[1..6] of ansistring;		//change
procedure work(t1,t2,t3:longint);
var	i:longint;
begin
	for k:=0 to 6 do begin
		s[4]:='';s[5]:='';s[6]:='';
		for i:=1 to n do begin
			s[4]:=s[t1][i]+s[4];
			s[5]:=s[5]+chr((ord(s[t2][i])-ord('a')-k+26) mod 26+ord('a'));
			s[6]:=s[6]+chr((ord(s[t3][i])-ord('a')+k+26) mod 26+ord('a'));
		end;
		if (s[4]=s[5]) and (s[5]=s[6]) then begin
			writeln(s[4]);
			halt;
		end;
	end;
end;
begin
	assign(input,'data.in');reset(input);
	readln(n);
	for i:=1 to 3 do 
		readln(s[i]);
	for i:=1 to 3 do 
	for j:=1 to 3 do begin 
	if (i=j) then continue;
	for k:=1 to 3 do begin
	if (i=k) or (j=k) then continue;
		work(i,j,k);
	end;	
	end;
	
end.
