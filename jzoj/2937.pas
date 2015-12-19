const	alpha='abcdefghijklmnopqrstuvwxyz';
var	i,j,k,m,n,len:longint;
	s,s1,s2,std:ansistring;
	pas:array[1..26] of char;
	flag:boolean;
procedure print(x:longint);
var	i:longint;
begin
	for i:=1 to x do write(s[i]);
	for i:=1 to x do write(pas[ord(s[i])-ord('a')+1]);
	writeln;
	write(chr(26));
	halt;
end;
begin
	assign(input,'2937.in');reset(input);
	readln(std);
	readln(s);

	for i:=1 to length(std) do 
		pas[ord(std[i])-ord('a')+1] := chr(i+ord('a')-1);

	len:=length(s) div 2;
	if length(s) mod 2=1 then inc(len);
	for i:=len to length(s) do begin
		s1:=copy(s,1,i);
		s2:=copy(s,i+1,length(s)-i);
		flag:=true;
		for j:=1 to length(s2) do 
			if std[ord(s2[j])-ord('a')+1]<>s1[j] then begin
				flag:=false;
				break;	
			end;
		if flag then print(i);
	end;
end.
