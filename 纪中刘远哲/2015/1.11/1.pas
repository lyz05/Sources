const	mo=1000000000+7;
var	i,j,k,m,n,s,t,kk:longint;
	c:array[0..1000,0..1000] of longint;
	ans:int64;
begin
	assign(input,'1.in');reset(input);
	//assign(output,'.out');rewrite(output);

	readln(s,t,n,m);

	c[1,1]:=1;
	for i:=2 to s do
		for j:=1 to i do
			c[i,j]:=c[i-1,j]+c[i-1,j-1];

	kk:=n*t;
	for i:=0 to kk-n do begin
		ans:=ans+(c[s-kk+i,m-n]*(c[kk-i,n]-c[kk-t,n]) mod mo) mod mo;
		ans:=ans mod mo;
	end;
	writeln(ans mod mo);
end.
