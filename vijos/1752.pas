var	i,j,k,m,n,cnt,len,t:longint;
	s1,s2,std:string;
	pass:array[1..26] of char;
	p:array[1..26] of boolean;
procedure fail;
begin
	writeln('Failed');
	halt;
end;
begin
	fillchar(pass,sizeof(pass),0);
	readln(s1);
	readln(std);
	readln(s2);
	len:=length(s1);
	if len<26 then fail;
	cnt:=0;
	for i:=1 to len do begin
		t:=ord(s1[i])-64;
		if (ord(pass[t])=0) then begin
			pass[t]:=std[i];
			p[ord(std[i])-64]:=true;
			inc(cnt);
		end else 
		if pass[t]<>std[i] then fail;
	end;
	if cnt<>26 then fail;
	for i:=1 to 26 do 
		if not p[i] then fail;
	for i:=1 to length(s2) do write(pass[ord(s2[i])-64]);
end.
