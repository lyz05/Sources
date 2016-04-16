const	mo=292912345;
var	s,s1:string;
	t,t1:int64;
	i,j,len:longint;
	h:array[0..100001] of int64;
begin
	readln(s);
	h[0]:=0;
	len:=length(s);
	for i:=1 to len do begin
		h[i]:=(h[i-1]*26+ord(s[i])-96) mod mo;
	end;
	readln(s1);
	t:=0;
	for i:=1 to length(s1) do begin
		t:=(t*26+ord(s1[i])-96) mod mo;
	end;
	for i:=length(s1) to length(s) do begin
		t1:=h[i-length(s1)];
		for j:=1 to length(s1) do t1:=26*t1;
		t1:=((h[i]-t1)+mo) mod mo;
		if t=t1 then writeln(i-length(s1)+1);
		//t:=(t+26*26) mod mo;
	end;
end.

