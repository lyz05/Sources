const	maxy=15000;mo=10000;
var	i,j,k,m,n,t,x,y,ans:longint;
	f,s:array[0..maxy] of longint;
procedure prepar;
var	i:longint;
begin
	f[1]:=1;f[2]:=1;s[1]:=1;s[2]:=2;
	for i:=3 to maxy do begin
		f[i]:=(f[i-1]+f[i-2]) mod mo;
		s[i]:=(s[i-1]+f[i]) mod mo;
	end;
end;
begin
	//assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	prepar;
	//for i:=1 to maxy do writeln(s[i]);
	readln(t);
	while t>0 do begin
		ans:=0;
		readln(x,y);
		y:=y mod maxy;
		x:=x mod maxy;
		if x=0 then x:=maxy;
		if y=0 then y:=maxy;
		ans:=s[y]-s[x-1];
		while ans<0 do inc(ans,mo);
		writeln(ans);
		dec(t);
	end;
end.
